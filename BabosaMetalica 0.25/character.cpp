#include "character.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;

character::character() {
	t.loadFromFile("file.png");
	s.setTexture(t);
	s.setPosition(100,350); 
	s.setOrigin(35,35);
	box=s.getGlobalBounds();
	}

void character::update(vector <stage> objects){
	bool collision=process_collisions(objects);
	if (up==false||right==false||left==false||down==false){
		if (up==false&&Keyboard::isKeyPressed(Keyboard::Key::S)){
			up=true;
		}
		if (down==false&&Keyboard::isKeyPressed(Keyboard::Key::W)){
			down=true;
		}
		if (left==false&&Keyboard::isKeyPressed(Keyboard::Key::D)){
			left=true;
		}
		if (right==false&&Keyboard::isKeyPressed(Keyboard::Key::A)){
			right=true;
		}
	}else{
	if (Keyboard::isKeyPressed(Keyboard::Key::D)&&collision==true){
		right=false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)&&collision==true){
		left=false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)&&collision==true){
		up=false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)&&collision==true){
		down=false;
	}
	}
	if (collision==false){
		up=true;
		down=true;
		right=true;
		left=true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(4);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-4);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)&&right==true){
		s.move(3,0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)&&left==true){
		s.move(-3,0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)&&down==true){
		s.move(0,3);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)&&up==true){
		s.move(0,-3);
	}

}

void character::draw(RenderWindow &w){
	w.draw(s);
}

bool character::mustshoot(){
	if (m_clock.getElapsedTime().asMilliseconds()<300) return false;
	if (not Keyboard::isKeyPressed(Keyboard::Key::Space)) return false;
	m_clock.restart();
	return true;
}

Shot character::shotgen(){
	Vector2f p = s.getPosition();
	float ang = s.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	return Shot(p+25.f*d,d);
}
bool character::process_collisions(vector<stage> objects){	//Recibe todos los objetos con los que puede colisionar
	for(int i=0; i<objects.size(); ++i){
		if (process_collision(objects[i])==true){
			return true;
		}
	}return false;
}

bool character::process_collision(stage o){			//Recibe los objetos de a uno
	FloatRect cBB = s.getGlobalBounds();
	float ang = s.getRotation()*M_PI/180;
	Vector2f d(cos(ang),sin(ang));
	if (cBB.intersects(o.get_box())){
		
		return true;
	}
	return false;
}


