// input.c
#include "input.h"
#include "state.h"
#include <stdio.h>
#include "video.h" //Window
#include "actions.h" //ProcessActions
#include <string.h> //strcpy
#include <stdlib.h> //abs
#include "configuration.h" //joystickdeadzone
#include "delog.h"
#include "stretchy_buffer.h"

#if USE_SDL2

#include <SDL2/SDL.h>
SDL_Event Event;
SDL_Event PreviousEvent;
int EventMatch(SDL_Event event, SDL_Event previousevent){
	printl(5, "%s: %d %d", __func__, event, previousevent);
	if(event.type == previousevent.type){
		switch(event.type){
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				if((event.key.keysym.scancode == previousevent.key.keysym.scancode) && (event.key.keysym.mod == previousevent.key.keysym.mod) && (event.key.state == previousevent.key.state)) return 1;
				break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				if((event.button.button == previousevent.button.button) && (event.button.state == previousevent.button.state) && (event.button.x == previousevent.button.x) && (event.button.y == previousevent.button.y) ) return 1;
				break;
			case SDL_FINGERDOWN:
			case SDL_FINGERUP:
				if((event.tfinger.type == previousevent.tfinger.type) && (event.tfinger.fingerId == previousevent.tfinger.fingerId) && (event.tfinger.x == previousevent.tfinger.x) && (event.tfinger.y == previousevent.tfinger.y)) return 1;
				break;
			default:
				return 0;
				break;
		}
	}
	return 0;
}

#elif USE_GLFW3

GLFWwindow *window_ptr;
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void MouseButtonCallback(GLFWwindow *windoww, int button, int action, int mods);
unsigned char oldbuttons[32];

#elif USE_TIGR

#include "gamepad/Gamepad.h"
typedef struct Gamepad_device Gamepad;
void DownCallback(Gamepad *device, int buttonID, double timestamp, void *context);
void UpCallback(Gamepad *device, int buttonID, double timestamp, void *context);
void AxesCallback(Gamepad *device, int axisID, float value, float lastValue, double timestamp, void *context);
int SKFromTK(int tk);
char CharFromSK(int sk);
int SKFromChar(char c);
int TKFromSK(int sk);

#endif

int InitInput(){
	InputEvents = NULL;
	Joystick_type Joystick;
#if USE_SDL2
	int i;
	for(i = 0; i < SDL_NumJoysticks(); i++){
		Joystick.joystick = SDL_JoystickOpen(i);
		Joystick.id = SDL_JoystickInstanceID(Joystick.joystick);
		sb_push(Joysticks,Joystick);
	}
	MouseX = 0;
	MouseY = 0;
#endif //USE_SDL2

#if USE_GLFW3

	window_ptr = GetWindow();
	glfwSetKeyCallback(window_ptr, KeyCallback);
	glfwSetMouseButtonCallback(window_ptr, MouseButtonCallback);

#elif USE_TIGR
	/*printf("SK\t|\tTK\t|\tchar\n");
	for(i = 0; i < 105; i++){
		Keys[i] = 0;
		printf("%d\t|\t%d\t|\t%c\n", i, TKFromSK(i), CharFromSK(i));
	}*/
	//window_ptr = GetWindow();
	Gamepad_buttonDownFunc(DownCallback,NULL);
	Gamepad_buttonUpFunc(UpCallback,NULL);
	Gamepad_axisMoveFunc(AxesCallback,NULL);
	Gamepad_init();
#endif
	return 0;
}

