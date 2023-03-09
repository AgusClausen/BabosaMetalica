#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Shot.h"
#include <string>
using namespace std;
class character{
	int dmg;
	int pen;
	int rsv;
	int dev;
	int hp;
	bool alive;
	FloatRect box;
	Clock m_clock;
	Vector2f vel;
	string gun;
	Texture t;
	Sprite s;
public:
	character(string name);
	void change_weapon(string gun, int damage,int penetration, int deviation, int rounds_spawn_velocity);
	void update();
	void draw(RenderWindow &w);
	void get_damage(int damage);
	bool mustshoot();
	Shot shotgen(Vector2f pos_mapa);
	FloatRect get_box();
	bool is_alive();
	string get_gun();
	void reset ();
	int get_hp(){
		return hp;
	}
};
#endif

