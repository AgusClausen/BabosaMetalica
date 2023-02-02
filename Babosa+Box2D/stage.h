#ifndef STAGE_H
#define STAGE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <Box2D/Box2D.h>

using namespace std;
using namespace sf;

class stage {
	Texture t;
	Sprite s;
	b2Body * b;
	b2BodyDef b_def;
	b2Fixture * f;
	b2FixtureDef f_def;
	b2PolygonShape s_box;
public:
	stage(string,int,int,int,int,int,int,b2World * w);
	void draw(RenderWindow &w);
	FloatRect get_box();
	Vector2f give_position();
};

#endif