int Input(){
#if USE_SDL2
	InputEvent_type InputEvent;
	int ww, wh, lw, lh;
	SDL_GetWindowSize(Window, &ww, &wh);
	SDL_RenderGetLogicalSize(Renderer, &lw, &lh);
	printl(5, "Input %d %d %d %d", ww, wh, lw, lh);
	while(SDL_PollEvent(&Event)){
		printl(5, "EventMatch returned %d", EventMatch(Event,PreviousEvent));
		if( !EventMatch(Event, PreviousEvent) ){
			switch(Event.type){
				case SDL_QUIT: 
					printl(5, "SDL Quit after %d ticks", Event.quit.timestamp);
					CriticalVariables.AppRunning = 0;
					break;
				case SDL_KEYDOWN:
					InputEvent.type = KeyboardEvent;
					InputEvent.value = 1;
					sprintf(InputEvent.code, "K%d+%d", Event.key.keysym.scancode, Event.key.keysym.mod);
					InputEvent.time = Event.key.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_KEYUP:
					InputEvent.type = KeyboardEvent;
					InputEvent.value = -1;
					sprintf(InputEvent.code, "K%d+%d", Event.key.keysym.scancode, Event.key.keysym.mod);
					InputEvent.time = Event.key.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_MOUSEMOTION:
					InputEvent.type = MouseMotionEvent;
					InputEvent.value = 0;
					sprintf(InputEvent.code, "M%d", Event.motion.which);
					MouseX = (int)((Event.motion.x*lw)/ww);
					MouseY = (int)((Event.motion.y*lh)/wh);
					InputEvent.x = (int)((Event.motion.xrel*lw)/ww);
					InputEvent.y = (int)((Event.motion.yrel*lh)/wh);
					InputEvent.time = Event.motion.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
				case SDL_MOUSEBUTTONDOWN:
					InputEvent.type = MouseButtonEvent;
					InputEvent.value = 1;
					sprintf(InputEvent.code, "M%dB%d", Event.button.which, Event.button.button);
					MouseX = (int)((Event.button.x*lw)/ww);
					MouseY = (int)((Event.button.y*lh)/wh);
					InputEvent.time = Event.button.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
					
				case SDL_MOUSEBUTTONUP:
					InputEvent.type = MouseButtonEvent;
					InputEvent.value = -1;
					sprintf(InputEvent.code, "M%dB%d", Event.button.which, Event.button.button);
					MouseX = (int)((Event.button.x*lw)/ww);
					MouseY = (int)((Event.button.y*lh)/wh);
					InputEvent.time = Event.button.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_JOYBUTTONDOWN:
					InputEvent.type = JoystickButtonEvent;
					InputEvent.value = 1;
					sprintf(InputEvent.code, "J%dB%d", Event.jbutton.which, Event.jbutton.button);
					InputEvent.time = Event.jbutton.timestamp;
					sb_push(InputEvents, InputEvent);
					//printf("Added event %s with value %f at %d to %d\n", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_JOYBUTTONUP:
					InputEvent.type = JoystickButtonEvent;
					InputEvent.value = -1;
					sprintf( InputEvent.code, "J%dB%d", Event.jbutton.which, Event.jbutton.button);
					InputEvent.time = Event.jbutton.timestamp;
					sb_push( InputEvents, InputEvent);
					//printf("Added event %s with value %f at %d to %d\n", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_JOYAXISMOTION:
					InputEvent.type = JoystickAxisEvent;
					InputEvent.value = Event.jaxis.value;
					sprintf(InputEvent.code, "J%dA%d", Event.jaxis.which, Event.jaxis.axis);
					InputEvent.time = Event.jaxis.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_JOYHATMOTION:
					InputEvent.type = JoystickHatEvent;
					InputEvent.value = Event.jhat.value;
					sprintf(InputEvent.code, "J%dH%d", Event.jhat.which, Event.jhat.hat);
					InputEvent.time = Event.jhat.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_FINGERMOTION:
					InputEvent.type = TouchEvent;
					InputEvent.value = 0;
					sprintf(InputEvent.code, "T%d", Event.tfinger.touchId);
					MouseX = (int)((Event.tfinger.x*lw)/ww);
					MouseY = (int)((Event.tfinger.y*lh)/wh);
					InputEvent.x = (int)((Event.tfinger.dx*lw)/ww);
					InputEvent.y = (int)((Event.tfinger.dy*lh)/wh);
					InputEvent.time = Event.tfinger.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));

				case SDL_FINGERDOWN:
					InputEvent.type = TouchEvent;
					InputEvent.value = 1;
					sprintf(InputEvent.code, "T%d", Event.tfinger.touchId);
					MouseX = (int)((Event.tfinger.x*lw)/ww);
					MouseY = (int)((Event.tfinger.y*lh)/wh);
					InputEvent.x = (int)((Event.tfinger.dx*lw)/ww);
					InputEvent.y = (int)((Event.tfinger.dy*lh)/wh);
					InputEvent.time = Event.tfinger.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				case SDL_FINGERUP:
					InputEvent.type = TouchEvent;
					InputEvent.value = -1;
					sprintf(InputEvent.code, "T%d", Event.tfinger.touchId);
					MouseX = (int)((Event.tfinger.x*lw)/ww);
					MouseY = (int)((Event.tfinger.y*lh)/wh);
					InputEvent.x = (int)((Event.tfinger.dx*lw)/ww);
					InputEvent.y = (int)((Event.tfinger.dy*lh)/wh);
					InputEvent.time = Event.tfinger.timestamp;
					sb_push(InputEvents,InputEvent);
					printl(4, "Added event %s with value %f at %d to %d", InputEvent.code, InputEvent.value, InputEvent.time, sb_count(InputEvents));
					break;
				default:
					break;
			}
			PreviousEvent = Event;
		}
	}
	ProcessActions();
	if(InputEvents != NULL){
		sb_free(InputEvents);
		InputEvents = NULL;
	}
