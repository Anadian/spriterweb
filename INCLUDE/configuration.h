// configuration.h

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#ifdef __cplusplus
extern "C" {
#endif

//#include <stdio.h>

typedef struct ConfigurationVideo_struct {unsigned long xpos;
	unsigned long ypos;
	unsigned short resolution; //refer to resolution file.
	unsigned long width;
	unsigned long height;
	unsigned short fullscreen;
	unsigned short refresh;} ConfigurationVideo_type;
typedef struct ConfigurationAudio_struct {unsigned short bgmvolume;
	unsigned short sfxvolume;
	unsigned long bitrate;} ConfigurationAudio_type;
typedef struct ConfigurationInterface_strcut {float initialselectionchangedelay;
	float selectionchangerate;} ConfigurationInterface_type;
typedef struct ConfigurationControls_struct {
	float joystickdeadzone; //0.125
	unsigned short thirdpersoncameraspeed;
	unsigned short thirdpersoncamerax;
	unsigned short thirdpersoncameray;
	unsigned short firstpersoncameraspeed;
	unsigned short firstpersoncamerax;
	unsigned short firstpersoncameray;
	unsigned short crouch;
	unsigned short firstpersonview;} ConfigurationControls_type;
typedef struct ConfigurationDebug_struct {unsigned short verbosity;
	unsigned short savepreviouslogs;} ConfigurationDebug_type;
typedef struct ConfigurationFile_struct {ConfigurationVideo_type video;
	ConfigurationAudio_type audio;
	ConfigurationInterface_type interface;
	ConfigurationControls_type controls;
	ConfigurationDebug_type debug;} ConfigurationFile_type;
ConfigurationFile_type Configuration;

int SaveConfiguration(char *configfilename);
int LoadConfiguration(char *configfilename);
int CreateNewConfiguration(char *configfilename);

#ifdef __cplusplus
}
#endif

#endif //CONFIGURATION_H