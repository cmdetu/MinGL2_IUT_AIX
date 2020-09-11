#include "pixelexception.h"

#include <string>
#include <sstream>

using namespace std;

PixelException::PixelException(const Vec2D &pixelPosition, const RGBAcolor &color, const std::string &problem)
    : pixelPosition(pixelPosition), pixelColor(color), problem(problem)
{}

const char* PixelException::what() const noexcept
{
    ostringstream sstr;

    sstr << "Pixel error: ";
    sstr << "(" << pixelPosition.x << "," << pixelPosition.y << ") ";
    sstr << "[" << pixelColor << "]: ";
    sstr << problem;

    return sstr.str().c_str();
}
