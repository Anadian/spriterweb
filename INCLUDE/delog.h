// debug.h

#ifndef DELOG_H
#define DELOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <time.h>

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