#include "Sounds.h"

Sounds::Sounds(string name) {
	buffer.loadFromFile(name);
	sound_p.setBuffer(buffer);
}

void Sounds::play_sound(){
	sound_p.play();
}
