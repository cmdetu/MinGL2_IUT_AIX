#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "basefig.h"

#include "../tools/myexception.h"
#include "../graph/iminglinjectable.h"

namespace nsFigure
{
    class Triangle : public BaseFig
    {
    public:
        Triangle(const Vec2D & pos1_, const Vec2D &pos2_, const Vec2D & pos3_, const RGBAcolor & fillCol_, const RGBAcolor & borderColl_ = RGBAcolor ());
        Triangle (const BaseFig &);
        virtual ~Triangle() {}

        virtual void draw(MinGL &window) override;

        // Opérateur de décalage +
        Triangle operator + (const Vec2D & pos_) const {
            return Triangle(pos1 + pos_, pos2 + pos_, pos3 + pos_, getInColor(), getBorderColor());
        }

        // Opérateur de réduction *
        Triangle operator * (const float & f) const {
            return Triangle(pos1 * f, pos2 * f, pos3 * f, getInColor(), getBorderColor());
        }

        // Fonction de clonage
        virtual std::unique_ptr<IDrawable> clone() const override;

    private:
        Vec2D pos1;
        Vec2D pos2;
        Vec2D pos3;
    };
}

#endif // TRIANGLE_H
