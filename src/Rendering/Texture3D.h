#include <GL/glew.h>
#include <string>
#include <vector>
#include "Texture.h"

#ifndef TEXTURE3D_H
#define TEXTURE3D_H

class Texture3D : public Texture {
    private:
        std::vector<std::string> filePaths;

    public:
        Texture3D(const std::vector<std::string> &paths);
        ~Texture3D();

        void Bind(GLuint slot = 0) override;
        void Unbind() override;
};

#endif