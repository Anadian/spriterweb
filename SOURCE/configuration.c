// configuration.c
#include "configuration.h"

#include "ini.h"
#include <string.h>
#include <stdlib.h>

int UpdateMostRecent(char *configfilename);

static int handler(void* user, const char* section, const char* name, const char* value){
    ConfigurationFile_type *pconfig = (ConfigurationFile_type*)user;
	
	if(strcmp(section,"video") == 0){
		if(strcmp(name,"xpos") == 0) pconfig->video.xpos = atol(value);
		else if(strcmp(name,"ypos") == 0) pconfig->video.ypos = atol(value);
		else if(strcmp(name,"resolution") == 0) pconfig->video.resolution = atol(value);
		else if(strcmp(name,"width") == 0) pconfig->video.width = atol(value);
		else if(strcmp(name,"height") == 0) pconfig->video.height = atol(value);
		else if(strcmp(name,"fullscreen") == 0) pconfig->video.fullscreen = atol(value);
		else if(strcmp(name,"refresh") == 0) pconfig->video.refresh = atol(value);
	} else if(strcmp(section,"audio") == 0){
		if(strcmp(name,"bgmvolume") == 0) pconfig->audio.bgmvolume = atol(value);
		else if(strcmp(name,"sfxvolume") == 0) pconfig->audio.sfxvolume = atol(value);
		else if(strcmp(name,"bitrate") == 0) pconfig->audio.bitrate = atol(value);
	} else if(strcmp(section,"interface") == 0){
		if(strcmp(name,"initialselectionchangedelay") == 0) pconfig->interface.initialselectionchangedelay = atof(value);
		else if(strcmp(name,"selectionchangerate") == 0) pconfig->interface.selectionchangerate = atof(value);
	} else if(strcmp(section,"controls") == 0){
		if(strcmp(name,"thirdpersoncameraspeed") == 0) pconfig->controls.thirdpersoncameraspeed = atol(value);
		else if(strcmp(name,"thirdpersoncamerax") == 0) pconfig->controls.thirdpersoncamerax = atol(value);
		else if(strcmp(name,"thridpersoncameray") == 0) pconfig->controls.thirdpersoncameray = atol(value);
		else if(strcmp(name,"firstpersoncameraspeed") == 0) pconfig->controls.firstpersoncameraspeed = atol(value);
		else if(strcmp(name,"firstpersoncamerax") == 0) pconfig->controls.firstpersoncamerax = atol(value);
		else if(strcmp(name,"firstpersoncameray") == 0) pconfig->controls.firstpersoncameray = atol(value);
		else if(strcmp(name,"crouch") == 0) pconfig->controls.crouch = atol(value);
		else if(strcmp(name,"firstpersonview") == 0) pconfig->controls.firstpersonview = atol(value);
	} else if(strcmp(section,"debug") == 0){
		if(strcmp(name,"verbosity") == 0) pconfig->debug.verbosity = atol(value);
		else if(strcmp(name,"savepreviouslogs") == 0) pconfig->debug.savepreviouslogs = atol(value);
	} else return 0;
    return 1;
}

