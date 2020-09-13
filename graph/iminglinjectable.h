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

#include "../mingl.h"
#include "idrawable.h"
#include "../tools/myexception.h"

class IminGLInjectable : public IDrawable
{

public:
    virtual ~IminGLInjectable() {};

    friend MinGL& operator<<(MinGL& window, const IminGLInjectable& drawable)
    {
        drawable.draw(window);

        return window;
    }

}; // IminGLInjectable

#endif // IMINGLINJECTABLE_H
