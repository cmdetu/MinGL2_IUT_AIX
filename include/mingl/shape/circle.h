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
     * @fn Circle(const nsGraphics::Vec2D& position, const unsigned& radius, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);
     */
    Circle(const nsGraphics::Vec2D& position, const unsigned& radius, const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);

    /**
     * @brief Destructeur virtuel pour la classe Circle
     * @fn virtual ~Circle() override = default;
     */
    virtual ~Circle() override = default;

    virtual void draw(MinGL& window) const override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Circle operator+(const nsGraphics::Vec2D& position) const
     */
    Circle operator+(const nsGraphics::Vec2D& position) const;

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Circle operator*(const float& f) const
     */
    Circle operator*(const float& f) const;

private:
    /**
     * @brief m_position : Position du centre
     */
    nsGraphics::Vec2D m_position;

    /**
     * @brief m_radius : Rayon du cercle
     */
    unsigned m_radius;

}; // class Circle

} // namespace nsShape

#endif // CIRCLE_H
