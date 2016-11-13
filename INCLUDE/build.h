// build.h: Defines what libraries to include along with other build information.

#ifndef BUILD_H
#define BUILD_H

#define USE_LUA 0
#define USE_SDL2 1
#define USE_GLFW3 0
#define USE_TIGR 0
#define ALLOW_PRINTF 1
#define BUILD_FOR_BINARY 1
#define BUILD_FOR_LIBRARY 0

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;
typedef float f32;
typedef double f64;

#define BUILD_NAME "spriterweb"
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define BUILD_DATE __DATE__
#define BUILD_TIME __TIME__

//OS
#ifdef __APPLE__
#define __OS__ MacOSX
#elif __gnu_linux__
#define __OS__ Linux
#elif __CYGWIN__
#define __OS__ Windows
#elif __WIN32
#define __OS__ Windows
#endif

#ifdef __unix__
#define __UNIX__ 1
#endif

#ifdef __x86_64__
#define __ARC__ x84_64
#define __BIT__ 64
#elif __i386__
#define __ARC__ i386
#define __BIT__ 32
#elif __powerpc__
#define __ARC__ PowerPC
#elif __mips__
#define __ARC__ Mips
#elif __m68k__
#define __ARC__ Motorola68k
#elif __arm__
#define __ARC__ arm
#define __BIT__ 32
#endif

#ifdef __clang__
#define __COMPILER__ clang
#elif __GNUC__
#define __COMPILER__ gcc
#endif

#if USE_SDL2
#define USE_SDL_THREADS 1
#define USE_SDL_FILEIO 1
#define USE_SDL_IMAGE 1
#define USE_SDL_TTF 1
#endif //USE_SDL2

#define DESKTOP_BUILD 1
#endif
