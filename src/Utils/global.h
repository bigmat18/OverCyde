#include <iostream>
#include <glm/glm.hpp>

#ifndef GLOBAL_H
#define GLOBAL_H

#define DESTRUCT(color) color.x, color.y, color.z, color.w

const unsigned int HEIGHT = 800;
const unsigned int WIDTH = 900;

const float ZOOM = 45.0f;

const glm::vec4 BACKGROUND_COLOR(0.0f, 0.0f, 0.0f, 1.0f);

#endif