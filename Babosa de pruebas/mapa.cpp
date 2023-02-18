#include <SFML/Window/Keyboard.hpp>
#include "mapa.h"
using namespace std;
using namespace sf;
mapa::mapa() {
	t.loadFromFile("ciudad.png");
	s.setTexture(t);
	s.setPosition(0, 0);
	s.setOrigin(1500,1500);
}
void mapa::update(){
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		s.move(0,3);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		s.move(3,0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		s.move(0,-3);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		s.move(-3,0);
	}
}
void mapa::draw(RenderWindow &w){
	w.draw(s);
}

