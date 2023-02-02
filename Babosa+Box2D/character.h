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
using namespace std;
using namespace sf;

class character {
	Texture t;
	Sprite s;
	Clock m_clock;
	bool alive=true;
	b2Vec2 vel;
	bool up=true;
	bool right=true;
	bool left=true;
	bool down=true;
	b2Body * b;
	b2BodyDef b_def;
	b2Fixture * f;
	b2FixtureDef f_def;
	b2CircleShape s_box;
public:
	character(b2World * w);
	void update(vector<stage>objects);
	void draw(RenderWindow &w);
	bool mustshoot();
	Shot shotgen();
};

#endif

