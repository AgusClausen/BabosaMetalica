#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class enemies {
	Texture t;
	Sprite s;
	Vector2f pos_enemie;
	int x; int y;
public:
	enemies(int x, int y);
	void update(Vector2f pos_mapa);
	void draw(RenderWindow &w);
};
#endif
