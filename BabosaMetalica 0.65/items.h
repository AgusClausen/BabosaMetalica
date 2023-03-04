#ifndef ITEMS_H
#define ITEMS_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Shot.h"
#include <SFML/System/Clock.hpp>
#include <vector>
#include "stage.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
using namespace std;
class items {
	Texture t;
	Sprite s;
	string name;
	bool exists=true;
	public:
	items(string str, float posx, float posy);
	FloatRect get_box();
	void eliminate();
	bool check();
	void draw(RenderWindow &w);
	void update(Vector2f pos_mapa);
	string get_name();
	Vector2f seePos(){
		return s.getPosition();
	}
};

#endif

