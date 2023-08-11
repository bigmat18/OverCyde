#include "Shape.h"
#include <GL/glew.h>

#ifndef CUBE_H
#define CUBE_H

class Cube : public Shape {
    public:
        Cube(GLfloat side, const bool is3D);
        void BuildShape();

    private:
        void BuildShape3D();
        void BuildShape2D();
        
        GLfloat side;
        bool is3D;
};

#endif