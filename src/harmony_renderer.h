#ifndef HARMONY_RENDERER_H
#define HARMONY_RENDERER_H

#include "harmony_linked_list.h"
#include "harmony_shader.h"

typedef struct harmony_context harmony_context_t;

typedef struct harmony_batch
{
    harmony_ll_t *sprites;
    size_t size;

    GLuint vbo;
    GLuint ebo;
    GLuint vao;
} harmony_batch_t;

typedef struct harmony_sprite
{
    int placeholder;
} harmony_sprite_t;

void harmony_initializeRenderPipeline();

harmony_batch_t *harmony_createBatch();

void harmony_initializeBatch(harmony_batch_t *batch);

void harmony_addSpriteToBatch(harmony_batch_t *batch, harmony_sprite_t *sprite);

void harmony_renderBatch(harmony_batch_t *batch);

void harmony_testInit();

void harmony_testRender(harmony_context_t *ctx);

#endif
