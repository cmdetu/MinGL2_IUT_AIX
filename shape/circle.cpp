/**
 *
 * @file    circle.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente un cercle
 *
 **/

#include <cmath>

#include "circle.h"
#include "../macros.h"

nsShape::Circle::Circle(const nsGraphics::Vec2D &position, const unsigned &radius, const nsGraphics::RGBAcolor &fillColor, const nsGraphics::RGBAcolor &borderColor)
    : Shape(fillColor, borderColor)
    , m_position(position)
    , m_radius(radius)
{} // Circle()

void nsShape::Circle::draw(MinGL& window) const
{
    UNUSED(window);

    // Source: https://gist.github.com/linusthe3rd/803118

    int i;
    int triangleAmount = 20; // Nombre de triangles a dessiner

    // On règle la couleur du cercle
    const nsGraphics::RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.getRed(), inColor.getGreen(), inColor.getBlue(), inColor.getAlpha()); // Couleur du cercle

    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(m_position.getX(), m_position.getY()); // Centre du cercle

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(m_position.getX() + (m_radius * cos(i * twicePi / triangleAmount)),
                   m_position.getY() + (m_radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();

    if (getBorderColor() != nsGraphics::KTransparent) {
        // On a une bordure, on l'affiche
        const nsGraphics::RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.getRed(), borderColor.getGreen(), borderColor.getBlue(), borderColor.getAlpha());

        glBegin(GL_LINE_LOOP);

        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(m_position.getX() + (m_radius * cos(i * twicePi / triangleAmount)),
                       m_position.getY() + (m_radius * sin(i * twicePi / triangleAmount)));
        }

        glEnd();
    }
} // draw()

nsShape::Circle nsShape::Circle::operator+(const nsGraphics::Vec2D& position) const
{
    return Circle(m_position + position, m_radius, getFillColor(), getBorderColor());
} // operator+()

nsShape::Circle nsShape::Circle::operator*(const float& f) const
{
    return Circle(m_position * f, m_radius, getFillColor(), getBorderColor());
} // operator*()
