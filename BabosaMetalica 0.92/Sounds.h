#ifndef SOUNDS_H
#define SOUNDS_H
#include <SFML/Audio/SoundBuffer.hpp>
#include "Sounds.h"
#include <SFML/Audio/Sound.hpp>
using namespace std;
using namespace sf;

class Sounds {
public:
	Sounds(string name);
	void play_sound();
private:
	SoundBuffer buffer;
	string name;
	Sound sound_p;
	
};

#endif

