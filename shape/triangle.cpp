/**
 *
 * @file    triangle.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente un triangle
 *
 **/

#include "triangle.h"

#include <algorithm>
#include <vector>

#include "line.h"
#include "../macros.h"
#include "../tools/CstCodErr.h"
#include "../tools/tools.h"

using namespace std;
using namespace nsUtil;


nsShape::Triangle::Triangle(const Vec2D& firstPosition, const Vec2D& secondPosition, const Vec2D& thirdPosition,
                            const RGBAcolor& fillColor, const RGBAcolor& borderColor)
    : Shape(fillColor, borderColor)
    , m_firstPosition(firstPosition)
    , m_secondPosition(secondPosition)
    , m_thirdPosition(thirdPosition)
{

}

void nsShape::Triangle::draw(MinGL &window)
{
    UNUSED(window);

    // On règle la couleur du triangle
    const RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // On dessine le triangle
    glBegin(GL_TRIANGLES);
    glVertex2i(m_firstPosition.x, m_firstPosition.y);
    glVertex2i(m_secondPosition.x, m_secondPosition.y);
    glVertex2i(m_thirdPosition.x, m_thirdPosition.y);
    glEnd();

    if (getBorderColor() != KTransparent) {
        // On a une bordure, on l'affiche
        const RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.Red, borderColor.Green, borderColor.Blue, borderColor.Alpha);

        glBegin(GL_LINE_LOOP);
        glVertex2i(m_firstPosition.x, m_firstPosition.y);
        glVertex2i(m_secondPosition.x, m_secondPosition.y);
        glVertex2i(m_thirdPosition.x, m_thirdPosition.y);
        glEnd();
    }
}

std::unique_ptr<IDrawable> nsShape::Triangle::clone() const
{
    return std::unique_ptr<Triangle>(new Triangle(*this));
}
