//cno_build_info.h: Runtime readable build information

#ifndef CNO_BUILD_INFO_H
#define CNO_BUILD_INFO_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

typedef enum CNO_OS_enum {
	Windows=1,
	MacOSX=2,
	Linux=3,
	Unkown=4} CNO_OS_type;
typedef enum CNO_Device_enum {
	Desktop=1,
	Mobile=2,
	Unkown=3} CNO_Device_type;

typedef struct CNO_Build_Info_struct {
	cno_u8_type buildstring[1024];
	CNO_OS_type os;
	CNO_Device_type device;} CNO_Build_Info_type;

cno_u8_type CNO_Build_Info_Init_func(cno_option_type *options);
typedef C:var_struct C:var:t;
#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_BUILD_INFO_H
