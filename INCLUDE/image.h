//image.h

#ifndef SURFACE_H
#define SURFACE_H

#ifdef __cplusplus
extern "C" {
#endif //cplusplus

#include <IL/il.h>
#include <IL/ilu.h>
#include "rect.h"

typedef struct Image_struct {
	char *name;
	ILuint *id;
} Image_type;

Image_type ScreenImage;
Image_type *Images;

int InitScreenImage();
int LoadImage(char *filename);
int BlitImageToScreen(unsigned int imageid, Rect_type imagerect, Rect_type screenrect);
int ClearImages();
int QuitScreenImage();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //IMAGE_H