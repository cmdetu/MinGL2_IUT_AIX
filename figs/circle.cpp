#define _USE_MATH_DEFINES
#include <cmath>

#include "../macros.h"
#include "../tools/CstCodErr.h"
#include "circle.h"

using namespace std;
using namespace nsUtil;

void nsFigure::Circle::draw(MinGL &window)
{
    UNUSED(window);

    // Source: https://gist.github.com/linusthe3rd/803118

    int i;
    int triangleAmount = 20; // Nombre de triangles a dessiner

    // On règle la couleur du cercle
    const RGBAcolor inColor = getInColor();
    glColor4ub(inColor.Red, inColor.Green, inColor.Blue, inColor.Alpha); // Couleur du cercle

    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(pos.x, pos.y); // Centre du cercle

    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(pos.x + (radius * cos(i * twicePi / triangleAmount)),
                   pos.y + (radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();

    if (getBorderColor() != KTransparent) {
        // On a une bordure, on l'affiche
        const RGBAcolor borderColor = getBorderColor();
        glColor4ub(borderColor.Red, borderColor.Green, borderColor.Blue, borderColor.Alpha);

        glBegin(GL_LINE_LOOP);

        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(pos.x + (radius * cos(i * twicePi / triangleAmount)),
                       pos.y + (radius * sin(i * twicePi / triangleAmount)));
        }

        glEnd();
    }
}

nsFigure::Circle::Circle(const Vec2D &pos_, const unsigned &rad_, const RGBAcolor &inCol_, const RGBAcolor &borderCol_)
    : BaseFig(inCol_, borderCol_, "circle")
    , pos(pos_)
    , radius(rad_)
{

}

nsFigure::Circle::Circle(const BaseFig & b)
    : BaseFig(b.getInColor(), b.getBorderColor(), b.getName())
{

}

std::unique_ptr<IDrawable> nsFigure::Circle::clone() const
{
    return std::unique_ptr<Circle>(new Circle(*this));
}
