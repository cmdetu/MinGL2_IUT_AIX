/**
 *
 * @file    audioengine.h
 * @author  Clément Mathieu--Drif
 * @date    Septembre 2020
 * @version 1.0
 * @brief   Gestionnaire audio de minGL
 *
 **/

#include "mingl/audio/audioengine.h"
#include "mingl/audio/fonctoroldsound.h"
#include "mingl/exception/cexception.h"

using namespace std;

void nsAudio::AudioEngine::setMusic(const std::string& fileName, bool loop /* = true */)
{
    if (!m_music.openFromFile(fileName))
        throw nsException::CException(fileName + " cannot be loaded", nsException::KFileError);

    m_music.setLoop(loop);
} // setMusic()

void nsAudio::AudioEngine::toggleMusic()
{
    if (m_music.getStatus() != sf::Music::Status::Playing)
        m_music.play();
    else
        m_music.pause();
} // toggleMusic()

void nsAudio::AudioEngine::startMusicFromBeginning()
{
    m_music.stop();
    m_music.play();
} // startMusicFromBeginning()

void nsAudio::AudioEngine::playSoundEffects(const std::string& fileName)
{
    removeOldSounds();
    m_sounds.emplace_back(new sf::Music());
    if (!m_sounds.back()->openFromFile(fileName))
        throw nsException::CException("file cannot be loaded", nsException::KFileError);

    m_sounds.back()->play();
} // playSoundEffects()

void nsAudio::AudioEngine::removeOldSounds()
{
    list<unique_ptr<sf::Music>>::iterator it(m_sounds.begin());
    while (find_if(it, m_sounds.end(), nsAudio::FonctorOldSound()) != m_sounds.end())
        it = m_sounds.erase(it);
} // removeOldSounds()
