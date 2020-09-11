#ifndef FONCTOROLDSOUND_H
#define FONCTOROLDSOUND_H

#include <SFML/Audio.hpp>
#include "IFonctorUnaire.hpp"

namespace nsAudio
{
    class FonctorOldSound : public nsUtil::IFonctorUnaire<std::unique_ptr<sf::Music>, bool>
    {
    public:
        virtual bool operator() (const std::unique_ptr<sf::Music> & eff) const;
        virtual ~FonctorOldSound();
    };
}

#endif // FONCTOROLDSOUND_H
