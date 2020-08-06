#include <GL/glew.h>
#include <GL/GL.h>

#include <stdio.h>

#include "harmony_log.h"

static const char *prefix = "[HARMONY]";

void harmony_clearErrors()
{
    while (glGetError() != GL_NO_ERROR);
}

int harmony_logErrors()
{
    GLenum error;
    int errorFound = 0;
    while (error = glGetError())
    {
        printf("%s OpenGL Error! Code: %i\n", prefix, error);
        errorFound = 1;
    }
    return errorFound;
}
