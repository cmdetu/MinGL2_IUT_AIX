/**
 *
 * @file    rgbacolor.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.1
 * @brief   Représente une couleur RGBA
 *
 **/

#ifndef RGBACOLOR_H
#define RGBACOLOR_H

#include <GL/freeglut.h> // GLubyte
#include "../tools/IEditable.h"

class RGBAcolor : public nsUtil::IEditable
{

public:
    GLubyte Red;
    GLubyte Green;
    GLubyte Blue;
    GLubyte Alpha;

    RGBAcolor (const GLubyte & R = 0, const GLubyte & G = 0, const GLubyte & B = 0, const GLubyte & A = 255)
        : Red (R)
        , Green (G)
        , Blue (B)
        , Alpha(A)
    {}

    bool operator ==(const RGBAcolor & col) const {
        return col.Red == Red && col.Green == Green && col.Blue == Blue && col.Alpha == Alpha;
    }

    bool operator !=(const RGBAcolor &col) const {
        return col.Red != Red || col.Green != Green || col.Blue != Blue || col.Alpha != Alpha;
    }

    RGBAcolor operator *(const float &rhs) const {
        return RGBAcolor(Red * rhs, Green * rhs, Blue * rhs, Alpha * rhs);
    }

    RGBAcolor operator +(const RGBAcolor &rhs) const {
        return RGBAcolor(Red + rhs.Red, Green + rhs.Green, Blue + rhs.Blue, Alpha + rhs.Alpha);
    }

protected:
   virtual std::ostream & _Edit (std::ostream & os = std::cout) const;

};

// Quelques couleurs trouvées sur:
// https://www.rapidtables.com/web/color/RGB_Color.html
const RGBAcolor KBlack       {  0,   0,   0};
const RGBAcolor KWhite       {255, 255, 255};
const RGBAcolor KRed         {255,   0,   0};
const RGBAcolor KLime        {  0, 255,   0};
const RGBAcolor KBlue        {  0,   0, 255};
const RGBAcolor KYellow      {255, 255,   0};
const RGBAcolor KCyan        {  0, 255, 255};
const RGBAcolor KMagenta     {255,   0, 255};
const RGBAcolor KSilver      {192, 192, 192};
const RGBAcolor KGray        {128, 128, 128};
const RGBAcolor KMaroon      {128,   0,   0};
const RGBAcolor KOlive       {128, 128,   0};
const RGBAcolor KGreen       {  0, 128,   0};
const RGBAcolor KPurple      {128,   0, 128};
const RGBAcolor KTeal        {  0, 128, 128};
const RGBAcolor KNavy        {  0,   0, 128};
const RGBAcolor KTransparent {  0,   0,   0,  0};

#endif // RGBACOLOR_H
