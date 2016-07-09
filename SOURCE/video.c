// video.c

#include "video.h"
#include "configuration.h"

#include "build.h"

#if USE_SDL2
SDL_Window *window;
SDL_GLContext glcontext;
#elif USE_GLFW3
GLFWwindow *window;
#endif

#include "vertexbuffer.h"

#include "camera.h"

Camera_type Camera;

int InitVideo(){
	
#if USE_SDL2
	window = CreateWindow("SDL2 Window", Configuration.video.xpos, Configuration.video.ypos, Configuration.video.width, Configuration.video.height, Configuration.video.fullscreen);
#elif USE_GLFW3
	
	//glfwInit();
	window = CreateWindow("GLFW3 Window", Configuration.video.xpos, Configuration.video.ypos, Configuration.video.width, Configuration.video.height, Configuration.video.fullscreen);
#endif
	
	//InitVertexArray();
	//InitVertexBuffer();
	//InitShader();
	//Camera = CreateNewCamera(FREE, {{0, 0, 0.5}, {0, 0, 0}, 0});
	
	return 0;
}
#if USE_SDL2
SDL_Window *CreateWindow(char *title, int xpos, int ypos, int width, int height, int fullscreen){
	int x_off;
	int y_off;
	SDL_Window *subwindow;
	//OpenGL Stuff
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	if(fullscreen == 1) subwindow = SDL_CreateWindow(title, 1, 1, 1, 1, SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN_DESKTOP);
	else{
		if(xpos == -1) x_off = SDL_WINDOWPOS_CENTERED;
		else x_off = xpos;
		if(ypos == -1) y_off = SDL_WINDOWPOS_CENTERED;
		else y_off = ypos;
		subwindow = SDL_CreateWindow(title, x_off, y_off, width, height, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
	}
	//OpenGL stuff
	glcontext = SDL_GL_CreateContext(subwindow);
	glewExperimental = GL_TRUE;
	glewInit();
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

	
int Video(){
#if USE_SDL2

	glClearColor(1.f,0.f,1.f,1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);

#elif USE_GLFW3

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	float ratio;
	ratio = (float)(width/height);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Copy code.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(-1.f, 1.f, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef((float) glfwGetTime() * 25.f, /*(float) glfwGetTime() */ 10.f, /*(float) glfwGetTime() */ 2.f, 1.f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, -0.9f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, -0.9f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, -0.9f);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(Point.x,Point.y,Point.z);
	glEnd();
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(window);
	//End copy code.
	
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