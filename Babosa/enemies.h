#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;
class enemies {
	Texture et;
	
public:
	Sprite es;
	enemies();
	void update();
	void draw(RenderWindow &w);
	Vector2f seePos(){
		return es.getPosition();
	}
};



#endif
