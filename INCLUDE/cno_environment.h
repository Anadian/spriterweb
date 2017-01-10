//cno_environment.h

#ifndef CNO_ENVIRONMENT_H
#define CNO_ENVIRONMENT_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef CNO_Environment_struct {
	cno_u8_type username[32];
	cno_u8_type hostname[32];
	cnu_u8_type pwd[256];
	cno_u8_type home[256];
	cno_u8_type whereami[256];
	cno_u8_type ipaddress[32];
} CNO_Environment_type;
CNO_Environment_type CNO_Environment;

cno_u8_type CNO_Environment_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_ENVIRONMENT_H
