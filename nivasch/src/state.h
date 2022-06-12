#pragma once

#ifndef STATE_H_
#define STATE_H_

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t a, b, c, d;
} State;

typedef struct {
    uint8_t hash[10];
} Hash;

State absorb_one_round(uint64_t m, State current_state);

State absorb(const uint8_t* stream, size_t len, State initial);

State squeeze_one_round(uint8_t* target, State input);

Hash squeeze(State input);

#endif // STATE_H_