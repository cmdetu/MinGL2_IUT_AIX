/**
 *
 * @file    idrawable.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Interface pour un objet affichable
 *
 **/

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <memory>

class MinGL;

/**
 * @class IDrawable
 * @brief Interface pour un objet affichable
 */
class IDrawable
{
public:
    /**
     * @brief Destructeur pour la classe IDrawable
     * @fn virtual ~IDrawable() {}
     */
    virtual ~IDrawable() {}

    /**
     * @brief Fonction pour cloner une instance
     * @return Un pointeur unique vers l'objet cloné
     * @fn virtual std::unique_ptr<IDrawable> clone() const;
     */
    virtual std::unique_ptr<IDrawable> clone() const = 0;

    /**
     * @brief Fonction pour afficher l'objet
     * @param[in, out] window : La fenêtre d'affichage
     * @fn virtual void draw(MinGL &window);
     */
    virtual void draw(MinGL &window) = 0;
};

#endif // DRAWABLE_H
