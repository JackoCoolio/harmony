#include <stdlib.h>
#include <stdio.h>

#include "harmony_context.h"

harmony_context_t *harmony_createContext()
{
	harmony_context_t *ctx = malloc(sizeof(harmony_context_t));
	return ctx;
}

int harmony_initialize(harmony_context_t *ctx, int width, int height, const char *title, int makeCurrent)
{
	
	glfwInit();

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	
	ctx->window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!ctx->window)
	{
		printf("woah hold on");
		harmony_terminate();
		return 1;
	}

	if (makeCurrent)
		glfwMakeContextCurrent(ctx->window);

	glewExperimental = 1;
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW failed to initialize!");
		harmony_terminate();
		return 1;
	}
	
	return 0;
}

int harmony_destroyContext(harmony_context_t *ctx)
{
	glfwDestroyWindow(ctx->window);
	free(ctx);

	return 0;
}

int harmony_terminate()
{
	glfwTerminate();
	return 0;
}

