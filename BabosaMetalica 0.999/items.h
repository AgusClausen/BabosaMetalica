#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include "Shot.h"
#ifndef ITEMS_H
using namespace std;
class items{
	Vector2f center;
	Texture t;
	Sprite s;
	string name;
	bool exists;;
	public:
	items(Texture* itt, float posx, float posy, string str);
	void update(Vector2f pos_mapa);
	void draw(RenderWindow &w);
	void eliminate();
	bool check();
	FloatRect get_box();
	Vector2f seePos();
	string get_name();
};
#endif
