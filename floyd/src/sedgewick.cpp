#include "hash.h"
#include <cstdint>
#include <cstdio>
#include <cstdarg>
#include <chrono>
#include <thread>

#define M 400000000

extern const int hash_byte{ 7 };

class HashTable
{
public:
    HashTable()
    {
        m = 0;
        keys = new Hash[M];
        values = new uint64_t[M];
        vis = new bool[M];
        memset( values, 0, M * sizeof( uint64_t ));
        memset( vis, false, M * sizeof( bool ));
    }

    ~HashTable()
    {
        delete[] keys;
        delete[] values;
        delete[] vis;
    }

    void insert( Hash k, uint64_t v )
    {
        size_t i = hash_to_idx( k );
        while (true)
        {
            if (vis[i])
            {
                ++i;
                if (i == M)
                {
                    i = 0;
                }
            } else
            {
                memcpy( &keys[i], &k, sizeof( Hash ));
                values[i] = v;
                vis[i] = true;
                ++m;
                break;
            }
        }
    }

    uint64_t search( Hash k )
    {
        size_t i = hash_to_idx( k );
        while (true)
        {
            if (vis[i])
            {
                if (memcmp( &keys[i], &k, sizeof( Hash )) == 0)
                {
                    return values[i];
                } else
                {
                    ++i;
                    if (i == M)
                    {
                        i = 0;
                    }
                }
            } else
            {
                return 0;
            }
        }
    }

    void prune( uint64_t b )
    {
        b *= 2;
        for (size_t i = 0; i < M; i++)
        {
            if (values[i] % b)
            {
                vis[i] = false;
                --m;
            }
        }
    }

    bool is_full() const
    {
        return m > M * 0.7;
    }

private:
    size_t hash_to_idx( const Hash &h )
    {
        return static_cast<size_t>((( h.hash[3] << 24 ) | ( h.hash[2] << 16 ) | ( h.hash[1] << 8 ) | ( h.hash[0] ))) %
               M;
    }

    size_t m;
    Hash *keys;
    uint64_t *values;
    bool *vis;
};

class Console
{
public:
    void log( const char *__restrict fmt, ... )
    {
        printf( "\33[2K\r" );
        va_list args;
        va_start( args, fmt );
        vprintf( fmt, args );
        va_end( args );
        fflush( stdout );
    }

    void new_line()
    {
        printf( "\t\n" );
    }
} console;

class StopWatch
{
public:
    using clk_t = std::chrono::high_resolution_clock;

    StopWatch() : start( clk_t::now()) {}

    long long time_ms()
    {
        namespace ch = std::chrono;
        return ch::duration_cast<ch::milliseconds>( clk_t::now() - start ).count();
    }

    void reset()
    {
        start = clk_t::now();
    }

private:
    clk_t::time_point start;
};

class CircularBuffer
{
public:
    explicit CircularBuffer( uint64_t n ) : buf( new Hash[n] ), n( n ), i( 0 ), l( 0 ) {}

    ~CircularBuffer()
    {
        delete[] buf;
    }

    void push( const Hash &h )
    {
        memcpy( &buf[i], &h, sizeof( Hash ));
        i = ( i + 1 ) % n;
        l = std::min( n, l + 1 );
    }

    Hash operator[]( int j ) const
    {
        return buf[( i + j + n - l ) % n];
    }

private:
    Hash *buf;
    uint64_t n, i, l;
};

void dump_data( const uint8_t *data, size_t n )
{
    for (uint64_t i = 0; i < n; i++)
    {
        printf( "%02X ", data[i] );
    }
}

void dump_hash( const Hash &h )
{
    dump_data( h.hash, hash_byte );
}

int main()
{
    Hash initial{ .hash{ 1 }};
    Hash h = initial;
    uint64_t i = 0, b = 1, g = 4, j = 0;
    StopWatch report_timer, total_timer;

    auto table = new HashTable;
    while (true)
    {
        if (i % b == 0 && table->is_full())
        {
            table->prune( b );
            b *= 2;
        }
        if (i % b == 0)
        {
            table->insert( h, i );
        }
        h = hash( h.hash, hash_byte );
        ++i;
        if (report_timer.time_ms() > 1000)
        {
            console.log( "Finding cycle iteration: %lld", i );
            report_timer.reset();
        }
        if (i % ( g * b ) < b)
        {
            j = table->search( h );
            if (j)
            {
                break;
            }
        }
    }
    console.log( "Cycle found: i = %lld, j = %lld, elapsed_time = %lf s", i, j, 0.001 * total_timer.time_ms());
    console.new_line();
    delete table;

    uint64_t c = 1;
    bool find_c = false;
    Hash h_c = hash( h.hash, hash_byte );
    console.log( "Prepare to recover" );
    console.new_line();
    for (; c <= ( g + 1 ) * b; ++c)
    {
        if (memcmp( h_c.hash, h.hash, hash_byte ) == 0)
        {
            find_c = true;
            break;
        } else
        {
            h_c = hash( h_c.hash, hash_byte );
        }
    }
    if (!find_c)
    {
        c = i - j;
    }
    uint64_t ii = std::max( c, g * b * ( i / ( g * b ) - 1 ));
    uint64_t jj = ii - c;
    console.log( "Recover parameter: ii = %lld, jj = %lld, c = %lld\n", ii, jj, c );

    CircularBuffer cb( c );
    Hash h_l = initial;
    report_timer.reset();
    for (uint64_t i = 0; i < jj + c; i++)
    {
        cb.push( h_l );
        h_l = hash( h_l.hash, hash_byte );
        if (report_timer.time_ms() > 1000)
        {
            console.log( "Calculating f^(jj + c): i = %lld", i );
            report_timer.reset();
        }
    }
    console.new_line();

    report_timer.reset();
    while (true)
    {
        ++jj;
        Hash h1 = cb[1];
        Hash h2 = hash( h_l.hash, hash_byte );
        if (memcmp( h1.hash, h2.hash, hash_byte ) == 0)
        {
            printf( "\nFound collision:\n" );
            printf( "l: %lld\n", jj );
            printf( "x: " );
            dump_hash( cb[0] );
            printf( "\ny: " );
            dump_hash( h_l );
            printf( "\nh: " );
            dump_hash( h1 );
            printf( "\nelapsed time: %lf s", 0.001 * total_timer.time_ms());
            break;
        }
        cb.push( h_l );
        h_l = h2;
        if (report_timer.time_ms() > 1000)
        {
            console.log( "Recovering: l = %d", jj );
            report_timer.reset();
        }
    }

}