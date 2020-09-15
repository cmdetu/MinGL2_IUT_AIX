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

class IminGLInjectable : public IDrawable
{

public:
    virtual ~IminGLInjectable() = default;

    friend MinGL& operator<<(MinGL& window, const IminGLInjectable& drawable)
    {
        drawable.draw(window);

        return window;
    }

}; // class IminGLInjectable

} // namespace nsGraphics

#endif // IMINGLINJECTABLE_H
