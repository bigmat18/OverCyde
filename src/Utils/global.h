#include <iostream>
#include <glm/glm.hpp>

#ifndef GLOBAL_H
#define GLOBAL_H

#define DESTRUCT(color) color.x, color.y, color.z, color.w

const u_int16_t HEIGHT = 1200;
const u_int16_t WEIGHT = 900;

const glm::vec4 BACKGROUND_COLOR(0.0f, 0.0f, 0.0f, 1.0f);

#endif