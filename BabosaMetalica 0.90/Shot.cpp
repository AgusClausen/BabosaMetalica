#include "Shot.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

Shot::Shot(Vector2f pos, Vector2f dir,int penetration,int deviation, int dmg) {
	dev=deviation;
	
	m_circ.setPosition(pos);
	m_circ.setRadius(4);
	m_circ.setOrigin(2,2);
	m_circ.setFillColor({200,150,0});
	m_vel = dir*10.f;
	pen=penetration;
	damage=dmg;
	clock.restart();
}
 
void Shot::update(Vector2f pos_mapa){
	float x = pos_mapa.x;
	float y = pos_mapa.y;
	m_circ.move(m_vel);
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(y<1860){
			m_circ.move(0,4);
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(x<2120){
			m_circ.move(4,0);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(y>-1140){
			m_circ.move(0,-4);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(x>-850){
			m_circ.move(-4,0);
		}
	}
	if (pen<=0){must_app=false;}
}
int Shot::show_damage(){return damage;}

void Shot::draw(RenderWindow &w){
	w.draw(m_circ); 
}

void Shot::shot_colliding(){
	pen -= 1;
}

bool Shot::shot_must_appear(){
	return must_app;
}
Clock Shot::get_clock(){
	return clock;
}
