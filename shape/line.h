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
     * @fn Line(const Vec2D& firstPosition, const Vec2D& secondPosition, const RGBAcolor& fillColor, const float& lineWidth = 1.f);
     */
    Line(const Vec2D& firstPosition, const Vec2D& secondPosition, const RGBAcolor& fillColor, const float& lineWidth = 1.f);

    /**
     * @brief Destructeur virtuel pour la classe Line
     * @fn virtual ~Line() override = default;
     */
    virtual ~Line() override = default;

    virtual void draw() override;

    /**
     * @brief Opérateur de décalage
     * @param[in] position : Position a additionner
     * @fn Line operator+(const Vec2D& position) const
     */
    Line operator+(const Vec2D& position) const
    {
        return Line(m_firstPosition + position, m_secondPosition + position, getFillColor());
    }

    /**
     * @brief Opérateur de réduction
     * @param[in] f : Nombre avec lequel multiplier la position actuelle
     * @fn Line operator*(const float& f) const
     */
    Line operator*(const float& f) const
    {
        return Line(m_firstPosition * f, m_secondPosition * f, getFillColor());
    }

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

private:
    /**
     * @brief m_firstPosition : Position du premier sommet
     */
    Vec2D m_firstPosition;

    /**
     * @brief m_position : Position du second sommet
     */
    Vec2D m_secondPosition;

    /**
     * @brief m_position : Epaisseur de la ligne
     */
    float m_lineWidth;

};

}

#endif // LINE_H
