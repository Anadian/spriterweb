// state.h

#ifndef STATE_H
#define STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "build.h"

#if USE_SDL_THREADS
#include <SDL2/SDL_thread.h>
#define Thread_type SDL_Thread
#define ThreadFunction_type SDL_ThreadFunction
#define CreateThread(threadname,threadfunction) SDL_CreateThread(threadfunction, #threadname, NULL);
#define JoinThread(thread) SDL_WaitThread(thread, NULL);
#include <SDL2/SDL_mutex.h>
#define Mutex_type SDL_mutex
#define CreateMutex(mutex) mutex = SDL_CreateMutex();
#define DestroyMutex(mutex) SDL_DestroyMutex(mutex);
#define LockMutex(mutex) SDL_LockMutex(mutex);
#define UnlockMutex(mutex) SDL_UnlockMutex(mutex);
#else
#include <pthread.h>
#define Thread_type pthread_t
#define ThreadFunction_type void
#define CreateThread(threadname,threadfunction) pthread_create(&##threadname, NULL, threadfunction, NULL);
#define JoinThread(thread) pthread_join(thread, NULL);
#define Mutex_type pthread_mutex_t
#define CreateMutex(mutex) pthread_mutex_init(&##mutex, NULL);
#define DestroyMutex(mutex) pthread_mutex_destroy(&##mutex, NULL);
#define LockMutex(mutex) pthread_mutex_lock(&##mutex);
#define UnlockMutex(mutex) pthread_mutex_unlock(&##mutex);
#endif //USE_SDL_THREADS


//#include <stdio.h>
typedef struct CriticalVariables_struct {signed short AppRunning;
	signed short MainThread;
	signed short VideoInit;
	signed short LogicThread;
	char State;} CriticalVariables_type;

CriticalVariables_type CriticalVariables;

#ifdef __cplusplus
}
#endif

#endif //STATE_H