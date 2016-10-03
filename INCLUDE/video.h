// video.h

#ifndef VIDEO_H
#define VIDEO_H

#include "build.h"

#ifdef __cplusplus
extern "C" {
#endif

#if USE_SDL2
#include <SDL2/sdl.h>

#elif USE_GLFW3
#include <GLFW/glfw3.h>

#endif
#if USE_TIGR
#include "tigr.h"
#endif



int InitVideo();

#if USE_SDL2
#define Surface_type SDL_Texture
#define Rect_type SDL_Rect
#define Flip_type SDL_RendererFlip 
#define Colour_type SDL_Color
#define Point_type SDL_Point
int CreateWindow();
int DestroyWindow();
SDL_Window *Window;
SDL_Renderer *Renderer;
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#define TTF_type TTF_Font


typedef struct Image_struct{
	char filename[16];
	int frame; 
	Surface_type *image;} Image_type;
Image_type *Images;
Rect_type *Frames;
typedef struct Font_struct{
	char filename[16];
	int size;
	TTF_type *font;} Font_type;
Font_type *Fonts;
typedef struct Blit_struct{
	int x;
	int y;
	int image;
	int frame;
	float rotation;
	Flip_type flip;} Blit_type;
Blit_type *Blits;
typedef struct RenderPoint_struct{
	Point_type point;
	int colour;} RenderPoint_type;
typedef struct RenderLine_struct{
	Point_type point1;
	Point_type point2;
	int colour;} RenderLine_type;
typedef struct RenderRect_struct{
	Rect_type rect;
	unsigned short filled;
	int colour;} RenderRect_type;
Colour_type *Colours;
RenderPoint_type *RenderPoints;
RenderLine_type *RenderLines;
RenderRect_type *RenderRects;
#elif USE_GLFW3
GLFWwindow *CreateWindow(char *title, int xpos, int ypos, int width, int height, int fullscreen);
void DestroyWindow(GLFWwindow *subwindow);

GLFWwindow *GetWindow();

#endif
#if USE_TIGR
Tigr *CreateWindow(char *title, int xpod, int ypos, int width, int height, int fullscreen);
void DestroyWindow(Tigr *subwindow);
Tigr *Window;
#endif

int LoadImage(char *filename);
int ClearImages();
/*int LoadFrames(char *filename);
int ClearFrames();*/
int LoadFont(char *filename, int size);
int ClearFonts();
int WriteText(int font, char *text, Colour_type colour);
int AddBlit(int image, int frame, int x, int y, float rotation, Flip_type flip);
int ClearBlits();
int Video();
int QuitVideo();

int AddColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int ClearColours();
int AddRenderPoint(int x, int y, int colour);
int ClearRenderPoints();
int AddRenderLine(int x1, int y1, int x2, int y2, int colour);
int ClearRenderLines();
int RenderRect(int x, int y, int w, int h, int filled, int colour);
int ClearRenderRects();

#ifdef __cplusplus
}
#endif

#endif //VIDEO_H