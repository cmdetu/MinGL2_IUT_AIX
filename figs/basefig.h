#ifndef BASEFIG_H
#define BASEFIG_H

#include <map>
#include <memory>

#include "../graph/vec2d.h"
#include "../graph/rgbacolor.h"
#include "../graph/iminglinjectable.h"

namespace nsFigure {

class BaseFig : public IminGlInjectable
{
protected:
    BaseFig (const RGBAcolor &, const RGBAcolor &, const std::string &);

public:
    BaseFig();
     ~BaseFig() {}

    virtual void draw(MinGL &window) override;

    // Fonction de clonage
    virtual std::unique_ptr<IDrawable> clone() const override;

    const RGBAcolor getInColor() const;
    const RGBAcolor getBorderColor() const;
    const std::string getName() const;

    void setInColor(const RGBAcolor &inColor_);
    void setBorderColor(const RGBAcolor &borderColor_);

private:
    RGBAcolor inColor, borderColor;
    const std::string name; // ajouter pour l'introspection
};

}

#endif // BASEFIG_H
