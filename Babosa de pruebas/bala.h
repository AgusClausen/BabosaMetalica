#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class bala {
	Texture t;
	Sprite s;
public:
	bala();
	bool update();
	void draw(RenderWindow &w);
};
#endif

