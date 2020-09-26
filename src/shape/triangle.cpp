/**
 *
 * @file    triangle.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente un triangle
 *
 **/

#include <algorithm>
#include <vector>

#include "mingl/shape/triangle.h"
#include "mingl/macros.h"

nsShape::Triangle::Triangle(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::Vec2D& thirdPosition,
                            const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor)
    : Shape(fillColor, borderColor)
    , m_firstPosition(firstPosition)
    , m_secondPosition(secondPosition)
    , m_thirdPosition(thirdPosition)
{} // Triangle()

void nsShape::Triangle::draw(MinGL& window) const
{
    UNUSED(window);

    // On règle la couleur du triangle
    const nsGraphics::RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.getRed(), inColor.getGreen(), inColor.getBlue(), inColor.getAlpha());

    // On dessine le triangle
    glBegin(GL_TRIANGLES);
    glVertex2i(m_firstPosition.getX(), m_firstPosition.getY());
    glVertex2i(m_secondPosition.getX(), m_secondPosition.getY());
    glVertex2i(m_thirdPosition.getX(), m_thirdPosition.getY());
    glEnd();

    if (getBorderColor() != nsGraphics::KTransparent) {
        // On a une bordure, on l'affiche
        const nsGraphics::RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.getRed(), borderColor.getGreen(), borderColor.getBlue(), borderColor.getAlpha());

        glBegin(GL_LINE_LOOP);
        glVertex2i(m_firstPosition.getX(), m_firstPosition.getY());
        glVertex2i(m_secondPosition.getX(), m_secondPosition.getY());
        glVertex2i(m_thirdPosition.getX(), m_thirdPosition.getY());
        glEnd();
    }
} // draw()

nsShape::Triangle nsShape::Triangle::operator+(const nsGraphics::Vec2D& position) const
{
    return Triangle(m_firstPosition + position, m_secondPosition + position, m_thirdPosition + position, getFillColor(), getBorderColor());
} // operator+()

nsShape::Triangle nsShape::Triangle::operator*(const float& f) const
{
    return Triangle(m_firstPosition * f, m_secondPosition * f, m_thirdPosition * f, getFillColor(), getBorderColor());
} // operator*()

const nsGraphics::Vec2D& nsShape::Triangle::getFirstPosition() const
{
    return m_firstPosition;
} // getFirstPosition()

void nsShape::Triangle::setFirstPosition(const nsGraphics::Vec2D &firstPosition)
{
    m_firstPosition = firstPosition;
} // setFirstPosition()

const nsGraphics::Vec2D& nsShape::Triangle::getSecondPosition() const
{
    return m_secondPosition;
} // getSecondPosition()

void nsShape::Triangle::setSecondPosition(const nsGraphics::Vec2D &secondPosition)
{
    m_secondPosition = secondPosition;
} // setSecondPosition()

const nsGraphics::Vec2D& nsShape::Triangle::getThirdPosition() const
{
    return m_thirdPosition;
} // getThirdPosition()

void nsShape::Triangle::setThirdPosition(const nsGraphics::Vec2D &thirdPosition)
{
    m_thirdPosition = thirdPosition;
} // setThirdPosition()
