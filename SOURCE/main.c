#include <stdlib.h> //exit, atexit
#include <stdio.h>
#include <string.h>
#include <getopt.h> //getopt_long

#if USE_GLFW3
#include <GLFW/glfw3.h> //GLFW3
#elif USE_ALLEGRO5
#include <allegro5/allegro.h> //Allegro5
#endif

#include "build.h"
#include "test.h"
#include "configuration.h"
#include "delog.h"
#include "actions.h"
#include "middleware.h"
#include "state.h"
#include "unit.h"
#include "kairos.h"
#include "input.h"
#include "video.h"
#include "logic_main.h"


int main(int argc, char *argv[]){
	static struct option long_options[] = {
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
	long_option_index = 0;
	while( ((c = getopt_long(argc,argv,"hVc:a:v::", long_options, &long_option_index)) != -1) && (c != 255)){
		printf("%c %d\n", c, c);
		switch(c){
			case 'h':
printf("Available options:\n\
	-h, --help\t Display this help message.\n\
	-v [uint], --verbose [uint]\t Set verbosity to unsigned integer uint; 0 is equivalent to silent.\n\
	-V, --version\t Display version information.\n\
	-c [file], --config [file]\t Use file for config file; defaults to ./CONFIG/config.current.ini.\n\
	-a [file], --actions [file]\t Use file for actions file; defaults to ./CONFIG/input.current.ini.\n");
				break;
			case 'V': 
				printf("v%d.%d %s: built on %s at %s\n", VERSION_MAJOR, VERSION_MINOR, BUILD_NAME, BUILD_DATE, BUILD_TIME);
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
	if(LoadConfiguration(configfilename)){
		if(LoadConfiguration("CONFIG/config.current.ini")){
			CreateNewConfiguration("CONFIG/config.default.ini");
			LoadConfiguration("CONFIG/config.default.ini");
			SaveConfiguration("CONFIG/config.current.ini");
		}
	}
	//Load actions
	if(LoadActions(actionsfilename)){
		if(LoadActions("CONFIG/input.current.ini")){
			CreateNewActions("CONFIG/input.default.ini");
			LoadActions("CONFIG/input.default.ini");
			SaveActions("CONFIG/input.current.ini");
		}
	}
	
	int i;
	for(i = 0; i < Numberofmutexes; i++){
		CreateMutex(i)
	}
	CreateNewLog();
	InitMiddleWare();

	InitVideo();
	InitInput();

#if USE_GLFW3
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
	
	Thread_type LogicThread;
	LogicThread = CreateThread(LogicThread,LogicMain)
	
	int font;
	font = LoadFont("Resources/FSMR.ttf", 16);
	int image;
	image = LoadImage("Resources/C3P1.png");
	
	CriticalVariables.MainFrame = 0;
	CriticalVariables.MainThread = 1;
	Timer_type FrameTimer;
	while(CriticalVariables.AppRunning == 1){
		printl(5, "MainFrame: %d Split: %d FPS: %f", CriticalVariables.MainFrame, CriticalVariables.MainSplit, (float)(1000/((CriticalVariables.MainSplit>0)?CriticalVariables.MainSplit:1)));
		ResetTimer(&FrameTimer);
		//usleep(2000000);
		//Input (input/video thread)
		Input();
		//printf("Point.x:%f Point.y:%f Point.z:%f\n", Points.pos.x, Points.pos.y, Points.pos.z);
		//Logic (logic/player thread)
		//Video (input/video thread)
		LockMutex(BlitsMutex)
		ClearBlits();
		AddBlit(image, 0, 0, 0, 0, 0);
		UnlockMutex(BlitsMutex)
		Video();
		//FileIO (fileIO thread)
		//State (logic/player thread)
		CriticalVariables.MainFrame++;
		CriticalVariables.MainSplit = GetTicks(&FrameTimer);
	}
	printf("Exiting cleanly.\n");
	
	JoinThread(LogicThread)
	
	ClearBlits();
	ClearFonts();
	ClearImages();
	QuitInput();
	QuitVideo();
	QuitMiddleWare();
	//SaveConfiguration("current.ini");

#if USE_GLFW3
	glfwTerminate();
#endif// 
// 	lua_close(L);
	QuitDelog();
	for(i = 0; i < Numberofmutexes; i++){
		DestroyMutex(i)
	}
	
	CriticalVariables.MainThread = 2;
	printf("Main thread terminating\n");
	
	exit(EXIT_SUCCESS);
}
