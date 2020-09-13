#ifndef IMINGLINJECTABLE_H
#define IMINGLINJECTABLE_H

#include <memory>

#include "../mingl.h"
#include "idrawable.h"
#include "../tools/myexception.h"

class IminGlInjectable : public IDrawable
{
public:
    virtual ~IminGlInjectable() {};

    friend MinGL & operator << (MinGL & Window, const IminGlInjectable & Obj)
    {
        Window.addDrawable(std::unique_ptr<IDrawable>(Obj.clone()));
        return Window;
    }
}; // IminGlInjectable

#endif // IMINGLINJECTABLE_H
