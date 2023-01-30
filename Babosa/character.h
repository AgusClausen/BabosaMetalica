#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Shot.h"
#include <SFML/System/Clock.hpp>
using namespace sf;

class character {
	Texture t;
	Sprite s;
	Clock m_clock;
public:
	character();
	void update();
	void draw(RenderWindow &w);
	bool mustshoot();
	Shot shotgen();
};

#endif

