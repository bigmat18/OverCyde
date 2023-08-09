#include "Shape.h"
#include <GL/glew.h>

#ifndef SURFACE_H
#define SURFACE_H

class Surface : public Shape
{
public:
    Surface(GLfloat side);
    void BuildShape();

private:
    GLfloat side;
};

#endif