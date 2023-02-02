#include "stage.h"
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <Box2D/Box2D.h>

stage::stage(string name,int p1,int p2,int p3,int p4,int x, int y,b2World * w) {
	t.loadFromFile (name);
	s.setTexture(t);
	s.setTextureRect(IntRect(p1,p2,p3,p4));
	s.move(x,y);
	//s.setOrigin(t.getSize().x/2,t.getSize().y/2);
	b_def.type = b2BodyType::b2_staticBody;
	b_def.position=b2Vec2(s.getPosition().x+s.getScale().x/2,s.getPosition().y+s.getScale().y/2-1);
	b= w->CreateBody(&b_def);
	s_box.SetAsBox  (s.getScale().x/2.f,s.getScale().y/2.f);
	f_def.shape=&s_box;
	f_def.density=1.f;
	f_def.friction=0.3f;
	f_def.restitution=0.f;
	f= b->CreateFixture(&f_def);
	s.setPosition(b->GetPosition().x,b->GetPosition().y);
	//s.setOrigin(t.getSize().x/2,t.getSize().y/2);
}

void stage::draw(RenderWindow &w){
	w.draw(s);
}
FloatRect stage::get_box(){
	return s.getGlobalBounds();
}
Vector2f stage::give_position(){return s.getPosition();}
