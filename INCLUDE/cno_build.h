#ifndef CNO_BUILD_H
#define CNO_BUILD_H

#define CNO_BUILD_NAME "spriterweb"
#define CNO_BUILD_DATE __DATE__
#define CNO_BUILD_TIME __TIME__
#define CNO_BUILD_VERSION_MAJOR 1
#define CNO_BUILD_VERSION_MINOR 0

#ifdef __clang__
#define CNO_COMPILER "clang"
#define CNO_COMPILER_VERSION __clang_version__
#elif __GNUC__
#define CNO_COMPILER "gcc"
#endif

#define CNO_BYTE_SIZE __CHAR_BIT__
#define CNO_ENDIAN __BYTE_ORDER__

#ifdef __x86_64__ || __amd64__
#define CNO_ARCHITECTURE "AMD64"
#define CNO_CPU_BIT_TYPE 64
#elif __i386__
#define CNO_ARCHITECTURE "i386"
#define CNO_CPU_BIT_TYPE 32
#elif __powerpc__
#define CNO_ARCHITECTURE "PowerPC"
#elif __mips__
#define CNO_ARCHITECTURE "Mips"
#elif __m68k__
#define CNO_ARCHITECTURE "Motorola68k"
#elif __arm__
#define CNO_ARCHITECTURE "ARM"
#define CNO_CPU_BIT_TYPE 32
#endif

#define CNO_BUILD_FOR_BINARY 1
#define CNO_BUILD_FOR_LIBRARY 0

typedef unsigned short cno_u8_type;
typedef signed char cno_s8_type;
typedef unsigned short cno_u16_type;
typedef signed short cno_s16_type;
typedef unsigned long cno_u32_type;
typedef signed long cno_s32_type;
typedef unsigned long long cno_u64_type;
typedef signed long long cno_s64_type;
typedef float cno_f32_type;
typedef double cno_f64_type;

#ifdef __unix__
#define CNO_IS_UNIX __unix__
#endif //__unix__
#ifdef __POSIX_VERSION
#define CNO_IS_POSIX __POSIX_VERSION
#endif //__POSIX_VERSION
#define CNO_C_VERSION __STDC_VERSION__
#ifdef BSD
#define CNO_IS_BSD BSD
#endif //BSD
#ifdef __GNU__
#define CNO_IS_GNU __GNU__
#endif //__GNU__

//OS
#ifdef __APPLE__
#define CNO_OS_NAME "MacOSX"
#define CNO_OS 2
#elif __gnu_linux__
#define CNO_OS_NAME "Linux"
#define CNO_OS 3
#elif __CYGWIN__ || __WIN32
#define CNO_OS_NAME "Windows"
#define CNO_OS 1
#else
#define CNO_OS_NAME "Unknown"
#define CNO_OS 4
#endif

//Static Dependencies
#define CNO_HAVE_STDIO 1
#define CNO_HAVE_STDLIB 1
#define CNO_HAVE_STRING 1
#define CNO_HAVE_TIME 1
#define CNO_HAVE_UNISTD 1
#define CNO_HAVE_GETOPT 1
#define CNO_HAVE_INIH 1
#define CNO_HAVE_WHEREAMI 1
#define CNO_HAVE_STRETCHYBUFFER 1
#define CNO_HAVE_PARSON 1
#define CNO_HAVE_SDL2 1

#if CNO_HAVE_STDIO
#define CNO_ALLOW_PRINTF 1
#endif //CNO_HAVE_STDIO

#if CNO_HAVE_STDLIB
#define CNO_ALLOW_EXIT 1
#endif //CNO_HAVE_STDLIB

#if CNO_HAVE_SDL2
#include <SDL2/SDL_version.h>
#endif //CNO_HAVE_SDL2

#define CNO_ALLOW_WINDOW 1
#define CNO_ALLOW_AUDIO 1
#define CNO_ALLOW_THREADS 1
#define CNO_ALLOW_OBJECTS 1

#define DESKTOP_BUILD 1
#define MOBILE_BUILD 0

#if DESKTOP_BUILD && !MOBILE_BUILD
#define CNO_DEVICE_TYPE 1
#elif MOBILE_BUILD && !DESKTOP_BUILD
#define CNO_DEVICE_TYPE 2
#endif //DESKTOP_BUILD && MOBILE_BUILD

#endif //CNO_BUILD_H
