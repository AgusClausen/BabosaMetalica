#include "enemies.h"
#include <SFML/Window/Keyboard.hpp>
#include <windows.h>
#include "Shot.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
using namespace std;
using namespace sf;
	
	
enemies::enemies(int x,int y, int type, Texture *et,float enemy_hp) {
	if (type==1){
	}
	hp = enemy_hp;
	es.setTexture(*et);
	es.setOrigin(35,35);
	es.setPosition(x,y);
	alive=true;
}



void enemies::update(Vector2f pos_mapa,Vector2f pos_char){
	float x = pos_mapa.x;
	float y = pos_mapa.y;
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(y<1820){
			es.move(0,4);
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(x<2100){
			es.move(4,0);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(y>-1100){
			es.move(0,-4);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(x>-1300){
			es.move(-4,0);
		}
	}
	float angle = 0;
	float pi = 3.14159265359;
	pos_enemie = es.getPosition();
	Vector2f pos_central (640,360);
	pos_enemie = pos_central - pos_enemie;
	float ekis = pos_enemie.x;
	float ye = pos_enemie.y;
	hipotenusa = sqrt(ekis*ekis + ye*ye);
	ekis = ekis/hipotenusa;
	ye = ye/hipotenusa;
	if(ekis>0 && ye>0){
		angle = (atan(ye/ekis))/3;
	};
	if(ekis>0 && ye<0){
		angle = (atan(ye/ekis))/3;
	};
	if(ekis<0 && ye>0){
		angle = pi*0.9525+(atan(ye/ekis))/3;
	};
	if(ekis<0 && ye<0){
		angle = pi*0.9525+(atan(ye/ekis))/3;
	};
	Vector2f vUnitario (2*ekis,2*ye);
	es.setRotation(angle*180);
	if(hipotenusa>50){
		es.move(vUnitario);
	}
	if (hp<=0){alive=false;}
}

void enemies::draw(RenderWindow &w){
	w.draw(es);
}

void enemies::get_damage(float d){
	hp-=d;
}

bool enemies::is_alive(){
	return alive;
}

void enemies::is_attacking(){
	if(hipotenusa<50){
		attacking = true;
	}else{
		attacking = false;
	}
}
