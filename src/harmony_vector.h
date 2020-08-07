#ifndef HARMONY_VECTOR_H
#define HARMONY_VECTOR_H

#include <malloc.h>

typedef struct harmony_vec2
{
    float x, y;
} harmony_vec2_t;

typedef struct harmony_vec3
{
    float x, y, z;
} harmony_vec3_t;

typedef struct harmony_vec4
{
    float x, y, z, w;
} harmony_vec4_t;

extern inline harmony_vec2_t harmony_createVec2(float x, float y)
{
    harmony_vec2_t vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

extern inline harmony_vec2_t *harmony_createVec2Alloc(float x, float y)
{
    harmony_vec2_t *vec = (harmony_vec2_t*) malloc(sizeof(harmony_vec2_t));
    vec->x = x;
    vec->y = y;
    return vec;
}

extern inline harmony_vec3_t harmony_createVec3(float x, float y, float z)
{
    harmony_vec3_t vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}

extern inline harmony_vec3_t *harmony_createVec3Alloc(float x, float y, float z)
{
    harmony_vec3_t *vec = (harmony_vec3_t*) malloc(sizeof(harmony_vec3_t));
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return vec;
}

extern inline harmony_vec4_t harmony_createVec4(float x, float y, float z, float w)
{
    harmony_vec4_t vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = w;
    return vec;
}

extern inline harmony_vec4_t *harmony_createVec4Alloc(float x, float y, float z, float w)
{
    harmony_vec4_t *vec = (harmony_vec4_t*) malloc(sizeof(harmony_vec4_t));
    vec->x = x;
    vec->y = y;
    vec->z = z;
    vec->w = w;
    return vec;
}

#endif