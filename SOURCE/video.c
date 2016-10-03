// video.c

#include "video.h"
#include "configuration.h"

#include "build.h"

#if USE_SDL2


#elif USE_GLFW3
#include <IL/il.h>
#include <IL/ilu.h>
#include "texture.h"
GLFWwindow *window;

#endif

#include <string.h> //strcpy
#include "state.h"
#include "stretchy_buffer.h"
#include "delog.h"

int InitVideo(){
	
#if USE_SDL2
	CreateWindow();
#if USE_SDL_TTF
	printl(5, "%s: NULL | %s %s", __func__, SDL_GetError(), TTF_GetError());
#endif //USE_SDL_TTF
#elif (USE_GLFW3 && !USE_TIGR)
	
	//glfwInit();
	window = CreateWindow("GLFW3 Window", Configuration.video.xpos, Configuration.video.ypos, Configuration.video.width, Configuration.video.height, Configuration.video.fullscreen);
	glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping ( NEW )
    glShadeModel(GL_SMOOTH);                        // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);                   // Black Background
    glClearDepth(1.0f);                         // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);                         // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // Really Nice Perspective Calculations
#endif
#if USE_TIGR

	Window = CreateWindow("Tigr Window", Configuration.video.xpos, Configuration.video.ypos, Configuration.video.width, Configuration.video.height, Configuration.video.fullscreen);
	
#endif
	
	return 0;
}
#if USE_SDL2
int CreateWindow(){
	if(Window != NULL) DestroyWindow();
	Uint32 flags;
	flags = 0;
	if(Configuration.video.fullscreen) flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	else flags = SDL_WINDOW_RESIZABLE;
	//printf("flags: %d\n", flags);
	SDL_CreateWindowAndRenderer(Configuration.video.width, Configuration.video.height, flags, &Window, &Renderer);
	SDL_RenderSetLogicalSize(Renderer, 640, 480);
	return 1;
}
int DestroyWindow(){
	SDL_DestroyRenderer(Renderer);
	Renderer = NULL;
	SDL_DestroyWindow(Window);
	Window = NULL;
	return 1;
}
#elif USE_GLFW3
GLFWwindow *CreateWindow(char *title, int xpos, int ypos, int width, int height, int fullscreen){
	int x_off;
	int y_off;
	GLFWmonitor *monitor;
	monitor = glfwGetPrimaryMonitor();
	GLFWvidmode *vidmode;
	vidmode = glfwGetVideoMode(monitor);
	GLFWwindow *subwindow;
	if(fullscreen == 1) subwindow = glfwCreateWindow(vidmode->width, vidmode->height, title, monitor, NULL);
	else{
		if(xpos == -1) x_off = (vidmode->width - width)/2;
		else x_off = xpos;
		if(ypos == -1) y_off = (vidmode->height - height)/2;
		else y_off = ypos;
		subwindow = glfwCreateWindow(width, height, title, NULL, NULL);
	}
	glfwMakeContextCurrent(subwindow);
	glfwSwapInterval(1);
	
	//ResIL Stuff
	//ilutRenderer(ILUT_OPENGL);
	
	return subwindow;
}
void DestroyWindow(GLFWwindow *subwindow){
	return glfwDestroyWindow(subwindow);
}

