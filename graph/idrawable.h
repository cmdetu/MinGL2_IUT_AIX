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
     * @fn virtual ~IDrawable() = default;
     */
    virtual ~IDrawable() = default;

    /**
     * @brief Fonction pour afficher l'objet.
     * **Attention**: L'objet doit être toujours vivant quand la fonction MinGL::updateGraphic() est appelée.
     * @fn virtual void draw(MinGL& window) const = 0;
     */
    virtual void draw(MinGL& window) const = 0;
};

#endif // DRAWABLE_H
