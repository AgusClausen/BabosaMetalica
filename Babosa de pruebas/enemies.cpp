#include <SFML/Window/Keyboard.hpp>
#include "enemies.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
using namespace std;
using namespace sf;
enemies::enemies(int x, int y){
	t.loadFromFile("zombie.png");
	s.setTexture(t);
	s.setPosition(x, y);
	s.setOrigin(35,35);
}
void enemies::update(Vector2f pos_mapa){
	float x = pos_mapa.x;
	float y = pos_mapa.y;
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(y<1860){
			s.move(0,40);
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(x<2120){
			s.move(40,0);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(y>-1140){
			s.move(0,-40);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(x>-850){
			s.move(-40,0);
		}
	}
	pos_enemie = s.getPosition();
	Vector2f pos_central (640,360);
	pos_enemie = pos_central - pos_enemie;
	float ekis = pos_enemie.x;
	float ye = pos_enemie.y;
	float modulo = sqrt(ekis*ekis + ye*ye);
	ekis = ekis/modulo;
	ye = ye/modulo;
	Vector2f vUnitario (2*ekis,2*ye);
	if(modulo<00&&modulo>10){
		s.move(vUnitario);
	}
}
void enemies::draw(RenderWindow &w){
	w.draw(s);
}
