#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "character.h"
#include <vector>
#ifndef HUD_H
using namespace std;
class hud {
	vector<Text> datos;
	Font fuente;
public:
	hud();
	void update(character c);
	void draw(RenderWindow &w);
};
#endif