#elif USE_GLFW3
	glfwPollEvents();
	if(glfwWindowShouldClose(window_ptr)){
		CriticalVariables.AppRunning = 0;
	}
	int i;
	for(i = 0; i < 16; i++){
		if(glfwJoystickPresent(i)){
			float *axes;
			int count;
			axes = glfwGetJoystickAxes(i,&count);
			int j;
			for(j = 0; j < count; j++){
				if(abs(axes[j]) > Configuration.controls.joystickdeadzone){
					InputEvent_type Event;
					Event.type = 2;
					Event.value = axes[j];
					sprintf(Event.code, "J%dA%d", i, j);
					Event.time = glfwGetTime();
					InputAddEvent(Event);
				}
			}
			unsigned char *buttons;
			buttons = glfwGetJoystickButtons(i,&count);
			for(j = 0; j < count; j++){
				if(buttons[j] != oldbuttons[j]){ 
					InputEvent_type Event;
					Event.type = 3;
					if(buttons[j] == GLFW_PRESS) Event.value = 1;
					else if(buttons[j] == GLFW_RELEASE) Event.value = -1;
					sprintf(Event.code, "J%dB%d", i, j);
					Event.time = glfwGetTime();
					InputAddEvent(Event);
				}
				oldbuttons[j] = buttons[j];
			}
		}
		//for(i = 0; i < 8; i++
	}
					 
	ProcessActions();
