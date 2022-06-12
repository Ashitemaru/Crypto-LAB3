#include "sbox.h"
#include <stddef.h>
#include <stdint.h>

#include <stdint.h>
const uint64_t S[8][256] = {{0x7Full,0xD1ull,0xDCull,0x8Aull,0x38ull,0x17ull,0x68ull,0xBAull,0xF3ull,0xA1ull,0x4Full,0x00ull,0x50ull,0xA2ull,0xF4ull,0xB9ull,0x67ull,0x16ull,0x39ull,0x8Bull,0xDDull,0xD0ull,0x7Eull,0x2Dull,0x22ull,0x73ull,0xC5ull,0xE8ull,0x96ull,0x44ull,0x0Bull,0x5Cull,0xAEull,0xFFull,0xADull,0x5Bull,0x0Aull,0x45ull,0x97ull,0xE9ull,0xC4ull,0x72ull,0x21ull,0x2Eull,0x80ull,0xD2ull,0xDBull,0x89ull,0x37ull,0x18ull,0x69ull,0xBBull,0xF2ull,0xA0ull,0x4Eull,0x01ull,0x51ull,0xA3ull,0xF5ull,0xB8ull,0x66ull,0x15ull,0x3Aull,0x8Cull,0xDEull,0xCFull,0x7Dull,0x2Cull,0x23ull,0x74ull,0xC6ull,0xE7ull,0x95ull,0x43ull,0x0Cull,0x5Dull,0xAFull,0xFEull,0xACull,0x5Aull,0x09ull,0x46ull,0x98ull,0xEAull,0xC3ull,0x71ull,0x20ull,0x2Full,0x81ull,0xD3ull,0xDAull,0x88ull,0x36ull,0x19ull,0x6Aull,0xBCull,0xF1ull,0x9Full,0x4Dull,0x02ull,0x53ull,0xA5ull,0xF7ull,0xB6ull,0x64ull,0x13ull,0x3Cull,0x8Eull,0xE0ull,0xCDull,0x7Bull,0x2Aull,0x25ull,0x76ull,0xC8ull,0xE5ull,0x93ull,0x41ull,0x0Eull,0x5Full,0xB1ull,0xFCull,0xAAull,0x58ull,0x07ull,0x48ull,0x9Aull,0xECull,0xC1ull,0x6Full,0x1Eull,0x31ull,0x83ull,0xD5ull,0xD8ull,0x86ull,0x34ull,0x1Bull,0x6Cull,0xBEull,0xEFull,0x9Dull,0x4Bull,0x04ull,0x55ull,0xA7ull,0xF9ull,0xB4ull,0x62ull,0x11ull,0x3Eull,0x90ull,0xE2ull,0xCBull,0x79ull,0x28ull,0x27ull,0x78ull,0xCAull,0xE3ull,0x91ull,0x3Full,0x10ull,0x61ull,0xB3ull,0xFAull,0xA8ull,0x56ull,0x05ull,0x4Aull,0x9Cull,0xEEull,0xBFull,0x6Dull,0x1Cull,0x33ull,0x85ull,0xD7ull,0xD6ull,0x84ull,0x32ull,0x1Dull,0x6Eull,0xC0ull,0xEDull,0x9Bull,0x49ull,0x06ull,0x57ull,0xA9ull,0xFBull,0xB2ull,0x60ull,0x0Full,0x40ull,0x92ull,0xE4ull,0xC9ull,0x77ull,0x26ull,0x29ull,0x7Aull,0xCCull,0xE1ull,0x8Full,0x3Dull,0x12ull,0x63ull,0xB5ull,0xF8ull,0xA6ull,0x54ull,0x03ull,0x4Cull,0x9Eull,0xF0ull,0xBDull,0x6Bull,0x1Aull,0x35ull,0x87ull,0xD9ull,0xD4ull,0x82ull,0x30ull,0x1Full,0x70ull,0xC2ull,0xEBull,0x99ull,0x47ull,0x08ull,0x59ull,0xABull,0xFDull,0xB0ull,0x5Eull,0x0Dull,0x42ull,0x94ull,0xE6ull,0xC7ull,0x75ull,0x24ull,0x2Bull,0x7Cull,0xCEull,0xDFull,0x8Dull,0x3Bull,0x14ull,0x65ull,0xB7ull,0xF6ull,0xA4ull,0x52ull},
                            {0x0400ull,0x4D00ull,0x9E00ull,0xF000ull,0xBD00ull,0x6C00ull,0x1B00ull,0x3600ull,0x8700ull,0xD900ull,0xD400ull,0x8300ull,0x3200ull,0x1F00ull,0x7000ull,0xC100ull,0xEC00ull,0x9A00ull,0x4900ull,0x0800ull,0x5900ull,0xAA00ull,0xFC00ull,0xB100ull,0x6000ull,0x0F00ull,0x4200ull,0x9300ull,0xE500ull,0xC800ull,0x7700ull,0x2600ull,0x2B00ull,0x7C00ull,0xCD00ull,0xE000ull,0x8E00ull,0x3D00ull,0x1400ull,0x6500ull,0xB600ull,0xF700ull,0xA500ull,0x5400ull,0x0200ull,0x4F00ull,0xA000ull,0xF200ull,0xBB00ull,0x6A00ull,0x1900ull,0x3800ull,0x8900ull,0xDB00ull,0xD200ull,0x8100ull,0x3000ull,0x2100ull,0x7200ull,0xC300ull,0xEA00ull,0x9800ull,0x4700ull,0x0A00ull,0x5B00ull,0xAC00ull,0xFE00ull,0xAF00ull,0x5E00ull,0x0D00ull,0x4400ull,0x9500ull,0xE700ull,0xC600ull,0x7500ull,0x2400ull,0x2D00ull,0x7E00ull,0xCF00ull,0xDE00ull,0x8C00ull,0x3B00ull,0x1600ull,0x6700ull,0xB800ull,0xF500ull,0xA300ull,0x5200ull,0x0000ull,0x5100ull,0xA200ull,0xF400ull,0xB900ull,0x6800ull,0x1700ull,0x3A00ull,0x8B00ull,0xDD00ull,0xD000ull,0x7F00ull,0x2E00ull,0x2300ull,0x7400ull,0xC500ull,0xE800ull,0x9600ull,0x4500ull,0x0C00ull,0x5D00ull,0xAE00ull,0xFF00ull,0xAD00ull,0x5C00ull,0x0B00ull,0x4600ull,0x9700ull,0xE900ull,0xC400ull,0x7300ull,0x2200ull,0x2F00ull,0x8000ull,0xD100ull,0xDC00ull,0x8A00ull,0x3900ull,0x1800ull,0x6900ull,0xBA00ull,0xF300ull,0xA100ull,0x5000ull,0x0100ull,0x5300ull,0xA400ull,0xF600ull,0xB700ull,0x6600ull,0x1500ull,0x3C00ull,0x8D00ull,0xDF00ull,0xCE00ull,0x7D00ull,0x2C00ull,0x2500ull,0x7600ull,0xC700ull,0xE600ull,0x9400ull,0x4300ull,0x0E00ull,0x5F00ull,0xB000ull,0xFD00ull,0xAB00ull,0x5A00ull,0x0900ull,0x4800ull,0x9900ull,0xEB00ull,0xC200ull,0x7100ull,0x2000ull,0x3100ull,0x8200ull,0xD300ull,0xDA00ull,0x8800ull,0x3700ull,0x1A00ull,0x6B00ull,0xBC00ull,0xF100ull,0x9F00ull,0x4E00ull,0x0300ull,0x5500ull,0xA600ull,0xF800ull,0xB500ull,0x6400ull,0x1300ull,0x3E00ull,0x8F00ull,0xE100ull,0xCC00ull,0x7B00ull,0x2A00ull,0x2700ull,0x7800ull,0xC900ull,0xE400ull,0x9200ull,0x4100ull,0x1000ull,0x6100ull,0xB200ull,0xFB00ull,0xA900ull,0x5800ull,0x0700ull,0x4A00ull,0x9B00ull,0xED00ull,0xC000ull,0x6F00ull,0x1E00ull,0x3300ull,0x8400ull,0xD500ull,0xD800ull,0x8600ull,0x3500ull,0x1C00ull,0x6D00ull,0xBE00ull,0xEF00ull,0x9D00ull,0x4C00ull,0x0500ull,0x5600ull,0xA700ull,0xF900ull,0xB400ull,0x6300ull,0x1200ull,0x3F00ull,0x9000ull,0xE200ull,0xCB00ull,0x7A00ull,0x2900ull,0x2800ull,0x7900ull,0xCA00ull,0xE300ull,0x9100ull,0x4000ull,0x1100ull,0x6200ull,0xB300ull,0xFA00ull,0xA800ull,0x5700ull,0x0600ull,0x4B00ull,0x9C00ull,0xEE00ull,0xBF00ull,0x6E00ull,0x1D00ull,0x3400ull,0x8500ull,0xD600ull,0xD700ull},
                            {0x860000ull,0x340000ull,0x1D0000ull,0x6F0000ull,0xC10000ull,0xEE0000ull,0x9D0000ull,0x4B0000ull,0x060000ull,0x580000ull,0xAA0000ull,0xFA0000ull,0xB50000ull,0x630000ull,0x110000ull,0x400000ull,0x920000ull,0xE30000ull,0xCC0000ull,0x7A0000ull,0x280000ull,0x290000ull,0x7B0000ull,0xCD0000ull,0xE20000ull,0x910000ull,0x3F0000ull,0x120000ull,0x640000ull,0xB60000ull,0xF90000ull,0xA90000ull,0x570000ull,0x050000ull,0x4C0000ull,0x9E0000ull,0xEF0000ull,0xC00000ull,0x6E0000ull,0x1C0000ull,0x350000ull,0x870000ull,0xD80000ull,0xD70000ull,0x850000ull,0x330000ull,0x1E0000ull,0x700000ull,0xC20000ull,0xED0000ull,0x9C0000ull,0x4A0000ull,0x070000ull,0x590000ull,0xAB0000ull,0xFB0000ull,0xB40000ull,0x620000ull,0x100000ull,0x410000ull,0x930000ull,0xE40000ull,0xCB0000ull,0x790000ull,0x270000ull,0x2A0000ull,0x7C0000ull,0xCE0000ull,0xE10000ull,0x900000ull,0x3E0000ull,0x130000ull,0x650000ull,0xB70000ull,0xF80000ull,0xA80000ull,0x560000ull,0x040000ull,0x4D0000ull,0x9F0000ull,0xF00000ull,0xBF0000ull,0x6D0000ull,0x1B0000ull,0x360000ull,0x880000ull,0xD90000ull,0xD60000ull,0x840000ull,0x320000ull,0x1F0000ull,0x710000ull,0xC30000ull,0xEC0000ull,0x9B0000ull,0x490000ull,0x080000ull,0x5A0000ull,0xAC0000ull,0xFC0000ull,0xB30000ull,0x610000ull,0x0F0000ull,0x420000ull,0x940000ull,0xE50000ull,0xCA0000ull,0x780000ull,0x260000ull,0x2B0000ull,0x7D0000ull,0xCF0000ull,0xE00000ull,0x8F0000ull,0x3D0000ull,0x140000ull,0x660000ull,0xB80000ull,0xF70000ull,0xA70000ull,0x550000ull,0x030000ull,0x4E0000ull,0xA00000ull,0xF10000ull,0xBE0000ull,0x6C0000ull,0x1A0000ull,0x370000ull,0x890000ull,0xDA0000ull,0xD50000ull,0x830000ull,0x310000ull,0x200000ull,0x720000ull,0xC40000ull,0xEB0000ull,0x9A0000ull,0x480000ull,0x090000ull,0x5B0000ull,0xAD0000ull,0xFD0000ull,0xB20000ull,0x600000ull,0x0E0000ull,0x430000ull,0x950000ull,0xE60000ull,0xC90000ull,0x770000ull,0x250000ull,0x2C0000ull,0x7E0000ull,0xD00000ull,0xDF0000ull,0x8E0000ull,0x3C0000ull,0x150000ull,0x670000ull,0xB90000ull,0xF60000ull,0xA50000ull,0x530000ull,0x010000ull,0x500000ull,0xA20000ull,0xF30000ull,0xBC0000ull,0x6A0000ull,0x180000ull,0x390000ull,0x8B0000ull,0xDC0000ull,0xD30000ull,0x810000ull,0x2F0000ull,0x220000ull,0x740000ull,0xC60000ull,0xE90000ull,0x980000ull,0x460000ull,0x0B0000ull,0x5D0000ull,0xAF0000ull,0xFF0000ull,0xB00000ull,0x5E0000ull,0x0C0000ull,0x450000ull,0x970000ull,0xE80000ull,0xC70000ull,0x750000ull,0x230000ull,0x2E0000ull,0x800000ull,0xD20000ull,0xDD0000ull,0x8C0000ull,0x3A0000ull,0x170000ull,0x690000ull,0xBB0000ull,0xF40000ull,0xA30000ull,0x510000ull,0x000000ull,0x520000ull,0xA40000ull,0xF50000ull,0xBA0000ull,0x680000ull,0x160000ull,0x3B0000ull,0x8D0000ull,0xDE0000ull,0xD10000ull,0x7F0000ull,0x2D0000ull,0x240000ull,0x760000ull,0xC80000ull,0xE70000ull,0x960000ull,0x440000ull,0x0D0000ull,0x5F0000ull,0xB10000ull,0xFE0000ull,0xAE0000ull,0x5C0000ull,0x0A0000ull,0x470000ull,0x990000ull,0xEA0000ull,0xC50000ull,0x730000ull,0x210000ull,0x300000ull,0x820000ull,0xD40000ull,0xDB0000ull,0x8A0000ull,0x380000ull,0x190000ull,0x6B0000ull,0xBD0000ull,0xF20000ull,0xA10000ull,0x4F0000ull,0x020000ull,0x540000ull,0xA60000ull},
                            {0xF5000000ull,0xB8000000ull,0x67000000ull,0x15000000ull,0x3C000000ull,0x8D000000ull,0xDE000000ull,0xCF000000ull,0x7E000000ull,0x2D000000ull,0x24000000ull,0x75000000ull,0xC6000000ull,0xE7000000ull,0x96000000ull,0x45000000ull,0x0C000000ull,0x5E000000ull,0xAF000000ull,0xFE000000ull,0xAC000000ull,0x5B000000ull,0x09000000ull,0x48000000ull,0x99000000ull,0xEA000000ull,0xC3000000ull,0x72000000ull,0x20000000ull,0x31000000ull,0x82000000ull,0xD3000000ull,0xDA000000ull,0x89000000ull,0x38000000ull,0x19000000ull,0x6B000000ull,0xBC000000ull,0xF1000000ull,0xA0000000ull,0x4F000000ull,0x02000000ull,0x54000000ull,0xA5000000ull,0xF7000000ull,0xB6000000ull,0x65000000ull,0x13000000ull,0x3E000000ull,0x8F000000ull,0xE0000000ull,0xCD000000ull,0x7C000000ull,0x2B000000ull,0x26000000ull,0x77000000ull,0xC8000000ull,0xE5000000ull,0x94000000ull,0x43000000ull,0x0E000000ull,0x60000000ull,0xB1000000ull,0xFC000000ull,0xAA000000ull,0x59000000ull,0x07000000ull,0x4A000000ull,0x9B000000ull,0xEC000000ull,0xC1000000ull,0x70000000ull,0x1E000000ull,0x33000000ull,0x84000000ull,0xD5000000ull,0xD8000000ull,0x87000000ull,0x36000000ull,0x1B000000ull,0x6D000000ull,0xBE000000ull,0xEF000000ull,0x9E000000ull,0x4D000000ull,0x04000000ull,0x56000000ull,0xA7000000ull,0xF9000000ull,0xB4000000ull,0x63000000ull,0x11000000ull,0x40000000ull,0x91000000ull,0xE2000000ull,0xCB000000ull,0x7A000000ull,0x29000000ull,0x28000000ull,0x79000000ull,0xCA000000ull,0xE3000000ull,0x92000000ull,0x41000000ull,0x10000000ull,0x62000000ull,0xB3000000ull,0xFA000000ull,0xA8000000ull,0x57000000ull,0x05000000ull,0x4C000000ull,0x9D000000ull,0xEE000000ull,0xBF000000ull,0x6E000000ull,0x1C000000ull,0x35000000ull,0x86000000ull,0xD7000000ull,0xD6000000ull,0x85000000ull,0x34000000ull,0x1D000000ull,0x6F000000ull,0xC0000000ull,0xED000000ull,0x9C000000ull,0x4B000000ull,0x06000000ull,0x58000000ull,0xA9000000ull,0xFB000000ull,0xB2000000ull,0x61000000ull,0x0F000000ull,0x42000000ull,0x93000000ull,0xE4000000ull,0xC9000000ull,0x78000000ull,0x27000000ull,0x2A000000ull,0x7B000000ull,0xCC000000ull,0xE1000000ull,0x90000000ull,0x3F000000ull,0x12000000ull,0x64000000ull,0xB5000000ull,0xF8000000ull,0xA6000000ull,0x55000000ull,0x03000000ull,0x4E000000ull,0x9F000000ull,0xF0000000ull,0xBD000000ull,0x6C000000ull,0x1A000000ull,0x37000000ull,0x88000000ull,0xD9000000ull,0xD4000000ull,0x83000000ull,0x32000000ull,0x1F000000ull,0x71000000ull,0xC2000000ull,0xEB000000ull,0x9A000000ull,0x49000000ull,0x08000000ull,0x5A000000ull,0xAB000000ull,0xFD000000ull,0xB0000000ull,0x5F000000ull,0x0D000000ull,0x44000000ull,0x95000000ull,0xE6000000ull,0xC7000000ull,0x76000000ull,0x25000000ull,0x2C000000ull,0x7D000000ull,0xCE000000ull,0xDF000000ull,0x8E000000ull,0x3D000000ull,0x14000000ull,0x66000000ull,0xB7000000ull,0xF6000000ull,0xA4000000ull,0x53000000ull,0x01000000ull,0x50000000ull,0xA1000000ull,0xF2000000ull,0xBB000000ull,0x6A000000ull,0x18000000ull,0x39000000ull,0x8A000000ull,0xDB000000ull,0xD2000000ull,0x81000000ull,0x30000000ull,0x21000000ull,0x73000000ull,0xC4000000ull,0xE9000000ull,0x98000000ull,0x47000000ull,0x0A000000ull,0x5C000000ull,0xAD000000ull,0xFF000000ull,0xAE000000ull,0x5D000000ull,0x0B000000ull,0x46000000ull,0x97000000ull,0xE8000000ull,0xC5000000ull,0x74000000ull,0x23000000ull,0x2E000000ull,0x7F000000ull,0xD0000000ull,0xDD000000ull,0x8C000000ull,0x3B000000ull,0x16000000ull,0x68000000ull,0xB9000000ull,0xF4000000ull,0xA3000000ull,0x52000000ull,0x00000000ull,0x51000000ull,0xA2000000ull,0xF3000000ull,0xBA000000ull,0x69000000ull,0x17000000ull,0x3A000000ull,0x8B000000ull,0xDC000000ull,0xD1000000ull,0x80000000ull,0x2F000000ull,0x22000000ull},
                            {0x7200000000ull,0xC400000000ull,0xE900000000ull,0x9700000000ull,0x4500000000ull,0x0A00000000ull,0x5A00000000ull,0xAC00000000ull,0xFE00000000ull,0xAF00000000ull,0x5D00000000ull,0x0D00000000ull,0x4200000000ull,0x9400000000ull,0xE600000000ull,0xC700000000ull,0x7500000000ull,0x2300000000ull,0x2C00000000ull,0x7E00000000ull,0xD000000000ull,0xDD00000000ull,0x8B00000000ull,0x3900000000ull,0x1600000000ull,0x6700000000ull,0xB900000000ull,0xF400000000ull,0xA200000000ull,0x5000000000ull,0x0000000000ull,0x4F00000000ull,0xA100000000ull,0xF300000000ull,0xBA00000000ull,0x6800000000ull,0x1700000000ull,0x3800000000ull,0x8A00000000ull,0xDC00000000ull,0xD100000000ull,0x7F00000000ull,0x2D00000000ull,0x2200000000ull,0x7400000000ull,0xC600000000ull,0xE700000000ull,0x9500000000ull,0x4300000000ull,0x0C00000000ull,0x5C00000000ull,0xAE00000000ull,0xFF00000000ull,0xAD00000000ull,0x5B00000000ull,0x0B00000000ull,0x4400000000ull,0x9600000000ull,0xE800000000ull,0xC500000000ull,0x7300000000ull,0x2100000000ull,0x2E00000000ull,0x8000000000ull,0xD200000000ull,0xDB00000000ull,0x8900000000ull,0x3700000000ull,0x1800000000ull,0x6900000000ull,0xBB00000000ull,0xF200000000ull,0xA000000000ull,0x4E00000000ull,0x0100000000ull,0x5100000000ull,0xA300000000ull,0xF500000000ull,0xB800000000ull,0x6600000000ull,0x1500000000ull,0x3A00000000ull,0x8C00000000ull,0xDE00000000ull,0xCF00000000ull,0x7D00000000ull,0x2B00000000ull,0x2400000000ull,0x7600000000ull,0xC800000000ull,0xE500000000ull,0x9300000000ull,0x4100000000ull,0x0E00000000ull,0x5E00000000ull,0xB000000000ull,0xFD00000000ull,0xAB00000000ull,0x5900000000ull,0x0900000000ull,0x4600000000ull,0x9800000000ull,0xEA00000000ull,0xC300000000ull,0x7100000000ull,0x2000000000ull,0x2F00000000ull,0x8100000000ull,0xD300000000ull,0xDA00000000ull,0x8800000000ull,0x3600000000ull,0x1900000000ull,0x6A00000000ull,0xBC00000000ull,0xF100000000ull,0x9F00000000ull,0x4D00000000ull,0x0200000000ull,0x5200000000ull,0xA400000000ull,0xF600000000ull,0xB700000000ull,0x6500000000ull,0x1400000000ull,0x3B00000000ull,0x8D00000000ull,0xDF00000000ull,0xCE00000000ull,0x7C00000000ull,0x2A00000000ull,0x2500000000ull,0x7700000000ull,0xC900000000ull,0xE400000000ull,0x9200000000ull,0x4000000000ull,0x0F00000000ull,0x5F00000000ull,0xB100000000ull,0xFC00000000ull,0xAA00000000ull,0x5800000000ull,0x0800000000ull,0x4700000000ull,0x9900000000ull,0xEB00000000ull,0xC200000000ull,0x7000000000ull,0x1F00000000ull,0x3000000000ull,0x8200000000ull,0xD400000000ull,0xD900000000ull,0x8700000000ull,0x3500000000ull,0x1A00000000ull,0x6B00000000ull,0xBD00000000ull,0xF000000000ull,0x9E00000000ull,0x4C00000000ull,0x0300000000ull,0x5300000000ull,0xA500000000ull,0xF700000000ull,0xB600000000ull,0x6400000000ull,0x1300000000ull,0x3C00000000ull,0x8E00000000ull,0xE000000000ull,0xCD00000000ull,0x7B00000000ull,0x2900000000ull,0x2600000000ull,0x7800000000ull,0xCA00000000ull,0xE300000000ull,0x9100000000ull,0x3F00000000ull,0x1000000000ull,0x6100000000ull,0xB300000000ull,0xFA00000000ull,0xA800000000ull,0x5600000000ull,0x0600000000ull,0x4900000000ull,0x9B00000000ull,0xED00000000ull,0xC000000000ull,0x6E00000000ull,0x1D00000000ull,0x3200000000ull,0x8400000000ull,0xD600000000ull,0xD700000000ull,0x8500000000ull,0x3300000000ull,0x1C00000000ull,0x6D00000000ull,0xBF00000000ull,0xEE00000000ull,0x9C00000000ull,0x4A00000000ull,0x0500000000ull,0x5500000000ull,0xA700000000ull,0xF900000000ull,0xB400000000ull,0x6200000000ull,0x1100000000ull,0x3E00000000ull,0x9000000000ull,0xE200000000ull,0xCB00000000ull,0x7900000000ull,0x2700000000ull,0x2800000000ull,0x7A00000000ull,0xCC00000000ull,0xE100000000ull,0x8F00000000ull,0x3D00000000ull,0x1200000000ull,0x6300000000ull,0xB500000000ull,0xF800000000ull,0xA600000000ull,0x5400000000ull,0x0400000000ull,0x4B00000000ull,0x9D00000000ull,0xEF00000000ull,0xBE00000000ull,0x6C00000000ull,0x1B00000000ull,0x3400000000ull,0x8600000000ull,0xD800000000ull,0xD500000000ull,0x8300000000ull,0x3100000000ull,0x1E00000000ull,0x6F00000000ull,0xC100000000ull,0xEC00000000ull,0x9A00000000ull,0x4800000000ull,0x0700000000ull,0x5700000000ull,0xA900000000ull,0xFB00000000ull,0xB200000000ull,0x6000000000ull},
                            {0x100000000000ull,0x410000000000ull,0x920000000000ull,0xE30000000000ull,0xCA0000000000ull,0x790000000000ull,0x280000000000ull,0x290000000000ull,0x7A0000000000ull,0xCB0000000000ull,0xE20000000000ull,0x910000000000ull,0x400000000000ull,0x110000000000ull,0x620000000000ull,0xB30000000000ull,0xFA0000000000ull,0xA80000000000ull,0x570000000000ull,0x050000000000ull,0x4C0000000000ull,0x9D0000000000ull,0xEF0000000000ull,0xBE0000000000ull,0x6D0000000000ull,0x1C0000000000ull,0x350000000000ull,0x860000000000ull,0xD70000000000ull,0xD60000000000ull,0x850000000000ull,0x340000000000ull,0x1D0000000000ull,0x6E0000000000ull,0xBF0000000000ull,0xEE0000000000ull,0x9C0000000000ull,0x4B0000000000ull,0x060000000000ull,0x580000000000ull,0xA90000000000ull,0xFB0000000000ull,0xB20000000000ull,0x610000000000ull,0x0F0000000000ull,0x420000000000ull,0x930000000000ull,0xE50000000000ull,0xC80000000000ull,0x770000000000ull,0x260000000000ull,0x2B0000000000ull,0x7C0000000000ull,0xCD0000000000ull,0xE00000000000ull,0x8F0000000000ull,0x3E0000000000ull,0x130000000000ull,0x640000000000ull,0xB50000000000ull,0xF80000000000ull,0xA60000000000ull,0x550000000000ull,0x030000000000ull,0x4E0000000000ull,0x9F0000000000ull,0xF10000000000ull,0xBC0000000000ull,0x6B0000000000ull,0x1A0000000000ull,0x370000000000ull,0x880000000000ull,0xD90000000000ull,0xD40000000000ull,0x830000000000ull,0x320000000000ull,0x1F0000000000ull,0x700000000000ull,0xC10000000000ull,0xEC0000000000ull,0x9A0000000000ull,0x490000000000ull,0x080000000000ull,0x5A0000000000ull,0xAB0000000000ull,0xFD0000000000ull,0xB00000000000ull,0x5F0000000000ull,0x0D0000000000ull,0x440000000000ull,0x950000000000ull,0xE70000000000ull,0xC60000000000ull,0x750000000000ull,0x240000000000ull,0x2D0000000000ull,0x7E0000000000ull,0xCF0000000000ull,0xDE0000000000ull,0x8D0000000000ull,0x3C0000000000ull,0x150000000000ull,0x660000000000ull,0xB70000000000ull,0xF60000000000ull,0xA40000000000ull,0x530000000000ull,0x010000000000ull,0x500000000000ull,0xA10000000000ull,0xF30000000000ull,0xBA0000000000ull,0x690000000000ull,0x180000000000ull,0x390000000000ull,0x8A0000000000ull,0xDB0000000000ull,0xD20000000000ull,0x810000000000ull,0x300000000000ull,0x210000000000ull,0x720000000000ull,0xC30000000000ull,0xEA0000000000ull,0x980000000000ull,0x470000000000ull,0x0A0000000000ull,0x5C0000000000ull,0xAD0000000000ull,0xFF0000000000ull,0xAE0000000000ull,0x5D0000000000ull,0x0B0000000000ull,0x460000000000ull,0x970000000000ull,0xE90000000000ull,0xC40000000000ull,0x730000000000ull,0x220000000000ull,0x2F0000000000ull,0x800000000000ull,0xD10000000000ull,0xDC0000000000ull,0x8B0000000000ull,0x3A0000000000ull,0x170000000000ull,0x680000000000ull,0xB90000000000ull,0xF40000000000ull,0xA20000000000ull,0x510000000000ull,0x000000000000ull,0x520000000000ull,0xA30000000000ull,0xF50000000000ull,0xB80000000000ull,0x670000000000ull,0x160000000000ull,0x3B0000000000ull,0x8C0000000000ull,0xDD0000000000ull,0xD00000000000ull,0x7F0000000000ull,0x2E0000000000ull,0x230000000000ull,0x740000000000ull,0xC50000000000ull,0xE80000000000ull,0x960000000000ull,0x450000000000ull,0x0C0000000000ull,0x5E0000000000ull,0xAF0000000000ull,0xFE0000000000ull,0xAC0000000000ull,0x5B0000000000ull,0x090000000000ull,0x480000000000ull,0x990000000000ull,0xEB0000000000ull,0xC20000000000ull,0x710000000000ull,0x200000000000ull,0x310000000000ull,0x820000000000ull,0xD30000000000ull,0xDA0000000000ull,0x890000000000ull,0x380000000000ull,0x190000000000ull,0x6A0000000000ull,0xBB0000000000ull,0xF20000000000ull,0xA00000000000ull,0x4F0000000000ull,0x020000000000ull,0x540000000000ull,0xA50000000000ull,0xF70000000000ull,0xB60000000000ull,0x650000000000ull,0x140000000000ull,0x3D0000000000ull,0x8E0000000000ull,0xDF0000000000ull,0xCE0000000000ull,0x7D0000000000ull,0x2C0000000000ull,0x250000000000ull,0x760000000000ull,0xC70000000000ull,0xE60000000000ull,0x940000000000ull,0x430000000000ull,0x0E0000000000ull,0x600000000000ull,0xB10000000000ull,0xFC0000000000ull,0xAA0000000000ull,0x590000000000ull,0x070000000000ull,0x4A0000000000ull,0x9B0000000000ull,0xED0000000000ull,0xC00000000000ull,0x6F0000000000ull,0x1E0000000000ull,0x330000000000ull,0x840000000000ull,0xD50000000000ull,0xD80000000000ull,0x870000000000ull,0x360000000000ull,0x1B0000000000ull,0x6C0000000000ull,0xBD0000000000ull,0xF00000000000ull,0x9E0000000000ull,0x4D0000000000ull,0x040000000000ull,0x560000000000ull,0xA70000000000ull,0xF90000000000ull,0xB40000000000ull,0x630000000000ull,0x120000000000ull,0x3F0000000000ull,0x900000000000ull,0xE10000000000ull,0xCC0000000000ull,0x7B0000000000ull,0x2A0000000000ull,0x270000000000ull,0x780000000000ull,0xC90000000000ull,0xE40000000000ull},
                            {0x93000000000000ull,0x41000000000000ull,0x10000000000000ull,0x62000000000000ull,0xB4000000000000ull,0xFB000000000000ull,0xAB000000000000ull,0x59000000000000ull,0x07000000000000ull,0x4A000000000000ull,0x9C000000000000ull,0xEC000000000000ull,0xC3000000000000ull,0x71000000000000ull,0x1F000000000000ull,0x32000000000000ull,0x84000000000000ull,0xD6000000000000ull,0xD9000000000000ull,0x87000000000000ull,0x35000000000000ull,0x1C000000000000ull,0x6E000000000000ull,0xC0000000000000ull,0xEF000000000000ull,0x9F000000000000ull,0x4D000000000000ull,0x04000000000000ull,0x56000000000000ull,0xA8000000000000ull,0xF8000000000000ull,0xB7000000000000ull,0x65000000000000ull,0x13000000000000ull,0x3E000000000000ull,0x90000000000000ull,0xE2000000000000ull,0xCD000000000000ull,0x7B000000000000ull,0x29000000000000ull,0x28000000000000ull,0x7A000000000000ull,0xCC000000000000ull,0xE3000000000000ull,0x91000000000000ull,0x3F000000000000ull,0x12000000000000ull,0x64000000000000ull,0xB6000000000000ull,0xF9000000000000ull,0xA9000000000000ull,0x57000000000000ull,0x05000000000000ull,0x4C000000000000ull,0x9E000000000000ull,0xEE000000000000ull,0xC1000000000000ull,0x6F000000000000ull,0x1D000000000000ull,0x34000000000000ull,0x86000000000000ull,0xD8000000000000ull,0xD7000000000000ull,0x85000000000000ull,0x33000000000000ull,0x1E000000000000ull,0x70000000000000ull,0xC2000000000000ull,0xED000000000000ull,0x9D000000000000ull,0x4B000000000000ull,0x06000000000000ull,0x58000000000000ull,0xAA000000000000ull,0xFA000000000000ull,0xB5000000000000ull,0x63000000000000ull,0x11000000000000ull,0x40000000000000ull,0x92000000000000ull,0xE4000000000000ull,0xCB000000000000ull,0x79000000000000ull,0x27000000000000ull,0x2A000000000000ull,0x7C000000000000ull,0xCE000000000000ull,0xE1000000000000ull,0x8F000000000000ull,0x3D000000000000ull,0x14000000000000ull,0x66000000000000ull,0xB8000000000000ull,0xF7000000000000ull,0xA7000000000000ull,0x55000000000000ull,0x03000000000000ull,0x4E000000000000ull,0xA0000000000000ull,0xF0000000000000ull,0xBF000000000000ull,0x6D000000000000ull,0x1B000000000000ull,0x36000000000000ull,0x88000000000000ull,0xDA000000000000ull,0xD5000000000000ull,0x83000000000000ull,0x31000000000000ull,0x20000000000000ull,0x72000000000000ull,0xC4000000000000ull,0xEB000000000000ull,0x9B000000000000ull,0x49000000000000ull,0x08000000000000ull,0x5A000000000000ull,0xAC000000000000ull,0xFC000000000000ull,0xB3000000000000ull,0x61000000000000ull,0x0F000000000000ull,0x42000000000000ull,0x94000000000000ull,0xE5000000000000ull,0xCA000000000000ull,0x78000000000000ull,0x26000000000000ull,0x2B000000000000ull,0x7D000000000000ull,0xCF000000000000ull,0xE0000000000000ull,0x8E000000000000ull,0x3C000000000000ull,0x15000000000000ull,0x67000000000000ull,0xB9000000000000ull,0xF6000000000000ull,0xA6000000000000ull,0x54000000000000ull,0x02000000000000ull,0x4F000000000000ull,0xA1000000000000ull,0xF1000000000000ull,0xBE000000000000ull,0x6C000000000000ull,0x1A000000000000ull,0x37000000000000ull,0x89000000000000ull,0xDB000000000000ull,0xD4000000000000ull,0x82000000000000ull,0x30000000000000ull,0x21000000000000ull,0x73000000000000ull,0xC5000000000000ull,0xEA000000000000ull,0x9A000000000000ull,0x48000000000000ull,0x09000000000000ull,0x5B000000000000ull,0xAD000000000000ull,0xFD000000000000ull,0xB2000000000000ull,0x60000000000000ull,0x0E000000000000ull,0x43000000000000ull,0x95000000000000ull,0xE6000000000000ull,0xC9000000000000ull,0x77000000000000ull,0x25000000000000ull,0x2C000000000000ull,0x7E000000000000ull,0xD0000000000000ull,0xDF000000000000ull,0x8D000000000000ull,0x3B000000000000ull,0x16000000000000ull,0x68000000000000ull,0xBA000000000000ull,0xF5000000000000ull,0xA5000000000000ull,0x53000000000000ull,0x01000000000000ull,0x50000000000000ull,0xA2000000000000ull,0xF2000000000000ull,0xBD000000000000ull,0x6B000000000000ull,0x19000000000000ull,0x38000000000000ull,0x8A000000000000ull,0xDC000000000000ull,0xD3000000000000ull,0x81000000000000ull,0x2F000000000000ull,0x22000000000000ull,0x74000000000000ull,0xC6000000000000ull,0xE9000000000000ull,0x99000000000000ull,0x47000000000000ull,0x0A000000000000ull,0x5C000000000000ull,0xAE000000000000ull,0xFE000000000000ull,0xB1000000000000ull,0x5F000000000000ull,0x0D000000000000ull,0x44000000000000ull,0x96000000000000ull,0xE7000000000000ull,0xC8000000000000ull,0x76000000000000ull,0x24000000000000ull,0x2D000000000000ull,0x7F000000000000ull,0xD1000000000000ull,0xDE000000000000ull,0x8C000000000000ull,0x3A000000000000ull,0x17000000000000ull,0x69000000000000ull,0xBB000000000000ull,0xF4000000000000ull,0xA4000000000000ull,0x52000000000000ull,0x00000000000000ull,0x51000000000000ull,0xA3000000000000ull,0xF3000000000000ull,0xBC000000000000ull,0x6A000000000000ull,0x18000000000000ull,0x39000000000000ull,0x8B000000000000ull,0xDD000000000000ull,0xD2000000000000ull,0x80000000000000ull,0x2E000000000000ull,0x23000000000000ull,0x75000000000000ull,0xC7000000000000ull,0xE8000000000000ull,0x97000000000000ull,0x45000000000000ull,0x0C000000000000ull,0x5E000000000000ull,0xB0000000000000ull,0xFF000000000000ull,0xAF000000000000ull,0x5D000000000000ull,0x0B000000000000ull,0x46000000000000ull,0x98000000000000ull},
                            {0xE900000000000000ull,0xC400000000000000ull,0x7300000000000000ull,0x2200000000000000ull,0x2F00000000000000ull,0x8000000000000000ull,0xD100000000000000ull,0xDC00000000000000ull,0x8B00000000000000ull,0x3A00000000000000ull,0x1700000000000000ull,0x6800000000000000ull,0xB900000000000000ull,0xF400000000000000ull,0xA200000000000000ull,0x5100000000000000ull,0x0000000000000000ull,0x5200000000000000ull,0xA300000000000000ull,0xF500000000000000ull,0xB800000000000000ull,0x6700000000000000ull,0x1600000000000000ull,0x3B00000000000000ull,0x8C00000000000000ull,0xDD00000000000000ull,0xD000000000000000ull,0x7F00000000000000ull,0x2E00000000000000ull,0x2300000000000000ull,0x7400000000000000ull,0xC500000000000000ull,0xE800000000000000ull,0x9700000000000000ull,0x4600000000000000ull,0x0B00000000000000ull,0x5D00000000000000ull,0xAE00000000000000ull,0xFF00000000000000ull,0xAD00000000000000ull,0x5C00000000000000ull,0x0A00000000000000ull,0x4700000000000000ull,0x9800000000000000ull,0xEA00000000000000ull,0xC300000000000000ull,0x7200000000000000ull,0x2100000000000000ull,0x3000000000000000ull,0x8100000000000000ull,0xD200000000000000ull,0xDB00000000000000ull,0x8A00000000000000ull,0x3900000000000000ull,0x1800000000000000ull,0x6900000000000000ull,0xBA00000000000000ull,0xF300000000000000ull,0xA100000000000000ull,0x5000000000000000ull,0x0100000000000000ull,0x5300000000000000ull,0xA400000000000000ull,0xF600000000000000ull,0xB700000000000000ull,0x6600000000000000ull,0x1400000000000000ull,0x3D00000000000000ull,0x8E00000000000000ull,0xDF00000000000000ull,0xCE00000000000000ull,0x7D00000000000000ull,0x2C00000000000000ull,0x2500000000000000ull,0x7600000000000000ull,0xC700000000000000ull,0xE600000000000000ull,0x9500000000000000ull,0x4400000000000000ull,0x0D00000000000000ull,0x5F00000000000000ull,0xB000000000000000ull,0xFD00000000000000ull,0xAB00000000000000ull,0x5A00000000000000ull,0x0800000000000000ull,0x4900000000000000ull,0x9A00000000000000ull,0xEC00000000000000ull,0xC100000000000000ull,0x7000000000000000ull,0x1F00000000000000ull,0x3200000000000000ull,0x8300000000000000ull,0xD400000000000000ull,0xD900000000000000ull,0x8800000000000000ull,0x3700000000000000ull,0x1A00000000000000ull,0x6B00000000000000ull,0xBC00000000000000ull,0xF100000000000000ull,0x9F00000000000000ull,0x4E00000000000000ull,0x0300000000000000ull,0x5500000000000000ull,0xA600000000000000ull,0xF800000000000000ull,0xB500000000000000ull,0x6400000000000000ull,0x1200000000000000ull,0x3F00000000000000ull,0x9000000000000000ull,0xE100000000000000ull,0xCC00000000000000ull,0x7B00000000000000ull,0x2A00000000000000ull,0x2700000000000000ull,0x7800000000000000ull,0xC900000000000000ull,0xE400000000000000ull,0x9300000000000000ull,0x4200000000000000ull,0x0F00000000000000ull,0x6100000000000000ull,0xB200000000000000ull,0xFB00000000000000ull,0xA900000000000000ull,0x5800000000000000ull,0x0600000000000000ull,0x4B00000000000000ull,0x9C00000000000000ull,0xEE00000000000000ull,0xBF00000000000000ull,0x6E00000000000000ull,0x1D00000000000000ull,0x3400000000000000ull,0x8500000000000000ull,0xD600000000000000ull,0xD700000000000000ull,0x8600000000000000ull,0x3500000000000000ull,0x1C00000000000000ull,0x6D00000000000000ull,0xBE00000000000000ull,0xEF00000000000000ull,0x9D00000000000000ull,0x4C00000000000000ull,0x0500000000000000ull,0x5700000000000000ull,0xA800000000000000ull,0xFA00000000000000ull,0xB300000000000000ull,0x6200000000000000ull,0x1000000000000000ull,0x4100000000000000ull,0x9200000000000000ull,0xE300000000000000ull,0xCA00000000000000ull,0x7900000000000000ull,0x2800000000000000ull,0x2900000000000000ull,0x7A00000000000000ull,0xCB00000000000000ull,0xE200000000000000ull,0x9100000000000000ull,0x4000000000000000ull,0x1100000000000000ull,0x6300000000000000ull,0xB400000000000000ull,0xF900000000000000ull,0xA700000000000000ull,0x5600000000000000ull,0x0400000000000000ull,0x4D00000000000000ull,0x9E00000000000000ull,0xF000000000000000ull,0xBD00000000000000ull,0x6C00000000000000ull,0x1B00000000000000ull,0x3600000000000000ull,0x8700000000000000ull,0xD800000000000000ull,0xD500000000000000ull,0x8400000000000000ull,0x3300000000000000ull,0x1E00000000000000ull,0x6F00000000000000ull,0xC000000000000000ull,0xED00000000000000ull,0x9B00000000000000ull,0x4A00000000000000ull,0x0700000000000000ull,0x5900000000000000ull,0xAA00000000000000ull,0xFC00000000000000ull,0xB100000000000000ull,0x6000000000000000ull,0x0E00000000000000ull,0x4300000000000000ull,0x9400000000000000ull,0xE500000000000000ull,0xC800000000000000ull,0x7700000000000000ull,0x2600000000000000ull,0x2B00000000000000ull,0x7C00000000000000ull,0xCD00000000000000ull,0xE000000000000000ull,0x8F00000000000000ull,0x3E00000000000000ull,0x1300000000000000ull,0x6500000000000000ull,0xB600000000000000ull,0xF700000000000000ull,0xA500000000000000ull,0x5400000000000000ull,0x0200000000000000ull,0x4F00000000000000ull,0xA000000000000000ull,0xF200000000000000ull,0xBB00000000000000ull,0x6A00000000000000ull,0x1900000000000000ull,0x3800000000000000ull,0x8900000000000000ull,0xDA00000000000000ull,0xD300000000000000ull,0x8200000000000000ull,0x3100000000000000ull,0x2000000000000000ull,0x7100000000000000ull,0xC200000000000000ull,0xEB00000000000000ull,0x9900000000000000ull,0x4800000000000000ull,0x0900000000000000ull,0x5B00000000000000ull,0xAC00000000000000ull,0xFE00000000000000ull,0xAF00000000000000ull,0x5E00000000000000ull,0x0C00000000000000ull,0x4500000000000000ull,0x9600000000000000ull,0xE700000000000000ull,0xC600000000000000ull,0x7500000000000000ull,0x2400000000000000ull,0x2D00000000000000ull,0x7E00000000000000ull,0xCF00000000000000ull,0xDE00000000000000ull,0x8D00000000000000ull,0x3C00000000000000ull,0x1500000000000000ull}};


uint64_t sbox(uint64_t input) {
    uint64_t ret = 0;

    for (uint64_t i = 0; i < 8; ++i) {
        ret |= S[i][input & 0xffull];
        input >>= 8;
    }

    return ret;
}

void cache_prefetch() {
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 256; j += 8) {
            __builtin_prefetch(&S[i][j], 0, 3);
        }
    }
}
