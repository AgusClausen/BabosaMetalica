#ifndef FONDO_H
#define FONDO_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "enemies.h"
using namespace sf;
class fondo {
	Texture t;
	Sprite s;
public:
	fondo();
	void update();
	void draw(RenderWindow &w);
};
#endif
