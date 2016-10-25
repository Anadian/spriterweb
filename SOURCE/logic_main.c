// Logic_Main.c

#include "logic_main.h"
#include <unistd.h> //usleep
#include <stdio.h> //printf
#include "delog.h"

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "video.h"
#include "input.h"
#include "actions.h"
#include "kairos.h"
#include "unit.h"
#include "parson.h"

ThreadFunction_type *LogicMain(void *arg){
	CriticalVariables.LogicThread = 1;
	
	//Init Lua
	char buffer[256];
	lua_State *L = luaL_newstate();
	double *version;
	//version = lua_version(L);
	luaL_openlibs(L);
	//printl(5, "Lua: %f", *version);
	
	printl(5, "Lual_loadfile: %d %d %d %d", luaL_loadfile(L, "./SCRIPT/init.lua"), LUA_ERRSYNTAX, LUA_ERRMEM, LUA_ERRFILE);
	printl(5, "Lual_pcall: %d", lua_pcall(L, 0, 0, 0));
	//luaL_loadfile(L, "./SCRIPT/main.lua");
	int colour;
	colour = AddColour(255,0,0,0);
	int x, y, w, h;
	x = 0;
	y = 0;
	w = 32;
	h = 32; 
	
	JSON_Value *root_value;
	root_value = json_value_init_array();
	JSON_Array *json_array;
	json_array = json_value_get_array(root_value);
	
	CriticalVariables.LogicFrame = 0;
	Timer_type FrameTimer;
	while(CriticalVariables.AppRunning == 1){
		printl(5, "LogicFrame: %d LogicSplit: %d", CriticalVariables.LogicFrame, CriticalVariables.LogicSplit);
		ResetTimer(&FrameTimer);
		//pthread_mutex_lock(&(CriticalVariables.ActionsMutex));
		//usleep(5000000);
		LockMutex(ActionsMutex)
		if(Action(Up) > 0) h--;
		if(Action(Down) > 0) h++;
		if(Action(Left) > 0) w--;
		if(Action(Right) > 0) w++;
		if(Action(Accept) == 1){
			JSON_Object *object;
			json_object_set_number(object, "x", x);
			json_object_set_number(object, "y", y);
			json_object_set_number(object, "w", w);
			json_object_set_number(object, "h", h);
			//json_array_append_value(json_array, json_object_get_value(object));
		}
		UnlockMutex(ActionsMutex)
		
		LockMutex(RenderMutex)
		ClearRenderRects();
		AddRenderPoint(MouseX,MouseY,colour);
		AddRenderRect(x, y, w, h, 0, colour);
		UnlockMutex(RenderMutex)
		CriticalVariables.LogicFrame++;
		CriticalVariables.LogicSplit = GetTicks(&FrameTimer);
	}
	
	json_serialize_to_file_pretty(root_value, "yo.json");
	json_array_clear(json_array);
	json_value_free(root_value);
	
	ClearRenderPoints();
	ClearRenderRects();
	ClearColours();
	
	luaL_dofile(L, "./SCRIPT/quit.lua");
	lua_close(L);
	
	CriticalVariables.LogicThread = 2;
	printl(5,"Logic thread teminated");
	return NULL;
}
