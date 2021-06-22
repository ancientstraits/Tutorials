#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>	/* include GLEW and new version of GL on Windows */
#include <GLFW/glfw3.h> /* GLFW helper library */

extern const char* vertex_shader;
extern const char* fragment_shader;

GLuint mkShader(const char *vert_source, const char *frag_source);

#endif // !SHADER_H