// kairos.h

#ifndef KAIROS_H
#define KAIROS_H

#ifdef __cplusplus
extern "C" {
#endif


#include "build.h"

#if USE_SDL2

typedef struct Timer_struct {unsigned long PastTicks;
	unsigned long CurrentTicks;
	unsigned short Paused;} Timer_type;

unsigned long GetTicks(Timer_type *Timer);
unsigned long PauseTimer(Timer_type *Timer);
unsigned long ResumeTimer(Timer_type *Timer);
unsigned long ResetTimer(Timer_type *Timer);
//char *TimerString(Timer_type *Timer);

#elif USE_GLFW3

typedef struct Timer_struct {double PastSeconds;
	double CurrentSeconds;
	unsigned short paused;} Timer_type;
	
double GetSeconds(Timer_type *Timer);
double PauseTimer(Timer_type *Timer);
double ResumeTimer(Timer_type *Timer);
double ResetTimer(Timer_type *Timer);

#endif

#ifdef __cplusplus
}
#endif

#endif //KAIROS_H