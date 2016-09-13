//draw.h

#ifndef DRAW_H
#define DRAW_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "types.h"

typedef struct DrawObject_struct {
	int type;
	int vertices;
	Position_type *vertex;
	Position_type *position;
	Position_type *rotation;
	Colour_type *colour;} DrawObject_type;

DrawObject_type *DrawObjects;

	

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DRAW_H