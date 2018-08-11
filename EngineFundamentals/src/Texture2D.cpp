#include "Texture2D.h"

#include "stb_image/stb_image.h"

Texture2D::Texture2D(std::string filePath) 
    :   _rendererID(0),
        _filePath(filePath),
        _pixelBuffer(nullptr),
        _width(0),
        _height(0),
        _bytesPerPixel(0)
{
    stbi_set_flip_vertically_on_load(1);
    _pixelBuffer = stbi_load(filePath.c_str(), &_width, &_height, &_bytesPerPixel, 4);

    if (_pixelBuffer)
    {
        printf("Texture loaded successfully -- {%s}\n", filePath.c_str());
    }
    else 
    {
        printf("Texture failed to load -- {%s}\n", filePath.c_str());
    }
    
    glGenTextures(1, &_rendererID);
    glBindTexture(GL_TEXTURE_2D, _rendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _pixelBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (_pixelBuffer)
    {
        stbi_image_free(_pixelBuffer);
    }
}

Texture2D::~Texture2D() 
{
    glDeleteTextures(1, &_rendererID);
}

void Texture2D::Bind(unsigned int unit) const
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, _rendererID);
}

void Texture2D::UnBind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
