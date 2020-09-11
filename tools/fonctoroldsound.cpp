#include "fonctoroldsound.h"

using namespace std;

bool nsAudio::FonctorOldSound::operator() (const std::unique_ptr<sf::Music> &eff) const
{
    return eff->getStatus() != sf::Music::Status::Playing;
}

nsAudio::FonctorOldSound::~FonctorOldSound()
{}
