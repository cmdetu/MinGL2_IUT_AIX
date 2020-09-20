/**
 *
 * @file    iminglinjectable.h
 * @version 1.0
 * @brief   Interface pour un objet injectable dans une fenêtre minGL
 *
 **/

#ifndef IMINGLINJECTABLE_H
#define IMINGLINJECTABLE_H

#include <memory>

#include "idrawable.h"
#include "../mingl.h"

namespace nsGraphics
{

/**
 * @class IminGLInjectable
 * @brief Classe représentant un élément injectable dans une fenêtre minGL
 */
class IminGLInjectable : public IDrawable
{

public:
    /**
     * @brief Destructeur virtuel pour la classe IminGLInjectable
     * @fn virtual ~IminGLInjectable() override = default;
     */
    virtual ~IminGLInjectable() = default;

    /**
     * @brief Opérateur d'e décalage'injection
     * @param[in] window : Fenêtre dans laquelle injecter l'élément
     * @param[in] drawable : Elément a injecter
     * @fn friend MinGL& operator<<(MinGL& window, const IminGLInjectable& drawable)
     */
    friend MinGL& operator<<(MinGL& window, const IminGLInjectable& drawable)
    {
        drawable.draw(window);

        return window;
    }

}; // class IminGLInjectable

} // namespace nsGraphics

#endif // IMINGLINJECTABLE_H
