#ifndef CNO_CONFIG_H
#define CNO_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include <cno_build.h>

char *CNO_LowLevelConfig_Directories_a1[] = {"/etc","/usr/etc","/usr/local/etc","~/.config","~/Library/Application Support","./config"};

typedef struct CNO_LowLevelConfig_struct {
	cno_u8_type audio;
	cno_u8_type threads;
	cno_u8_type windows;
	cno_u8_type debug;
} CNO_LowLevelConfig_type;

cno_u8_type CNO_LowLevelConfig_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_CONFIG_H
