#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
using namespace std;
using namespace sf;
class enemies {
	friend class hud;
	float hp = 0;
	bool alive=true;
	Clock e_clock;
	Vector2f pos_enemie;
	int x; int y;
	Sprite es;
	vector <Sprite> v_es;
	float modulo;
	bool attacking = false;
	public:
	
	enemies(int x,int y,int type, Texture *et, float enemy_hp);
	void update(Vector2f pos_mapa);
	void get_damage(float);
	void draw(RenderWindow &w);
	Vector2f seePos(){
		return es.getPosition();
	}
	bool is_alive();
	void is_attacking();
};



#endif
