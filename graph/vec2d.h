/**
 *
 * @file    vec2d.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.1
 * @brief   Représente un vecteur sur deux dimensions
 *
 **/

#ifndef VEC2D_H
#define VEC2D_H

#include <ostream>

struct Vec2D
{
    int x, y;

    // Constructeurs
    Vec2D(const int & x_ = 0, const int & y_ = 0)
      : x(x_)
      , y(y_)
    {}

    Vec2D(const Vec2D & pos_)
      : x (pos_.x)
      , y (pos_.y)
    {}

    // Décalage
    Vec2D operator + (const Vec2D & pos_) const
    {
      return Vec2D (x + pos_.x, y + pos_.y);
    }

    // Réduction
    Vec2D operator * (const float & reductionRation) const
    {
      return Vec2D (x * reductionRation, y * reductionRation);
    }

    friend Vec2D operator *(const float & reductionRation, const Vec2D & pos_)
    {
      return pos_ * (reductionRation);
    }

    // Égalité
    bool operator == (const Vec2D & pos_) const
    {
      return pos_.x == x && pos_.y == y;
    }

    // Assignement
    Vec2D& operator = (const Vec2D & pos_)
    {
      x = pos_.x;
      y = pos_.y;

      return *this;
    }

    Vec2D& operator += (const Vec2D& pos_)
    {
      x += pos_.x;
      y += pos_.y;

      return *this;
    }

    // Comparaison
    bool operator > (const Vec2D &pos_) const
    {
      return x > pos_.x && y > pos_.y;
    }

    bool operator < (const Vec2D &pos_) const
    {
      return x < pos_.x && y < pos_.y;
    }

    bool operator >= (const Vec2D &pos_) const
    {
      return x >= pos_.x && y >= pos_.y;
    }

    bool operator <= (const Vec2D &pos_) const
    {
      return x <= pos_.x && y <= pos_.y;
    }

    // Le min
    static Vec2D min (const Vec2D & p1, const Vec2D & p2)
    {
      if (p1.x < p2.x) return p1;
      else if (p1.x == p2.x && p1.y < p2.y) return p1;
      return p2;
    }

    // Pointeur de fonction sur min
    static bool minf (const Vec2D & p1, const Vec2D & p2)
    {
      return (p1 == min(p1, p2));
    }

    int & getAbs()
    {
      return x;
    }

    int & getOrd()
    {
      return y;
    }

    bool isInside(Vec2D firstCorner, Vec2D secondCorner) const
    {
        // On inverse les coordonnées si nécessaire
        if (secondCorner.x < firstCorner.x)
            std::swap(secondCorner.x, firstCorner.x);

        if (secondCorner.y < firstCorner.y)
            std::swap(secondCorner.y, firstCorner.y);

        // On retourne si notre vecteur est entre ces deux coins
        return (operator>=(firstCorner) && operator<=(secondCorner));
    }

    friend std::ostream &operator <<(std::ostream &os, const Vec2D &vec)
    {
      os << "X: " << vec.x << ", Y: " << vec.y;
      return os;
    }
};

#endif // VEC2D_H
