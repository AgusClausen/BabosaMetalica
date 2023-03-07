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
	int hp;
	int pen=1;
	int rsv=225;
	int dev=0;
	int dmg=30;
	string name;
public:
	character(string str);
	void update(vector<stage>objects);
	void draw(RenderWindow &w);
	bool mustshoot();
	Shot shotgen(Vector2f pos_mapa);
	bool process_collisions(vector<stage>);
	bool process_collision(stage);
	void get_damage(int);
	void change_weapon(string str, int damage,int penetration, int deviation, int rounds_spawn_velocity);
	FloatRect get_box();
	bool is_alive();
	Vector2f seePos(){
		return s.getPosition();
	}
	string get_name () {
		return name;
	}
	int get_hp(){
		return hp;
	}
};
#endif

