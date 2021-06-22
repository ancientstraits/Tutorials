#include <stdio.h>
#include <stdlib.h>

#include "shader.h"
#include "const.h"

/* these are the strings of code for the shaders
the vertex shader positions each vertex point */
const char *vertex_shader = "#version 410\n"
				   "in vec3 vp;"
				   "void main () {"
				   "  gl_Position = vec4(vp, 1.0);"
				   "}";

/* the fragment shader colours each fragment (pixel-sized area of the
triangle) */
const char *fragment_shader =
    "#version 410\n"
    "out vec4 frag_colour;"
    "void main () {"
    "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
    "}";

GLuint mkShader(const char *vert_source, const char *frag_source)
{
	/* here we copy the shader strings into GL shaders, and compile them. we
	then create an executable shader 'program' and attach both of the
	compiled shaders. we link this, which matches the outputs of the vertex
	shader to the inputs of the fragment shader, etc. and it is then ready
	to use */
	GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_shader, 1, &vert_source, NULL);
	glCompileShader(vert_shader);

    GLint result = GL_FALSE;
    int infoLogLen;

    glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vert_shader, GL_INFO_LOG_LENGTH, &infoLogLen);

    if (infoLogLen > 0) {
        char vert_err[infoLogLen + 1];
        glGetShaderInfoLog(vert_shader, infoLogLen, NULL, &vert_err[0]);

		// TODO no pretty error for tutorial
		fprintf(stderr, "%s%svertex shader error:\t%s%s%s%s\n", FAIL, BOLD, ENDC, BOLD, &vert_err[0], ENDC);
    }

	GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_shader, 1, &frag_source, NULL);
	glCompileShader(frag_shader);

    glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(frag_shader, GL_INFO_LOG_LENGTH, &infoLogLen);

    if (infoLogLen > 0) {
        char frag_err[infoLogLen + 1];
        glGetShaderInfoLog(frag_shader, infoLogLen, NULL, &frag_err[0]);

		// TODO no pretty error for tutorial
		fprintf(stderr, "%s%sfragment shader error:\t%s%s%s%s\n", FAIL, BOLD, ENDC, BOLD, &frag_err[0], ENDC);
    }


	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, frag_shader);
	glAttachShader(shader_programme, vert_shader);
	glLinkProgram(shader_programme);



    return shader_programme;
}