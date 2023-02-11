#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;


class Shot {
public:
	Shot(Vector2f pos, Vector2f dir);
	
	float penetration = 1;
	bool must_app = true;
	
	void update();
	
	
	void draw(RenderWindow &w);	
	Vector2f seePos() {
		return m_circ.getPosition();
	}
	float show_damage();
	void shot_colliding();
	bool shot_must_appear();
private:
	CircleShape m_circ;
	Vector2f m_vel;
	float damage=20;
};


#endif

