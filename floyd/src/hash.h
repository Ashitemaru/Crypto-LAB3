#pragma once

#ifndef HASH_H_
#define HASH_H_

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "state.h"

Hash hash(const uint8_t* stream, size_t len);

#endif