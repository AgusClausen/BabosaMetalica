#include "character.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;

character::character(string str) {
	t.loadFromFile("g1.png");
	s.setTexture(t);
	s.setPosition(640,360); 
	s.setOrigin(37.5,35);
	name=str;
	}

void character::update(vector <stage> objects){
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(3);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-3);
	}
}

void character::draw(RenderWindow &w){
	w.draw(s);
}

bool character::mustshoot(){
	if (m_clock.getElapsedTime().asMilliseconds()<rsv) return false;
	if (not Keyboard::isKeyPressed(Keyboard::Key::Space)) return false;
	m_clock.restart();
	return true;
}

Shot character::shotgen(Vector2f pos_mapa){
	Vector2f p = s.getPosition();
	float ang = s.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	if (name=="g6.png"){
		return Shot(p+5.f*d,d,pen,dev,dmg);
	}
	return Shot(p+29.f*d,d,pen,dev,dmg);
}


void character::change_weapon(string str, int damage,int penetration, int deviation, int rounds_spawn_velocity){
	t.loadFromFile(str);
	s.setTexture(t);
	name=str;
	dmg=damage;
	pen=penetration;
	dev=deviation;
	rsv=rounds_spawn_velocity;
	
}

FloatRect character::get_box(){
	return s.getGlobalBounds();
}
