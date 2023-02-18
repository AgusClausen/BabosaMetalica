#include <SFML/Window/Keyboard.hpp>
#include "mapa.h"
#include <SFML/System/Vector2.hpp>
using namespace std;
using namespace sf;
mapa::mapa() {
	t.loadFromFile("ciudad.png");
	s.setTexture(t);
	s.setPosition(0, 0);
	s.setOrigin(1500,1500);
	int x = 1500;
}
void mapa::update(Vector2f pos_mapa){
	float ekis = pos_mapa.x;
	float ye = pos_mapa.y;
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(ye<1860){
			s.move(0,40);
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(ekis<2120){
			s.move(40,0);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(ye>-1140){
			s.move(0,-40);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(ekis>-850){
			s.move(-40,0);
		}
	}
}
Vector2f mapa::coordenadas(){
	return s.getPosition();
}
void mapa::draw(RenderWindow &w){
	w.draw(s);
}
