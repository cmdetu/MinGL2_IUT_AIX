#include "triangle.h"

#include <algorithm>
#include <vector>

#include "line.h"
#include "../macros.h"
#include "../tools/CstCodErr.h"
#include "../tools/tools.h"

using namespace std;
using namespace nsUtil;

void nsShape::Triangle::draw(MinGL &window)
{
    UNUSED(window);

    // On règle la couleur du triangle
    const RGBAcolor inColor = getInColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha);

    // On dessine le triangle
    glBegin(GL_TRIANGLES);
    glVertex2i(pos1.x, pos1.y);
    glVertex2i(pos2.x, pos2.y);
    glVertex2i(pos3.x, pos3.y);
    glEnd();

    if (getBorderColor() != KTransparent) {
        // On a une bordure, on l'affiche
        const RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.Red, borderColor.Green, borderColor.Blue, borderColor.Alpha);

        glBegin(GL_LINE_LOOP);
        glVertex2i(pos1.x, pos1.y);
        glVertex2i(pos2.x, pos2.y);
        glVertex2i(pos3.x, pos3.y);
        glEnd();
    }
}

nsShape::Triangle::Triangle(const Vec2D &pos1_, const Vec2D &pos2_, const Vec2D &pos3_, const RGBAcolor &fillCol_, const RGBAcolor &borderCol_)
    : Shape(fillCol_, borderCol_)
    , pos1(pos1_)
    , pos2(pos2_)
    , pos3(pos3_)
{

}

std::unique_ptr<IDrawable> nsShape::Triangle::clone() const
{
    return std::unique_ptr<Triangle>(new Triangle(*this));
}
