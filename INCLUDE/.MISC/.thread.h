// Thread.h

#ifndef THREAD_H
#define THREAD_H

#ifdef __cplusplus
extern "C" {
#endif

//#include "state.h"

#include <pthread.h>

typedef struct Thread_struct {char *thname;
	pthread_t *th;} Thread_type;

int ThreadInit();
int CreateThread(char *name, void *function, void *arg);
//int WaitForAllThreadsToInit();
//int WaitForAllThreadsToTerminate();
int TerminateThread(char *name);
int ThreadQuit();

#ifdef __cplusplus
}
#endif

#endif //THREAD_H