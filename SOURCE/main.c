#include <stdio.h>
#include <string.h>
#include <unistd.h> //access, getopt
#include <getopt.h> //getopt_long
//#include <lua.h>
//#include <lauxlib.h> //Lua Auxiliary
//#include <lualib.h> //Lua Libraries

#include "build.h"

#include <pthread.h> //POSIX Multi-thread library
#include "logic_main.h"

#if USE_SDL2
#include <SDL2/sdl.h> //SDL2
#elif USE_GLFW3
#include <GLFW/glfw3.h> //GLFW3
#elif USE_ALLEGRO5
#include <allegro5/allegro.h> //Allegro5
#endif

#include "test.h"
#include "state.h"
#include "configuration.h"
#include "delog.h"
#include "input.h"
#include "actions.h"
#include "video.h"

// Index test
//#include "index.h"


int main(int argc, char *argv[]){
	struct option long_options[] = {
		{"help", no_argument, 0, 'h'},
		{"verbose", optional_argument, 0, 'v'},
		{"config", required_argument, 0, 'c'},
		{"actions", required_argument, 0, 'a'},
		{"version", no_argument, 0, 'V'},
		{0,0,0,0}};
	
	//Process shell arguments
	char configfilename[64] = "CONFIG/config.current.ini";
	char actionsfilename[64] = "CONFIG/input.current.ini";
	printf("%d arguments:\n",argc);
	char c;
	int long_option_index;
	while((c = getopt_long(argc,argv,"hVv::c:a:", long_options, &long_option_index) != -1)){
		switch(c){
			case 'h':
				printf("Available options:\n\t\
						-h, --help\t Display this help message.\n\t\
						-v [uint], --verbose [uint]\t Set verbosity to unsigned integer uint; 0 is equivalent to silent.\n\t\
						-V, --version\t Display version information.\n\t\
						-c [file], --config [file]\t Use file for config file; defaults to ./CONFIG/config.current.ini.\n\t\
						-a [file], --actions [file]\t Use file for actions file; defaults to ./CONFIG/input.current.ini.\n");
				break;
			case 'V': 
				printf("v%d.%d Built on %s at %s (%s)\n", VERSION_MAJOR, VERSION_MINOR, BUILD_DATE, BUILD_TIME, __STDC_VERSION__);
				break;
			case 'v': break;
			case 'c':
				strcpy(configfilename,optarg);
				break;
			case 'a':
				strcpy(actionsfilename,optarg);
			default:
				break;
		}
	}
	printf("testval: %d sizeof float: %d sizeof double: %d\n", testval, sizeof(float), sizeof(double));
	
	//Load configuration
	if(access(configfilename,F_OK) == 0) LoadConfiguration(configfilename);
	else if(access("CONFIG/config.current.ini",F_OK) == 0) LoadConfiguration("CONFIG/config.current.ini");
	else{
		CreateNewConfiguration("CONFIG/config.default.ini");
		LoadConfiguration("CONFIG/config.default.ini");
		SaveConfiguration("CONFIG/config.current.ini");
	}
	//Load actions
	if(access(actionsfilename,F_OK) == 0) LoadActions(actionsfilename);
	else if(access("CONFIG/input.current.ini",F_OK) == 0) LoadActions("CONFIG/input.current.ini");
	else{
		CreateNewActions("CONFIG/input.default.ini");
		LoadActions("CONFIG/input.default.ini");
		SaveActions("CONFIG/input.current.ini");
	}
	
	CreateNewLog();
	
	//Init Lua (moved to logic thread)
	// char buffer[256];
// 	lua_State *L = luaL_newstate();
// 	double *version;
// 	version = lua_version(L);
// 	luaL_openlibs(L);
// 	printf("Lua: %f\n", *version);
	
	pthread_t logic_thread;
	
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
#elif USE_ALLEGRO5
	//Init Allegro5
	al_init();
	printl(1, "Allegro: %d", ALLEGRO_VERSION_INT);
#endif
	
	//Init Custom Code
	CriticalVariables.AppRunning = 1;
	CriticalVariables.MainThread = 0;
	CriticalVariables.LogicThread = 0;
	
	pthread_create(&logic_thread, NULL, LogicMain, NULL);
	
	InitVideo();
	InitInput();
	
	CriticalVariables.MainThread = 1;
	
	while(CriticalVariables.AppRunning == 1){
		//Input (input/video thread)
		Input();
		//printf("Point.x:%f Point.y:%f Point.z:%f\n", Points.pos.x, Points.pos.y, Points.pos.z);
		//Logic (logic/player thread)
		//Video (input/video thread)
		Video();
		//FileIO (fileIO thread)
		//State (logic/player thread)
	}
	printf("Exiting cleanly.\n");
	
	QuitInput();
	QuitVideo();
	SaveConfiguration("current.ini");
#if USE_SDL2
	SDL_Quit();
#elif USE_GLFW3
	glfwTerminate();
#endif// 
// 	lua_close(L);
	QuitDelog();
	
	CriticalVariables.MainThread = 2;
	printf("Main thread terminating\n");
	pthread_join(logic_thread, NULL);
	//TerminateThread("Logic");
	
	//ThreadQuit();
	
	return 0;
}