//texture.c

#include "texture.h"
#include "delog.h"
// 
// int InitScreenTexture(){
// 	glGenTextures(1, &(ScreenTexture.texture));
// 	glBindTexture(GL_TEXTURE_2D, ScreenTexture.texture);
// 	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // Linear Filtering
//     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // Linear Filtering
// 	return 0;
// }
// int UpdateScreenTexture();
// 	glTexImage2D(GL_TEXTURE_2D, 0, /*Textures[0].BPP*/GL_RGB, ScreenTexture.width, ScreenTexture.height, 0, /*Textures[0].BPP*/GL_RGB, GL_UNSIGNED_BYTE, ScreenTexture.data);
// 	return 0;
// }
// int QuitScreenTexture(){}