#elif USE_TIGR
	if(tigrClosed(Window)) CriticalVariables.AppRunning = 0;
	//if(tigrKeyHeld(window_ptr,TK_SPACE)) tigrPrint(window_ptr, tfont, 0, 0, tigrRGB(255,0,0), "Space is held");
	unsigned char i;
	for(i = '0'; i <= '9'; i++){
		if(tigrKeyHeld(Window,i) != Keys[i-48]){
			if(tigrKeyHeld(Window,i)){ //Pressed
				InputEvent_type Event;
				Event.type = 1;
				Event.value = 1;
				sprintf(Event.code, "K%d", i);
				Event.time = tigrTime();
				InputAddEvent(Event);
				Keys[i-48] = 1;
			}
			else{ //Released
				InputEvent_type Event;
				Event.type = 1;
				Event.value = -1;
				sprintf(Event.code, "K%d", i);
				Event.time = tigrTime();
				InputAddEvent(Event);
				Keys[i-48] = 0;
			}
		}
	}
	for(i = 'A'; i <= 'Z'; i++){
		if(tigrKeyHeld(Window,i) != Keys[i-55]){
			if(tigrKeyHeld(Window,i)){ //Pressed
				//TextBufferAdd(i);
				InputEvent_type Event;
				Event.type = 1;
				Event.value = 1;
				sprintf(Event.code, "K%d", i);
				Event.time = tigrTime();
				InputAddEvent(Event);
				Keys[i-55] = 1;
			}
			else{ //Released
				InputEvent_type Event;
				Event.type = 1;
				Event.value = -1;
				sprintf(Event.code, "K%d", i);
				Event.time = tigrTime();
				InputAddEvent(Event);
				Keys[i-55] = 0;
			}
		}
	}
	for(i = 128; i <= 197; i++){
		if(tigrKeyHeld(Window,i) != Keys[i-92]){
			if(tigrKeyHeld(Window,i)){ //Pressed
				InputEvent_type Event;
				Event.type = 1;
				Event.value = 1;
				sprintf(Event.code, "K%d", i);
				Event.time = tigrTime();
				InputAddEvent(Event);
				Keys[i-92] = 1;
			}
			else{ //Released
				InputEvent_type Event;
				Event.type = 1;
				Event.value = -1;
				sprintf(Event.code, "K%d", i);
				Event.time = tigrTime();
				InputAddEvent(Event);
				Keys[i-92] = 0;
			}
		}
	}
	Gamepad_processEvents();
	Gamepad_detectDevices();
	ProcessActions();
	LastUnicode = tigrReadChar(Window);
#endif
	return 0;
}
int QuitInput(){
#if USE_SDL2
	int i;
	for(i = 0; i < sb_count(Joysticks); i++){
		SDL_JoystickClose(Joysticks[i].joystick);
	}
	sb_free(Joysticks);
#endif //USE_SDL2
	return 0;
}
/*
int InputAddEvent(InputEvent_type Event){
	printl(4, "Added event %s with %d to %d\t", Event.code, InputAddReference);
	printf("Added event %s with %d to %d\t", Event.code, InputAddReference);
	if(Event.type != NULL){
		InputEvent[InputAddReference] = Event;
		InputAddReference++;
		if(InputAddReference == INPUTEVENT_BUFFER_SIZE) InputAddReference = 0;
		return 1;
	}
	if(InputAddReference == INPUTEVENT_BUFFER_SIZE) InputAddReference = 0;
	return 0;
}
int InputGetEvent(InputEvent_type *Event){
	if(InputEvent[InputReadReference].type != 0){
		Event->type = InputEvent[InputReadReference].type;
		Event->value = InputEvent[InputReadReference].value;
		Event->time = InputEvent[InputReadReference].time;
		strcpy(Event->code,InputEvent[InputReadReference].code);
		InputEvent[InputReadReference].type = 0;
		printl(4, "Read event %s with %d from %d\n", Event->code, InputReadReference);
		printf("Read event %s with %d from %d\n", Event->code, InputReadReference);
		InputReadReference++;
		if(InputReadReference == INPUTEVENT_BUFFER_SIZE) InputReadReference = 0;
		return 1;
	}else if(InputReadReference != InputAddReference) InputReadReference++;
	if(InputReadReference == INPUTEVENT_BUFFER_SIZE) InputReadReference = 0;
	return 0;
}*/
	

