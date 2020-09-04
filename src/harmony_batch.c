#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include <gl/glew.h>
#include <gl/GL.h>

#include "harmony_batch.h"
#include "harmony_log.h"

harmony_batch_t *harmony_createBatch(int numQuads, harmony_shader_t shader)
{
    
    harmony_batch_t *batch = malloc(sizeof(harmony_batch_t));
    
    // Set shader
    batch->shader = shader;
    harmony_checkError(glUseProgram(shader));
    harmony_checkError(glBindFragDataLocation(shader, 0, "outColor"));
    
    // Number of vertices
    batch->quadsCapacity = numQuads;
    
    // Number of sets of indices
    batch->indicesCapacity = 6 * numQuads;
    
    // Memory size
    int quadsSize = numQuads * sizeof(harmony_quad_t);
    int texturesSize = HARMONY_BATCH_MAX_TEXTURES * sizeof(harmony_texture_t);
    int indicesSize = 6 * numQuads * sizeof(unsigned int);
    
    // Allocating memory for quads array
    batch->quads = malloc(quadsSize);
    memset(batch->quads, 0, quadsSize);
    
    // Allocating memory for textures array
    batch->textures = malloc(texturesSize);
    
    // Allocating memory for indices array
    batch->indices = malloc(indicesSize);
    
    // Resetting available indices
    batch->quadsIndex = 0;
    batch->texturesIndex = 0;
    batch->indicesIndex = 0;
    
    // Bind VAO
    glGenVertexArrays(1, &batch->vao);
    glBindVertexArray(batch->vao);
    
    glGenBuffers(1, &batch->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, batch->vbo);
    harmony_checkError(glBufferData(GL_ARRAY_BUFFER, quadsSize, (void*) 0, GL_DYNAMIC_DRAW));
    
    glGenBuffers(1, &batch->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, batch->ebo);
    harmony_checkError(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * numQuads * sizeof(int), (void*) 0, GL_DYNAMIC_DRAW));
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), (void*) (0 * sizeof(float))); // 0 * 4
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), (void*) (2 * sizeof(float))); // 2 * 4
    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), (void*) (6 * sizeof(float))); // 6 * 4
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), (void*) (7 * sizeof(float))); // 7 * 4
    
    //harmony_logErrors();
    //harmony_clearErrors();
    
    // Set up attributes //
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glUseProgram(0);
    
    return batch;
}

int harmony_addTexture(harmony_batch_t *batch, harmony_texture_t texture)
{
    if (batch->texturesIndex == HARMONY_BATCH_MAX_TEXTURES)
        return -1;
    
    batch->textures[batch->texturesIndex] = texture;
    return batch->texturesIndex++;
}

int harmony_deleteSprite(harmony_batch_t *batch, harmony_sprite_t sprite)
{
    if (sprite == batch->quadsIndex)
        return 1;
    
    void *quadSrc = batch->quads + ((batch->quadsIndex - 1) * sizeof(harmony_quad_t));
    void *quadDest = batch->quads + (sprite * sizeof(harmony_quad_t));
    
    memcpy(quadDest, quadSrc, sizeof(harmony_quad_t));
    
    void *indicesSrc = batch->indices + (6 * (batch->indicesIndex - 1) * sizeof(unsigned int));
    void *indicesDest = batch->indices + (6 * sprite * sizeof(unsigned int));
    
    memcpy(indicesDest, indicesSrc, 6 * sizeof(unsigned int));
    
    batch->quadsIndex--;
    batch->indicesIndex -= 6;
    
    return 0;
}

harmony_sprite_t harmony_addSprite(harmony_batch_t *batch, int textureIndex)
{
    harmony_sprite_t sprite = -1;
    
    if (batch->quadsIndex < batch->quadsCapacity)
    {
        sprite = batch->quadsIndex++;
        
        // Set up indices
        // Indices will always be in the order:
        // 0, 2, 3, 0, 1, 2
        // And vertices will always be clockwise starting from the top-left
        
        int offset = sprite * 4;
        
        batch->indices[sprite * 6 + 0] = 0 + offset;
        batch->indices[sprite * 6 + 1] = 2 + offset;
        batch->indices[sprite * 6 + 2] = 3 + offset;
        batch->indices[sprite * 6 + 3] = 0 + offset;
        batch->indices[sprite * 6 + 4] = 1 + offset;
        batch->indices[sprite * 6 + 5] = 2 + offset;
        batch->indicesIndex += 6;
    }
    
    return sprite;
}

void harmony_setSpriteQuad(harmony_batch_t *batch, harmony_sprite_t sprite, harmony_quad_t data)
{
    batch->quads[sprite] = data;
}

void harmony_renderBatch(harmony_batch_t *batch)
{
    
    harmony_checkError(glUseProgram(batch->shader));
    
    harmony_checkError(glBindVertexArray(batch->vao));
    
    harmony_checkError(glBindBuffer(GL_ARRAY_BUFFER, batch->vbo));
    //printf("Calling glBufferData on GL_ARRAY_BUFFER with params: %I64i, %p\n", batch->quadsIndex * sizeof(harmony_quad_t), batch->quads);
    
    harmony_checkError(glBufferData(GL_ARRAY_BUFFER, batch->quadsIndex * sizeof(harmony_quad_t), batch->quads, GL_DYNAMIC_DRAW));
    
    harmony_checkError(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, batch->ebo));
    //printf("Calling glBufferData on GL_ELEMENT_ARRAY_BUFFER with params: %I64i, %p\n", batch->indicesIndex * sizeof(unsigned int), batch->indices);
    harmony_checkError(glBufferData(GL_ELEMENT_ARRAY_BUFFER, batch->indicesIndex * sizeof(unsigned int), batch->indices, GL_DYNAMIC_DRAW));
    
    int sampleUniformLoc = 5;
    
    int *samplers = malloc(HARMONY_BATCH_MAX_TEXTURES * sizeof(int));
    memset(samplers, 0, HARMONY_BATCH_MAX_TEXTURES * sizeof(int));
    // Iterate through textures, and glBindTextureUnit(i, textureVar) for each one
    for (int i = 0; i < batch->texturesIndex; i++)
    {
        samplers[i] = i;
        harmony_checkError(glBindTextureUnit(i, batch->textures[i]));
    }
    
    harmony_checkError(glUniform1iv(sampleUniformLoc, HARMONY_BATCH_MAX_TEXTURES, samplers));
    
    harmony_checkError(glDrawElements(GL_TRIANGLES, batch->quadsIndex * 6, GL_UNSIGNED_INT, BUFFER_OFFSET(0)));
    
    glUseProgram(0);
    
    free(samplers);
}
