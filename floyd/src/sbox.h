#pragma once

#ifndef SBOX_H_
#define SBOX_H_

#include <stdint.h>

uint64_t sbox(uint64_t input);

void cache_prefetch();

#endif // SBOX_H_
