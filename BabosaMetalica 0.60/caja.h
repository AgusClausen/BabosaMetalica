#ifndef CAJA_H
#define CAJA_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class caja {
	Texture t;
	Sprite s;
public:
	caja();
	void update();
	void draw(RenderWindow &w);
};

#endif

