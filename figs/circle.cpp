#include <cmath>

#include "../macros.h"
#include "../tools/CstCodErr.h"
#include "circle.h"

using namespace std;
using namespace nsUtil;

void nsShape::Circle::draw(MinGL &window)
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

nsShape::Circle::Circle(const Vec2D &pos_, const unsigned &rad_, const RGBAcolor &inCol_, const RGBAcolor &borderCol_)
    : Shape(inCol_, borderCol_)
    , pos(pos_)
    , radius(rad_)
{

}

std::unique_ptr<IDrawable> nsShape::Circle::clone() const
{
    return std::unique_ptr<Circle>(new Circle(*this));
}
