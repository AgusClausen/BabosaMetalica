#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class enemies {
	Texture t;
	Sprite s;
public:
	enemies();
	void update();
	void draw(RenderWindow &w);
};

#endif
