// Actions.h

#ifndef ACTIONS_H
#define ACTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Action_struct {signed long state;
	char primary[16];
	char secondary[16];
	char tertiary[16];} Action_type;
	
typedef enum ActionList_enum {Up,
	Down,
	Left,
	Right,
	Accept,
	Cancel,
	Numberofactions} ActionList_type;

Action_type Actions[Numberofactions];

int ProcessActions();

int LoadActions(char *actionsfilename);
int SaveActions(char *actionsfilename);
int CreateNewActions(char *actionsfilename);

#ifdef __cplusplus
}
#endif

#endif //ACTIONS_H