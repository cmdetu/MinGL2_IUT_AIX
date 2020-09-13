/**
 *
 * @file    triangle.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente un triangle
 *
 **/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

#include "../tools/myexception.h"
#include "../graph/iminglinjectable.h"

namespace nsShape
{

class Triangle : public Shape
{

public:
    Triangle(const Vec2D & pos1_, const Vec2D &pos2_, const Vec2D & pos3_, const RGBAcolor & fillCol_, const RGBAcolor & borderColl_ = RGBAcolor ());
    virtual ~Triangle() override = default;

    virtual void draw(MinGL &window) override;

    // Opérateur de décalage +
    Triangle operator + (const Vec2D & pos_) const {
        return Triangle(m_firstPosition + pos_, m_secondPosition + pos_, m_thirdPosition + pos_, getFillColor(), getBorderColor());
    }

    // Opérateur de réduction *
    Triangle operator * (const float & f) const {
        return Triangle(m_firstPosition * f, m_secondPosition * f, m_thirdPosition * f, getFillColor(), getBorderColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    Vec2D m_firstPosition;
    Vec2D m_secondPosition;
    Vec2D m_thirdPosition;

};

}

#endif // TRIANGLE_H
