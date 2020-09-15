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

namespace nsShape
{

/**
 * @class Line
 * @brief Classe représentant une ligne
 */
class Line : public Shape
{

public:
    /**
     * @brief Constructeur pour la classe Line
     * @param[in] firstPosition : Position du premier sommet
     * @param[in] secondPosition : Position du second sommet
     * @param[in] fillColor : Couleur de remplissage
     * @param[in] lineWidth : Epaisseur de la ligne
     * @fn Line(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::RGBAcolor& fillColor, const float& lineWidth = 1.f);
     */
    Line(const nsGraphics::Vec2D& firstPosition, const nsGraphics::Vec2D& secondPosition, const nsGraphics::RGBAcolor& fillColor, const float& lineWidth = 1.f);

    /**
     * @brief Destructeur virtuel pour la classe Line
     * @fn virtual ~Line() override = default;
     */
    virtual ~Line() override = default;

    virtual void draw(MinGL& window) const override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Line operator+(const nsGraphics::Vec2D& position) const
     */
    Line operator+(const nsGraphics::Vec2D& position) const;

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Line operator*(const float& f) const
     */
    Line operator*(const float& f) const;

private:
    /**
     * @brief m_firstPosition : Position du premier sommet
     */
    nsGraphics::Vec2D m_firstPosition;

    /**
     * @brief m_position : Position du second sommet
     */
    nsGraphics::Vec2D m_secondPosition;

    /**
     * @brief m_position : Epaisseur de la ligne
     */
    float m_lineWidth;

}; // class Line

} // namespace nsShape

#endif // LINE_H
