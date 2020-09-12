#include "figure.h"

#include "line.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

using namespace std;
using namespace nsUtil;

void nsFigure::Figure::draw(MinGL &window)
{
    for (const std::shared_ptr<BaseFig> &fig : vFig) {
        fig->draw(window);
    }
}

nsFigure::BaseFig nsFigure::Figure::operator *(const float &f) const
{
    Figure tmp;
    for (unsigned i = 0; i < this->vFig.size(); ++i)
    {
        if (vFig[i]->getName() == "circle")
            tmp.Add(Circle(*vFig[i]).operator * (f));
        else if (vFig[i]->getName() == "rectangle")
            tmp.Add(Rectangle(*vFig[i]).operator * (f));
        else if (vFig[i]->getName() == "triangle")
            tmp.Add(Triangle(*vFig[i]).operator * (f));
        else if (vFig[i]->getName() == "line")
            tmp.Add(Line(*vFig[i]).operator * (f));
    }

    return tmp;
}

nsFigure::BaseFig nsFigure::Figure::operator +(const Vec2D &pos_) const
{
    Figure tmp;
    for (unsigned i = 0; i < this->vFig.size(); ++i)
    {
        if (vFig[i]->getName() == "circle")
            tmp.Add(Circle(*vFig[i]).operator + (pos_));
        else if (vFig[i]->getName() == "rectangle")
            tmp.Add(Rectangle(*vFig[i]).operator + (pos_));
        else if (vFig[i]->getName() == "triangle")
            tmp.Add(Triangle(*vFig[i]).operator + (pos_));
        else if (vFig[i]->getName() == "line")
            tmp.Add(Line(*vFig[i]).operator + (pos_));
    }

    return tmp;
}

std::unique_ptr<IDrawable> nsFigure::Figure::clone() const
{
    return std::unique_ptr<Figure>(new Figure(*this));
}
