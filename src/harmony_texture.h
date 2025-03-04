#ifndef HARMONY_TEXTURE_H
#define HARMONY_TEXTURE_H

typedef unsigned int harmony_texture_t;

harmony_texture_t harmony_createTexture(const char *path, int alpha, int generateMipmap, int wrapMode, int filterMode);

float *harmony_convertImageToTextureCoordinates(int x, int y, int w, int h);

// harmony_texture_t harmony_createTextureArrayVertical(const char *path, int alpha, int generateMipmap, int wrapMode, int filterMode, int numFrames);

#endif
