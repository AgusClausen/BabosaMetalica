#include "character.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;

character::character() {
	t.loadFromFile("file.png");
	s.setTexture(t);
	s.setPosition(35,350); 
	s.setOrigin(35,35);
	}

void character::update(){
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(4);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-4);
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

bool character::mustshoot(){
	if (m_clock.getElapsedTime().asMilliseconds()<300) return false;
	if (not Keyboard::isKeyPressed(Keyboard::Key::Space)) return false;
	
	m_clock.restart();
	
	return true;
}

Shot character::shotgen(){
	Vector2f p = s.getPosition();
	float ang = s.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	return Shot(p+25.f*d,d);
}
