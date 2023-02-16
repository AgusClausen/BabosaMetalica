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
	es.setOrigin(32.5,32.5);
	es.setPosition(x,y);
}



void enemies::update(Vector2f pos){
Vector2f pose = es.getPosition();
pos = pos - pose;
float ekis = pos.x;
float ye = pos.y;
if(abs(ekis)<300 && abs(ye)<200){
	float mag = sqrt(ekis*ekis+ye*ye);
	ekis = 1.5*ekis/mag;
	ye = 1.5*ye/mag;
	Vector2f posd (ekis,ye);
	es.move(posd);
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
