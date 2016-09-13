// drawables.c

#include "drawables.h"
#include "delog.h"
#include <string.h> //strcpy

/*DrawableObject_type CreateDrawableObject(GLType_type type, char *name){
	if( (type != NULL) && (name != NULL) ){
		printl(5,"Creating object %s with type %d", name, type);
		DrawableObject_type ReturnDrawableObject;
		ReturnDrawableObject.type = type;
		switch(type){
			case GLType_type.Point:
				ReturnDrawableObject.point = {{0,0,0},{1,1,1}};
				break;
			case GLType_type.Line:
				ReturnDrawableObject.line = {{{-0.5,-0.5,-0.5},{0.5,0.5,0.5}},{{0,0,0},{1,1,1}}};
				break;
			case GLType_type.Triangle:
				ReturnDrawableObject.triangle = { {{-0.5,-0.5,0}, {0,0.5,0}, {0.5,-0.5,0}}, {{1,0,0}, {0,1,0}, {0,0,1}} };
				break;
			case GLType_type.Quad:
				ReturnDrawableObject.quad = { {{-0.5,-0.5,0}, {0.5,-0.5,0}, {0.5,0.5,0}, {-0.5,0.5}}, {{0.25,0.25,0.25}, {0.50,0.50,0.50}, {0.75,0.75,0.75}} };
				break;
			default:
				printl(2, "Invalid GLType %d for %s", type, name);
				break;
		}
		ReturnDrawableObject.centre = {0,0,0};
		ReturnDrawableObject.rotation = {0,0,0};
		ReturnDrawableObject.scale = {1,1,1};
		ReturnDrawableObject.visible = 1;
		strcpy(ReturnDrawableObject.name,name);
		return ReturnDrawableObject;
	else{
		printl(2,"Insufficient arguments in %s: %d %s", __func__, type, name);
		return -1;
	}
}*/
	
		