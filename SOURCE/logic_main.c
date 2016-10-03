// Logic_Main.c

#include "logic_main.h"
#include "state.h"
#include <unistd.h> //usleep
#include <stdio.h> //printf
#include "delog.h"

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "video.h"
#include "actions.h"

void *LogicMain(void *arg){
	CriticalVariables.LogicThread = 1;
	
	//Init Lua
	char buffer[256];
	lua_State *L = luaL_newstate();
	double *version;
	version = lua_version(L);
	luaL_openlibs(L);
	printl(5, "Lua: %f", *version);
	
	printl(5, "Lual_loadfile: %d %d %d %d", luaL_loadfile(L, "./SCRIPT/init.lua"), LUA_ERRSYNTAX, LUA_ERRMEM, LUA_ERRFILE);
	printl(5, "Lual_pcall: %d", lua_pcall(L, 0, 0, 0));
	//luaL_loadfile(L, "./SCRIPT/main.lua");
	int imageid;
	//imageid = WriteText("Blit test success.");
	int imagex;
	imagex = 10;
	int imagey;
	imagey = 10;
	
	int LogicFrame;
	LogicFrame = 0;
	while(CriticalVariables.AppRunning == 1){
		printl(5, "LogicFrame: %d", LogicFrame);
		//pthread_mutex_lock(&(CriticalVariables.ActionsMutex));
		//usleep(5000000);
		//Lock(Actions)
		if(Actions[Up].state > 0) imagey--;
		if(Actions[Down].state > 0) imagey++;
		if(Actions[Left].state > 0) imagex--;
		if(Actions[Right].state > 0) imagex++;
		/*Unlock(Actions)
		Lock(Blits)
		ClearBlits();
		AddBlit(imageid, 0, imagex, imagey);
		Unlock(Blits)
		//pthread_mutex_unlock(&(CriticalVariables.ActionsMutex));*/
		LogicFrame++;
	}
	
	luaL_dofile(L, "./SCRIPT/quit.lua");
	lua_close(L);
	
	CriticalVariables.LogicThread = 2;
	printl(5,"Logic thread teminated");
	return NULL;
}