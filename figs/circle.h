/**
 *
 * @file    circle.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente un cercle
 *
 **/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include "../tools/myexception.h"

namespace nsShape
{
    class Circle : public Shape
    {
    public:
        Circle(const Vec2D & pos_, const unsigned & rad_, const RGBAcolor & inCol_, const RGBAcolor & borderCol_ = RGBAcolor ());
        virtual ~Circle() override = default;

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
}

#endif // CIRCLE_H
