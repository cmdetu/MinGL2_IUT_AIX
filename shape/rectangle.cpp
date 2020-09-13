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

void nsShape::Rectangle::draw(MinGL &window)
{
    UNUSED(window);

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

nsShape::Rectangle::Rectangle(const Vec2D &pos1_, const Vec2D &pos2_, const RGBAcolor &inCol_, const RGBAcolor &borderCol_)
    : Shape(inCol_, borderCol_)
    , m_firstPosition(pos1_)
    , m_secondPosition(pos2_)
{

}

nsShape::Rectangle::Rectangle(const Vec2D &pos_, const unsigned &width_, const unsigned &height_, const RGBAcolor &inCol_, const RGBAcolor &borderCol_)
    : Shape(inCol_, borderCol_)
    , m_firstPosition(pos_)
    , m_secondPosition(Vec2D(pos_.x + width_, pos_.y + height_))
{

}

std::unique_ptr<IDrawable> nsShape::Rectangle::clone() const
{
    return std::unique_ptr<Rectangle>(new Rectangle(*this));
}
