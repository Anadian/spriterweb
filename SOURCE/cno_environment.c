//cno_environment.c

#include "cno_environment.h"

#include "cno_build.h"
#include "cno_build_info.h"

#if CNO_HAVE_STDLIB
#include <stdlib.h> //getenv
#endif //CNO_HAVE_STDLIB

#if CNO_HAVE_STRING
#include <string.h> //strcpy
#endif //CNO_HAVE_STRING

#if CNO_HAVE_WHEREAMI
#include "whereami.h"
#endif // CNO_HAVE_WHEREAMI

cno_u8_type CNO_Environment_Init(){
#if CNO_HAVE_STDLIB && CNO_HAVE_STRING	
	strcpy(&(CNO_Environment.username),getenv("USERNAME"));
	strcpy(&(CNO_Environment.hostname),getenv("HOSTNAME"));
	strcpy(&(CNO_Environment.pwd),getenv("PWD"));
	strcpy(&(CNO_Environment.home),getenv("HOME"));
#if CNO_HAVE_WHEREAMI
	wai_getExecutablePath(&(CNO_Environment.whereami), sizeof(CNO_Evironment.whereami), NULL);
#endif //CNO_HAVE_WHEREAMI
	return 1;
#else
	return 0;
#endif //CNO_HAVE_STDLIB && CNO_HAVE_STRING
}