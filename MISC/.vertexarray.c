// VertexArray.c

#include "vertexarray.h"
#include <GL/gl.h>

GLuint VertexArray;

int InitVertexArray(){
	glGenVertexArrays(1, &VertexArray);
	glBindVertexArray(VertexArray);
	return 0;
}
int QuitVertexArray(){
	glDeleteVertexArrays(1, &VertexArray);
	return 0;
}
	