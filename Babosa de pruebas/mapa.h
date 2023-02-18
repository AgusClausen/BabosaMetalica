#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class mapa {
	Texture t;
	Sprite s;
public:
	mapa();
	void update();
	void draw(RenderWindow &w);
};
#endif
