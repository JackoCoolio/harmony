#include <GL/glew.h>
#include <GL/GL.h>

#include <stdio.h>

#include "harmony_log.h"

static const char *prefix = "HARMONY";

void harmony_clearErrors()
{
    GLenum error;
    do
    {
        error = glGetError();
    } while (error != GL_NO_ERROR);
}

int harmony_logErrors(const char *message)
{
    GLenum error = glGetError();
    int errorFound = 0;
    while (error != GL_NO_ERROR)
    {
        printf("[%s] OpenGL Error: %i\n", message, error);
        errorFound = 1;
        error = glGetError();
    }
    return errorFound;
}

void harmony_log(const char* message)
{
    printf("[%s-info] %s", prefix, message);
    fflush(stdout);
}

void harmony_warn(const char* message)
{
    printf("[%s-warn] %s", prefix, message); 
    fflush(stdout);
}

void harmony_error(const char* message)
{
    printf("[%s-error] %s", prefix, message);
    fflush(stdout);
}