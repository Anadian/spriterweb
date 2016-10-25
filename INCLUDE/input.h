// input.h

#ifndef INPUT_H
#define INPUT_H

#include "build.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum InputEventType_enum {
	KeyboardEvent,
	JoystickAxisEvent,
	JoystickHatEvent,
	JoystickButtonEvent,
	MouseMotionEvent,
	MouseButtonEvent,
	TouchEvent,
	DragEvent,
	GestureEvent,
	SystemEvent,
	NumberofInputEventTypes} InputEvent_enum;

typedef struct InputEvent_struct {InputEvent_enum type;
	float value;
	unsigned long time;
	char code[16];
	int x;
	int y;} InputEvent_type;
InputEvent_type *InputEvents;

#if USE_SDL2
#include <SDL2/SDL_joystick.h>
typedef struct Joystick_struct {int id;
	SDL_Joystick *joystick;} Joystick_type;
Joystick_type *Joysticks;

int MouseX;
int MouseY;
#endif //USE_SDL2

/*#define INPUTEVENT_BUFFER_SIZE 32
InputEvent_type InputEvent[INPUTEVENT_BUFFER_SIZE];
int InputAddReference;
int InputReadReference;*/

int InitInput();
int Input();
int QuitInput();
/*int InputAddEvent(InputEvent_type Event);
int InputGetEvent(InputEvent_type *Event);*/

#ifdef __cplusplus
}
#endif

#endif //INPUT_H
