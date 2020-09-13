/**
 *
 * @file    line.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente une ligne
 *
 **/

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
        return Line(m_firstPosition + pos_, m_secondPosition + pos_, getFillColor());
    }

    // Opérateur de réduction *
    Line operator * (const float & f) const {
        return Line(m_firstPosition * f, m_secondPosition * f, getFillColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    Vec2D m_firstPosition;
    Vec2D m_secondPosition;
    float m_lineWidth;

};

}

#endif // LINE_H
