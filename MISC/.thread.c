// Thread.c

#include "thread.h"

#include "index.h"
#include <stdio.h>
#include <string.h>

Index_type ThreadIndex;

int ThreadInit(){
	Thread_type SampleThread;
	CreateIndex(&ThreadIndex, &SampleThread);
	return 0;
}
int CreateThread(char *name, void *function, void *arg);
	Thread_type samplethread;
	strcpy(samplethread.thname, name);
	pthread_create(thread.th, NULL, function, arg);
	AddToIndex(&ThreadIndex, &thread);
	return 0;
}
int TerminateThread(char *name){
	int i;
	Thread_type placeholder_thread;
	for(i = 0; i < ThreadIndex.count; i++){
		placeholder_thread = (Thread_type)*(GetObject(&ThreadIndex, i));
		if(strcmp(placeholder_thread.name, name) == 0){
			RemoveFromIndex(&ThreadIndex, i);
			i = ThreadIndex.count;
		}
	}
	return 0;
}
int ThreadQuit(){
	DropIndex(&ThreadIndex);
	return 0;
}
		