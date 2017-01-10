//cno_time.h: Time retrieval functions

#ifndef CNO_TIME_H
#define CNO_TIME_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#if CNO_HAVE_TIME
#include <time.h>

typedef time_t CNO_Time_type;

#endif //CNO_HAVE_TIME

CNO_Time_type CNO_Time_Unix();
cno_u8_type CNO_Time_Calendar(cno_u8_type *buffer);
cno_u8_type CNO_Time_Concise(cno_u8_type *buffer);
cno_u8_type CNO_Time_Full(cno_u8_type *buffer);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_TIME_H