#include "stage.h"
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

stage::stage(string name,int p1,int p2,int p3,int p4) {
	t.loadFromFile (name);
	s.setTexture(t);
	s.setTextureRect(IntRect(p1,p2,p3,p4));
}
void stage::move (int x, int y){
	s.move(x,y);
}
void stage::draw(RenderWindow &w){
	w.draw(s);
}
FloatRect stage::get_box(){
	return s.getGlobalBounds();
}
Vector2f stage::give_position(){return s.getPosition();}
