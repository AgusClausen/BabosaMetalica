#include "character.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;

character::character() {
	t.loadFromFile("file.png");
	s.setTexture(t);
	s.setPosition(640,360); 
	s.setOrigin(35,35);
	}

void character::update(vector <stage> objects){
	
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

bool character::mustshoot(){
	if (m_clock.getElapsedTime().asMilliseconds()<300) return false;
	if (not Keyboard::isKeyPressed(Keyboard::Key::Space)) return false;
	m_clock.restart();
	return true;
}

Shot character::shotgen(Vector2f pos_mapa){
	Vector2f p = s.getPosition();
	float ang = s.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	return Shot(p+25.f*d,d);
}


