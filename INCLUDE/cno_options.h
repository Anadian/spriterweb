//cno_options.h

#ifndef CNO_OPTIONS_H
#define CNO_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_GETOPT
#include "getopt.h"
typedef static struct option CNO_Option_type;

CNO_Option_type CNO_Options[] = {
		{"version", no_argument, 0, 'V'},
		{"help", no_argument, 0, 'h'},
		{"verbose", optional_argument, 0, 'v'},
		{"config", required_argument, 0, 'c'},
		{"actions", required_argument, 0, 'a'},
		{0,0,0,0}
};

typedef enum CNO_Option_Flag_enum{
	CNO_Option_Version,
	CNO_Option_Help,
	CNO_Option_Verbose,
	CNO_Option_Config,
	CNO_Option_Actions,
	Number_of_CNO_Options
} CNO_Option_Flag_type;

typedef struct CNO_Option_Plus_struct{
	cno_u8_type flag;
	cno_u8_type hint[8];
	cno_u8_type description[512];
} CNO_Option_Plus_type;

CNO_Option_Plus_type CNO_Options_Plus[Number_of_CNO_Options];

#endif //CNO_HAVE_GETOPT

cno_s8_type CNO_Options_GetOpt(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_OPTIONS_H
