#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

menu::menu() {
	t1.loadFromFile("Imágen menú principal alpha.jpg");
	s1.setTexture(t1);
	s1.setPosition(0,0);
}
void menu::draw(RenderWindow &w){
	w.draw(s1);
}
