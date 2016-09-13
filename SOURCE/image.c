//image.c
#include "image.h"
#include <string.h>
#include "stretchy_buffer.h"

int InitScreenImage(){
	strcpy(ScreenImage.name,"screen");
	return 0;
}
int LoadImage(char *filename){
	int RN;
	RN = 0;
	int i;
	for(i = 0; i < sb_count(Images); i++){
		if(strcmp(Images[i].name,filename) == 0){
			RN = i;
			i = sb_count(Images);
		}
	}
	if(RN == 0){
		Image_type subimage;
		strcpy(subimage.name,filename);
		//ilGenImages(1, subimage.id);
		//ilBindImage(subimage.id);
		//ilLoadImage(filename);
		sb_push(Images, subimage);
		RN = sb_count(Images);
	}
	return RN;
}
int BlitImageToScreen(unsigned int imageid, Rect_type imagerect, Rect_type screenrect){}
	