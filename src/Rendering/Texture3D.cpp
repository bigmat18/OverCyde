#include "Texture3D.h"
#include <GL/glew.h>

Texture3D::Texture3D(const std::vector<std::string> &paths) : Texture(), 
                                                              filePaths(paths)
{
    this->SetFlipVerticallyOnLoad(false);
    glGenTextures(1, &this->rendererID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->rendererID);

    for(int i = 0; i<this->filePaths.size(); i++) {
        this->LoadImageBuffer(this->filePaths[i].c_str());
        if (this->localBuffer) {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                         0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->localBuffer);
        }
        this->FreeImageBuffer();
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

Texture3D::~Texture3D() { glDeleteTextures(1, &this->rendererID); }

void Texture3D::Bind(GLuint slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->rendererID);
}

void Texture3D::Unbind() { glBindTexture(GL_TEXTURE_CUBE_MAP, 0); }