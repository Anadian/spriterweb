// kairos.c

#include "kairos.h"

#if USE_SDL2
#include <SDL2/sdl.h>

unsigned long GetTicks(Timer_type *Timer){
	if(Timer->Paused) return Timer->CurrentTicks;
	else return (SDL_GetTicks() - Timer->PastTicks);
}
unsigned long PauseTimer(Timer_type *Timer){
	if(Timer->Paused) return Timer->CurrentTicks;
	else{
		Timer->Paused = 1;
		Timer->CurrentTicks = (SDL_GetTicks() - Timer->PastTicks);
		//Timer->PastTicks = (SDL_GetTicks() - Timer->CurrentTicks);
		return Timer->CurrentTicks;
	}
}
unsigned long ResumeTimer(Timer_type *Timer){
	if(Timer->Paused){
		Timer->Paused = 0;
		Timer->PastTicks = (SDL_GetTicks() - Timer->CurrentTicks);
		Timer->CurrentTicks = (SDL_GetTicks() - Timer->PastTicks);
		return Timer->CurrentTicks;
	} else return (SDL_GetTicks() - Timer->PastTicks);
}
unsigned long ResetTimer(Timer_type *Timer){
	Timer->Paused = 0;
	Timer->CurrentTicks = 0;
	Timer->PastTicks = SDL_GetTicks();
	return (SDL_GetTicks() - Timer->PastTicks);
}
/*char *TimerString(Timer_type *Timer){
	unsigned long Ticks;
	Ticks = GetTicks(Timer);
	char strbuffer[16];
	unsigned long hours,minutes,seconds,centiseconds;
	hours = (Ticks / (1000*60*60));
	minutes = ((Ticks / (1000*60)) % 60);
	seconds = ((Ticks / 1000) % 60);
	centiseconds = ((Ticks / 10) % 100);
	sprintf(strbuffer, "%lu:%lu:%lu.%lu", hours, minutes, seconds, centiseconds);
	return &strbuffer;
}*/

#elif USE_GLFW3

double GetSeconds(Timer_type *Timer){
	if(Timer->Paused == 0) Timer->CurrentSeconds = (glfwGetTime() - Timer->PastSeconds);
	return Timer->CurrentSeconds;
}
double PauseTimer(Timer_type *Timer){
	if(Timer->Paused == 0){
		Timer->Paused = 1;
		Timer->CurrentSeconds = (glfwGetTime() - Timer->PastSeconds);
	}
	return Timer->CurrentSeconds;
}
double ResumeTimer(Timer_type *Timer){
	if(Timer->Paused != 0){
		Timer->Paused = 0;
		Timer->PastSeconds = (glfwGetTime() - Timer->CurrentSeconds);
	}
	return Timer->CurrentSeconds;
}
double ResetTimer(Timer_type *Timer){
	Timer->PastSeconds = glfwGetTime();
	Timer->CurrentSeconds = 0;
	Timer->Paused = 0;
	return (glfwGetTime() - Timer->PastSeconds);
}
	
#endif