int SaveConfiguration(char *configfilename){
	FILE *configfile = fopen(configfilename,"w+");
	char buffer[256];//char buffer[strlen(configfilename)+1];
	sprintf(buffer, ";%s\n", configfilename);
	fputs(buffer, configfile);
	fputs("[video]\n", configfile);
	sprintf(buffer, "xpos=%d\t;The X position of the window in windowed mode. Set to -1 to centre the window.\n", Configuration.video.xpos);
	fputs(buffer, configfile);
	sprintf(buffer, "ypos=%d\t;The Y position of the window in windowed mode. Set to -1 to centre the window.\n", Configuration.video.ypos);
	fputs(buffer, configfile);
	sprintf(buffer, "resolution=%d\t;The window/display resolution. 0 = custom (resizable window), 1 = native (desktop resolurion) and [2,21] being listed in \"resolutionlist.txt\".\n", Configuration.video.resolution);
	fputs(buffer, configfile);
	sprintf(buffer, "width=%d\t;The width (horizontal resolution) of the window in windowed mode.\n", Configuration.video.width);
	fputs(buffer, configfile);
	sprintf(buffer, "height=%d\t;The height (vertical resolution) of the window in windowed mode.\n", Configuration.video.height);
	fputs(buffer, configfile);
	sprintf(buffer, "fullscreen=%d\t;Determines whether to display in fullscreen or not. 0 = windowed mode 1 = fullscreen.\n", Configuration.video.fullscreen);
	fputs(buffer, configfile);
	sprintf(buffer, "refresh=%d\t;The refresh rate (also known as frame rate or frames per second) normal values are 30 Hz, 60 Hz, or 120 Hz (without the units obviously).\n", Configuration.video.refresh);
	fputs(buffer, configfile);
	fputs("[audio]\n",configfile);
	sprintf(buffer, "bgmvolume=%d\t;The music volume [0,255] with 0 being mute and 255 being the loudest volume.\n", Configuration.audio.bgmvolume);
	fputs(buffer, configfile);
	sprintf(buffer, "sfxvolume=%d\t;The sound effect volume [0,255] with 0 being mute and 255 being the loudest volume.\n", Configuration.audio.sfxvolume);
	fputs(buffer, configfile);
	sprintf(buffer, "bitrate=%d\t;The bitrate for all audio (only change if you need to).\n", Configuration.audio.bitrate);
	fputs(buffer, configfile);
	fputs("[interface]\n",configfile);
	sprintf(buffer, "initialselectionchangedelay=%f\t;The time (in seconds) until the selection cursor on a menu begins moving continuously after you initial pressed the key to move it.\n", Configuration.interface.initialselectionchangedelay);
	fputs(buffer, configfile);
	sprintf(buffer, "selectionchangerate=%f\t;The rate at which the selection cursor on a menu moves (represented as time, in seconds, between changes here) once the cursor as entered continuous movement.\n", Configuration.interface.selectionchangerate);
	fputs(buffer, configfile);
	fputs("[controls]\n",configfile);
	sprintf(buffer, "thirdpersoncameraspeed=%d\t;The speed at which the camera moves while in a third person view. 0 being the slowest and 10 being the fastest.\n", Configuration.controls.thirdpersoncameraspeed);
	fputs(buffer, configfile);
	sprintf(buffer, "thirdpersoncamerax=%d\t;Determines whether the x-axis of the camera is inverted while in a third person view. 0 for \"normal\" and 1 for inverted.\n", Configuration.controls.thirdpersoncamerax);
	fputs(buffer, configfile);
	sprintf(buffer, "thirdpersoncameray=%d\t;Determines whether the y-axis of the camera is inverted while in a third person view. 0 for \"normal\" and 1 for inverted.\n", Configuration.controls.thirdpersoncameray);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersoncameraspeed=%d\t;The speed at which the camera (/the sensitivity at which the reticle) moves while in a first person view. 0 being the slowest and 10 being the fastest.\n", Configuration.controls.firstpersoncameraspeed);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersoncamerax=%d\t;Determines whether the x-axis of the camera is inverted while in a first person view. 0 for \"normal\" and 1 for inverted.\n", Configuration.controls.firstpersoncamerax);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersoncameray=%d\t;Determines whether the y-axis of the camera is inverted while in a first person view. 0 for \"normal\" and 1 for inverted.\n", Configuration.controls.firstpersoncameray);
	fputs(buffer, configfile);
	sprintf(buffer, "crouch=%d\t;Determines whether you press a key to toggle crouching or hold a key to crouch. 0 for toggle and 1 for hold.\n", Configuration.controls.crouch);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersonview=%d\t;Determines whether you press a key to toggle first person view or hold a key to remain in first person view. 0 for toggle and 1 for hold.\n", Configuration.controls.firstpersonview);
	fputs(buffer, configfile);
	fputs("[debug]\n",configfile);
	sprintf(buffer, "verbosity=%d\t;Determines how verbose log messages are. 0 = no logging at all, [1,5] = messages of varying importance: 1 being \"only very important messages\" to 5 being \"every message will be logged\".\n", Configuration.debug.verbosity);
	fputs(buffer, configfile);
	sprintf(buffer, "savepreviouslogs=%d\t;0 = previous log files will automatically be overwritten on start up, 1 = previous log files will be preserved.\n", Configuration.debug.savepreviouslogs);
	fputs(buffer, configfile);
	
	fclose(configfile);
	return 0;
}
int LoadConfiguration(char *configfilename){
	/*config_t ConfigFile;
	config_init(&ConfigFile);
	char *configfilename_localcopy;
	strcpy(configfilename_localcopy,configfilename);
	printf("In LoadConfiguration, configfilename: %s\n", configfilename_localcopy);
	if(config_read_file(&ConfigFile, configfilename_localcopy) == CONFIG_TRUE){
		printf("File read okay\n");
		config_lookup_int(&ConfigFile,"video.xpos",&(Configuration.Video.xpos));
		config_lookup_int(&ConfigFile,"video.ypos",&(Configuration.Video.ypos));
		config_lookup_int(&ConfigFile,"video.width",&(Configuration.Video.width));
		//printf("Video.width: %d\n", Configuration.Video.width);
		config_lookup_int(&ConfigFile,"video.height",&(Configuration.Video.height));
		config_lookup_int(&ConfigFile,"video.fullscreen",&(Configuration.Video.fullscreen));
		config_destroy(&ConfigFile);
		printf("Result of UpdateMostRecent: %d\n", UpdateMostRecent(configfilename_localcopy));
		return 0;
	} else{
		printf("File read not okay\n");
		config_destroy(&ConfigFile);
		return -1;
	}*/
	printf("Loading: %s\n", configfilename);
	return ini_parse(configfilename,handler,&Configuration);
}
int CreateNewConfiguration(char *configfilename){
	FILE *configfile = fopen(configfilename,"w+");
	char buffer[256];//char buffer[strlen(configfilename)+1];
	sprintf(buffer, ";%s\n", configfilename);
	fputs(buffer, configfile);
	fputs("[video]\n", configfile);
	sprintf(buffer, "xpos=%d\t;The X position of the window in windowed mode. Set to -1 to centre the window.\n", -1);
	fputs(buffer, configfile);
	sprintf(buffer, "ypos=%d\t;The Y position of the window in windowed mode. Set to -1 to centre the window.\n", -1);
	fputs(buffer, configfile);
	sprintf(buffer, "resolution=%d\t;The window/display resolution. 0 = custom (resizable window), 1 = native (desktop resolurion) and [2,21] being listed in \"resolutionlist.txt\".\n", 0);
	fputs(buffer, configfile);
	sprintf(buffer, "width=%d\t;The width (horizontal resolution) of the window in windowed mode.\n", 640);
	fputs(buffer, configfile);
	sprintf(buffer, "height=%d\t;The height (vertical resolution) of the window in windowed mode.\n", 480);
	fputs(buffer, configfile);
	sprintf(buffer, "fullscreen=%d\t;Determines whether to display in fullscreen or not. 0 = windowed mode 1 = fullscreen.\n", 0);
	fputs(buffer, configfile);
	sprintf(buffer, "refresh=%d\t;The refresh rate (also known as frame rate or frames per second) normal values are 30 Hz, 60 Hz, or 120 Hz (without the units obviously).\n", 60);
	fputs(buffer, configfile);
	fputs("[audio]\n",configfile);
	sprintf(buffer, "bgmvolume=%d\t;The music volume [0,255] with 0 being mute and 255 being the loudest volume.\n", 255);
	fputs(buffer, configfile);
	sprintf(buffer, "sfxvolume=%d\t;The sound effect volume [0,255] with 0 being mute and 255 being the loudest volume.\n", 255);
	fputs(buffer, configfile);
	sprintf(buffer, "bitrate=%d\t;The bitrate for all audio (only change if you need to).\n", 48000);
	fputs(buffer, configfile);
	fputs("[interface]\n",configfile);
	sprintf(buffer, "initialselectionchangedelay=%f\t;The time (in seconds) until the selection cursor on a menu begins moving continuously after you initial pressed the key to move it.\n", 0.5);
	fputs(buffer, configfile);
	sprintf(buffer, "selectionchangerate=%f\t;The rate at which the selection cursor on a menu moves (represented as time, in seconds, between changes here) once the cursor as entered continuous movement.\n", 0.2);
	fputs(buffer, configfile);
	fputs("[controls]\n",configfile);
	sprintf(buffer, "thirdpersoncameraspeed=%d\t;The speed at which the camera moves while in a third person view. 0 being the slowest and 10 being the fastest.\n", 5);
	fputs(buffer, configfile);
	sprintf(buffer, "thirdpersoncamerax=%d\t;Determines whether the x-axis of the camera is inverted while in a third person view. 0 for \"normal\" and 1 for inverted.\n", 1);
	fputs(buffer, configfile);
	sprintf(buffer, "thirdpersoncameray=%d\t;Determines whether the y-axis of the camera is inverted while in a third person view. 0 for \"normal\" and 1 for inverted.\n", 1);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersoncameraspeed=%d\t;The speed at which the camera (/the sensitivity at which the reticle) moves while in a first person view. 0 being the slowest and 10 being the fastest.\n", 5);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersoncamerax=%d\t;Determines whether the x-axis of the camera is inverted while in a first person view. 0 for \"normal\" and 1 for inverted.\n", 0);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersoncameray=%d\t;Determines whether the y-axis of the camera is inverted while in a first person view. 0 for \"normal\" and 1 for inverted.\n", 0);
	fputs(buffer, configfile);
	sprintf(buffer, "crouch=%d\t;Determines whether you press a key to toggle crouching or hold a key to crouch. 0 for toggle and 1 for hold.\n", 0);
	fputs(buffer, configfile);
	sprintf(buffer, "firstpersonview=%d\t;Determines whether you press a key to toggle first person view or hold a key to remain in first person view. 0 for toggle and 1 for hold.\n", 1);
	fputs(buffer, configfile);
	fputs("[debug]\n",configfile);
	sprintf(buffer, "verbosity=%d\t;Determines how verbose log messages are. 0 = no logging at all, [1,5] = messages of varying importance: 1 being \"only very important messages\" to 5 being \"every message will be logged\".\n", 5);
	fputs(buffer, configfile);
	sprintf(buffer, "savepreviouslogs=%d\t;0 = previous log files will automatically be overwritten on start up, 1 = previous log files will be preserved.\n", 0);
	fputs(buffer, configfile);
	
	fclose(configfile);
	return 0;
}
int UpdateMostRecent(char *configfilename){
	/*config_t ConfigFile;
	config_init(&ConfigFile);
	if(config_read_file(&ConfigFile, "appname.cfg") == CONFIG_TRUE){
		config_setting_set_string(config_lookup(&ConfigFile,"configfilename"),configfilename);
		config_destroy(&ConfigFile);
		return 0;
	} else{
		config_destroy(&ConfigFile);
		return -1;
	}*/
}