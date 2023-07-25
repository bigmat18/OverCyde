#include "Shape.h"
#include <GL/glew.h>

#ifndef CUBE_H
#define CUBE_H

typedef struct {
    GLfloat red;
    GLfloat green;
    GLfloat blue;
    GLfloat alpha;
} Color;

class Cube : public Shape {
    public:
        Cube(GLfloat side, const char *vertexPath, const char *fragmentPath, const Color* color = nullptr, const bool texture = false);
        void BuildShape();
        std::vector<Color>getColor();
        std::vector<Color>getTexture();

    private:
        const GLfloat side;
        const bool texture;
        const Color* color;
};

#endif