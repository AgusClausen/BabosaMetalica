#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#ifndef SHOT_H
#define SHOT_H
using namespace sf;
class Shot{
	int pen;
	CircleShape m_circ;
	Vector2f m_vel;
	int damage;
	int dev;
	Clock clock;
	bool must_app;
public:
	Shot(Vector2f pos, Vector2f dir,int penetration,int deviation,int dmg);
	void update(Vector2f pos_mapa);
	void draw(RenderWindow &w);	
	void shot_colliding();
	void restart_clock();
	bool shot_must_appear();
	int show_damage();
	Clock get_clock();
	Vector2f seePos();
};


#endif

