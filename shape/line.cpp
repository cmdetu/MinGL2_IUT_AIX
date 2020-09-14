/**
 *
 * @file    line.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente une ligne
 *
 **/

#include "line.h"

#include <cmath>
#include "../macros.h"
#include "../tools/CstCodErr.h"
#include "../tools/tools.h"

using namespace std;
using namespace nsUtil;

nsShape::Line::Line(const Vec2D & pos1_, const Vec2D & pos2_, const RGBAcolor &fillCol_, const float &lineWidth_)
    : Shape(fillCol_, fillCol_)
    , m_firstPosition(pos1_)
    , m_secondPosition(pos2_)
    , m_lineWidth(lineWidth_)
{

}

void nsShape::Line::draw(MinGL& window) const
{
    UNUSED(window);

    // On met la couleur de la ligne
    const RGBAcolor inColor = getFillColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // On règle le volume de la ligne
    glLineWidth(m_lineWidth);

    // On dessine la ligne
    glBegin(GL_LINES);
    glVertex2i(m_firstPosition.x, m_firstPosition.y);
    glVertex2i(m_secondPosition.x, m_secondPosition.y);
    glEnd();
}
