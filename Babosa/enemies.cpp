#include "enemies.h"
#include <SFML/Window/Keyboard.hpp>
#include <windows.h>
enemies::enemies() {
	t.loadFromFile("zombie.png");
	s.setTexture(t);
	s.setPosition(1200, 700);
	s.setOrigin(35,35);
}
void enemies::update(){
//	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
//		s.rotate(2);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
//		s.rotate(-2);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
//		s.move(3,0);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
//		s.move(-3,0);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
//		s.move(0,3);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
//		s.move(0,-3);
//	}
	Sleep(5000);
	s.move(-1,-1);
	
}
void enemies::draw(RenderWindow &w){
	w.draw(s);
}
