#ifndef CIRCLE_H
#define CIRCLE_H

#include "basefig.h"

#include "../tools/myexception.h"

class Circle : public BaseFig
{
public:
    Circle(const Vec2D & pos_, const unsigned & rad_, const RGBAcolor & inCol_, const RGBAcolor & borderCol_ = RGBAcolor ());
    Circle(const BaseFig &);
    virtual ~Circle() {}

    virtual void draw(MinGL &window) override;

    // Opérateur de décalage +
    Circle operator + (const Vec2D & pos_) const {
        return Circle(pos + pos_, radius, getInColor(), getBorderColor());
    }

    // Opérateur de réduction *
    Circle operator * (const float & f) const {
        return Circle(pos * f, radius, getInColor(), getBorderColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    Vec2D pos;
    unsigned radius;
};

#endif // CIRCLE_H
