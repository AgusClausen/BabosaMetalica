#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
using namespace sf;
class mapa {
	Texture t;
	Sprite s;
public:
	mapa();
	void update(Vector2f pos_mapa);
	void draw(RenderWindow &w);
	Vector2f coordenadas();
};
#endif
