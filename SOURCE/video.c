// video.c

#include "video.h"
#include "configuration.h"

#include "build.h"

#if USE_SDL2
SDL_Window *window;
SDL_GLContext glcontext;
#elif USE_GLFW3
#include <IL/il.h>
#include <IL/ilu.h>
#include "texture.h"
GLFWwindow *window;

#endif
#if USE_TIGR
Tigr *window;
#endif

int InitVideo(){
	
#if USE_SDL2
	window = CreateWindow("SDL2 Window", Configuration.video.xpos, Configuration.video.ypos, Configuration.video.width, Configuration.video.height, Configuration.video.fullscreen);
	//OpenGL stuff
	/*glcontext = SDL_GL_CreateContext(window);
	glewExperimental = GL_TRUE;
	glewInit();*/
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

	window = CreateWindow("Tigr Window", Configuration.video.xpos, Configuration.video.ypos, Configuration.video.width, Configuration.video.height, Configuration.video.fullscreen);
	
#endif
	
	//InitVertexArray();
	//InitVertexBuffer();
	//InitShader();
	//Camera = CreateNewCamera(FREE, {{0, 0, 0.25}, {0, 0, 0}, 0});
	
	return 0;
}
#if USE_SDL2
SDL_Window *CreateWindow(char *title, int xpos, int ypos, int width, int height, int fullscreen){
	int x_off;
	int y_off;
	SDL_Window *subwindow;
	//OpenGL Stuff
	/*SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);*/
	
	if(fullscreen == 1) subwindow = SDL_CreateWindow(title, 1, 1, 1, 1, SDL_WINDOW_FULLSCREEN_DESKTOP);
	else{
		if(xpos == -1) x_off = SDL_WINDOWPOS_CENTERED;
		else x_off = xpos;
		if(ypos == -1) y_off = SDL_WINDOWPOS_CENTERED;
		else y_off = ypos;
		subwindow = SDL_CreateWindow(title, x_off, y_off, width, height, NULL);
	}
	return subwindow;
}
void DestroyWindow(SDL_Window *subwindow){
	SDL_GL_DeleteContext(glcontext);
	return SDL_DestroyWindow(subwindow);
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
Tigr *GetWindow(){
	return window;
}
#endif

	
int Video(){
#if USE_SDL2

	

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
	tigrUpdate(window);
	tigrClear(window, (TPixel){255,255,255,255});
	//tigrPrint(window, tfont, 0, 0, tigr(255,255,255), textbuffer);
#endif
	return 0;
}
int QuitVideo(){
	/*QuitShader();
	QuitVertexBuffer();
	QuitVertexArray();*/
	DestroyWindow(window);
	return 0;
}
