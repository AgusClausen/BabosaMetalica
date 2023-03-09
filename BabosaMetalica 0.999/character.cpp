#include <SFML/Window/Keyboard.hpp>
#include "character.h"
#include <cmath>
character::character(string gun) {
	t.loadFromFile("g1.png");
	s.setPosition(640,360); 
	s.setOrigin(37.5,37.5);
	this->gun = gun;
	s.setTexture(t);
	FloatRect box;
	alive = true;
	rsv = 225;
	dmg = 30;
	pen = 1;
	dev = 0;
	hp=100;
}
void character::update(){
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(3);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-3);
	}
	if (hp<1){
		alive=false;
	}
}
void character::draw(RenderWindow &w){
	w.draw(s);
}
bool character::mustshoot(){
	if (m_clock.getElapsedTime().asMilliseconds()<rsv){
		return false;
	}
	if (not Keyboard::isKeyPressed(Keyboard::Key::Space)){
		return false;
	}
	m_clock.restart();
	return true;
}
Shot character::shotgen(Vector2f pos_mapa){
	Vector2f center(640,360);
	int ndir=0;
	if(dev>0)ndir=(-dev/2)+rand()%(dev);
	float ang = s.getRotation()*M_PI/180;
	Vector2f d(cos(ang+(ndir*M_PI/180)),sin(ang+(ndir*M_PI/180)));
	if (gun == "g6.png"){
		return Shot(center+5.f*d,d,pen,dev,dmg);
	}
	return Shot(center+29.f*d,d,pen,dev,dmg);
}
void character::change_weapon(string gun, int damage,int penetration, int deviation, int rounds_spawn_velocity){
	t.loadFromFile(gun);
	s.setTexture(t);
	this->gun=gun;
	dmg=damage;
	pen=penetration;
	dev=deviation;
	rsv=rounds_spawn_velocity;
}
void character::get_damage(int damage){
	hp=hp-damage;
}
bool character::is_alive(){
	return alive;
}
FloatRect character::get_box(){
	return s.getGlobalBounds();
}
void character::reset (){
	t.loadFromFile("g1.png");
	gun = "basicpistol.png";
	s.setTexture(t);
	alive = true;
	rsv = 225;
	dmg = 30;
	hp = 100;
	pen = 1;
	dev = 0;
}
string character::get_gun(){
	return gun;
}
