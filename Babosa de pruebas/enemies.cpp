#include <SFML/Window/Keyboard.hpp>
#include "enemies.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
using namespace std;
using namespace sf;
enemies::enemies(){
	t.loadFromFile("zombie.png");
	s.setTexture(t);
	s.setPosition(0, 0);
	s.setOrigin(35,35);
}
void enemies::update(){
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
	pos = s.getPosition();
	Vector2f pos_central (640,360);
	pos = pos_central - pos;
	float ekis = pos.x;
	float ye = pos.y;
	float modulo = sqrt(ekis*ekis + ye*ye);
	ekis = ekis/modulo;
	ye = ye/modulo;
	Vector2f vUnitario (2*ekis,2*ye);
	if(modulo<300){
		s.move(vUnitario);
	}
}
void enemies::draw(RenderWindow &w){
	w.draw(s);
}
