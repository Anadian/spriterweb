// types.h

#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef enum GLType_enum {Point = 1,Line = 2, Triangle = 4, Quad = 8} GLType_type;	

typedef struct Coordinate_struct {float x;
	float y;
	float z;} Coordinate_type;
	
typedef struct Colour_struct {float r;
	float g;
	float b;} Colour_type;

typedef struct GLPoint_struct {
	Coordinate_type pos;
	Colour_type col;} GLPoint_type;

typedef struct GLLine_struct { Coordinate_type pos[2];
	Colour_type col[2];} GLLine_struct;

typedef struct GLTrianle_struct {Coordinate_type vert[3];
	Colour_type col[3];} GLTriangle_type;

typedef struct GLQuad_struct { Coordinate_type vert[4];
	Colour_type col[4];} GLQuad_type;
	
typedef struct GLPolygon_struct { Coordinate_type *vert;
	Colour_type *col;} GLPolygon_type;



#ifdef __cplusplus
}
#endif //__cplusplus

#endif //TYPES_H