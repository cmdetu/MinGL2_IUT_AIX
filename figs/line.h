#ifndef LINE_H
#define LINE_H

#include "shape.h"

#include "../tools/myexception.h"

namespace nsShape
{

class Line : public Shape
{

public:
    Line(const Vec2D& pos1_, const Vec2D & pos2_, const RGBAcolor & fillCol_ = RGBAcolor (), const float &lineWidth_ = 1.f);
    virtual ~Line() override = default;

    virtual void draw(MinGL &window) override;

    // Opérateur de décalage +
    Line operator + (const Vec2D & pos_) const {
        return Line(pos1 + pos_, pos2 + pos_, getInColor());
    }

    // Opérateur de réduction *
    Line operator * (const float & f) const {
        return Line(pos1 * f, pos2 * f, getInColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    Vec2D pos1;
    Vec2D pos2;
    float lineWidth;

};

}

#endif // LINE_H
