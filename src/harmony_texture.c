#include <GL/glew.h>
#include <GL/GL.h>
#include <lodepng.h>

#include "harmony_texture.h"

harmony_texture_t harmony_createTexture(const char *path, int alpha, int generateMipmap, int wrapMode, int filterMode)
{
    harmony_texture_t tex;
    glGenTextures(1, &tex); // Generate an ID for the texture.

    glBindTexture(GL_TEXTURE_2D, tex); // Bind texture.

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode); // Set horizontal wrap mode.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode); // Set vertical wrap mode.

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMode); // Set filter mode for minification.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMode); // Set filter mode for magnification.

    if (generateMipmap)
        glGenerateMipmap(GL_TEXTURE_2D); // Generate mipmaps.

    unsigned char *image;
    int width, height;
    if (alpha)
    {
        lodepng_decode32_file(&image, &width, &height, path); // Read RGBA image.
    }
    else
    {
        lodepng_decode24_file(&image, &width, &height, path); // Read RGB image.
    }

    glTexImage2D(GL_TEXTURE_2D, 0, (alpha)? GL_RGBA : GL_RGB, width, height, 0, (alpha)? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image); // Load texture.

    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture.

    return tex;
}

harmony_texture_t harmony_createTextureArrayVertical(const char *path, int alpha, int generateMipmap, int wrapMode, int filterMode, int numFrames)
{
    harmony_texture_t tex;
    glGenTextures(1, &tex);

    glBindTexture(GL_TEXTURE_2D_ARRAY, tex);

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, wrapMode);

    glTexParamateri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, filterMode);
    glTexParamateri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, filterMode);

    if (generateMipmap)
        glGenerateMipmap(GL_TEXTURE_2D_ARRAY);

    unsigned char *image;
    int width, height, frameHeight;
    if (alpha)
    {
        lodepng_decode32_file(&image, &width, &height, path); // Read RGBA image.
    }
    else
    {
        lodepng_decode24_file(&image, &width, &height, path); // Read RGB image.
    }

    frameHeight = height / numFrames;

    glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, (alpha)? GL_RGBA : GL_RGB, width, height, numFrames);

    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0, width, height, numFrames, (alpha)? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);

    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);

    return tex;
}
