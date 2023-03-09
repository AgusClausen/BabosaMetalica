#include <SFML/Graphics/RenderWindow.hpp>
#include "menu.h"
menu::menu() {
	t1.loadFromFile("main_menu.png");
	s1.setTexture(t1);
	s1.setPosition(0,0);
	t2.loadFromFile("records_screen.png");
	s2.setTexture(t2);
	s2.setPosition(0,0);
	t3.loadFromFile("death_screen.png");
	s3.setTexture(t3);
	s3.setPosition(0,0);
}
bool menu::start(Clock game_time,int enemy_kill_count,bool dead){
	ready=dead;
	if (ready==true){
		points = game_time.getElapsedTime().asSeconds();
		points = (points*enemy_kill_count)/2;
		return false;
	}else {
		return true;
	}
}
void menu::draw_death_screen (RenderWindow &w){
	w.draw(s3);
}
void menu::draw_main_menu (RenderWindow &w){
	w.draw(s1);
}
void menu::draw_records_screen (RenderWindow &w){
	w.draw(s2);
}
