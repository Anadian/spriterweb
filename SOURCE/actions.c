// Actions.c

#include "actions.h"

#include "ini.h"
#include <string.h>
#include <stdio.h>

static int actions_handler(void *user, const char *section, const char *name, const char *value){
	Actions_type *pActions = (Actions_type *)user;
	if(strcmp(section,"PointUp") == 0){
		if(strcmp(name,"primary") == 0) pActions->PointUp.primary = value;
		else if(strcmp(name,"secondary") == 0) pActions->PointUp.secondary = value;
		else if(strcmp(name,"tertiary") == 0) pActions->PointUp.tertiary = value;
	} else if(strcmp(section,"PointDown") == 0){
		if(strcmp(name,"primary") == 0) pActions->PointDown.primary = value;
		else if(strcmp(name,"secondary") == 0) pActions->PointDown.secondary = value;
		else if(strcmp(name,"tertiary") == 0) pActions->PointDown.tertiary = value;
	} else if(strcmp(section,"PointLeft") == 0){
		if(strcmp(name,"primary") == 0) pActions->PointLeft.primary = value;
		else if(strcmp(name,"secondary") == 0) pActions->PointLeft.secondary = value;
		else if(strcmp(name,"tertiary") == 0) pActions->PointLeft.tertiary = value;
	} else if(strcmp(section,"PointRight") == 0){
		if(strcmp(name,"primary") == 0) pActions->PointRight.primary = value;
		else if(strcmp(name,"secondary") == 0) pActions->PointRight.secondary = value;
		else if(strcmp(name,"tertiary") == 0) pActions->PointRight.tertiary = value;
	} else if(strcmp(section,"PointBack") == 0){
		if(strcmp(name,"primary") == 0) pActions->PointBack.primary = value;
		else if(strcmp(name,"secondary") == 0) pActions->PointBack.secondary = value;
		else if(strcmp(name,"tertiary") == 0) pActions->PointBack.tertiary = value;
	} else if(strcmp(section,"PointFoward") == 0){
		if(strcmp(name,"primary") == 0) pActions->PointForward.primary = value;
		else if(strcmp(name,"secondary") == 0) pActions->PointForward.secondary = value;
		else if(strcmp(name,"tertiary") == 0) pActions->PointForward.tertiary = value;
	} return 0;
	return 1;
}
int LoadActions(char *actionsfilename){
	printf("Loading %s\n", actionsfilename);
	return ini_parse(actionsfilename,actions_handler,&Actions);
}
	