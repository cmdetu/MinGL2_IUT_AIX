/**
 *
 * @file    audioengine.h
 * @author  Clément Mathieu--Drif
 * @date    Septembre 2020
 * @version 1.0
 * @brief   Gestionnaire audio de minGL
 *
 **/

#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <memory>
#include <list>
#include <SFML/Audio.hpp> // based on SFML

/**
 * @namespace nsAudio
 * @brief Espace de nom pour les utilitaires audio. Il est conseillé d'utiliser des fichiers .wav
 */
namespace nsAudio
{
/**
 * @class AudioEngine
 * @brief Une classe de gestion des effets audio et de la musique
 */
class AudioEngine
{

public:
    /**
     * @brief Définit le fichier audio de la musique
     * @param[in] fileName : nom du fichier
     * @param[in] loop : indique si la musique est lue en boucle ou non (oui par défaut)
     * @fn void setMusic(const std::string& fileName, bool loop = true);
     */
    void setMusic(const std::string& fileName, bool loop = true);

    /**
     * @brief Met en pause ou relance la musique
     * @fn void toggleMusic();
     */
    void toggleMusic();

    /**
     * @brief Relance la musique depuis le début
     * @fn void startMusicFromBeginning();
     */
    void startMusicFromBeginning();

    /**
     * @brief Joue un effet audio
     * @param[in] fileName : nom du fichier
     * @fn void playSoundEffects(const std::string& fileName);
     */
    void playSoundEffects(const std::string& fileName);

private:
    /**
     * @brief m_sounds : Liste des effets audio en cours de lecture
     */
    std::list<std::unique_ptr<sf::Music>> m_sounds;

    /**
     * @brief m_music : Musique principale
     */
    sf::Music m_music;

    /**
     * @brief Retire les sons terminés de la liste m_sounds
     * @fn void removeOldSounds();
     */
    void removeOldSounds();

}; // class AudioEngine

} // namespace nsAudio

#endif // AUDIOENGINE_H
