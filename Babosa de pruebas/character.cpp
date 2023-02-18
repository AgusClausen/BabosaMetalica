#include <SFML/Window/Keyboard.hpp>
#include "character.h"
using namespace std;
using namespace sf;
character::character(){
	t.loadFromFile("personaje.png");
	s.setTexture(t);
	s.setPosition(640, 360);
	s.setOrigin(35,35);
}
void character::update(){
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(4);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-4);
	}
}
void character::draw(RenderWindow &w){
	w.draw(s);
}
