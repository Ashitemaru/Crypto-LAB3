#include <assert.h>
#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "define.h"
#include "hash.h"
#include "sbox.h"

char *low_density_stream(size_t *len) {
#define buf_sz 100
    static char buf[buf_sz];
    for (int i = 0; i < buf_sz; ++i) {
        char byte = 0;
        for (int j = 0; j < 8; ++j) {
            uint8_t rn = rand() % 100;
            if (rn < 5) {
                byte |= (1 << j);
            }
        }
        buf[i] = byte;
    }
    *len = buf_sz;
    return buf;
}

char *high_density_stream(size_t *len) {
#define buf_sz 100
    static char buf[buf_sz];
    for (int i = 0; i < buf_sz; ++i) {
        char byte = 0;
        for (int j = 0; j < 8; ++j) {
            uint8_t rn = rand() % 100;
            if (rn < 95) {
                byte |= (1 << j);
            }
        }
        buf[i] = byte;
    }
    *len = buf_sz;
    return buf;
}

char *random_stream(size_t *len) {
#define buf_sz 1000
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

void process_bar(double ratio) {
    setvbuf(stdout, 0, _IONBF, 0);
    static int prev_r = 0;
    const int total = 20;

    int current_r = (int)(100 * ratio);
    if (current_r != prev_r) {
        printf("\r");
        int i = 0;
        int process = ratio * total;
        printf("[");
        for (; i < process - 1; ++i) {
            printf("=");
        }
        printf(">");
        ++i;
        for (; i < total; ++i) {
            printf(" ");
        }
        printf("] %2d%%", current_r);
        prev_r = current_r;
    }
}



void print_hash(Hash *h) {
    for (int i = 0; i < 10; ++i) {
        printf("%02X ", h->hash[i]);
    }
    puts("");
}

int main() {
    const uint64_t file_size = 40 * 1024 * 1024;
    const uint64_t iteration_count = file_size / sizeof(Hash);
    char *buf = malloc(file_size);
    char *buf_p;
    char *input;
    size_t len;
    FILE *sample;

    srand(time(0));

    // random stream
    printf("Generating random sample...\n");
    sample = fopen("sample_random.out", "w");
    buf_p = buf;
    for (int i = 0; i < iteration_count; ++i) {
        input = random_stream(&len);
        Hash h = hash((const uint8_t*)input, len);
        memcpy(buf_p, &h, sizeof(Hash));
        buf_p += sizeof(Hash);
        process_bar((double) i / (iteration_count - 1));
    }
    puts("");
    fwrite(buf, file_size, 1, sample);

    // high density stream
    printf("Generating high density sample...\n");
    sample = fopen("sample_high_density.out", "w");
    buf_p = buf;
    for (int i = 0; i < iteration_count; ++i) {
        input = high_density_stream(&len);
        Hash h = hash((const uint8_t*)input, len);
        memcpy(buf_p, &h, sizeof(Hash));
        buf_p += sizeof(Hash);
        process_bar((double) i / (iteration_count - 1));
    }
    puts("");
    fwrite(buf, file_size, 1, sample);

    // low density stream
    printf("Generating low density sample...\n");
    sample = fopen("sample_low_density.out", "w");
    buf_p = buf;
    for (int i = 0; i < iteration_count; ++i) {
        input = low_density_stream(&len);
        Hash h = hash((const uint8_t*)input, len);
        memcpy(buf_p, &h, sizeof(Hash));
        buf_p += sizeof(Hash);
        process_bar((double) i / (iteration_count - 1));
    }
    puts("");
    fwrite(buf, file_size, 1, sample);

    return 0;
}
