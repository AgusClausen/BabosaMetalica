#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "enemies.h"
#include <cmath>
enemies::enemies(int x,int y, Texture *et, float hp){
	s.setOrigin(37.5,37.5);
	s.setPosition(x,y);
	s.setTexture(*et);
	this->hp = hp;
	alive = true;
	drop = true;
}
void enemies::update(Vector2f pos_mapa){
	position = this->seePos();
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(pos_mapa.y<1820){
			s.move(0,4);
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(pos_mapa.x<2100){
			s.move(4,0);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(pos_mapa.y>-1100){
			s.move(0,-4);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(pos_mapa.x>-1300){
			s.move(-4,0);
		}
	}
	float angle = 0;
	Vector2f center(640,360);
	Vector2f pendiente = center - position;
	modulo = sqrt(pow(pendiente.x,2)+pow(pendiente.y,2));
	float x = pendiente.x/modulo;
	float y = pendiente.y/modulo;
	if(x>0 && y>0){
		angle = (atan(y/x))/3;
	};
	if(x>0 && y<0){
		angle = (atan(y/x))/3;
	};
	if(x<0 && y>0){
		angle = 3.14*0.9525+(atan(y/x))/3;
	};
	if(x<0 && y<0){
		angle = 3.14*0.9525+(atan(y/x))/3;
	};
	Vector2f vUnitario (2*x,2*y);
	s.setRotation(angle*180);
	if(modulo>50){
		s.move(vUnitario);
	}
	if (hp<=0){alive=false;}
}
void enemies::get_damage(float damage){
	hp=hp-damage;
}
void enemies::draw(RenderWindow &w){
	w.draw(s);
}
void enemies::reset(){
	hp = 0;
	drop = false;
}
bool enemies::check_drop(){
	return drop;
}
bool enemies::is_alive(){
	return alive;
}
Vector2f enemies::seePos(){
	return s.getPosition();
}
