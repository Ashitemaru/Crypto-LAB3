#include <stdio.h>
#include <string.h>

#include "define.h"
#include "hash.h"
#include "sbox.h"

inline int hashcmp(uint8_t *ptr_a, uint8_t *ptr_b, int len) {
    for (int i = 0; i < len; ++i)
        if (ptr_a[i] != ptr_b[i])
            return 0;
    return 1;
}

int main() {
    uint8_t ptr_a[10] = { 0 }, ptr_b[10] = { 0 };
    unsigned int cnt = 0;
    do {
        Hash h1 = hash((const uint8_t*)ptr_a, 10);
        Hash h2 = hash((const uint8_t*)h1.hash, 10);
        Hash h3 = hash((const uint8_t*)ptr_b, 10);
        memcpy(ptr_a, h2.hash, 10);
        memcpy(ptr_b, h3.hash, 10);
        if (++cnt > 2147483648) return -1; 
        if (cnt % 1000000 == 0) printf("%d\n", cnt);
    } while (!hashcmp(ptr_a, ptr_b, 10));
    memset(ptr_a, 0, 10);
    while (!hashcmp(ptr_a, ptr_b, 10)) {
        Hash h1 = hash((const uint8_t*)ptr_a, 10);
        Hash h2 = hash((const uint8_t*)ptr_b, 10);
        memcpy(ptr_a, h1.hash, 10);
        memcpy(ptr_b, h2.hash, 10);
    }
    for (size_t i = 0; i < 10; ++i) {
        printf("%02x", ptr_a[i]);
    }

    return 0;
}
