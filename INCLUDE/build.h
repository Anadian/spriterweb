// build.h: Defines what libraries to include along with other build information.

#ifndef BUILD_H
#define BUILD_H

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

#if USE_SDL2
#define USE_SDL_THREADS 1
#define USE_SDL_FILEIO 1
#define USE_SDL_IMAGE 1
#define USE_SDL_TTF 1
#endif //USE_SDL2

#endif
