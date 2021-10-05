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
// hashlib.sha256(b'testing').hexdigest()
// `cf80cd8aed482d5d1527d7dc72fceff84e6326592848447d2dc0b0e87dfc9a90`

static unsigned char x[] = "testing";
static unsigned char h[crypto_hash_sha256_BYTES];

int sha256(int argc, char* argv[])
{
    size_t i;

    // Hash function
    if (argc == 2) {
        crypto_hash_sha256(h, (const unsigned char *) argv[1], strlen(argv[1]));
        printf("sha256(\"%s\") = ", argv[1]);
    }
    else {
        printf("Usage: %s testing\n", argv[0]);
        crypto_hash_sha256(h, x, sizeof(x) - 1U);     // remove the ending '\0'
        printf("sha256(\"%s\") = ", x);
    }

    // Print the hash result
    for (i = 0; i < crypto_hash_sha256_BYTES; ++i) {
        printf("%02x", (unsigned int) h[i]);
    }
    printf("\n");

    return 0;
}
MSH_CMD_EXPORT(sha256, sha256)
