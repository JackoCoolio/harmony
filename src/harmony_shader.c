#include "harmony_shader.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harmony_file.h"

void checkErrors(harmony_shader_t shader, int type);

harmony_shader_t harmony_compileShaderFromFile(const char *vertPath, const char *fragPath)
{

    char *vertSourceTmp, *fragSourceTmp;
    harmony_readIntoBuffer(vertPath, &vertSourceTmp);
    harmony_readIntoBuffer(fragPath, &fragSourceTmp);

    const char* vertSource = vertSourceTmp;
    const char* fragSource = fragSourceTmp;

    harmony_shader_t shader;

    GLuint sVert, sFrag;

    sVert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVert, 1, &vertSource, NULL);
    glCompileShader(sVert);

    sFrag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFrag, 1, &fragSource, NULL);
    glCompileShader(sFrag);

    shader = glCreateProgram();

    checkErrors(shader, 0);

    glAttachShader(shader, sVert);
    glAttachShader(shader, sFrag);

    glLinkProgram(shader);

    checkErrors(shader, 1);

    glDeleteShader(sVert);
    glDeleteShader(sFrag);

    return shader;

}

void checkErrors(harmony_shader_t shader, int type)
{
    
    int compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        int length;
        char* log;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        log = malloc(length);
        memset(log, 0, length);
        glGetShaderInfoLog(shader, length, &length, log);
        printf("Shader error (length %i):\n%s\n\n", length, log);
        free(log);
    }

}

// TODO: Compiler error logging.
