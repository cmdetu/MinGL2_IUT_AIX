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

/**
 * @class Circle
 * @brief Classe représentant un cercle
 */
class Circle : public Shape
{

public:
    /**
     * @brief Constructeur pour la classe Circle
     * @param[in] firstPosition : Position du centre
     * @param[in] radius : Rayon du cercle
     * @param[in] fillColor : Couleur de remplissage
     * @param[in] borderColor : Couleur de bord
     * @fn Circle(const Vec2D& position, const unsigned& radius, const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);
     */
    Circle(const Vec2D& position, const unsigned& radius, const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);

    /**
     * @brief Destructeur virtuel pour la classe Circle
     * @fn virtual ~Circle() override = default;
     */
    virtual ~Circle() override = default;

    virtual void draw(MinGL &window) override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Circle operator+(const Vec2D& position) const
     */
    Circle operator+(const Vec2D& position) const
    {
        return Circle(m_position + position, m_radius, getFillColor(), getBorderColor());
    }

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Circle operator*(const float& f) const
     */
    Circle operator*(const float& f) const
    {
        return Circle(m_position * f, m_radius, getFillColor(), getBorderColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_position : Position du centre
     */
    Vec2D m_position;

    /**
     * @brief m_radius : Rayon du cercle
     */
    unsigned m_radius;

};

}

#endif // CIRCLE_H
