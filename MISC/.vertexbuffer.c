// VertexBuffer.c

#include "vertexbuffer.h"
#include <GL/gl.h>

GLuint VertexBuffer;
float vertices[] = {
     0.0f,  0.5f, // Vertex 1 (X, Y)
     0.5f, -0.5f, // Vertex 2 (X, Y)
    -0.5f, -0.5f  // Vertex 3 (X, Y)
};

int InitVertexBuffer(){
	glGenBuffers(1, &VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	return 0;
}
int QuitVertexBuffer(){
	glDeleteBuffers(1, VertexBuffer);
	return 0;
}