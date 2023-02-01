#include "caja.h"
#include <SFML/Window/Keyboard.hpp>
caja::caja() {
	t.loadFromFile("boca.png");
	s.setTexture(t);
	s.setPosition(700, 700);
	s.setOrigin(240,240);
}
void caja::draw(RenderWindow &w){
	w.draw(s);
}

