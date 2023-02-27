#ifndef STAGE_H
#define STAGE_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;
using namespace sf;
class stage {
	Texture t;
	Sprite s;
public:
	stage(string,int,int,int,int);
	void move (int,int);
	void draw(RenderWindow &w);
	FloatRect get_box();
	Vector2f give_position();
};

#endif

