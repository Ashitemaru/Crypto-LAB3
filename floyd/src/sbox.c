#include "sbox.h"
#include <stddef.h>
#include <stdint.h>

extern const uint64_t S[8][256];

uint64_t sbox(uint64_t input) {
    uint64_t ret = 0;

    for (uint64_t i = 0; i < 8; ++i) {
        ret |= S[i][input & 0xffull];
        input >>= 8;
    }

    return ret;
}

void cache_prefetch() {
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 256; j += 8) {
            __builtin_prefetch(&S[i][j], 0, 3);
        }
    }
}
