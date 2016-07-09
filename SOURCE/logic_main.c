// Logic_Main.c

#include "logic_main.h"
#include "state.h"
#include <unistd.h> //usleep
#include <stdio.h> //printf

void *LogicMain(void *arg){
	CriticalVariables.LogicThread = 1;
	
	while(CriticalVariables.AppRunning == 1){
		usleep(5000000);
		printf("Logic thread running\n");
	}
	
	
	CriticalVariables.LogicThread = 2;
	printf("Logic thread teminated\n");
	return NULL;
}