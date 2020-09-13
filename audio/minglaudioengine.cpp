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
    if(!m_music.openFromFile(fileName))
        throw nsUtil::CException(fileName + " cannot be loaded", nsUtil::KFileError);
    m_music.setLoop(loop);
} // addMusic

void nsAudio::MinGLAudioEngine::toggleMusic()
{
    if(m_music.getStatus() != sf::Music::Status::Playing)
        m_music.play();
    else
        m_music.pause();
}

void nsAudio::MinGLAudioEngine::startMusicFromBeginning()
{
    m_music.stop();
    m_music.play();
}

void nsAudio::MinGLAudioEngine::playSoundEffects(const std::string & fileName)
{
    removeOldSounds();
    m_sounds.emplace_back(new sf::Music);
    if(!m_sounds.back()->openFromFile(fileName))
        throw nsUtil::CException("file cannot be loaded", nsUtil::KFileError);

    m_sounds.back()->play();
}

void nsAudio::MinGLAudioEngine::removeOldSounds()
{
    list<unique_ptr<sf::Music>>::iterator it(m_sounds.begin());
    while(find_if(it, m_sounds.end(), nsAudio::FonctorOldSound()) != m_sounds.end())
        it = m_sounds.erase(it);
}
