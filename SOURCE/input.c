// input.c
#include "input.h"
#include <stdio.h>
#include "video.h"

#if USE_SDL2

#include <SDL2/sdl.h>

#elif USE_GLFW3

GLFWwindow *window_ptr;
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

#endif

#include <stdio.h>
#include "state.h"

int InitInput(){
#if USE_GLFW3

	window_ptr = GetWindow();
	glfwSetKeyCallback(window_ptr, KeyCallback);

#endif
	return 0;
}

int Input(){
#if USE_SDL2
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT: 
				printf("SDL Quit after %d ticks", event.quit.timestamp);
				CriticalVariables.AppRunning = 0;
				break;
			default:
				break;
		}
	}
#elif USE_GLFW3
	glfwPollEvents();
	if(glfwWindowShouldClose(window_ptr)){
		CriticalVariables.AppRunning = 0;
	}
#endif
	return 0;
}

#if USE_GLFW3
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
	if(action == GLFW_PRESS){
		printf("key: %d + %d at %f\n", key, mods, glfwGetTime());
		/*switch(key){
			case GLFW_KEY_UP: Asteriods_Thrust = 1; break;
			case GLFW_KEY_LEFT: Asteriods_TurnLeft = 1; break;
			case GLFW_KEY_RIGHT: Asteriods_TurnRight = 1; break;
		}*/
		
	}
	else if(action == GLFW_RELEASE){
		/*switch(key){
			case GLFW_KEY_UP: Asteriods_Thrust = 0; break;
			case GLFW_KEY_LEFT: Asteriods_TurnLeft = 0; break;
			case GLFW_KEY_RIGHT: Asteriods_TurnRight = 0; break;
		}*/
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
	
#endif