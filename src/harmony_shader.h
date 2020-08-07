#ifndef HARMONY_SHADER_H
#define HARMONY_SHADER_H

#include <gl/glew.h>

typedef unsigned int harmony_shader_t;

harmony_shader_t harmony_compileShaderFromFile(const char *vertSource, const char *fragSource);

#endif
