/**
 *
 * @file    minglaudioengine.h
 * @author  Clément Mathieu--Drif
 * @date    Septembre 2020
 * @version 1.0
 * @brief   Gestionnaire audio de minGL
 *
 **/

#ifndef MINGLAUDIOENGINE_H
#define MINGLAUDIOENGINE_H

#include <memory>
#include <list>
#include <SFML/Audio.hpp> // based on SFML

/*
 * Il est conseillé d'utiliser des fichiers .wav
*/

namespace nsAudio
{

class MinGLAudioEngine
{

public:
    void setMusic(const std::string& fileName, bool loop = true);
    void toggleMusic();
    void startMusicFromBeginning();

    void playSoundEffects(const std::string& fileName);

private:
    std::list<std::unique_ptr<sf::Music>> m_sounds;
    sf::Music m_music;

    void removeOldSounds();

}; // class MinGLAudioEngine

} // namespace nsAudio

#endif // MINGLAUDIOENGINE_H
