/**
 *
 * @file    shape.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente une forme
 *
 **/

#include "shape.h"

nsShape::Shape::Shape(const RGBAcolor &inColor, const RGBAcolor &borderColor)
    : m_fillColor(inColor)
    , m_borderColor(borderColor)
{

}

const RGBAcolor &nsShape::Shape::getFillColor() const
{
    return m_fillColor;
}

const RGBAcolor &nsShape::Shape::getBorderColor() const
{
    return m_borderColor;
}
