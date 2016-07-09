// Actions.h

#ifndef ACTIONS_H
#define ACTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Action_struct {signed long state;
	char *primary;
	char *secondary;
	char *tertiary;} Action_type;
	
typedef struct Actions_struct {
	Action_type PointUp;
	Action_type PointDown;
	Action_type PointLeft;
	Action_type PointRight;
	Action_type PointBack;
	Action_type PointForward;
} Actions_type;

Actions_type Actions;

int LoadActions(char *actionsfilename);

#ifdef __cplusplus
}
#endif

#endif //ACTIONS_H