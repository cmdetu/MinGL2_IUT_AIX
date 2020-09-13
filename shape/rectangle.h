/**
 *
 * @file    rectangle.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente un rectangle
 *
 **/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

#include "../tools/myexception.h"

namespace nsShape
{

class Rectangle : public Shape
{

public:
    Rectangle(const Vec2D & pos1_, const Vec2D & pos2_, const RGBAcolor & inCol_, const RGBAcolor & borderCol_ = RGBAcolor ());
    Rectangle(const Vec2D & Vec2D_, const unsigned & width_, const unsigned & height_, const RGBAcolor & inCol_, const RGBAcolor & borderCol_ = KTransparent);
    virtual ~Rectangle() override = default;

    virtual void draw(MinGL &window) override;

    // Opérateur de décalage +
    Rectangle operator + (const Vec2D & pos_) const {
        return Rectangle(m_firstPosition + pos_, m_secondPosition + pos_, getFillColor(), getBorderColor());
    }

    // Opérateur de réduction *
    Rectangle operator * (const float & f) const {
        return Rectangle(m_firstPosition * f, m_secondPosition * f, getFillColor(), getBorderColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    Vec2D m_firstPosition;
    Vec2D m_secondPosition;

};

}

#endif // RECTANGLE_H
