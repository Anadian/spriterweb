// video.h

#ifndef VIDEO_H
#define VIDEO_H

#include "build.h"

#ifdef __cplusplus
extern "C" {
#endif

#if USE_SDL2
#include <SDL2/sdl.h>
#define GL3_PROTOTYPES 1
#include <GL/glew.h>

#elif USE_GLFW3
#include <GLFW/glfw3.h>

#endif
#if USE_TIGR
#include "tigr.h"
#endif



int InitVideo();

#if USE_SDL2
SDL_Window *CreateWindow(char *title, int xpos, int ypos, int width, int height, int fullscreen);
void DestroyWindow(SDL_Window *subwindow);
#elif USE_GLFW3
GLFWwindow *CreateWindow(char *title, int xpos, int ypos, int width, int height, int fullscreen);
void DestroyWindow(GLFWwindow *subwindow);

GLFWwindow *GetWindow();

#endif
#if USE_TIGR
Tigr *CreateWindow(char *title, int xpod, int ypos, int width, int height, int fullscreen);
void DestroyWindow(Tigr *subwindow);
Tigr *GetWindow();
#endif

int Video();
int QuitVideo();

#ifdef __cplusplus
}
#endif

#endif //VIDEO_H