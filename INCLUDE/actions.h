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
	
enum Actions_enum {Up,
	Down,
	Left,
	Right,
	Accept,
	Cancel,
	Numberofactions};

Action_type Actions[Numberofactions];

int ProcessActions();

int LoadActions(char *actionsfilename);
int SaveActions(char *actionsfilename);
int CreateNewActions(char *actionsfilename);

signed long Action(int action);

#ifdef __cplusplus
}
#endif

#endif //ACTIONS_H