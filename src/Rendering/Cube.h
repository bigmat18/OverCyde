#include "Shape.h"
#include <GL/glew.h>

#ifndef CUBE_H
#define CUBE_H

class Cube : public Shape {
    public:
        Cube(GLfloat side);
        void BuildShape();

    private:
        GLfloat side;
};

#endif