#include "enemies.h"
#include <SFML/Window/Keyboard.hpp>
#include <windows.h>
#include "Shot.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
using namespace std;
using namespace sf;
	
	
enemies::enemies() {
	et.loadFromFile("zombie.png");
	es.setTexture(et);
	es.setPosition(1200, 650);
	es.setOrigin(35,35);
}



void enemies::update(){
//	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
//		s.rotate(2);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
//		s.rotate(-2);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
//		s.move(3,0);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
//		s.move(-3,0);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
//		s.move(0,3);
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Key::W)){
//		s.move(0,-3);
//	}
}

void enemies::draw(RenderWindow &w){
	w.draw(es);
}

