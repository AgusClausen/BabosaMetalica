#include "Shot.h"
#include <SFML/Graphics/CircleShape.hpp>

Shot::Shot(Vector2f pos, Vector2f dir) {
	m_circ.setPosition(pos);
	m_circ.setRadius(4);
	m_circ.setOrigin(2,2);
	m_circ.setFillColor({0,0,0});
	m_vel = dir*10.f;
}
 
void Shot::update(){
	m_circ.move(m_vel);
}
float Shot::show_damage(){return damage;}

void Shot::draw(RenderWindow &w){
	w.draw(m_circ); 
}

