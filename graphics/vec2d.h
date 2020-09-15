/**
 *
 * @file    vec2d.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.2
 * @brief   Représente un vecteur sur deux dimensions
 *
 **/

#ifndef VEC2D_H
#define VEC2D_H

#include <ostream>

#include "../tools/ieditable.h"

namespace nsGraphics
{

class Vec2D : public nsUtil::IEditable
{

public:
    Vec2D(const int& x = 0, const int& y = 0);
    Vec2D(const Vec2D& pos);

    Vec2D operator+(const Vec2D& pos) const;
    Vec2D operator*(const float& reductionRation) const;

    bool operator==(const Vec2D& pos) const;

    bool operator>(const Vec2D& pos) const;
    bool operator<(const Vec2D& pos) const;
    bool operator>=(const Vec2D& pos) const;
    bool operator<=(const Vec2D& pos) const;

    Vec2D& operator=(const Vec2D& pos);
    Vec2D& operator+=(const Vec2D& pos);

    static Vec2D min(const Vec2D& p1, const Vec2D& p2);
    static bool minf(const Vec2D& p1, const Vec2D& p2);

    bool isColliding(Vec2D firstCorner, Vec2D secondCorner) const;

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

protected:
    virtual std::ostream& _Edit(std::ostream& os = std::cout) const override;

private:
    int m_x;
    int m_y;

}; // class Vec2D

} // namespace nsGraphics

#endif // VEC2D_H
