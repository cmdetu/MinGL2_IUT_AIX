#include <iostream>

#include "basefig.h"

#include "../macros.h"

using namespace std;

BaseFig::BaseFig()
{}

void BaseFig::draw(MinGL &window)
{
    UNUSED(window);
}

BaseFig::BaseFig(const RGBAcolor & inCol_, const RGBAcolor & bdCol_, const std::string &name_)
    : inColor (inCol_)
    , borderColor (bdCol_)
    , name (name_)
{}

std::unique_ptr<IDrawable> BaseFig::clone() const
{
    return std::unique_ptr<BaseFig>(new BaseFig(*this));
}

const RGBAcolor BaseFig::getBorderColor() const
{
    return borderColor;
}

const RGBAcolor BaseFig::getInColor() const
{
    return inColor;
}

const string BaseFig::getName() const
{
    return name;
}

void BaseFig::setInColor(const RGBAcolor &inColor_)
{
    inColor = inColor_;
}

void BaseFig::setBorderColor(const RGBAcolor &borderColor_)
{
    borderColor = borderColor_;
}
