#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <SDL2/sdl.h>

#include <Irrlicht/irrlicht.h>

#include "test.h"
#include "state.h"
#include "configuration.h"
#include "input.h"
#include "video.h"

using namespace irr;

int main(int argc, char *argv[]){
	//Process shell arguments
	char configfilename[16] = "default.ini";
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
	printf("testval: %d\n", testval);
	
	//Init libconfig
	/*printf("libconfig: %d.%d.%d\n",LIBCONFIG_VER_MAJOR,LIBCONFIG_VER_MINOR,LIBCONFIG_VER_REVISION);
	config_t ConfigFile;
	config_init(&ConfigFile);
	char *configfilename;
	if(config_read_file(&ConfigFile,"appname.cfg") == CONFIG_TRUE){
		int ver_major, ver_minor;
		config_lookup_int(&ConfigFile,"ver_major",&ver_major);
		config_lookup_int(&ConfigFile,"ver_minor",&ver_minor);
		
		config_lookup_string(&ConfigFile,"configfilename",&configfilename);
		printf("Software version: %d.%d\n", ver_major,ver_minor);
	}
	char *configfilename_localcopy;
	strcpy(configfilename_localcopy,configfilename);
	config_destroy(&ConfigFile);*/
	
	if(access(configfilename,F_OK) == 0) LoadConfiguration(configfilename);
	else{
		CreateNewConfiguration("default.ini");
		LoadConfiguration("default.ini");
	}
	
	//Init Lua
	char buffer[256];
	lua_State *L = luaL_newstate();
	const double *version = lua_version(L);
	printf("Lua: %f\n", *version);
	
	//Init SDL2
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_version compiled, linked;
	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printf("SDL: %d.%d.%d. (compiled) %d.%d.%d. (linked)\n", compiled.major, compiled.minor, compiled.patch, linked.major, linked.minor, linked.patch);
	
	//Init Irrlicht
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL,core::dimension2d<u32>(640,480));
	
	//Init Custom Code
	CriticalVariables.AppRunning = 1;
	
	/*if(strcmp(configfilename,"default.cfg") == 0) CriticalVariables.ConfigurationMode = 1; // do something with this.
	else CriticalVariables.ConfigurationMode = 0;*/
	
	InitVideo();
	
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
	
	device->drop();
	
	QuitVideo();
	
	SDL_Quit();	
	lua_close(L);
	return 0;
}