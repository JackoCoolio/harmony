#ifndef HARMONY_RENDERER_H
#define HARMONY_RENDERER_H

#include "harmony_linked_list.h"
#include "harmony_shader.h"

typedef struct harmony_context harmony_context_t;

void harmony_initializeRenderPipeline();

void harmony_testInit();

void harmony_testRender(harmony_context_t *ctx);

#endif
