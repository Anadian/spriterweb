// Position.h

#ifndef POSITION_H
#define POSITION_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Position_struct {float x;
	float y;
	float z;} Position_type;

typedef struct Direction_struct {float x;
	float y;
	float z;} Direction_type;
	
typedef struct PDR_struct {Position_type p;
	Direction_type d;
	float r;} PDR_type;

#ifdef __cplusplus
}
#endif

#endif //POSITION_H