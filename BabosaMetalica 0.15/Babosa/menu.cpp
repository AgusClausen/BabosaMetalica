#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

menu::menu() {
	t.loadFromFile("Imágen menú principal alpha.jpg");
	s.setTexture(t);
	s.setPosition(0,0);
}
void menu::draw(RenderWindow &w){
	w.draw(s);
}
