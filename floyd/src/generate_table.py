from __future__ import annotations

import os
import math
import bisect
import sys
from typing import Iterable

big_prime = 56491852076393467


def table(byte_idx: int):
    nums = tuple(range(256 * byte_idx, 256 * (byte_idx + 1)))
    unsorted_mapped = list(map(lambda i: math.sin(i), nums))
    sorted_mapped = sorted(unsorted_mapped)
    return [bisect.bisect_left(sorted_mapped, i) for i in unsorted_mapped]


def tables_64():
    return [[f"0x{val:02X}{'00' * i}ull" for val in table(i)] for i in range(8)]


def format_S(s: list[str]):
    return "{" + ",".join(s) + "}"


def format_file(s: list[list[str]]):
    base = '#include <stdint.h>\nconst uint64_t S[8][256] = '
    return base + "{" + ",\n".join(map(format_S, s)) + "};\n"


def dot(x: Iterable[int], y: Iterable[int]):
    return math.sqrt(sum(map(lambda t: t[0] * t[1], zip(x, y))))


def cosine_similarity(x: list[int], y: list[int]):
    return dot(x, y) / math.sqrt(dot(x, x) * dot(y, y))


if __name__ == "__main__":
    with open(sys.argv[1], "w") as f:
        f.write(format_file(tables_64()))
