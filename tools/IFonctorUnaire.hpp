#ifndef IFONCTORBINAIRE_HPP
#define IFONCTORBINAIRE_HPP

namespace nsUtil
{
    template<typename T1, typename TRes>
    class IFonctorUnaire
    {
    public:
        virtual TRes operator() (const T1 &) const = 0;
        virtual ~IFonctorUnaire();
    };

    template<typename T1, typename TRes>
    IFonctorUnaire<T1, TRes>::~IFonctorUnaire() {}
}

#endif // IFONCTORBINAIRE_HPP
