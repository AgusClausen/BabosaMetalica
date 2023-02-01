#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class enemies {
	Texture et;
	float hp=100;
	bool alive=true;
	Clock e_clock;
public:
	Sprite es;
	enemies();
	void update();
	void get_damage(float);
	void draw(RenderWindow &w);
	Vector2f seePos(){
		return es.getPosition();
	}
	bool is_alive();
};



#endif
