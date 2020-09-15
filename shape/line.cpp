/**
 *
 * @file    line.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente une ligne
 *
 **/

#include <cmath>

#include "line.h"
#include "../macros.h"

nsShape::Line::Line(const nsGraphics::Vec2D & pos1_, const nsGraphics::Vec2D & pos2_, const nsGraphics::RGBAcolor &fillCol_, const float &lineWidth_)
    : Shape(fillCol_, fillCol_)
    , m_firstPosition(pos1_)
    , m_secondPosition(pos2_)
    , m_lineWidth(lineWidth_)
{} // Line()

void nsShape::Line::draw(MinGL& window) const
{
    UNUSED(window);

    // On met la couleur de la ligne
    const nsGraphics::RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.getRed(), inColor.getGreen(), inColor.getBlue(), inColor.getAlpha());

    // On règle le volume de la ligne
    glLineWidth(m_lineWidth);

    // On dessine la ligne
    glBegin(GL_LINES);
    glVertex2i(m_firstPosition.getX(), m_firstPosition.getY());
    glVertex2i(m_secondPosition.getX(), m_secondPosition.getY());
    glEnd();
} // draw()

nsShape::Line nsShape::Line::operator+(const nsGraphics::Vec2D& position) const
{
    return Line(m_firstPosition + position, m_secondPosition + position, getFillColor());
} // operator+()

nsShape::Line nsShape::Line::operator*(const float& f) const
{
    return Line(m_firstPosition * f, m_secondPosition * f, getFillColor());
} // operator*()
