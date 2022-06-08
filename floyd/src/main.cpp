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
void print_hash(Hash *h) {
    for (int i {0}; i < 10; ++i) {
        printf("%02X ", h->hash[i]);
    }
    puts("");
}
char *random_stream(size_t *len) {
#define buf_sz 100
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
inline int hashcmp(uint8_t *ptr_a, uint8_t *ptr_b, int len) {
    return memcmp(ptr_a, ptr_b, len);
}
int __main() {
    collision();
    return 0;
}

bool operator <= (const Hash &lhs, const Hash &rhs) {
    for (int i {0}; i < 10; ++i) {
        if (lhs.hash[i] > rhs.hash[i])
            return false;
        else if (lhs.hash[i] < rhs.hash[i])
            return true;
    }
    return true;
}

bool operator == (const Hash &lhs, const Hash &rhs) {
    return !memcmp(&lhs, &rhs, 10);
}

Hash min_x;

uint64_t stack_search() {
    Hash x {
        .hash = {1}
    };
    decltype(std::chrono::steady_clock::now()) tm;
    const int K=100; /* The number of stacks */
    const int stackSize=100;
    struct { Hash val; uint64_t t; }
    stack[K][stackSize];
    int h[K]; /* The stack sizes */
    uint64_t i, k, time=0;
    for (i=0; i<K; i++)
        h[i]=0;
    while(1)
    {
        k = (x.hash[2])% K;
        for (i=h[k]-1; i>=0; i--)
            if (stack[k][i].val<=x)
                break;
        if (i>=0 && stack[k][i].val==x){
            min_x = x;
            print_hash(&x);
            printf("Steps: %llu, Stack: %llu, Cycle: %llu\n", time, stack[k][i].t, time - stack[k][i].t);
            return time - stack[k][i].t;
        }

        stack[k][i+1].val=x;
        stack[k][i+1].t=time;
        h[k]=i+2;
        assert(h[k]<stackSize);
        x=hash((const uint8_t *) &x, 10);
        time++;
        if (time % 1000000 == 0) {
            printf("%llu\n", time);
            auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - tm);
            printf("Time Cost: %lf\n", delta.count() / 1000.0);
            tm = std::chrono::steady_clock::now();
//            for (int i {0}; i < K; ++i){
//                printf("%d ", h[i]);
//            }
            printf("\n");
        }
//        print_hash(&x);
    }
}

void get_coll(uint64_t d) {
    Hash x {
        .hash = {1}
    };

    for (int i {0}; i < d; ++i) {
        x=hash((const uint8_t *) &x, 10);
        if (min_x == x) {
            puts("init: Min! ");
            printf("%d\n", i);
        }
    }

    Hash y {
        .hash = {1}
    };
    Hash t1, t2;
    while(true) {
        t1 = hash((const uint8_t *) &x, 10);
        t2 = hash((const uint8_t *) &y, 10);
//        print_hash(&t1);
//        print_hash(&t2);
        if (t1 == t2) {
            break;
        }
        x = t1;
        y = t2;
    }

    printf("X_1: ");
    print_hash(&x);
    printf("Hash to: ");
    print_hash(&t1);
    printf("X_2: ");
    print_hash(&y);
    printf("Hash to: ");
    print_hash(&t2);
}



int floyd() {
    uint8_t ptr_a[10] = { 0 }, ptr_b[10] = { 0 };
    Hash h1, h2, h3;
    decltype(std::chrono::steady_clock::now()) time;
    unsigned int cnt = 0;
    do {
        HashAt((Hash *) ptr_a, (const uint8_t*)ptr_a, 10);
        HashAt((Hash *) ptr_a, (const uint8_t*)ptr_a, 10);
        HashAt((Hash *) ptr_b, (const uint8_t*)ptr_b, 10);
        if (++cnt > 2147483648) return -1; 
        if (cnt % 1000000 == 0) {
            printf("%d\n", cnt);
            auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - time);
            printf("Time Cost: %lf\n", delta.count() / 1000.0);
            time = std::chrono::steady_clock::now();
        }
//        print_hash(&h2);
//        print_hash(&h3);
    } while (hashcmp(ptr_a, ptr_b, 10));
    printf("Pointers meet @ ");
    print_hash((Hash *)ptr_a);
    printf("Iteration count: %d\n", cnt);
    memset(ptr_a, 0, 10);
    while (true) {
        h1 = hash((const uint8_t*)ptr_a, 10);
        h2 = hash((const uint8_t*)ptr_b, 10);
        if (hashcmp(h1.hash, h2.hash, 10)) {
            memcpy(ptr_a, h1.hash, 10);
            memcpy(ptr_b, h2.hash, 10);
        } else {
            break;
        }
    }
    printf("X_1: ");
    print_hash((Hash *)ptr_a);
    h1 = hash(ptr_a, 10);
    printf("Hash to: ");
    print_hash(&h1);
    printf("X_2: ");
    print_hash((Hash *)ptr_b);
    h2 = hash(ptr_b, 10);
    printf("Hash to: ");
    print_hash(&h2);
    return 0;
}
int main() {
    auto cyc {stack_search()};
    printf("%llu\n", cyc);
    get_coll(cyc);
//    floyd();
    return 0;
}