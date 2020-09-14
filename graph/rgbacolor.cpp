/**
 *
 * @file    rgbacolor.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.1
 * @brief   Représente une couleur RGBA
 *
 **/

#include "rgbacolor.hpp"

std::ostream &RGBAcolor::_Edit(std::ostream &os) const
{
    os << "R: " << int(Red) << ", G: " << int(Green) << ", B: " << int(Blue) << ", A: " << int(Alpha);
    return os;
}
