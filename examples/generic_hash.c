#include <rtthread.h>

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "sodium.h"

static char in[] = "testing";

unsigned char out[crypto_generichash_BYTES];
unsigned char key[crypto_generichash_KEYBYTES];

int generic_hash(int argc, char* argv[])
{
    size_t i;

    // Set Hash Key
    for (i = 0; i < crypto_generichash_KEYBYTES_MAX; ++i) {
        key[i] = (unsigned char) i;
    }

    // Hash function
    if (argc == 2) {
        crypto_generichash(out, sizeof out, (const unsigned char *) argv[1], (size_t) strlen(argv[1]), key, sizeof key);
        printf("generic_hash(\"%s\") = ", argv[1]);
    }
    else {
        printf("Usage: %s testing\n", argv[0]);
        crypto_generichash(out, sizeof out, (const unsigned char *) in, (size_t) strlen(in), key, sizeof key);
        printf("generic_hash(\"%s\") = ", in);
    }

    for (i = 0; i < crypto_generichash_BYTES; ++i) {
        printf("%02x", (unsigned int) out[i]);
    }
    printf("\n");

    return 0;
}
MSH_CMD_EXPORT(generic_hash, libsodium generic hash)
