#ifndef HARMONY_H
#define HARMONY_H

// #define GLFW_DLL
#include <gl/glew.h>
#include "GLFW/glfw3.h"

typedef struct harmony_context
{
	GLFWwindow *window;
} harmony_context_t;

harmony_context_t *harmony_createContext();

int harmony_initialize(harmony_context_t *ctx, int width, int height, const char *title, int makeCurrent);

int harmony_destroyContext(harmony_context_t *ctx);

int harmony_terminate();

#endif
