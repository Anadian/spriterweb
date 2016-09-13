// configure.h

#ifndef CONFIGURE_H
#define CONFIGURE_H

typedef struct ConfigurationVideo_struct = {unsigned long xpos;
	unsigned long ypos;
	unsigned long width;
	unsigned long height;
	unsigned short fullscreen;} ConfigurationVideo_type;
typedef struct ConfigurationFile_struct = {ConfigurationVideo_type Video;} ConfigurationFile_type;

int SaveConfiguration(char *configfilename);
int LoadConfiguration(char *configfilename);
int CreateNewConfiguration(char *configfilename);

#endif