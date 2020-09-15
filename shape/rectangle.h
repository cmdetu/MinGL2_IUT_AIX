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

namespace nsShape
{

/**
 * @class Rectangle
 * @brief Classe représentant un rectangle
 */
class Rectangle : public Shape
{

public:
    /**
     * @brief Constructeur pour la classe Rectangle
     * @param[in] firstPosition : Position du coin haut-gauche
     * @param[in] secondPosition : Position du coin bas-droit
     * @param[in] fillColor : Couleur de remplissage
     * @param[in] borderColor : Couleur de bord
     * @fn Rectangle(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::RGBAcolor& fillColor,
              const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);
     */
    Rectangle(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::RGBAcolor& fillColor,
              const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);

    /**
     * @brief Constructeur pour la classe Rectangle
     * @param[in] position : Position du coin haut-gauche
     * @param[in] width : Largeur du rectangle
     * @param[in] height : Hauteur du rectangle
     * @param[in] fillColor : Couleur de remplissage
     * @param[in] borderColor : Couleur de bord
     * @fn Rectangle(const nsGraphics::Vec2D& position, const unsigned& width, const unsigned& height, const nsGraphics::RGBAcolor& fillColor,
              const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);
     */
    Rectangle(const nsGraphics::Vec2D& position, const unsigned& width, const unsigned& height, const nsGraphics::RGBAcolor& fillColor,
              const nsGraphics::RGBAcolor& borderColor = nsGraphics::KTransparent);

    /**
     * @brief Destructeur virtuel pour la classe Line
     * @fn virtual ~Line() override = default;
     */
    virtual ~Rectangle() override = default;

    virtual void draw(MinGL& window) const override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Rectangle operator+(const nsGraphics::Vec2D& position) const
     */
    Rectangle operator+(const nsGraphics::Vec2D& position) const;

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Rectangle operator*(const float& f) const
     */
    Rectangle operator*(const float& f) const;

private:
    /**
     * @brief m_firstPosition : Position du premier sommet
     */
    nsGraphics::Vec2D m_firstPosition;

    /**
     * @brief m_secondPosition : Position du second sommet
     */
    nsGraphics::Vec2D m_secondPosition;

}; // class Rectangle

} // namespace nsShape

#endif // RECTANGLE_H
