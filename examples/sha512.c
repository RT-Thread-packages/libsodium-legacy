#include <rtthread.h>

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "sodium.h"

// Python equivalent
// hashlib.sha512(b'testing').hexdigest()
// `521b9ccefbcd14d179e7a1bb877752870a6d620938b28a66a107eac6e6805b9d0989f45b5730508041aa5e710847d439ea74cd312c9355f1f2dae08d40e41d50`

static unsigned char x[] = "testing";
static unsigned char h[crypto_hash_sha512_BYTES];

int sha512(int argc, char* argv[])
{
    size_t i;

    // Hash function
    if (argc == 2) {
        crypto_hash_sha512(h, (const unsigned char *) argv[1], strlen(argv[1]));
        printf("sha512(\"%s\") = ", argv[1]);
    }
    else {
        printf("Usage: %s testing\n", argv[0]);
        crypto_hash_sha512(h, x, sizeof(x) - 1U);     // remove the ending '\0'
        printf("sha512(\"%s\") = ", x);
    }

    // Print the hash result
    for (i = 0; i < crypto_hash_sha512_BYTES; ++i) {
        printf("%02x", (unsigned int) h[i]);
    }
    printf("\n");

    return 0;
}
MSH_CMD_EXPORT(sha512, sha512)
