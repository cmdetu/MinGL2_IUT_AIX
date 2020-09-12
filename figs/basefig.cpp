#include <iostream>

#include "basefig.h"

#include "../macros.h"

using namespace std;

nsFigure::BaseFig::BaseFig()
{}

void nsFigure::BaseFig::draw(MinGL &window)
{
    UNUSED(window);
}

nsFigure::BaseFig::BaseFig(const RGBAcolor & inCol_, const RGBAcolor & bdCol_, const std::string &name_)
    : inColor (inCol_)
    , borderColor (bdCol_)
    , name (name_)
{}

std::unique_ptr<IDrawable> nsFigure::BaseFig::clone() const
{
    return std::unique_ptr<BaseFig>(new BaseFig(*this));
}

const RGBAcolor nsFigure::BaseFig::getBorderColor() const
{
    return borderColor;
}

const RGBAcolor nsFigure::BaseFig::getInColor() const
{
    return inColor;
}

const string nsFigure::BaseFig::getName() const
{
    return name;
}

void nsFigure::BaseFig::setInColor(const RGBAcolor &inColor_)
{
    inColor = inColor_;
}

void nsFigure::BaseFig::setBorderColor(const RGBAcolor &borderColor_)
{
    borderColor = borderColor_;
}
