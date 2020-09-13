#ifndef FIG2_H
#define FIG2_H

#include "../graph/iminglinjectable.h"

namespace nsShape
{

class Shape: public IminGlInjectable
{

public:
    Shape(const RGBAcolor& inColor, const RGBAcolor& borderColor);
    virtual ~Shape() = default;

    const RGBAcolor& getInColor() const;
    const RGBAcolor& getBorderColor() const;

private:
    RGBAcolor m_inColor;
    RGBAcolor m_borderColor;

};

}

#endif // FIG2_H