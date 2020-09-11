#include "rgbacolor.h"

std::ostream &RGBAcolor::_Edit(std::ostream &os) const
{
    os << "R: " << int(Red) << ", G: " << int(Green) << ", B: " << int(Blue) << ", A: " << int(Alpha);
    return os;
}
