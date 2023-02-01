#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;


class Shot {
public:
	Shot(Vector2f pos, Vector2f dir);
	void update();
	void draw(RenderWindow &w);	
	Vector2f seePos() {
		return m_circ.getPosition();
	}
	float show_damage();
private:
	CircleShape m_circ;
	Vector2f m_vel;
	float damage=20;
};


#endif

