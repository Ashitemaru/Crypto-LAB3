#include "hash.h"
#include <cstdint>
#include <cstdio>
#include <cstdarg>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <functional>
#include <cmath>

#define M 200000000

extern const int hash_byte{ 6 };

template<>
struct std::hash<Hash>
{
    union hash_to_u64
    {
        uint64_t u64;
        uint8_t hash[8];
    };

    std::size_t operator()( Hash const &h ) const noexcept
    {
        hash_to_u64 conv;
        for (int i = 0; i < 8; i++)
        {
            conv.hash[i] = h.hash[i];
        }
        return conv.u64;
    }
};

bool operator==( const Hash &lhs, const Hash &rhs )
{
    for (int i = 0; i < hash_byte; i++)
    {
        if (lhs.hash[i] != rhs.hash[i])
        {
            return false;
        }
    }
    return true;
}

class HashTable
{
public:
    void insert( const Hash &k, uint64_t v )
    {
        _map[k] = v;
    }

    uint64_t search( const Hash &k )
    {
        auto res = _map.find( k );
        if (res == _map.end())
        {
            return 0;
        } else
        {
            return res->second;
        }
    }

    void prune( uint64_t b )
    {
        b *= 2;
        for (auto i = _map.begin(), last = _map.end(); i != last;)
        {
            if (i->second % b != 0)
            {
                i = _map.erase( i );
            } else
            {
                ++i;
            }
        }
    }

    bool is_full() const
    {
        return _map.size() > M;
    }

private:
    std::unordered_map<Hash, uint64_t> _map{ M };
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
    uint64_t i = 0, b = 1, j = 0;
    uint64_t g = (uint64_t) sqrt(( M / 16 ) * ( 1 + 14.0 / M ));
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