#if USE_GLFW3
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
	if(action == GLFW_PRESS){
		//printf("key: %d + %d at %f\n", key, mods, glfwGetTime());
		InputEvent_type Event;
		Event.type = 1;
		Event.value = 1;
		sprintf(Event.code, "K%d+%d", key, mods);
		//printf("Event.code: %s\n", Event.code);
		Event.time = glfwGetTime();
		InputAddEvent(Event);
		
	}
	else if(action == GLFW_RELEASE){
		InputEvent_type Event;
		Event.type = 1;
		Event.value = -1;
		sprintf(Event.code, "K%d+%d", key, mods);
		Event.time = glfwGetTime();
		InputAddEvent(Event);
	}
}
void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods){
	if(action == GLFW_PRESS){
		InputEvent_type Event;
		Event.type = 4;
		Event.value = 1;
		sprintf(Event.code, "M%d+%d", button, mods);
		Event.time = glfwGetTime();
		InputAddEvent(Event);
	}
	else if(action == GLFW_RELEASE){
		InputEvent_type Event;
		Event.type = 4;
		Event.value = -1;
		sprintf(Event.code, "M%d+%d", button, mods);
		InputAddEvent(Event);
	}
}
		

char *ASCIIFromGLFW3Key(int key){ //Returns to 16 byte buffer.
	if(key > 32 && key < 97) return (char)key;
	else switch (key) {
		case 32: return "[SPACE]"; break;
		case 161: return "[WORLD_1]"; break;

		case 162: return "[WORLD_2]"; break;

		case 256: return "[ESCAPE]"; break;

		case 257: return "[ENTER]"; break;

		case 258: return "[TAB]"; break;

		case 259: return "[BACKSPACE]"; break;

		case 260: return "[INSERT]"; break;

		case 261: return "[DELETE]"; break;

		case 262: return "[RIGHT]"; break;

		case 263: return "[LEFT]"; break;

		case 264: return "[DOWN]"; break;

		case 265: return "[UP]"; break;

		case 266: return "[PAGE_UP]"; break;

		case 267: return "[PAGE_DOWN]"; break;

		case 268: return "[HOME]"; break;

		case 269: return "[END]"; break;

		case 280: return "[CAPS_LOCK]"; break;

		case 281: return "[SCROLL_LOCK]"; break;

		case 282: return "[NUM_LOCK]"; break;

		case 283: return "[PRINT_SCREEN]"; break;

		case 284: return "[PAUSE]"; break;

		case 290: return "[F1]"; break;

		case 291: return "[F2]"; break;

		case 292: return "[F3]"; break;

		case 293: return "[F4]"; break;

		case 294: return "[F5]"; break;

		case 295: return "[F6]"; break;

		case 296: return "[F7]"; break;

		case 297: return "[F8]"; break;

		case 298: return "[F9]"; break;

		case 299: return "[F10]"; break;

		case 300: return "[F11]"; break;

		case 301: return "[F12]"; break;

		case 302: return "[F13]"; break;

		case 303: return "[F14]"; break;

		case 304: return "[F15]"; break;

		case 305: return "[F16]"; break;

		case 306: return "[F17]"; break;

		case 307: return "[F18]"; break;

		case 308: return "[F19]"; break;

		case 309: return "[F20]"; break;

		case 310: return "[F21]"; break;

		case 311: return "[F22]"; break;

		case 312: return "[F23]"; break;

		case 313: return "[F24]"; break;

		case 314: return "[F25]"; break;

		case 320: return "[KP_0]"; break;

		case 321: return "[KP_1]"; break;

		case 322: return "[KP_2]"; break;

		case 323: return "[KP_3]"; break;

		case 324: return "[KP_4]"; break;

		case 325: return "[KP_5]"; break;

		case 326: return "[KP_6]"; break;

		case 327: return "[KP_7]"; break;

		case 328: return "[KP_8]"; break;

		case 329: return "[KP_9]"; break;

		case 330: return "[KP_DECIMAL]"; break;

		case 331: return "[KP_DIVIDE]"; break;

		case 332: return "[KP_MULTIPLY]"; break;

		case 333: return "[KP_SUBTRACT]"; break;

		case 334: return "[KP_ADD]"; break;

		case 335: return "[KP_ENTER]"; break;

		case 336: return "[KP_EQUAL]"; break;

		case 340: return "[LEFT_SHIFT]"; break;

		case 341: return "[LEFT_CONTROL]"; break;

		case 342: return "[LEFT_ALT]"; break;

		case 343: return "[LEFT_SUPER]"; break;

		case 344: return "[RIGHT_SHIFT]"; break;

		case 345: return "[RIGHT_CONTROL]"; break;
 // Longest char* 
		case 346: return "[RIGHT_ALT]"; break;

		case 347: return "[RIGHT_SUPER]"; break;

		case 348: return "[MENU]"; break;

		}
}
//int GLFW3KeyFromASCII(char *ascii){
	
