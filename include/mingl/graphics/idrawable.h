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
 * @namespace nsGraphics
 * @brief Espace de nom pour les utilitaires graphiques
 */
namespace nsGraphics
{

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
     * @fn virtual void draw(MinGL& window) const = 0;
     */
    virtual void draw(MinGL& window) const = 0;

}; // class IDrawable

} // namespace nsGraphics

#endif // DRAWABLE_H
