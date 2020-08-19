#ifndef HARMONY_BATCH_H
#define HARMONY_BATCH_H

#include "harmony_texture.h"

typedef struct harmony_vertex
{
    float position[2];
    float color[4];
    float textureIndex;
    float textureOffset[2];
} harmony_vertex_t;

typedef struct harmony_sprite
{
    unsigned int index;
    harmony_texture_t texture;
} harmony_sprite_t;

typedef struct harmony_batch
{
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;

    harmony_vertex_t *vertices;
    harmony_texture_t *textures;

    unsigned int verticesCapacity;
    unsigned int texturesCapacity;

    unsigned int verticesIndex;
    unsigned int texturesIndex;
} harmony_batch_t;

harmony_batch_t *harmony_createBatch(int numQuads, int numTextures);

int harmony_addTexture(harmony_batch_t *batch, harmony_texture_t texture);

#endif
