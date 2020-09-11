#ifndef MINGLAUDIOENGINE_H
#define MINGLAUDIOENGINE_H

#include <memory>
#include <list>
#include <SFML/Audio.hpp> // based on SFML

/*
 * Il es conseillé d'utiliser des fichier .wav
*/

namespace nsAudio
{
    class MinGLAudioEngine
    {
    public:
        void setMusic(const std::string & fileName, bool loop = true);
        void toggleMusic();
        void startMusicFromBeginning();

        void playSoundEffects(const std::string & fileName);

    private:
        std::list<std::unique_ptr<sf::Music>> sounds;
        sf::Music music;

        void removeOldSounds();
    }; // MinGLAudioEngine
} // nsAudio
#endif // MINGLAUDIOENGINE_H
