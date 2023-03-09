#include <SFML/Window/Keyboard.hpp>
#include "items.h"
items::items(Texture* itt, float posx, float posy,string str){
	center.y = s.getTextureRect().height / 2.f;
	center.x = s.getTextureRect().width / 2.f;
	s.setPosition (posx,posy);
	s.setOrigin(center);
	s.setTexture(*itt);
	name=str;
	exists = true;
}
void items::update(Vector2f pos_mapa){
	float ekis = pos_mapa.x;
	float ye = pos_mapa.y;
	int mov_map;
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		if(ye<1820){
			s.move(0,4);
			mov_map = 1;
		}
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
void items::draw(RenderWindow &w){
	w.draw(s);
}
void items::eliminate(){
	exists=false;
}
bool items::check(){
	if (exists==true){
		return true;
	}return false;
}
FloatRect items::get_box(){
	return s.getGlobalBounds();
}
Vector2f items::seePos(){
	return s.getPosition();
}
string items::get_name(){
	return name;
}
