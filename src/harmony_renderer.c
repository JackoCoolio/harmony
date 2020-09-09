#include <GL/glew.h>
#include <GL/GL.h>

#include <GLFW/glfw3.h>

#include "harmony_renderer.h"
#include "harmony_context.h"
#include "harmony_log.h"
#include "harmony_vector.h"
#include "harmony_texture.h"
#include "harmony_batch.h"

#include <stdio.h>

void harmony_initializeRenderer(harmony_context_t *ctx)
{
    glViewport(0, 0, ctx->width, ctx->height);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glClearColor(0.2, 0.2, 0.2, 1.0);
}
