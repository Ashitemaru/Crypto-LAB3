#include "hash.h"
#include "define.h"

Hash hash(const uint8_t* stream, size_t len) {
    size_t remaining = len % 8;
    size_t groups = len / 8;

    // padding
    uint64_t m = 0;
    memcpy(&m, stream + 8 * groups, remaining);
    m = swap64(m);
    len = swap64(len);

    State state = {0, 0, 0, 0}; // initial
    state = absorb(stream, groups * 8, state);
    state = absorb_one_round(m, state);   // padding 1

    puts("=== Absorbing ===");
    DumpState(state);
    puts("=== Absorbing ===");

    state = absorb_one_round(len, state); // padding 2

    puts("After absorbing");
    DumpState(state);

    return squeeze(state);
}

void HashAt(Hash *dst, const uint8_t* stream, size_t len) {
    size_t remaining = len % 8;
    size_t groups = len / 8;

    // padding
    uint64_t m = 0;
    memcpy(&m, stream + 8 * groups, remaining);
    m = swap64(m);
    len = swap64(len);

    State state = {0, 0, 0, 0}; // initial
    state = absorb(stream, groups * 8, state);
    state = absorb_one_round(m, state);   // padding 1
    state = absorb_one_round(len, state); // padding 2

    for (int i = 0; i < 6; i += 2) {
        state = squeeze_one_round(dst->hash + i, state);
    }
}