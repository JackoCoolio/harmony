#include <gl/glew.h>
#include <gl/GL.h>

#include <stdio.h>
#include <string.h>

#include "harmony_buffer.h"

void harmony_setQuadData(harmony_quad_t *quads, unsigned int quadIndex, harmony_quad_t data)
{
    //               start     num of quads       size of quad
    //void *quadPtr = quads + quadIndex * sizeof(harmony_quad_t);
    //void *quadPtr = vertices + quadIndex * 4 * sizeof(harmony_vertex_t);
    
    quads[quadIndex] = data;
    
    //*((harmony_quad_t*)quadPtr) = data;
    // memset(quadPtr, data, sizeof(harmony_quad_t));
}

harmony_quad_t *harmony_getQuad(harmony_quad_t *quads, unsigned int quadIndex)
{
    return quads + quadIndex * sizeof(harmony_quad_t);
}

void harmony_printVertex(harmony_vertex_t *vertex)
{
    for (int i = 0; i < 9; i++)
    {
        printf("%f ", vertex->data[i]);
    }
    printf("\n");
}
