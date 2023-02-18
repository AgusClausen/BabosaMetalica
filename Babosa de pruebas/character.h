#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class character {
	Texture t;
	Sprite s;
public:
	character();
	void update();
	void draw(RenderWindow &w);
};
#endif
