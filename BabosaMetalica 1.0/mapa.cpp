#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "mapa.h"
mapa::mapa() {
	t.loadFromFile("world.png");
	s.setOrigin(1500,1500);
	s.setPosition(0, 0);
	s.setTexture(t);
	int x = 1500;
}
void mapa::update(Vector2f pos_mapa){
	float ekis = pos_mapa.x;
	float ye = pos_mapa.y;
	int mov_map;
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(ye<1820){
			s.move(0,4);
			mov_map = 1;
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(ekis<2100){
			s.move(4,0);
			mov_map = 2;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(ye>-1100){
			s.move(0,-4);
			mov_map = 3;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(ekis>-1300){
			s.move(-4,0);
			mov_map = 4;
		}
	}
}
Vector2f mapa::coordenadas(){
	return s.getPosition();
}
void mapa::draw(RenderWindow &w){
	w.draw(s);
}
void mapa::reset(){
	s.setPosition(0, 0);
	s.setOrigin(1500,1500);
}
