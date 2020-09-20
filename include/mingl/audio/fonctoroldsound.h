#ifndef FONCTOROLDSOUND_H
#define FONCTOROLDSOUND_H

#include <SFML/Audio.hpp>
#include "../tools/ifonctorunaire.hpp"

namespace nsAudio
{
/**
 * @class FonctorOldSound
 * @brief Fonctor de recherche des sons terminés
 */
class FonctorOldSound : public nsUtil::IFonctorUnaire<std::unique_ptr<sf::Music>, bool>
{

public:
    /**
     * @brief Définit le fichier audio de la musique
     * @param[in] eff : effet audio à tester
     * @fn virtual bool operator()(const std::unique_ptr<sf::Music>& eff) const override;
     */
    virtual bool operator()(const std::unique_ptr<sf::Music>& eff) const override;
    /**
     * @brief Destructeur pour la classe FonctorOldSound
     * @fn virtual ~FonctorOldSound() override = default;
     */
    virtual ~FonctorOldSound() override = default;

}; // class FonctorOldSound

} // namespace nsAudio

#endif // FONCTOROLDSOUND_H
