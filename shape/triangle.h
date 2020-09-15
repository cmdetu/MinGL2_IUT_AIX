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
     * @fn Triangle(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::Vec2D& thirdPosition,
             const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);
     */
    Triangle(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::Vec2D& thirdPosition,
             const nsGraphics::RGBAcolor& fillColor, const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);

    /**
     * @brief Destructeur virtuel pour la classe Triangle
     * @fn virtual ~Triangle() override = default;
     */
    virtual ~Triangle() override = default;

    virtual void draw(MinGL& window) const override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Triangle operator+(const nsGraphics::Vec2D& position) const
     */
    Triangle operator+(const nsGraphics::Vec2D& position) const;

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Triangle operator*(const float& f) const
     */
    Triangle operator*(const float& f) const;

private:
    /**
     * @brief m_firstPosition : Position du premier sommet
     */
    nsGraphics::Vec2D m_firstPosition;

    /**
     * @brief m_secondPosition : Position du second sommet
     */
    nsGraphics::Vec2D m_secondPosition;

    /**
     * @brief m_thirdPosition : Position du troisième sommet
     */
    nsGraphics::Vec2D m_thirdPosition;

}; // class Triangle

} // namespace nsShape

#endif // TRIANGLE_H
