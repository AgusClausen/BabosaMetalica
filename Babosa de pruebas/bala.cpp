#include "bala.h"
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;
using namespace sf;
bala::bala() {
	t.loadFromFile("bala.png");
	s.setTexture(t);
	s.setPosition(640, 360);
	s.setOrigin(0,0);
}
bool bala::update(){
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)){
		return true;
	}else{
		return false;
	}
}
void bala::draw(RenderWindow &w){
	w.draw(s);
	s.move(3,0);
}
