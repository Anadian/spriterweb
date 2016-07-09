#include <stdio.h>
#include <string.h>
#include <unistd.h> //access
#include <lua.h>
#include <lauxlib.h> //Lua Auxiliary
#include <lualib.h> //Lua Libraries

#include "build.h"

//#include <pthread.h> //POSIX Multi-thread library
//#include "logic_main.h"

#if USE_SDL2
#include <SDL2/sdl.h> //SDL2
#elif USE_GLFW3
#include <GLFW/glfw3.h> //GLFW3
#endif

#include "test.h"
#include "state.h"
#include "configuration.h"
#include "delog.h"
#include "input.h"
#include "video.h"

// Index test
//#include "index.h"


int main(int argc, char *argv[]){
	//Process shell arguments
	char configfilename[16] = "current.ini";
	printf("%d arguments:\n",argc);
	int i;
	for(i=0;i<argc;i++){
		printf("%s\n",argv[i]);
		//if(strncmp(argv[i],"--configfilename=",17) == 0) strcpy(configfilename,((strstr(argv[i],"=")-argv[i])+1));
		if(strncmp(argv[i],"--configfilename=",17) == 0){
			//printf("Conditional true\n");
			char *substring = strstr(argv[i],"=");
			//printf("substring: %s\n", substring);
			char *augmentedsubstring = (substring)+1;
			//printf("augmentedsubstring: %s\n", augmentedsubstring);
			strcpy(configfilename,augmentedsubstring);
			//printf("configfilename: %s\n", configfilename);
		}
	}
	printf("testval: %d sizeof float: %d sizeof double: %d\n", testval, sizeof(float), sizeof(double));
	
	//Load configuration
	if(access(configfilename,F_OK) == 0) LoadConfiguration(configfilename);
	else if(access("current.ini",F_OK) == 0) LoadConfiguration("current.ini");
	else{
		CreateNewConfiguration("default.ini");
		LoadConfiguration("default.ini");
		SaveConfiguration("current.ini");
	}
	
	CreateNewLog();
	
	//Init Lua
	char buffer[256];
	lua_State *L = luaL_newstate();
	double *version;
	version = lua_version(L);
	luaL_openlibs(L);
	printf("Lua: %f\n", *version);
	
	//pthread_t logic_thread;
	
#if USE_SDL2
	//Init SDL2
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_version compiled, linked;
	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printl(1, "SDL: %d.%d.%d. (compiled) %d.%d.%d. (linked)\n", compiled.major, compiled.minor, compiled.patch, linked.major, linked.minor, linked.patch);
#elif USE_GLFW3
	//Init GLFW3
	glfwInit();
	int major, minor, revision;
	glfwGetVersion(&major,&minor,&revision);
	printl(1, "GLFW: %d.%d.%d (compiled) %d.%d.%d (linked)\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION, major, minor, revision);
#endif
	
	//Init Custom Code
	CriticalVariables.AppRunning = 1;
	CriticalVariables.MainThread = 0;
	CriticalVariables.LogicThread = 0;
// 	
// 	double sampledouble;
// 	Index_type index;
// 	CreateIndex(&index, &sampledouble);
// 	PrintIndex(&index);
// 	sampledouble = 1.02;
// 	printf("First index id: %d\n", AddToIndex(&index, &sampledouble));
// 	sampledouble = 2.101;
// 	printf("Second index id: %d\n", AddToIndex(&index, &sampledouble));
// 	sampledouble = 3;
// 	GetObject(&index, 0, &sampledouble);
// 	printf("%u %lf,\n", GetObject(&index, 0, &sampledouble), sampledouble);
// 	GetObject(&index, 1, &sampledouble);
// 	printf("%u %lf\n", GetObject(&index, 1, &sampledouble), sampledouble);
// 	RemoveFromIndex(&index, 1);
// 	sampledouble = 4.441;
// 	AddToIndex(&index, &sampledouble);
// 	GetObject(&index, 0, &sampledouble);
// 	printf("%u %lf,\n", GetObject(&index, 0, &sampledouble), sampledouble);
// 	GetObject(&index, 1, &sampledouble);
// 	printf("%u %lf\n", GetObject(&index, 1, &sampledouble), sampledouble);
// 	DropIndex(&index);
	
	
	//ThreadInit();
	
	//CreateThread("Logic", LogicMain, NULL);
	
	/*if(strcmp(configfilename,"default.cfg") == 0) CriticalVariables.ConfigurationMode = 1; // do something with this.
	else CriticalVariables.ConfigurationMode = 0;*/
	
	InitVideo();
	InitInput();
	
	CriticalVariables.MainThread = 1;
	
	//pthread_create(&logic_thread, NULL, LogicMain, NULL);
	
	while(CriticalVariables.AppRunning == 1){
		//Input (input/video thread)
		Input();
		//Logic (logic/player thread)
		//Video (input/video thread)
		Video();
		//FileIO (fileIO thread)
		//State (logic/player thread)
	}
	printf("Exiting cleanly.\n");
	
	QuitVideo();
	SaveConfiguration("current.ini");
#if USE_SDL2
	SDL_Quit();
#elif USE_GLFW3
	glfwTerminate();
#endif
	lua_close(L);
	QuitDelog();
	
	CriticalVariables.MainThread = 2;
	printf("Main thread terminating\n");
	
	//TerminateThread("Logic");
	
	//ThreadQuit();
	
	return 0;
}