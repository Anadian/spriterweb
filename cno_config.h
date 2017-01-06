#ifndef CNO_CONFIG_H
#define CNO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include <cno_build.h>

char *CNO_LowLevelConfig_Directories_a1[] = {"/etc","/usr/etc","/usr/local/etc","~/.config","~/Library/Application Support","./"};

typedef struct CNO_LowLevelConfig_struct {
	cno_u8_type audio;
	cno_u8_type threads;
	cno_u8_type windows;
	cno_u8_type debug;
} CNO_LowLevelConfig_type;

cno_u8_type CNO_LowLevelConfig_Getaudio();
cno_u8_type CNO_LowLevelConfig_Setaudio(cno_u8_type audio);
cno_u8_type CNO_LowLevelConfig_Getthreads();
cno_u8_type CNO_LowLevelConfig_Setthreads(cno_u8_type threads);
cno_u8_type CNO_LowLevelConfig_Getwindows();
cno_u8_type CNO_LowLevelConfig_Setwindows(cno_u8_type windows);
cno_u8_type CNO_LowLevelConfig_Getdebug();
cno_u8_type CNO_LowLevelConfig_Setdebug(cno_u8_type debug);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_CONFIG_H
