#ifndef HARMONY_BATCH_H
#define HARMONY_BATCH_H

#include "harmony_texture.h"
#include "harmony_buffer.h"
#include "harmony_shader.h"

#define HARMONY_BATCH_MAX_TEXTURES 32

typedef unsigned int harmony_sprite_t;

typedef struct harmony_batch
{
    harmony_shader_t shader;
    
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
    
    harmony_quad_t *quads;
    harmony_texture_t *textures;
    unsigned int *indices;
    
    unsigned int quadsCapacity;
    unsigned int indicesCapacity;
    
    unsigned int quadsIndex;
    unsigned int texturesIndex;
    unsigned int indicesIndex;
} harmony_batch_t;

harmony_batch_t *harmony_createBatch(int numQuads, harmony_shader_t shader);

int harmony_addTexture(harmony_batch_t *batch, harmony_texture_t texture);

int harmony_deleteSprite(harmony_batch_t *batch, harmony_sprite_t sprite);

harmony_sprite_t harmony_addSprite(harmony_batch_t *batch, int textureIndex);

void harmony_setSpriteQuad(harmony_batch_t *batch, harmony_sprite_t sprite, harmony_quad_t data);

void harmony_updateBatch(harmony_batch_t *batch);

void harmony_renderBatch(harmony_batch_t *batch);

#endif
