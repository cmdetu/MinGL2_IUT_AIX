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
#include "../tools/CstCodErr.h"
#include "triangle.h"
#include "line.h"

using namespace std;
using namespace nsUtil;

nsShape::Rectangle::Rectangle(const Vec2D& firstPosition, const Vec2D& secondPosition, const RGBAcolor& fillColor, const RGBAcolor& borderColor)
    : Shape(fillColor, borderColor)
    , m_firstPosition(firstPosition)
    , m_secondPosition(secondPosition)
{

}

nsShape::Rectangle::Rectangle(const Vec2D& position, const unsigned& width, const unsigned& height, const RGBAcolor& fillColor, const RGBAcolor& borderColor)
    : Shape(fillColor, borderColor)
    , m_firstPosition(position)
    , m_secondPosition(Vec2D(position.x + width, position.y + height))
{

}

void nsShape::Rectangle::draw()
{
    // On règle la couleur du rectangle
    const RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // Affiche un rectangle via la routine OpenGL
    glRecti(m_firstPosition.x, m_firstPosition.y, m_secondPosition.x, m_secondPosition.y);

    if (getBorderColor() != KTransparent) {
        // On a une bordure, on l'affiche
        const RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.Red, borderColor.Green, borderColor.Blue, borderColor.Alpha);

        glBegin(GL_LINE_LOOP);
        glVertex2i(m_firstPosition.x, m_firstPosition.y);
        glVertex2i(m_firstPosition.x, m_secondPosition.y);
        glVertex2i(m_secondPosition.x, m_secondPosition.y);
        glVertex2i(m_secondPosition.x, m_firstPosition.y);
        glEnd();
    }
}

std::unique_ptr<IDrawable> nsShape::Rectangle::clone() const
{
    return std::unique_ptr<Rectangle>(new Rectangle(*this));
}
