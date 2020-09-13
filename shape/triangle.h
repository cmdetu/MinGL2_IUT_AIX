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

/**
 * @class Triangle
 * @brief Classe représentant un triangle
 */
class Triangle : public Shape
{

public:
    /**
     * @brief Constructeur pour la classe Triangle
     * @param[in] firstPosition : Position du premier sommet
     * @param[in] secondPosition : Position du second sommet
     * @param[in] thirdPosition : Position du troisième sommet
     * @param[in] fillColor : Couleur de remplissage
     * @param[in] borderColor : Couleur de bord
     * @fn Triangle(const Vec2D& firstPosition, const Vec2D& secondPosition, const Vec2D& thirdPosition,
             const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);
     */
    Triangle(const Vec2D& firstPosition, const Vec2D& secondPosition, const Vec2D& thirdPosition,
             const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);

    /**
     * @brief Destructeur virtuel pour la classe Triangle
     * @fn virtual ~Triangle() override = default;
     */
    virtual ~Triangle() override = default;

    virtual void draw() override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Triangle operator+(const Vec2D& position) const
     */
    Triangle operator+(const Vec2D& position) const
    {
        return Triangle(m_firstPosition + position, m_secondPosition + position, m_thirdPosition + position, getFillColor(), getBorderColor());
    }

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Triangle operator*(const float& f) const
     */
    Triangle operator*(const float& f) const
    {
        return Triangle(m_firstPosition * f, m_secondPosition * f, m_thirdPosition * f, getFillColor(), getBorderColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_firstPosition : Position du premier sommet
     */
    Vec2D m_firstPosition;

    /**
     * @brief m_secondPosition : Position du second sommet
     */
    Vec2D m_secondPosition;

    /**
     * @brief m_thirdPosition : Position du troisième sommet
     */
    Vec2D m_thirdPosition;

};

}

#endif // TRIANGLE_H
