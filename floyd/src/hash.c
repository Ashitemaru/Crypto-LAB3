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
    state = absorb_one_round(len, state); // padding 2

    return squeeze(state);
}