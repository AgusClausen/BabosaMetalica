#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;


class Shot {
public:
	Shot(Vector2f pos, Vector2f dir,int penetration,int deviation,int dmg);
	
	
	bool must_app = true;
	
	void update(Vector2f pos_mapa);
	Clock get_clock();
	void restart_clock(){
		clock.restart();
	}
	void draw(RenderWindow &w);	
	Vector2f seePos() {
		return m_circ.getPosition();
	}
	int show_damage();
	void shot_colliding();
	bool shot_must_appear();
private:
	int pen = 1;
	CircleShape m_circ;
	Vector2f m_vel;
	int damage=20;
	int dev;
	Clock clock;
};


#endif

