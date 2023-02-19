#include "enemies.h"
#include <SFML/Window/Keyboard.hpp>
#include <windows.h>
#include "Shot.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
using namespace std;
using namespace sf;
	
	
enemies::enemies(int x,int y) {
	et.loadFromFile("zombie.png");
	es.setTexture(et);
	es.setOrigin(35,35);
	es.setPosition(x,y);
}



void enemies::update(Vector2f pos_mapa){
	float x = pos_mapa.x;
	float y = pos_mapa.y;
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(y<1860){
			es.move(0,4);
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(x<2120){
			es.move(4,0);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(y>-1140){
			es.move(0,-4);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(x>-850){
			es.move(-4,0);
		}
	}
	pos_enemie = es.getPosition();
	Vector2f pos_central (640,360);
	pos_enemie = pos_central - pos_enemie;
	float ekis = pos_enemie.x;
	float ye = pos_enemie.y;
	float modulo = sqrt(ekis*ekis + ye*ye);
	ekis = ekis/modulo;
	ye = ye/modulo;
	Vector2f vUnitario (2*ekis,2*ye);
	if(modulo<500&&modulo>300){
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
