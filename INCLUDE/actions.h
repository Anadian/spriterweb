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
	
typedef struct Actions_struct {
	Action_type PointUp;
	Action_type PointDown;
	Action_type PointLeft;
	Action_type PointRight;
	Action_type PointBack;
	Action_type PointForward;
} Actions_type;

Actions_type Actions;

int ProcessActions();

int LoadActions(char *actionsfilename);
int SaveActions(char *actionsfilename);
int CreateNewActions(char *actionsfilename);

#ifdef __cplusplus
}
#endif

#endif //ACTIONS_H