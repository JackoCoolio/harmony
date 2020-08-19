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

// void harmony_initializeRenderPipeline()
// {
//     glViewport(0, 0, 640, 480);
// }

// harmony_batch_t *harmony_createBatch()
// {
//     harmony_batch_t *batch = malloc(sizeof(harmony_batch_t));

//     batch->size = 0;
//     batch->sprites = harmony_createLinkedList(NULL);

//     batch->vbo = 0;
//     batch->vao = 0;
//     batch->ebo = 0;
// }

// void harmony_initializeBatch(harmony_batch_t *batch)
// {
//     float vertices[] = {
//         0.0f, 1.0f, 0.0f, 1.0f,
//         1.0f, 0.0f, 1.0f, 0.0f,
//         0.0f, 0.0f, 0.0f, 0.0f,

//         0.0f, 1.0f, 0.0f, 1.0f,
//         1.0f, 1.0f, 1.0f, 1.0f,
//         1.0f, 0.0f, 1.0f, 0.0f
//     };

//     glGenVertexArrays(1, &batch->vao);
//     glGenBuffers(1, &batch->vbo);

//     glBindBuffer(GL_ARRAY_BUFFER, batch->vbo);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glBindVertexArray(batch->vao);
//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) 0);
//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);
// }

// void harmony_addSpriteToBatch(harmony_batch_t *batch, harmony_sprite_t *sprite)
// {
//     harmony_ll_append(batch->sprites, sprite);
// }

// void harmony_renderBatch(harmony_batch_t *batch)
// {
    
// }

// typedef struct harmony_vertex
// {
//     harmony_vec2_t pos;
//     harmony_vec2_t texCoords;
//     harmony_vec3_t color;
//     float texID;
// } harmony_vertex_t;

// typedef struct harmony_quad
// {
//     harmony_vertex_t a, b, c, d;
// } harmony_quad_t;

// harmony_quad_t createQuad(float x, float y, float size, float r, float g, float b, float texID)
// {
//     harmony_quad_t quad;

//     // Top Left
//     quad.a.pos = harmony_createVec2(x, y);
//     quad.a.texCoords = harmony_createVec2(0.0, 0.0);
//     quad.a.color = harmony_createVec3(r, g, b);
//     quad.a.texID = texID;

//     // Top Right
//     quad.b.pos = harmony_createVec2(x + size, y);
//     quad.b.texCoords = harmony_createVec2(1.0, 0.0);
//     quad.b.color = harmony_createVec3(r, g, b);
//     quad.b.texID = texID;

//     // Bottom Right
//     quad.c.pos = harmony_createVec2(x + size, y - size);
//     quad.c.texCoords = harmony_createVec2(1.0, 1.0);
//     quad.c.color = harmony_createVec3(r, g, b);
//     quad.c.texID = texID;

//     // Bottom Left
//     quad.d.pos = harmony_createVec2(x, y - size);
//     quad.d.texCoords = harmony_createVec2(0.0, 1.0);
//     quad.d.color = harmony_createVec3(r, g, b);
//     quad.d.texID = texID;

//     return quad;
// }

harmony_batch_t *batch;
harmony_texture_t tex;

void harmony_testInit()
{
    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 640, 480, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);

    batch = harmony_createBatch(1, 1);

    printf("%i\n", batch->texturesIndex);

    tex = harmony_createTexture("assets/texA.png", 1, 0, GL_REPEAT, GL_NEAREST);
    
    printf("%i", harmony_addTexture(batch, tex));

    printf("%i\n", batch->texturesIndex);

    printf("%i", harmony_addTexture(batch, tex));

    printf("%i\n", batch->texturesIndex);
}

void harmony_testRender(harmony_context_t *ctx)
{
}

// GLuint vbo, vao, ebo;
// harmony_shader_t shader;
// harmony_texture_t texA, texB;

// void harmony_testInit()
// {
//     glViewport(0, 0, 640, 480);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(0, 640, 480, 0, -1, 1);
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();

//     glDisable(GL_CULL_FACE);
//     glDisable(GL_DEPTH_TEST);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//     glEnable(GL_BLEND);
//     glDisable(GL_ALPHA_TEST);

//     shader = harmony_compileShaderFromFile("./default.vert", "./default.frag");
//     glBindFragDataLocation(shader, 0, "outColor");

//     texA = harmony_createTexture("assets/texA.png", 1, 0, GL_REPEAT, GL_NEAREST);
//     texB = harmony_createTexture("assets/heart.png", 1, 0, GL_REPEAT, GL_NEAREST);

//     printf("A: %i, B: %i\n", texA, texB);

//     harmony_quad_t quads[] = {
//         createQuad(-1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0),
//         createQuad(0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0)
//     };

//     int numQuads = sizeof(quads)/sizeof(harmony_quad_t);
//     // printf("Num Quads: %i\n", numQuads);
//     // printf("Bytes allocated for indices[]: %i\n", numQuads * 6 * sizeof(float));

//     int *indices = malloc(numQuads * 6 * sizeof(float));
//     for (int i = 0; i < numQuads; i++)
//     {
//         int offset = i * 4;
//         indices[i * 6 + 0] = 0 + offset;
//         indices[i * 6 + 1] = 2 + offset;
//         indices[i * 6 + 2] = 3 + offset;
//         indices[i * 6 + 3] = 0 + offset;
//         indices[i * 6 + 4] = 1 + offset;
//         indices[i * 6 + 5] = 2 + offset;
//     }

//     glGenVertexArrays(1, &vao);
//     glBindVertexArray(vao);

//     glGenBuffers(1, &vbo);
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(quads), quads, GL_STATIC_DRAW);

//     glGenBuffers(1, &ebo);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * numQuads * sizeof(int), indices, GL_STATIC_DRAW); // NOTICE "6 * numQuads", NOT sizeof(indices), because indices is a heap-allocated array.

//     GLint posAttrib = glGetAttribLocation(shader, "a_position");
//     glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), 0);
//     glEnableVertexAttribArray(posAttrib);

//     GLint texAttrib = glGetAttribLocation(shader, "a_texcoord");
//     glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), (void*) (2 * sizeof(GLfloat)));
//     glEnableVertexAttribArray(texAttrib);

//     GLint colorAttrib = glGetAttribLocation(shader, "a_color");
//     glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), (void*) (4 * sizeof(GLfloat)));
//     glEnableVertexAttribArray(colorAttrib);

//     GLint texIDAttrib = glGetAttribLocation(shader, "a_texID");
//     glVertexAttribPointer(texIDAttrib, 1, GL_FLOAT, GL_FALSE, sizeof(harmony_vertex_t), (void*) (7 * sizeof(GLfloat)));
//     glEnableVertexAttribArray(texIDAttrib);

//     glUseProgram(shader);
//     GLint sampleUniformLoc = glGetUniformLocation(shader, "u_sampler");
//     int samplers[2] = { 0, 1 };
//     glUniform1iv(sampleUniformLoc, 2, samplers);
//     glUseProgram(0);

//     glBindVertexArray(0);

//     glClearColor(0.2, 0.2, 0.2, 1.0);
// }

// void harmony_testRender(harmony_context_t *ctx)
// {
//     glClear(GL_COLOR_BUFFER_BIT);
    
//     glBindVertexArray(vao);

//     glUseProgram(shader);
//     glBindTextureUnit(0, texA);
//     glBindTextureUnit(1, texB);

//     harmony_logErrors();

//     harmony_checkError(glDrawElements(GL_TRIANGLES, 2 * 6, GL_UNSIGNED_INT, 0));

//     glBindVertexArray(0);

//     glfwSwapBuffers(ctx->window);
// }
