#pragma once

#ifndef DEFINE_H_
#define DEFINE_H_

#include <byteswap.h>
#include <endian.h>
#include <stdint.h>

#define sigma(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#if __BYTE_ORDER == __BIG_ENDIAN
#define swap64(x) bswap_64((x))
#define swap16(x) bswap_16((x))
#else
#define swap64(x) (x)
#define swap16(x) (x)
#endif

#define BUF_SIZE 4096

#define CHECK(expr)            \
    {                          \
        int ret = (expr);      \
        if (ret != 0) {        \
            return ret;        \
        }                      \
    }

#endif // DEFINE_H_
