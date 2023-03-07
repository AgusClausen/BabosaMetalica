#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;
using namespace sf;

class menu {
	Texture t1,t2;
	Sprite s1,s2;
public:
	menu();
	void draw(RenderWindow &w);
};

#endif

