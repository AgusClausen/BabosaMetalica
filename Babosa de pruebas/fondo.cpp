#include <SFML/Window/Keyboard.hpp>
#include "enemies.h"
#include "character.h"
using namespace std;
using namespace sf;
character::character() {
	t.loadFromFile("ciudad.png");
	s.setTexture(t);
	s.setPosition(35,350); 
	s.setOrigin(35,35);
}
void character::update(){
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		//		if(pos.x<1250){
		s.move(-3,0);
		//		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		//		if(pos.x>30){
		s.move(3,0);
		//		}
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		//		if(pos.y<692){
		s.move(0,-3);
		//		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
		//		if(pos.y>20){
		s.move(0,3);
		//		}
	}
}
void character::draw(RenderWindow &w){
	w.draw(s);
}
