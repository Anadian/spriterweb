//cno_time.c: Time retieval functions

#include "cno_time.h"

#include "cno_build.h"

#if CNO_HAVE_TIME
#include <time.h> //time, gmtime, strftime
#endif //CNO_HAVE_TIME

CNO_Time_type CNO_Time_Unix(){
#if CNO_HAVE_TIME
	return time(NULL);
#endif //CNO_HAVE_TIME
}

cno_u8_type CNO_Time_Calendar(cno_u8_type *buffer){
#if CNO_HAVE_TIME
	return strftime(buffer, sizeof(buffer), "%H%M%S", gmtime(CNO_Time_Unix()));
#endif //CNO_HAVE_TIME
}

cno_u8_type CNO_Time_Concise(cno_u8_type *buffer){
#if CNO_HAVE_TIME
	return strftime(buffer, sizeof(buffer), "%Y%m%dT%H%M%S", gmtime(CNO_Time_Unix()));
#endif //CNO_HAVE_TIME
}

cno_u8_type CNO_Time_Full(cno_u8_type *buffer){
#if CNO_HAVE_TIME
	return strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", gmtime(CNO_Time_Unix()));
#endif //CNO_HAVE_TIME
}
