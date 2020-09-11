#include "tools.h"

/*
 * Renvoie le coefficient de la droite passant par pt1 et pt2, ET
 * pair<coef_directeur, decalage>
 */
std::pair<float, float> computeab(const Vec2D & pt1, const Vec2D & pt2)
{
    float a = (float ((int)pt2.y - (int)pt1.y)) / (float ((int)pt2.x - (int)pt1.x));
    float b = pt2.y - a * pt2.x;

    return std::make_pair (a,b);
} // computeab()
