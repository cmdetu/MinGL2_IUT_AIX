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

#include "../macros.h"
#include "../tools/CstCodErr.h"
#include "circle.h"

using namespace std;
using namespace nsUtil;

nsShape::Circle::Circle(const Vec2D &position, const unsigned &radius, const RGBAcolor &fillColor, const RGBAcolor &borderColor)
    : Shape(fillColor, borderColor)
    , m_position(position)
    , m_radius(radius)
{

}

void nsShape::Circle::draw(MinGL &window)
{
    UNUSED(window);

    // Source: https://gist.github.com/linusthe3rd/803118

    int i;
    int triangleAmount = 20; // Nombre de triangles a dessiner

    // On règle la couleur du cercle
    const RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha); // Couleur du cercle

    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(m_position.x, m_position.y); // Centre du cercle

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(m_position.x + (m_radius * cos(i * twicePi / triangleAmount)),
                   m_position.y + (m_radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();

    if (getBorderColor() != KTransparent) {
        // On a une bordure, on l'affiche
        const RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.Red, borderColor.Green, borderColor.Blue, borderColor.Alpha);

        glBegin(GL_LINE_LOOP);

        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(m_position.x + (m_radius * cos(i * twicePi / triangleAmount)),
                       m_position.y + (m_radius * sin(i * twicePi / triangleAmount)));
        }

        glEnd();
    }
}

std::unique_ptr<IDrawable> nsShape::Circle::clone() const
{
    return std::unique_ptr<Circle>(new Circle(*this));
}
