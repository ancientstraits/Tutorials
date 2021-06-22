#ifndef VERT_H
#define VERT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

GLuint makeBuffer(float* vertex_points);
GLuint makeArray(GLuint vert_buffer);

#endif // !VERT_H