// input.h

#ifndef INPUT_H
#define INPUT_H

#include "build.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct InputEvent_struct {int type; //0 = empty, 1 = keyboard, 2 = joystick axis, 3 = joystick button, 4 = mouse motion, 5 = RNG
	float value;
	double time;
	char code[16];} InputEvent_type;
	
unsigned char Keys[105];
int LastUnicode;

#define INPUTEVENT_BUFFER_SIZE 32
InputEvent_type InputEvent[INPUTEVENT_BUFFER_SIZE];
int InputAddReference;
int InputReadReference;

int InitInput();
int Input();
int QuitInput();
int InputAddEvent(InputEvent_type Event);
int InputGetEvent(InputEvent_type *Event);

#ifdef __cplusplus
}
#endif

#endif //INPUT_H