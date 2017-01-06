//cno_environment.h

#ifndef CNO_ENVIRONMENT_H
#define CNO_ENVIRONMENT_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"
#include "cno_config.h"

typedef CNO_Environment_struct {
	cno_u8 username[16];
	cno_u8 hostname[16];
	cnu_u8 pwd[256];
	cnu_u8 

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_ENVIRONMENT_H
