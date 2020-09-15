/**
 *
 * @file    rectangle.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente un rectangle
 *
 **/

#include "rectangle.h"
#include "../macros.h"

nsShape::Rectangle::Rectangle(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor)
    : Shape(fillColor, borderColor)
    , m_firstPosition(firstPosition)
    , m_secondPosition(secondPosition)
{} // Rectangle()

nsShape::Rectangle::Rectangle(const nsGraphics::Vec2D& position, const unsigned& width, const unsigned& height, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor)
    : Shape(fillColor, borderColor)
    , m_firstPosition(position)
    , m_secondPosition(nsGraphics::Vec2D(position.getX() + width, position.getY() + height))
{} // Rectangle()

void nsShape::Rectangle::draw(MinGL& window) const
{
    UNUSED(window);

    // On règle la couleur du rectangle
    const nsGraphics::RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.getRed(), inColor.getGreen(), inColor.getBlue(), inColor.getAlpha());

    // Affiche un rectangle via la routine OpenGL
    glRecti(m_firstPosition.getX(), m_firstPosition.getY(), m_secondPosition.getX(), m_secondPosition.getY());

    if (getBorderColor() != nsGraphics::KTransparent) {
        // On a une bordure, on l'affiche
        const nsGraphics::RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.getRed(), borderColor.getGreen(), borderColor.getBlue(), borderColor.getAlpha());

        glBegin(GL_LINE_LOOP);
        glVertex2i(m_firstPosition.getX(), m_firstPosition.getY());
        glVertex2i(m_firstPosition.getX(), m_secondPosition.getY());
        glVertex2i(m_secondPosition.getX(), m_secondPosition.getY());
        glVertex2i(m_secondPosition.getX(), m_firstPosition.getY());
        glEnd();
    }
} // draw()

nsShape::Rectangle nsShape::Rectangle::operator+(const nsGraphics::Vec2D& position) const
{
    return Rectangle(m_firstPosition + position, m_secondPosition + position, getFillColor(), getBorderColor());
} // operator+()

nsShape::Rectangle nsShape::Rectangle::operator*(const float& f) const
{
    return Rectangle(m_firstPosition * f, m_secondPosition * f, getFillColor(), getBorderColor());
} // operator*()
