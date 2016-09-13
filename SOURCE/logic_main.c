// Logic_Main.c

#include "logic_main.h"
#include "state.h"
#include <unistd.h> //usleep
#include <stdio.h> //printf

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

void *LogicMain(void *arg){
	CriticalVariables.LogicThread = 1;
	
	//Init Lua
	char buffer[256];
	lua_State *L = luaL_newstate();
	double *version;
	version = lua_version(L);
	luaL_openlibs(L);
	printf("Lua: %f\n", *version);
	
	printf("Lual_loadfile: %d %d %d %d\n", luaL_loadfile(L, "./SCRIPT/init.lua"), LUA_ERRSYNTAX, LUA_ERRMEM, LUA_ERRFILE);
	printf("Lual_pcall: %d\n", lua_pcall(L, 0, 0, 0));
	//luaL_loadfile(L, "./SCRIPT/main.lua");
	
	while(CriticalVariables.AppRunning == 1){
		usleep(5000000);
		printf("Logic thread running\n");
		luaL_dofile(L, "./SCRIPT/main.lua");
		//lua_pcall(L, 0, 0, 0);
	}
	
	luaL_dofile(L, "./SCRIPT/quit.lua");
	lua_close(L);
	
	CriticalVariables.LogicThread = 2;
	printf("Logic thread teminated\n");
	return NULL;
}