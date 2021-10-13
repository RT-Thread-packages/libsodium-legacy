#include <rtthread.h>

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "sodium.h"

#define MAXLEN 64
static unsigned char in[MAXLEN];
static unsigned char out[crypto_shorthash_BYTES];
static unsigned char k[crypto_shorthash_KEYBYTES];

int short_hash(int argc, char* argv[])
{
    size_t i;

    // Set Hash Key
    for (i = 0; i < crypto_shorthash_KEYBYTES; ++i) {
        k[i] = (unsigned char) i;
    }

    // Hash function
    if (argc == 2) {
        crypto_shorthash(out, (const unsigned char *) argv[1], strlen(argv[1]), k);
        printf("short_hash(\"%s\") = ", argv[1]);
    }
    else {
        printf("Usage: %s 01\n", argv[0]);
        in[0] = (unsigned char) '0';
        in[1] = (unsigned char) '1';
        crypto_shorthash(out, in, 2, k);
        printf("short_hash(\"%c%c\") = ", in[0], in[1]);
    }

    for (i = 0; i < crypto_shorthash_BYTES; ++i) {
        printf("%02x", (unsigned int) out[i]);
    }
    printf("\n");

    return 0;
}
MSH_CMD_EXPORT(short_hash, libsodium short hash)
