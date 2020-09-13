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
        return Circle(m_position + pos_, m_radius, getFillColor(), getBorderColor());
    }

    // Opérateur de réduction *
    Circle operator * (const float & f) const {
        return Circle(m_position * f, m_radius, getFillColor(), getBorderColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    Vec2D m_position;
    unsigned m_radius;

};

}

#endif // CIRCLE_H