#elif USE_TIGR
void DownCallback(Gamepad *device, int buttonID, double timestamp, void *context){
	//tigrPrint(window_ptr, tfont, 0, (printplace % 30)*16, tigrRGB(255,0,0), "Button %d pressed", buttonID);
	InputEvent_type Event;
	Event.type = 3;
	Event.value = 1;
	sprintf(Event.code, "J%dB%d", device->deviceID, buttonID);
	Event.time = timestamp;
	InputAddEvent(Event);
}
void UpCallback(Gamepad *device, int buttonID, double timestamp, void *context){
	//tigrPrint(window_ptr, tfont, 0, (printplace % 30)*16, tigrRGB(0,255,0), "Button %d released, buttonID", buttonID);
	InputEvent_type Event;
	Event.type = 3;
	Event.value = -1;
	sprintf(Event.code, "J%dB%d", device->deviceID, buttonID);
	Event.time = timestamp;
	InputAddEvent(Event);
}
void AxesCallback(Gamepad *device, int axisID, float value, float lastValue, double timestamp, void *context){
	//tigrPrint(window_ptr, tfont, 0, (printplace % 30)*16, tigrRGB(0,0,255), "Axis %d has value %f", axisID, value);
	InputEvent_type Event;
	Event.type = 2;
	Event.value = value;
	sprintf(Event.code, "J%dA%d", device->deviceID, axisID);
	Event.time = timestamp;
	InputAddEvent(Event);
}
char *ASCIIFromSK(int sk){
	char string[10];
	if(sk < 10) strcpy(string,CharFromSK(sk));
	else if(sk < 36) strcpy(string,CharFromSK(sk));
	else{
		switch(sk + 92){
			case TK_PAD0: return "[PAD0]"; break;
			case TK_PAD1: return "[PAD1]"; break;
			case TK_PAD2: return "[PAD2]"; break;
			case TK_PAD3: return "[PAD3]"; break;
			case TK_PAD4: return "[PAD4]"; break;
			case TK_PAD5: return "[PAD5]"; break;
			case TK_PAD6: return "[PAD6]"; break;
			case TK_PAD7: return "[PAD7]"; break;
			case TK_PAD8: return "[PAD8]"; break;
			case TK_PAD9: return "[PAD9]"; break;
			case TK_PADMUL: return "[PADMUL]"; break;
			case TK_PADADD: return "[PADADD]"; break;
			case TK_PADENTER: return "[PADENTER]"; break;
			case TK_PADSUB: return "[PADSUB]"; break;
			case TK_PADDOT: return "[PADDOT]"; break;
			case TK_PADDIV: return "[PADDIV]"; break;
			case TK_F1: return "[F1]"; break;
			case TK_F2: return "[F2]"; break;
			case TK_F3: return "[F3]"; break;
			case TK_F4: return "[F4]"; break;
			case TK_F5: return "[F5]"; break;
			case TK_F6: return "[F6]"; break;
			case TK_F7: return "[F7]"; break;
			case TK_F8: return "[F8]"; break;
			case TK_F9: return "[F9]"; break;
			case TK_F10: return "[F10]"; break;
			case TK_F11: return "[F11]"; break;
			case TK_F12: return "[F12]"; break;
			case TK_BACKSPACE: return "[BACKSPACE]"; break;
			case TK_TAB: return "[TAB]"; break;
			case TK_RETURN: return "[RETURN]"; break;
			case TK_SHIFT: return "[SHIFT]"; break;
			case TK_CONTROL: return "[CONTROL]"; break;
			case TK_ALT: return "[ALT]"; break;
			case TK_PAUSE: return "[PAUSE]"; break;
			case TK_CAPSLOCK: return "[CAPSLOCK]"; break;
			case TK_ESCAPE: return "[ESCAPE]"; break;
			case TK_SPACE: return "[SPACE]"; break;
			case TK_PAGEUP: return "[PAGEUP]"; break;
			case TK_PAGEDN: return "[PAGEDN]"; break;
			case TK_END: return "[END]"; break;
			case TK_HOME: return "[HOME]"; break;
			case TK_LEFT: return "[LEFT]"; break;
			case TK_UP: return "[UP]"; break;
			case TK_RIGHT: return "[RIGHT]"; break;
			case TK_DOWN: return "[DOWN]"; break;
			case TK_INSERT: return "[INSERT]"; break;
			case TK_DELETE: return "[DELETE]"; break;
			case TK_LWIN: return "[LWIN]"; break;
			case TK_RWIN: return "[RWIN]"; break;
			case TK_NUMLOCK: return "[NUMLOCK]"; break;
			case TK_SCROLL: return "[SCROLL]"; break;
			case TK_LSHIFT: return "[LSHIFT]"; break;
			case TK_RSHIFT: return "[RSHIFT]"; break;
			case TK_LCONTROL: return "[LCONTROL]"; break;
			case TK_RCONTROL: return "[RCONTROL]"; break;
			case TK_LALT: return "[LALT]"; break;
			case TK_RALT: return "[RALT]"; break;
			case TK_SEMICOLON: return "[SEMICOLON]"; break;
			case TK_EQUALS: return "[EQUALS]"; break;
			case TK_COMMA: return "[COMMA]"; break;
			case TK_MINUS: return "[MINUS]"; break;
			case TK_DOT: return "[DOT]"; break;
			case TK_SLASH: return "[SLASH]"; break;
			case TK_BACKTICK: return "[BACKTICK]"; break;
			case TK_LSQUARE: return "[LSQUARE]"; break;
			case TK_BACKSLASH: return "[BACKSLASH]"; break;
			case TK_RSQUARE: return "[RSQUARE]"; break;
			case TK_TICK: return "[TICK]"; break;
		}
	}
	return string;
}
int SKFromTK(int tk){
	if(tk < 58) return (tk - 48);
	else if(tk < 91) return (tk-54);
	else return(tk-92);
}
char CharFromSK(int sk){
	if(sk < 10) return (sk + 48);
	else if(sk < 36) return (sk + 55);
	else switch(sk){
		case 64: return 8; break;
		case 65: return '\t'; break;
		case 66: return '\n'; break;
		case 73: return ' '; break;
		case 94: return ';'; break;
		case 95: return '='; break;
		case 96: return ','; break;
		case 97: return '-'; break;
		case 98: return '.'; break;
		case 99: return '/'; break;
		case 100: return '`'; break;
		case 101: return '['; break;
		case 102: return '\\'; break;
		case 103: return ']'; break;
		case 104: return '\''; break; 
		default: return '\0'; break;
	}
}
int SKFromChar(char c){
	if(c < 58 && c >= 48) return (c - 48);
	else if(c < 91 && c >= 65) return (c - 55);
	else switch(c){
		case 8: return 64; break;
		case '\t': return 65; break;
		case '\n': return 66; break;
		case ' ': return 73; break;
		case ';': return 94; break;
		case '=': return 95; break;
		case ',': return 96; break;
		case '-': return 97; break;
		case '.': return 98; break;
		case '/': return 99; break;
		case '`': return 100; break;
		case '[': return 101; break;
		case '\\': return 102; break;
		case ']': return 103; break;
		case '\'': return 104; break; 
		default: return 0; break;
	}
}
int TKFromSK(int sk){
	if(sk < 10 && sk >= 0) return (sk + 48);
	else if(sk < 36 && sk >= 10) return (sk + 55);
	else return (sk + 92);
}
#endif
