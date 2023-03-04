#include "items.h"
#include <SFML/Window/Keyboard.hpp>

items::items(string str, float posx, float posy) {
	t.loadFromFile(str);
	s.setTexture(t);
	s.setPosition (posx,posy);
	name=str;
	Vector2f center;
	center.x = s.getTextureRect().width / 2.f;
	center.y = s.getTextureRect().height / 2.f;
	s.setOrigin(center);
}
FloatRect items::get_box(){
	return s.getGlobalBounds();
}
void items::eliminate(){
	exists=false;
}
bool items::check(){
	if (exists==true){
		return true;
	}return false;
}
void items::update(Vector2f pos_mapa){
	float ekis = pos_mapa.x;
	float ye = pos_mapa.y;
	int mov_map;
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(ye<1860){
			s.move(0,4);
			mov_map = 1;
		};
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		if(ekis<2120){
			s.move(4,0);
			mov_map = 2;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		if(ye>-1140){
			s.move(0,-4);
			mov_map = 3;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		if(ekis>-850){
			s.move(-4,0);
			mov_map = 4;
		}
	}
}
void items::draw(RenderWindow &w){
	w.draw(s);
}
string items::get_name(){
	return name;
}
