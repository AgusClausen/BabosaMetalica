#include "character.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <Box2D/Box2D.h>
using namespace std;

character::character(b2World * w) {
	t.loadFromFile("file.png");
	s.setTexture(t);
	//s.setPosition(100,350); 
	//s.setOrigin(t.getSize().x/2,t.getSize().y/2);
	b_def.type = b2BodyType::b2_dynamicBody;
	b_def.position=b2Vec2(100+t.getSize().x/2,t.getSize().y/2+350);
	b= w->CreateBody(&b_def);
	s_box.m_radius = t.getSize().x/2.f;
	f_def.shape=&s_box;
	f_def.density=1.f;
	f_def.friction=0.2f;
	f_def.restitution=0.f;
	f= b->CreateFixture(&f_def);
	s.setPosition(b->GetPosition().x,b->GetPosition().y);
	s.setOrigin(t.getSize().x/2,t.getSize().y/2);
	}

void character::update(vector <stage> objects){
	b->ApplyForceToCenter(b2Vec2(b->GetPosition().x,b->GetPosition().y),false);
	if(Keyboard::isKeyPressed(Keyboard::Key::Right)||Keyboard::isKeyPressed(Keyboard::Key::Left)
	   ||Keyboard::isKeyPressed(Keyboard::Key::D)||Keyboard::isKeyPressed(Keyboard::Key::A)||Keyboard::isKeyPressed(Keyboard::Key::W)
		||Keyboard::isKeyPressed(Keyboard::Key::S)){
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		s.rotate(2);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		s.rotate(-2);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)){
		vel.x=3;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)){
		vel.x=-3;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)){
		vel.y=3;
	}
	if(Keyboard::isKeyPressed(Keyboard::Key::W)){
		vel.y=-3;
	}
	}
	
	up=true;
	down=true;
	left=true;
	right=true;
	b->SetLinearVelocity(vel);
}

void character::draw(RenderWindow &w){
	s.setPosition(b->GetPosition().x,b->GetPosition().y);
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



