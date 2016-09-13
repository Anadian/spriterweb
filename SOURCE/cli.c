// cli.c

#include "cli.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int CLIGetString(char *arg, char *flag, char *pstring){
	if(strncmp(arg,flag,strlen(flag)) == 0){
		char buffer[(strlen(arg) - (strlen(flag)+1))+1];
		int j;
		for(j = 0; j < ((strlen(arg) - (strlen(flag)+1))+1); j++){
			buffer[j] = arg[strlen(flag)+j];
		}
		strcpy(pstring,buffer);
		return 1;
	}
	return 0;
}
int CLIGetInt(char *arg, char *flag, int *pint){
	printf("In CLIGetInt. arg = %s flag = %s pint = %d\n", arg, flag, *pint);
	if(strncmp(arg,flag,strlen(flag)) == 0){
		char buffer[32];
		CLIGetString(arg,flag,buffer);
		*pint = atoi(buffer);
		return 1;
	}
	return 0;
}
		
		