#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <memory>
#include <type_traits>

#include "../graph/iminglinjectable.h"
#include "basefig.h"
#include "circle.h"

namespace nsFigure
{
    class Figure : public BaseFig
    {
    protected:
        virtual void draw(MinGL &window) override;
        std::vector<std::shared_ptr<BaseFig>> vFig;

    public:
        template <typename T, typename = typename std::enable_if<std::is_base_of<BaseFig, T>::value>::type>
        void Add (const T & Val)
        {
            std::shared_ptr<T> ptr (new T (Val));
            vFig.push_back(ptr);

        }

        // Opérateur de décalage +
        BaseFig operator + (const Vec2D & pos_) const;

        // Opérateur de réduction *
        BaseFig operator * (const float & f) const;

        // Fonction de clonage
        virtual std::unique_ptr<IDrawable> clone() const override;
    };
}

#endif // FIGURE_H
