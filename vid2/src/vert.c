#include "vert.h"

GLuint makeBuffer(float* vertex_points)
{
    GLuint vert_buffer;
	/* a vertex buffer object (VBO) is created here. this stores an array of
	data on the graphics adapter's memory. in our case - the vertex points
      */
	glGenBuffers(1, &vert_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vert_buffer);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertex_points,
		     GL_STATIC_DRAW);

    return vert_buffer;
}

GLuint makeArray(GLuint vert_buffer){
    GLuint vert_array;
	/* the vertex array object (VAO) is a little descriptor that defines
	which data from vertex buffer objects should be used as input variables
	to vertex shaders. in our case - use our only VBO, and say 'every three
	floats is a variable' */
	glGenVertexArrays(1, &vert_array);
	glBindVertexArray(vert_array);
	/* "attribute #0 should be enabled when this vert_array is bound" */
	glEnableVertexAttribArray(0);
	/* this VBO is already bound, but it's a good habit to explicitly
	specify which VBO's data the following vertex attribute pointer refers
	to */
	glBindBuffer(GL_ARRAY_BUFFER, vert_buffer);
	/* "attribute #0 is created from every 3 variables in the above buffer,
	of type float (i.e. make me vec3s)" */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    return vert_array;
}