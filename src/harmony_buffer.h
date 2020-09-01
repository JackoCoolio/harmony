#ifndef HARMONY_BUFFER_H
#define HARMONY_BUFFER_H

typedef unsigned int GLenum;

typedef union harmony_vertex
{
    struct
    {
        float position[2];
        float color[4];
        float textureIndex;
        float textureCoordinates[2];
    };
    float data[9];
} harmony_vertex_t;

typedef union harmony_quad
{
    struct
    {
        harmony_vertex_t v1;
        harmony_vertex_t v2;
        harmony_vertex_t v3;
        harmony_vertex_t v4;
    };
    float data[36];
} harmony_quad_t;

void harmony_setQuadData(harmony_quad_t *vertices, unsigned int quadIndex, harmony_quad_t data);

harmony_quad_t *harmony_getQuad(harmony_quad_t *vertices, unsigned int quadIndex);



void harmony_printVertex(harmony_vertex_t *vertex);

#endif
