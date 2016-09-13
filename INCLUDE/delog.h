// debug.h

#ifndef DELOG_H
#define DELOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include "build.h"

#if USE_SDL2
#define BUILD_NAME "SDL2/OpenGL Thing"
#elif USE_GLFW3
#define BUILD_NAME "GLFW3/OpenGL Thing"
#endif
#define BUILD_NAME "test"

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define BUILD_DATE __DATE__
#define BUILD_TIME __TIME__

typedef struct Delog_struct {char filename[32];
	time_t starttime;} Delog_type;

Delog_type Delog;
	
signed short CreateNewLog();
signed short printl(unsigned short priority, char *fmt,...);
signed short QuitDelog();

#ifdef __cplusplus
}
#endif

#endif //DELOG_H