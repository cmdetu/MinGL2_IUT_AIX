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
     * @fn Rectangle(const Vec2D& firstPosition, const Vec2D& secondPosition, const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);
     */
    Rectangle(const Vec2D& firstPosition, const Vec2D& secondPosition, const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);

    /**
     * @brief Constructeur pour la classe Rectangle
     * @param[in] position : Position du coin haut-gauche
     * @param[in] width : Largeur du rectangle
     * @param[in] height : Hauteur du rectangle
     * @param[in] fillColor : Couleur de remplissage
     * @param[in] borderColor : Couleur de bord
     * @fn Rectangle(const Vec2D& position, const unsigned& width, const unsigned& height, const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);
     */
    Rectangle(const Vec2D& position, const unsigned& width, const unsigned& height, const RGBAcolor& fillColor, const RGBAcolor& borderColor = KTransparent);

    /**
     * @brief Destructeur virtuel pour la classe Line
     * @fn virtual ~Line() override = default;
     */
    virtual ~Rectangle() override = default;

    virtual void draw(MinGL& window) const override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Rectangle operator+(const Vec2D& position) const
     */
    Rectangle operator+(const Vec2D& position) const
    {
        return Rectangle(m_firstPosition + position, m_secondPosition + position, getFillColor(), getBorderColor());
    }

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Rectangle operator*(const float& f) const
     */
    Rectangle operator*(const float& f) const
    {
        return Rectangle(m_firstPosition * f, m_secondPosition * f, getFillColor(), getBorderColor());
    }

private:
    /**
     * @brief m_firstPosition : Position du premier sommet
     */
    Vec2D m_firstPosition;

    /**
     * @brief m_secondPosition : Position du second sommet
     */
    Vec2D m_secondPosition;

};

}

#endif // RECTANGLE_H
