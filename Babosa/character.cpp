#include "character.h"
#include <SFML/Window/Keyboard.hpp>
character::character() {
	t.loadFromFile("file.png");
	s.setTexture(t);
	s.setOrigin(35,35);
	s.setPosition(360,360);
}
void character::update(){
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(2);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-2);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		s.move(3,0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		s.move(-3,0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		s.move(0,3);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		s.move(0,-3);
	}
}
void character::draw(RenderWindow &w){
	w.draw(s);
}
