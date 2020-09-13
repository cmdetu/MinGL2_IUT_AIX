/**
 *
 * @file    minglaudioengine.h
 * @author  Clément Mathieu--Drif
 * @date    Septembre 2020
 * @version 1.0
 * @brief   Gestionnaire audio de minGL
 *
 **/

#include "minglaudioengine.h"
#include "../tools/CException.h"
#include "../tools/fonctoroldsound.h"

using namespace std;

void nsAudio::MinGLAudioEngine::setMusic(const std::string & fileName, bool loop /* = true */)
{
    if(!music.openFromFile(fileName))
        throw nsUtil::CException(fileName + " cannot be loaded", nsUtil::KFileError);
    music.setLoop(loop);
} // addMusic

void nsAudio::MinGLAudioEngine::toggleMusic()
{
    if(music.getStatus() != sf::Music::Status::Playing)
        music.play();
    else
        music.pause();
}

void nsAudio::MinGLAudioEngine::startMusicFromBeginning()
{
    music.stop();
    music.play();
}

void nsAudio::MinGLAudioEngine::playSoundEffects(const std::string & fileName)
{
    removeOldSounds();
    sounds.emplace_back(new sf::Music);
    if(!sounds.back()->openFromFile(fileName))
        throw nsUtil::CException("file cannot be loaded", nsUtil::KFileError);

    sounds.back()->play();
}

void nsAudio::MinGLAudioEngine::removeOldSounds()
{
    list<unique_ptr<sf::Music>>::iterator it(sounds.begin());
    while(find_if(it, sounds.end(), nsAudio::FonctorOldSound()) != sounds.end())
        it = sounds.erase(it);
}
