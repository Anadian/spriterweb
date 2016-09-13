//texture.h

#ifndef TEXTURE_H
#define TEXTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <GLFW/glfw3.h>

typedef struct Texture_struct {
	GLuint texture;
	unsigned char *data;
	int width;
	int height;
	int BPP;
} Texture_type;

Texture_type ScreenTexture;

int InitScreenTexture();
int UpdateScreenTexture();
int QuitScreenTexture();

#ifdef __cplusplus
}
#endif

#endif //TEXTURE_H