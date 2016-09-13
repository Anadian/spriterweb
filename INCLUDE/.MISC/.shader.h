// Shader.h

#ifndef SHADER_H
#define SHADER_H

#ifdef __cplusplus
extern "C" {
#endif

int InitShader();
unsigned char *LoadShaderFromFile(char *filename);
int QuitShader();

#ifdef __cplusplus
}
#endif

#endif //SHADER_H