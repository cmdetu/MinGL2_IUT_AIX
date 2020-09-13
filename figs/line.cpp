#include "line.h"

#include <cmath>
#include "../macros.h"
#include "../tools/CstCodErr.h"
#include "../tools/tools.h"

using namespace std;
using namespace nsUtil;

void nsShape::Line::draw(MinGL &window)
{
    UNUSED(window);

    // On met la couleur de la ligne
    const RGBAcolor inColor = getInColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // On règle le volume de la ligne
    glLineWidth(lineWidth);

    // On dessine la ligne
    glBegin(GL_LINES);
    glVertex2i(pos1.x, pos1.y);
    glVertex2i(pos2.x, pos2.y);
    glEnd();
}

nsShape::Line::Line(const Vec2D & pos1_, const Vec2D & pos2_, const RGBAcolor &fillCol_, const float &lineWidth_)
    : Shape(fillCol_, fillCol_)
    , pos1(pos1_)
    , pos2(pos2_)
    , lineWidth(lineWidth_)
{

}

std::unique_ptr<IDrawable> nsShape::Line::clone() const
{
    return std::unique_ptr<Line>(new Line(*this));
}
