#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "define.h"
#include "sbox.h"
#include "state.h"

extern const int hash_byte;

// ?: Some other name?
const uint64_t big_prime1 = 3118691898498409469ull;
const uint64_t big_prime2 = 8177414977493372647ull;
const uint64_t big_prime3 = 8390810104093054171ull;

const int ABSORB_ROUNDS = 1; // TODO: Change Rounds here
const int SQUEEZE_ROUNDS = 10; // TODO: Change Rounds here

__attribute__((always_inline)) inline uint64_t circular_shiftr(uint64_t value, int s) {
    return (value >> s) | (value << (64 - s));
}

#define define_round_with_iter(ROUNDS)                                                      \
    __attribute__((always_inline)) inline State one_round_##ROUNDS(uint64_t m, State s) {   \
        uint64_t temp_m;                                                                    \
        State temp_s;                                                                       \
                                                                                            \
        for (int iter = 0; iter < ROUNDS; ++iter) {                                         \
            m = sbox(m);                                                                    \
            m = circular_shiftr(m, 57); /* 64 - 7 */                                        \
            s.a = sbox(s.a);                                                                \
            s.b = sbox(s.b);                                                                \
            s.c = sbox(s.c);                                                                \
            s.d = sbox(s.d);                                                                \
                                                                                            \
            temp_m = s.d + big_prime2;                                                      \
            temp_s.a = m;                                                                   \
            temp_s.c = s.b;                                                                 \
            temp_s.b = circular_shiftr(s.a, 17) + (sigma(s.b, s.c, s.d));                   \
            temp_s.d = s.c + big_prime1;                                                    \
                                                                                            \
            temp_s.a = temp_s.a ^ (temp_m & 0xffffull);                                     \
            temp_s.b = temp_s.b ^ ((temp_m >> 16) & 0xffffull);                             \
            temp_s.c = temp_s.c ^ ((temp_m >> 32) & 0xffffull);                             \
            temp_s.d = temp_s.d ^ (temp_m >> 48);                                           \
                                                                                            \
            m = temp_m;                                                                     \
            s = temp_s;                                                                     \
        }                                                                                   \
                                                                                            \
        return temp_s;                                                                      \
                                                                                                \
    }

define_round_with_iter(ABSORB_ROUNDS);
define_round_with_iter(SQUEEZE_ROUNDS);

State absorb_one_round(uint64_t m, State current_state) {
//    puts("Absorb one round");
    State state = one_round_ABSORB_ROUNDS(m, current_state);
//    DumpState(state);
    return state;
}

State absorb(const uint8_t* stream, size_t len, State state) {
    assert(len % 8 == 0);
    for (size_t i = 0; i < len / 8; i += 8) {
        uint64_t m = *(uint64_t*)(stream + i);
        m = swap64(m);
        state = absorb_one_round(m, state);
    }
    return state;
}

#define STEP 2

State squeeze_one_round(uint8_t* target, State input) {
    puts("Squeeze one round");
    State output = one_round_SQUEEZE_ROUNDS(big_prime3, input);
    uint16_t out = (output.a & 0xffffull) ^ (output.b & 0xffffull) ^ (output.c & 0xffffull) ^ (output.d & 0xffffull);
    out = swap16(out);
    memcpy(target, &out, 2);
    return output;
}

Hash squeeze(State input) {
    Hash ret;
    int i;
    for (i = 0; i < hash_byte; i += 2) { // TODO Change This
        input = squeeze_one_round(ret.hash + i, input);
    }
    for (; i < 10; ++i) {
        ret.hash[i] = 0;
    }
    return ret;
}
