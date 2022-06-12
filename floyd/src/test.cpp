#include "hash.h"
#include <cstdio>

extern const int hash_byte{ 6 };

Hash h1, h2, hh1, hh2;

int main()
{
    h1.hash[0] = 0x0A;
    h1.hash[1] = 0x34;
    h1.hash[2] = 0x15;
    h1.hash[3] = 0x2B;
    h1.hash[4] = 0x29;
    h1.hash[5] = 0xAA;
    h1.hash[6] = 0x5E;

    h2.hash[0] = 0x3B;
    h2.hash[1] = 0x6D;
    h2.hash[2] = 0x42;
    h2.hash[3] = 0x68;
    h2.hash[4] = 0xBC;
    h2.hash[5] = 0x8D;
    h2.hash[6] = 0xCE;

    hh1 = hash( h1.hash, hash_byte );
    hh2 = hash( h2.hash, hash_byte );

    for (int i = 0; i < hash_byte; i++)
    {
        printf( "%02X ", hh1.hash[i] );
    }
    printf( "\n" );
    for (int i = 0; i < hash_byte; i++)
    {
        printf( "%02X ", hh2.hash[i] );
    }
    printf( "\n" );
}