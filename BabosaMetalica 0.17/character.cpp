#include "character.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;

character::character() {
	t.loadFromFile("file.png");
	s.setTexture(t);
	s.setPosition(100,350); 
	s.setOrigin(35,35);
	}

void character::update(vector <stage> objects){
	vel.x=0;
	vel.y=0;
	bool collision=process_collisions(objects);
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
	if(Keyboard::isKeyPressed(Keyboard::Key::Right)||Keyboard::isKeyPressed(Keyboard::Key::Left)
	   ||Keyboard::isKeyPressed(Keyboard::Key::D)||Keyboard::isKeyPressed(Keyboard::Key::A)||Keyboard::isKeyPressed(Keyboard::Key::W)
		||Keyboard::isKeyPressed(Keyboard::Key::S)){
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(4);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-4);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)&&right==true){
		vel.x=3;
	} else if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		vel.x=-3;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)&&left==true){
		vel.x=-3;
	} else if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		vel.x=3;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)&&down==true){
		vel.y=3;
	}else if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		vel.y=-3;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)&&up==true){
		vel.y=-3;
	}else if(Keyboard::isKeyPressed(Keyboard::Key::W)){
		vel.y=3;
	}
	}
	
	up=true;
	down=true;
	left=true;
	right=true;
	
	s.move(vel);
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


