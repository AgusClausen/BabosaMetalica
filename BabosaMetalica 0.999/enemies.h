#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#ifndef ENEMIES_H
using namespace sf;
class enemies {
	float modulo;
	float hp;
	bool alive;
	bool drop;
	Vector2f position;
	Sprite s;
public:
	enemies(int x,int y, Texture *et, float hp);
	void update(Vector2f pos_mapa);
	void get_damage(float damage);
	void draw(RenderWindow &w);
	void reset();
	bool check_drop();
	bool is_alive();
	Vector2f seePos();
	~enemies(){}
};
#endif
