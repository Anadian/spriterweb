// Shader.c

#include "shader.h"
#include <stdio.h>
#include <string.h>
#include <GL/gl.h>

GLuint VertexShader;
GLuint FragmentShader;
GLuint SharedProgram;
GLint PositionAttrib;

int InitShader(){
	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint *shader;
	shader = LoadShaderFromFile("vertexshader.glsl");
	printf("shader from Init: %s\n", shader);
	glShaderSource(VertexShader, 1, shader, NULL);
	printf("Hello.\n");
	glCompileShader(VertexShader);
	
	FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, LoadShaderFromFile("fragmentshader.glsl"), NULL);
	glCompileShader(FragmentShader);
	
	//Check shader compilation
	
	SharedProgram = glCreateProgram();
	glAttachShader(SharedProgram, VertexShader);
	glAttachShader(SharedProgram, FragmentShader);
	
	glBindFragDataLocation(SharedProgram, 0, "outColor");
	
	glLinkProgram(SharedProgram);
	glUseProgram(SharedProgram);
	
	//Attribute
	PositionAttrib = glGetAttribLocation(SharedProgram, "position");
	glVertexAttribPointer(PositionAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	glEnableVertexAttribArray(PositionAttrib);
	
	return 0;
}
unsigned char *LoadShaderFromFile(char *filename){
	FILE *shader;
	shader = fopen(filename, "r");
	if(shader != NULL){
		fpos_t size;
		fseek(shader, 0, SEEK_END);
		fgetpos(shader,&size);
		fseek(shader, 0, SEEK_SET);
		unsigned char text[((int)size)];
		printf("size: %d\n", size);
		//fread(text, sizeof(unsigned char), size, shader);
		int i;
		for(i = 0; i < size; i++){
			text[i] = fgetc(shader);
		}
		printf("shader: %s\n", text);
		//char *finalstring;
		//strcpy(finalstring, text);
		//printf("finalstring: %s\n", finalstring);
		fclose(shader);
		return text;
	}
	return -1;
}
int QuitShader(){
	glDetachShader(SharedProgram, VertexShader);
	glDeleteShader(VertexShader);
	glDetachShader(SharedProgram, FragmentShader);
	glDeleteShader(FragmentShader);
	glDeleteShader(FragmentShader);
	glDeleteProgram(SharedProgram);
	return 0;
}