#include "harmony_timer.h"

#if defined(HARMONY_BUILD_LINUX)
    #define HAVE_POSIX_TIMER
    #include <time.h>
    #ifdef CLOCK_MONOTONIC
        #define CLOCKID CLOCK_MONOTONIC
    #else
        #define CLOCKID CLOCK_REALTIME
    #endif
#elif defined(HARMONY_BUILD_APPLE)
    #define HAVE_MACH_TIMER
    #include <mach/mach_time.h>
#elif defined(HARMONY_BUILD_WINDOWS)
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#endif

/**
 * Returns the time in nanoseconds.
 * Used for differences in time (like timestep/delta).
 */
uint64_t harmony_getNanoseconds()
{
    static uint64_t is_init = 0;

    #if defined(HARMONY_BUILD_APPLE)

    static mach_timebase_info_data_t info;
    if (!is_init)
    {
        mach_timebase_info(&info);
        is_init = 1;
    }
    uint64_t now;
    now = mach_absolute_time() * info.numer / info.denom;
    return now;
    
    #elif defined(HARMONY_BUILD_LINUX)

    static struct timespec linux_rate;
    if (!is_init)
    {
        clock_getres(CLOCKID, &linux_rate);
        is_init = 1;
    }
    uint64_t now;
    struct timespec spec;
    clock_gettime(CLOCKID, &spec);
    now = spec.tv_sec * 1e9 + spec.tv_nsec;
    return now;

    #elif defined(HARMONY_BUILD_WINDOWS)

    static LARGE_INTEGER win_frequency;
    if (!is_init)
    {
        QueryPerformanceFrequency(&win_frequency);
        is_init = 1;
    }
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    return (uint64_t) (1e9 * now.QuadPart / win_frequency.QuadPart);

    #endif
}
