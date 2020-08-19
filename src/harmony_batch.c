#include <gl/glew.h>
#include <gl/GL.h>

#include "harmony_batch.h"

harmony_batch_t *harmony_createBatch(int numQuads, int numTextures)
{
    harmony_batch_t *batch = malloc(sizeof(harmony_batch_t));

    batch->verticesCapacity = 4 * numQuads;
    batch->texturesCapacity = numTextures;

    int verticesSize = 4 * numQuads * sizeof(harmony_vertex_t);
    int texturesSize = numTextures * sizeof(harmony_texture_t);

    batch->vertices = malloc(verticesSize);
    batch->textures = malloc(texturesSize);

    batch->verticesIndex = 0;
    batch->texturesIndex = 0;

    glGenVertexArrays(1, &batch->vao);
    glBindVertexArray(batch->vao);

    glGenBuffers(1, &batch->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, batch->vbo);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, (void*) 0, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &batch->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, batch->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * numQuads * sizeof(int), (void*) 0, GL_DYNAMIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return batch;
}

int harmony_addTexture(harmony_batch_t *batch, harmony_texture_t texture)
{
    if (batch->texturesIndex == batch->texturesCapacity)
        return -1;

    batch->textures[batch->texturesIndex] = texture;
    return batch->texturesIndex++;
}