GLFWwindow *GetWindow(){
	return window;
}
#endif
#if USE_TIGR
Tigr *CreateWindow(char *title, int xpos, int ypos, int width, int height, int fullscreen){
	Tigr *subwindow;
	subwindow = tigrWindow(width, height, title, 0);
	return subwindow;
}
void DestroyWindow(Tigr *subwindow){
	return tigrFree(subwindow);
}
#endif

	
int Video(){
#if USE_SDL2
	SDL_RenderClear(Renderer);
	int i;
	for(i = 0; i < sb_count(Blits); i++){
		Rect_type dstrect;
		dstrect.x = Blits[i].x;
		dstrect.y = Blits[i].y;
		dstrect.w = Frames[Blits[i].frame].w;
		dstrect.h = Frames[Blits[i].frame].h;
		SDL_RenderCopyEx(Renderer, Images[Blits[i].image].image, &(Frames[Blits[i].frame]), &dstrect, Blits[i].rotation*180, NULL, Blits[i].flip);
	}
	int x1, y1, x2, y2, colour;
	unsigned char r, g, b, a;
	for(i = 0; i < sb_count(RenderPoints); i++){
		x1 = RenderPoints[i].point.x;
		y1 = RenderPoints[i].point.y;
		colour = RenderPoints[i].colour;
		r = Colours[colour].r;
		g = Colours[colour].g;
		b = Colours[colour].b;
		a = Colours[colour].a;
		SDL_SetRenderDrawColor(Renderer, r, g, b, a);
		SDL_RenderDrawPoint(Renderer, x1, y1);
	}
	for(i = 0; i < sb_count(RenderLines); i++){
		x1 = RenderLines[i].point1.x;
		y1 = RenderLines[i].point1.y;
		x2 = RenderLines[i].point2.x;
		y2 = RenderLines[i].point2.y;
		colour = RenderLines[i].colour;
		r = Colours[colour].r;
		g = Colours[colour].g;
		b = Colours[colour].b;
		a = Colours[colour].a;
		SDL_SetRenderDrawColor(Renderer, r, g, b, a);
		SDL_RenderDrawLine(Renderer, x1, y1, x2, y2);
	}
	for(i = 0; i < sb_count(RenderRects); i++){
		colour = RenderRects[i].colour;
		r = Colours[colour].r;
		g = Colours[colour].g;
		b = Colours[colour].b;
		a = Colours[colour].a;
		SDL_SetRenderDrawColor(Renderer, r, g, b, a);
		SDL_RenderDrawRect(Renderer, &(RenderRects[i].rect));
		if(RenderRects[i].filled == 1) SDL_RenderFillRect(Renderer, &(RenderRects[i].rect));
	}
	SDL_RenderPresent(Renderer);
	ClearBlits();
	

#elif USE_GLFW3

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	float ratio;
	ratio = (float)(width/height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Copy code.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(-1.f, 1.f, 1.f, -1.f, -1.f, 1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, ScreenTexture.texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f); glVertex3f(-0.25f, -0.25f, 0.25f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(0.25f, -0.25f, 0.25f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(0.25f, 0.25f, 0.25f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(-0.25f, 0.25f, 0.25f);
	glEnd();
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(window);
	//End copy code.
#elif USE_TIGR
	tigrClear(Window, tigrRGB(0,0,0));
	Lock(Images)
	Lock(Blits)
	if(sb_count(Blits) > 0){
		int i;
		for(i = 0; i < sb_count(Blits); i++){
			printl(5, "i: %d, Blits.image: %d, Images.filename: %s", i, Blits[i].image, Images[i].filename);
			tigrBlit(Window, Images[Blits[i].image].image, Blits[i].x, Blits[i].y, 0, 0, Images[Blits[i].image].image->w, Images[Blits[i].image].image->h);
		}
	}
	Unlock(Images)
	Unlock(Blits)
	tigrUpdate(Window);
#endif
	return 0;
}
int QuitVideo(){
	DestroyWindow();
	return 0;
}
int LoadImage(char *filename){
	Image_type Image;
	Rect_type rect;
	SDL_Surface *tmp_surface;
	strcpy(Image.filename, filename);
	tmp_surface = IMG_Load(filename);
	Image.image = SDL_CreateTextureFromSurface(Renderer, tmp_surface);
	rect.x = 0;
	rect.y = 0;
	rect.w = tmp_surface->w;
	rect.h = tmp_surface->h;
	sb_push(Frames, rect);
	Image.frame = sb_count(Frames);
	SDL_FreeSurface(tmp_surface);
	sb_push(Images,Image);
	printl(5, "%s: %s | %s %s %d %d", __func__, filename, SDL_GetError(), IMG_GetError(), sb_count(Frames), sb_count(Images));
	return sb_count(Images) - 1;
}
int ClearImages(){
	int i;
	for(i = 0; i < sb_count(Images); i++){
		SDL_DestroyTexture(Images[i].image);
	}
	sb_free(Images);
	Images = NULL;
	sb_free(Frames);
	Frames = NULL;
	return 0;
}	
int LoadFont(char *filename, int size){
	//printl(5, "%s: %s %d", __func__, filename, size);
	Font_type Font;
	strcpy(Font.filename, filename);
	Font.size = size;
	Font.font = TTF_OpenFont(filename, size);
	sb_push(Fonts, Font);
	printl(5, "%s: %s %d | %s %d", __func__, filename, size, TTF_GetError(), sb_count(Fonts));
	return sb_count(Fonts);
}
int ClearFonts(){
	int i;
	for(i = 0; i < sb_count(Fonts); i++){
		TTF_CloseFont(Fonts[i].font);
	}
	sb_free(Fonts);
	Fonts = NULL;
	return 0;
}
int WriteText(int font, char *text, Colour_type colour){
	Image_type Image;
	SDL_Surface *tmp_surface;
	tmp_surface = TTF_RenderText_Blended(Fonts[font].font, text, colour);
	Image.image = SDL_CreateTextureFromSurface(Renderer, tmp_surface);
	Rect_type rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = tmp_surface->w;
	rect.h = tmp_surface->h;
	sb_push(Frames, rect);
	Image.frame = sb_count(Frames);
	SDL_FreeSurface(tmp_surface);
	sb_push(Images,Image);
	printl(5, "%s: %d %s %d | %s %s %d", __func__, font, text, colour, SDL_GetError(), TTF_GetError(), sb_count(Images));
	return sb_count(Images) - 1;
}
int AddBlit(int image, int frame, int x, int y, float rotation, Flip_type flip){
	Blit_type Blit;
	Blit.image = image;
	Blit.frame = frame;
	Blit.x = x;
	Blit.y = y;
	Blit.rotation = rotation;
	Blit.flip = flip;
	sb_push(Blits,Blit);
	printl(5, "%s: %d %d %d %d %f %d | %d", __func__, image, frame, x, y, rotation, flip, sb_count(Blits));
	return sb_count(Blits);
}
int ClearBlits(){
	if(sb_count(Blits) > 0){
		sb_free(Blits);
		Blits = NULL;
	}
	return 0;
}
int AddColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
	Colour_type Colour;
	Colour.r = r;
	Colour.g = g;
	Colour.b = b;
	Colour.a = a;
	sb_push(Colours,Colour);
	printl(5, "%s: %d %d %d %d | %d", __func__, r, g, b, a, sb_count(Colours));
	return sb_count(Colours) - 1;
}
int ClearColours(){
	if(Colours != NULL){
		sb_free(Colours);
		Colours = NULL;
	}
	return 0;
}
int AddPoint(int x, int y, int colour){
	RenderPoint_type Point;
	Point.point.x = x;
	Point.point.y = y;
	Point.colour = colour;
	sb_push(RenderPoints,Point);
	printl(5, "%s: %d %d %d | %d", __func__, x, y, colour, sb_count(RenderPoints));
	return sb_count(RenderPoints) - 1;
}
int ClearRenderPoints(){
	if(RenderPoints != NULL){
		sb_free(RenderPoints);
		RenderPoints = NULL;
	}
	return 0;
}
int AddRenderLine(int x1, int y1, int x2, int y2, int colour){
	RenderLine_type Line;
	Line.point1.x = x1;
	Line.point1.y = y1;
	Line.point2.x = x2;
	Line.point2.y = y2;
	Line.colour = colour;
	sb_push(RenderLines,Line);
	printl(5, "%s: %d %d %d %d %d | %d", __func__, x1, y1, x2, y2, colour, sb_count(RenderLines));
	return sb_count(RenderLines) - 1;
}
int ClearRenderLines(){
	if(RenderLines != NULL){
		sb_free(RenderLines);
		RenderLines = NULL;
	}
	return 0;
}
int AddRenderRect(int x, int y, int w, int h, int filled, int colour){
	RenderRect_type Rect;
	Rect.rect.x = x;
	Rect.rect.y = y;
	Rect.rect.w = w;
	Rect.rect.h = h;
	Rect.filled = filled;
	Rect.colour = colour;
	sb_push(RenderRects,Rect);
	printl(5, "%s: %d %d %d %d %d | %d", __func__, x, y, w, h, colour, sb_count(RenderRects));
	return sb_count(RenderRects) - 1;
}
int ClearRenderRects(){
	if(RenderRects != NULL){
		sb_free(RenderRects);
		RenderRects = NULL;
	}
	return 0;
}