#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#ifndef SOUNDS_H
#define SOUNDS_H
#include "Sounds.h"
using namespace std;
using namespace sf;
class Sounds{
	SoundBuffer buffer;
	Sound sound_p;
	string name;
public:
	Sounds(string name);
	void play_sound();	
};
#endif
