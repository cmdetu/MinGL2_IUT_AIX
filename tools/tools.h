#ifndef TOOLS_H
#define TOOLS_H

#include <algorithm> // min, max
#include "../graph/vec2d.h"

// On calcule les coeff a et b de la droite aX + b = Y passant par les 2 points pt1 et pt2
std::pair <float, float> computeab (const Vec2D & pt1, const Vec2D & pt2);

#endif // TOOLS_H
