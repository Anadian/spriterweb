// Actions.c

#include "actions.h"

#include "ini.h"
#include <string.h>
#include <stdio.h>
#include "input.h"

// s/checkstate\((.*)\)/if\(Actions\.\1\.state \> 0\) Actions\.\1\.state\+\+;\n\telse if\(Actions\.\1\.state \< 0\) Actions\.\1\.state--;
// s/ifmatch\((.*)\)/if\( \(strcmp\(Event\.code,Actions.\1\.primary\) == 0\) || \(strcmp\(Event\.code,Actions\.\1\.secondary) == 0\) || \(strcmp\(Event\.code,Actions\.\1\.tertiary\) == 0\) \) Actions\.\1\.state = Event\.value;
int ProcessActions(){
	if(Actions.PointUp.state > 0) Actions.PointUp.state++;
	else if(Actions.PointUp.state < 0) Actions.PointUp.state--;
	if(Actions.PointDown.state > 0) Actions.PointDown.state++;
	else if(Actions.PointDown.state < 0) Actions.PointDown.state--;
	if(Actions.PointLeft.state > 0) Actions.PointLeft.state++;
	else if(Actions.PointLeft.state < 0) Actions.PointLeft.state--;
	if(Actions.PointRight.state > 0) Actions.PointRight.state++;
	else if(Actions.PointRight.state < 0) Actions.PointRight.state--;
	if(Actions.PointBack.state > 0) Actions.PointBack.state++;
	else if(Actions.PointBack.state < 0) Actions.PointBack.state--;
	if(Actions.PointForward.state > 0) Actions.PointForward.state++;
	else if(Actions.PointForward.state < 0) Actions.PointForward.state--;
	InputEvent_type Event;
	Event.type = 0;
	while(InputGetEvent(&Event)){
		//printf("Got code: %s\n", Event.code);
		//printf("Strncmp: %d Actions: %s\n", strncmp(Event.code,Actions.PointUp.primary,strlen(Actions.PointUp.primary)), Actions.PointUp.primary);
		//if( (strcmp(Event.code,Actions.PointUp.primary) == 0) || (strcmp(Event.code,Actions.PointUp.secondary) == 0) || (strcmp(Event.code,Actions.tertiary) == 0) ) Actions.PointUp.state = Event.value;
		if( (strcmp(Event.code,Actions.PointUp.primary) == 0) || (strcmp(Event.code,Actions.PointUp.secondary) == 0) || (strcmp(Event.code,Actions.PointUp.tertiary) == 0) ) Actions.PointUp.state = Event.value;
		if( (strcmp(Event.code,Actions.PointDown.primary) == 0) || (strcmp(Event.code,Actions.PointDown.secondary) == 0) || (strcmp(Event.code,Actions.PointDown.tertiary) == 0) ) Actions.PointDown.state = Event.value;
		if( (strcmp(Event.code,Actions.PointLeft.primary) == 0) || (strcmp(Event.code,Actions.PointLeft.secondary) == 0) || (strcmp(Event.code,Actions.PointLeft.tertiary) == 0) ) Actions.PointLeft.state = Event.value;
		if( (strcmp(Event.code,Actions.PointRight.primary) == 0) || (strcmp(Event.code,Actions.PointRight.secondary) == 0) || (strcmp(Event.code,Actions.PointRight.tertiary) == 0) ) Actions.PointRight.state = Event.value;
		if( (strcmp(Event.code,Actions.PointBack.primary) == 0) || (strcmp(Event.code,Actions.PointBack.secondary) == 0) || (strcmp(Event.code,Actions.PointBack.tertiary) == 0) ) Actions.PointBack.state = Event.value;
		if( (strcmp(Event.code,Actions.PointForward.primary) == 0) || (strcmp(Event.code,Actions.PointForward.secondary) == 0) || (strcmp(Event.code,Actions.PointForward.tertiary) == 0) ) Actions.PointForward.state = Event.value;
		Event.type = 0;
	}
	return 1;
}
static int handler(void* user, const char* section, const char* name, const char* value){
	Actions_type *pActions = (Actions_type *)user;
	//printf("In AH, section %s, name %s, value %s\n", section, name, value);
	if(strcmp(section,"PointUp") == 0){
		if(strcmp(name,"primary") == 0) strcpy(pActions->PointUp.primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(pActions->PointUp.secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(pActions->PointUp.tertiary,value);
	} else if(strcmp(section,"PointDown") == 0){
		if(strcmp(name,"primary") == 0) strcpy(pActions->PointDown.primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(pActions->PointDown.secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(pActions->PointDown.tertiary,value);
	} else if(strcmp(section,"PointLeft") == 0){
		if(strcmp(name,"primary") == 0) strcpy(pActions->PointLeft.primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(pActions->PointLeft.secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(pActions->PointLeft.tertiary,value);
	} else if(strcmp(section,"PointRight") == 0){
		if(strcmp(name,"primary") == 0) strcpy(pActions->PointRight.primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(pActions->PointRight.secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(pActions->PointRight.tertiary,value);
	} else if(strcmp(section,"PointBack") == 0){
		if(strcmp(name,"primary") == 0) strcpy(pActions->PointBack.primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(pActions->PointBack.secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(pActions->PointBack.tertiary,value);
	} else if(strcmp(section,"PointForward") == 0){
		if(strcmp(name,"primary") == 0) strcpy(pActions->PointForward.primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(pActions->PointForward.secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(pActions->PointForward.tertiary,value);
	} return 0;
	return 1;
}
int LoadActions(char *actionsfilename){
	printf("Loading %s\n", actionsfilename);
	return ini_parse(actionsfilename,handler,&Actions);
}
//s/PM\((.*)\)/fputs\(\"\[\1\]\", actionsfile);\n\tsprintf\(buffer, \"\1=%s\\nsecondary=%s\\ntertiary=%s\\n\", Actions.\1.primary, Actions.\1.secondary, Actions.\1.tertiary\);\n\tfputs\(buffer, actionsfile\);/
int SaveActions(char *actionsfilename){
	FILE *actionsfile = fopen(actionsfilename, "w+");
	char buffer[256];
	sprintf(buffer, ";%s\n", actionsfilename);
	fputs(buffer, actionsfile);
	/*fputs("[PointUp]", actionsfile);
	sprintf(buffer, "primary=%s\n", Actions.PointUp.primary);
	fputs(buffer, actionsfile);*/
	fputs("[PointUp]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions.PointUp.primary, Actions.PointUp.secondary, Actions.PointUp.tertiary);
	fputs(buffer, actionsfile);
	fputs("[PointDown]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions.PointDown.primary, Actions.PointDown.secondary, Actions.PointDown.tertiary);
	fputs(buffer, actionsfile);
	fputs("[PointLeft]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions.PointLeft.primary, Actions.PointLeft.secondary, Actions.PointLeft.tertiary);
	fputs(buffer, actionsfile);
	fputs("[PointRight]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions.PointRight.primary, Actions.PointRight.secondary, Actions.PointRight.tertiary);
	fputs(buffer, actionsfile);
	fputs("[PointBack]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions.PointBack.primary, Actions.PointBack.secondary, Actions.PointBack.tertiary);
	fputs(buffer, actionsfile);
	fputs("[PointForward]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions.PointForward.primary, Actions.PointForward.secondary, Actions.PointForward.tertiary);
	fputs(buffer, actionsfile);
	fclose(actionsfile);
	return 0;
}
int CreateNewActions(char *actionsfilename){
	FILE *actionsfile = fopen(actionsfilename, "w+");
	char buffer[256];
	sprintf(buffer, ";%s\n", actionsfilename);
	fputs(buffer, actionsfile);
	fputs("[PointUp]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K87+0", "M0+0", "J0B12");
	fputs(buffer, actionsfile);
	fputs("[PointDown]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K83+0", "M1+0", "J0B14");
	fputs(buffer, actionsfile);
	fputs("[PointLeft]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K65+0", "\0", "J0B15");
	fputs(buffer, actionsfile);
	fputs("[PointRight]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K68+0", "\0", "J0B13");
	fputs(buffer, actionsfile);
	fputs("[PointBack]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K81+0", "\0", "\0");
	fputs(buffer, actionsfile);
	fputs("[PointForward]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K69+0", "\0", "\0");
	fputs(buffer, actionsfile);
	fclose(actionsfile);
	return 0;
}
	
	