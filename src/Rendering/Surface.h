#include "Shape.h"
#include <GL/glew.h>

#ifndef SURFACE_H
#define SURFACE_H

class Surface : public Shape
{
public:
    Surface(GLfloat height, GLfloat width);
    void BuildShape();

private:
    GLfloat height, width;
};

#endif