#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <chrono>
#include "define.h"
#include "hash.h"
#include "sbox.h"

char *random_stream(size_t *len) {
#define buf_sz 10000
    static char buf[buf_sz];
    for (int i = 0; i < buf_sz; ++i) {
        char byte = 0;
        for (int j = 0; j < 8; ++j) {
            uint8_t rn = rand() % 100;
            if (rn < 50) {
                byte |= (1 << j);
            }
        }
        buf[i] = byte;
    }
    *len = buf_sz;
    return buf;
}

size_t diff(const Hash *lhs, const Hash *rhs) {
    size_t difference = 0;
    for (int i = 0; i < 10; ++i) {
        uint8_t res = lhs->hash[i] ^ rhs->hash[i];
        for (int j = 0; j < 8; ++j) {
            if (res & (1 << j))
                ++difference;
        }
    }
    return difference;
}

int __gt(const void *x, const void *y) {
    return *(size_t *) x > *(size_t *) y;
}

void collision() {
    size_t len;
    char *stream = random_stream(&len);
    Hash ori = hash((const uint8_t *) stream, len);
    size_t *list = (size_t *) malloc(sizeof(size_t) * len * 8);

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 8; ++j) {
            stream[i] ^= 1 << j;
            Hash new_hash = hash((const uint8_t *) stream, len);
            size_t delta = diff(&ori, &new_hash);
            list[8 * i + j] = delta;
        }
    }
    qsort(list, len * 8, sizeof(size_t), __gt);

    FILE *f = fopen("result.txt", "w");
    for (int i = 0; i < len * 8; ++i) {
        fprintf(f, "%zu\n", list[i]);
    }
    fclose(f);
}

int main() {
    collision();
    return 0;
}