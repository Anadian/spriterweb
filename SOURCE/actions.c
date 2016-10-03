// Actions.c

#include "actions.h"

#include "ini.h"
#include <stdio.h>
#include <string.h>
#include "stretchy_buffer.h"
#include "input.h"
#include <unistd.h> //access

// s/checkstate\((.*)\)/if\(Actions\.\1\.state \> 0\) Actions\.\1\.state\+\+;\n\telse if\(Actions\.\1\.state \< 0\) Actions\.\1\.state--;
// s/ifmatch\((.*)\)/if\( \(strcmp\(Event\.code,Actions.\1\.primary\) == 0\) || \(strcmp\(Event\.code,Actions\.\1\.secondary) == 0\) || \(strcmp\(Event\.code,Actions\.\1\.tertiary\) == 0\) \) Actions\.\1\.state = Event\.value;
int ProcessActions(){
	int i;
	for(i = 0; i < Numberofactions; i++){
		//printf("i: %d state: %d\n", i, Actions[i].state);
		if(Actions[i].state > 0) Actions[i].state++;
		else if(Actions[i].state < 0) Actions[i].state--;
	}
	int j;
	for(j = 0; j < sb_count(InputEvents); j++){
		for(i = 0; i < Numberofactions; i++){
			if( (strcmp(InputEvents[j].code,Actions[i].primary) == 0) || (strcmp(InputEvents[j].code,Actions[i].secondary) == 0) || (strcmp(InputEvents[j].code,Actions[i].tertiary) == 0) ) Actions[i].state = InputEvents[j].value;
		}
	}
	//sb_free(InputEvents);
	return 1;
}
static int handler(void* user, const char* section, const char* name, const char* value){
	//Actions_type *pActions = (Actions_type *)user;
	//printf("In AH, section %s, name %s, value %s\n", section, name, value);
	if(strcmp(section,"Up") == 0){
		if(strcmp(name,"primary") == 0) strcpy(Actions[Up].primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(Actions[Up].secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(Actions[Up].tertiary,value);
	} else if(strcmp(section,"Down") == 0){
		if(strcmp(name,"primary") == 0) strcpy(Actions[Down].primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(Actions[Down].secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(Actions[Down].tertiary,value);
	} else if(strcmp(section,"Left") == 0){
		if(strcmp(name,"primary") == 0) strcpy(Actions[Left].primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(Actions[Left].secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(Actions[Left].tertiary,value);
	} else if(strcmp(section,"Right") == 0){
		if(strcmp(name,"primary") == 0) strcpy(Actions[Right].primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(Actions[Right].secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(Actions[Right].tertiary,value);
	} else if(strcmp(section,"Accept") == 0){
		if(strcmp(name,"primary") == 0) strcpy(Actions[Accept].primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(Actions[Accept].secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(Actions[Accept].tertiary,value);
	} else if(strcmp(section,"Cancel") == 0){
		if(strcmp(name,"primary") == 0) strcpy(Actions[Cancel].primary,value);
		else if(strcmp(name,"secondary") == 0) strcpy(Actions[Cancel].secondary,value);
		else if(strcmp(name,"tertiary") == 0) strcpy(Actions[Cancel].tertiary,value);
	} else return 0;
	return 1;
}
int LoadActions(char *actionsfilename){
	if(access(actionsfilename, F_OK) == 0){
		printf("Loading: %s\n", actionsfilename);
		return ini_parse(actionsfilename,handler,NULL);
	} else{
		printf("Couldn't find %s\n", actionsfilename);
		return -1;
	}
}
//s/PM\((.*)\)/fputs\(\"\[\1\]\", actionsfile);\n\tsprintf\(buffer, \"\1=%s\\nsecondary=%s\\ntertiary=%s\\n\", Actions.\1.primary, Actions.\1.secondary, Actions.\1.tertiary\);\n\tfputs\(buffer, actionsfile\);/
int SaveActions(char *actionsfilename){
	FILE *actionsfile = fopen(actionsfilename, "w+");
	char buffer[256];
	sprintf(buffer, ";%s\n", actionsfilename);
	fputs(buffer, actionsfile);
	/*fputs("[Up]", actionsfile);
	sprintf(buffer, "primary=%s\n", Actions.Up.primary);
	fputs(buffer, actionsfile);*/
	fputs("[Up]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions[Up].primary, Actions[Up].secondary, Actions[Up].tertiary);
	fputs(buffer, actionsfile);
	fputs("[Down]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions[Down].primary, Actions[Down].secondary, Actions[Down].tertiary);
	fputs(buffer, actionsfile);
	fputs("[Left]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions[Left].primary, Actions[Left].secondary, Actions[Left].tertiary);
	fputs(buffer, actionsfile);
	fputs("[Right]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions[Right].primary, Actions[Right].secondary, Actions[Right].tertiary);
	fputs(buffer, actionsfile);
	fputs("[Accept]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions[Accept].primary, Actions[Accept].secondary, Actions[Accept].tertiary);
	fputs(buffer, actionsfile);
	fputs("[Cancel]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", Actions[Cancel].primary, Actions[Cancel].secondary, Actions[Cancel].tertiary);
	fputs(buffer, actionsfile);
	fclose(actionsfile);
	return 0;
}
int CreateNewActions(char *actionsfilename){
	FILE *actionsfile = fopen(actionsfilename, "w+");
	char buffer[256];
	sprintf(buffer, ";%s\n", actionsfilename);
	fputs(buffer, actionsfile);
	fputs("[Up]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K87+0", "M0", "J0A12");
	fputs(buffer, actionsfile);
	fputs("[Down]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K83+0", "M1", "J0B14");
	fputs(buffer, actionsfile);
	fputs("[Left]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K65+0", "\0", "J0B15");
	fputs(buffer, actionsfile);
	fputs("[Right]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K68+0", "\0", "J0B13");
	fputs(buffer, actionsfile);
	fputs("[Accept]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K158+0", "\0", "J0B1");
	fputs(buffer, actionsfile);
	fputs("[Cancel]\n", actionsfile);
	sprintf(buffer, "primary=%s\nsecondary=%s\ntertiary=%s\n", "K164+0", "\0", "J0B2");
	fputs(buffer, actionsfile);
	fclose(actionsfile);
	return 0;
}
	
	