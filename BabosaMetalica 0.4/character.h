#ifndef CHARACTER_H
#define CHARACTER_H
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
using namespace sf;

class character {
	Texture t;
	Sprite s;
	Clock m_clock;
	bool alive=true;
	Vector2f vel;
	bool up=true;
	bool right=true;
	bool left=true;
	bool down=true;
	FloatRect box;
public:
	character();
	void update(vector<stage>objects);
	void draw(RenderWindow &w);
	bool mustshoot();
	Shot shotgen(Vector2f pos_mapa);
	bool process_collisions(vector<stage>);
	bool process_collision(stage);
};

#endif

