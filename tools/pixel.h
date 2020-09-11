#ifndef PIXEL_H
#define PIXEL_H

#include <string>

#include "../graph/rgbacolor.h"
#include "tools.h"

class Pixel
{
public:
    unsigned abs, ord;
    RGBAcolor color;

    Pixel (const unsigned & Abscisse = 0, const unsigned & Ordonnee = 0, const RGBAcolor & coul = RGBAcolor ());

    Pixel operator +(const Pixel & pix) const {
        return Pixel(abs + pix.abs, ord + pix.ord, color);
    }

    bool operator ==(const Pixel & pix) const {
        return pix.abs == abs && pix.ord == ord;
    }

    Pixel operator *(const float & reductionRation) const {
        return Pixel(abs * reductionRation, ord * reductionRation);
    }

    Pixel operator *(const Pixel & pix) const {
        return Pixel(abs * pix.abs, ord * pix.ord);
    }
};

#endif // PIXEL_H
