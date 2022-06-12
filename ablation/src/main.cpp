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
int __main() {
    collision();
    return 0;
}

extern const int hash_byte {10}; // TODO: Change length here

void repr_hash(Hash *h) {
    printf("{");
    for (int i {0}; i < 10; ++i) {
        printf("0x%02X, ", h->hash[i]);
    }
    puts("}");
}

void print_hash(Hash *h) {
    for (int i {0}; i < hash_byte; ++i) {
        printf("%02X ", h->hash[i]);
    }
    puts("");
}

bool operator <= (const Hash &lhs, const Hash &rhs) {
    for (int i {0}; i < hash_byte; ++i) {
        if (lhs.hash[i] > rhs.hash[i])
            return false;
        else if (lhs.hash[i] < rhs.hash[i])
            return true;
    }
    return true;
}

bool operator == (const Hash &lhs, const Hash &rhs) {
    return !memcmp(&lhs, &rhs, hash_byte);
}

Hash min_x;
Hash init_hash {
    .hash {1}
};

int64_t stack_search() {
//    printf("%d\n", __LINE__);
    Hash x {init_hash};
//    printf("%d\n", __LINE__);
    decltype(std::chrono::steady_clock::now()) tm;
    const int K=100; /* The number of stacks */
    const int stackSize=10000;
    struct stack_elem{ Hash val; uint64_t t; };
    auto stack = new stack_elem*[K];
    for (int i = 0; i < K; ++i) {
        stack[i] = new stack_elem[stackSize];
    }
    int h[K]; /* The stack sizes */
    int64_t i, k, time=0;
//    printf("%d, %d, %d, %d\n", __LINE__, k, i, h[k]);
    for (i=0; i<K; i++)
        h[i]=0;
//    printf("%d, %d, %d, %d\n", __LINE__, k, i, h[k]);
    while(1)
    {
        k = (x.hash[2])% K;
        for (i=h[k]-1; i>=0; i--)
            if (stack[k][i].val<=x)
                break;

//        printf("%d, %d, %d, %d\n", __LINE__, k, i, h[k]);
        if (i>=0 && stack[k][i].val==x){
            min_x = x;
            printf("Minimum Element: ");
            print_hash(&x);
            printf("Steps: %lu, Stack: %lu, Cycle: %lu\n", time, stack[k][i].t, time - stack[k][i].t);
            return time - stack[k][i].t;
        }

        stack[k][i+1].val=x;
        stack[k][i+1].t=time;
        h[k]=i+2;
        if (h[k] >= stackSize) {
            printf("Out of stack_size\n");
            exit(-1);
        }
        assert(h[k]<stackSize);
        x=hash((const uint8_t *) &x, hash_byte);
        time++;
        if (time % 1000000 == 0) {
            printf("%lu\n", time);
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
    Hash x {init_hash};

    for (int i {0}; i < d; ++i) {
        x=hash((const uint8_t *) &x, hash_byte);
    }

    Hash y {init_hash};
    Hash t1, t2;
    while(true) {
        t1 = hash((const uint8_t *) &x, hash_byte);
        t2 = hash((const uint8_t *) &y, hash_byte);
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
    printf("Repr\n");
    repr_hash(&x);
    repr_hash(&y);

}
int main() {
    uint8_t f[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, };
    uint8_t f2[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 33, };
    Hash h = hash((const uint8_t *)f, 8);
    print_hash(&h);
    puts("");

    Hash h2 = hash((const uint8_t *)f2, 8);
    print_hash(&h2);
    return 0;
}