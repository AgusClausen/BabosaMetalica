#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
#include "character.h"
using namespace std;
using namespace sf;
class hud {
	Font fuente;
	vector<Text> datos;
public:
	hud();
	void update(character c);
	void draw(RenderWindow &w);
};

#endif

 
