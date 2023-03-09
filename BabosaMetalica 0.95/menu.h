#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "character.h"
#ifndef MENU_H
class menu {
	Texture t1,t2,t3;
	Sprite s1,s2,s3;
	bool ready;
	int points;
public:
	menu();
	bool start(Clock game_time,int game_kills,bool dead);
	void draw_death_screen (RenderWindow &w);
	void draw_main_menu (RenderWindow &w);
	void draw_records_screen (RenderWindow &w);
};
#endif
