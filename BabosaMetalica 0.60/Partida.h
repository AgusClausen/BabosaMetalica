#ifndef PARTIDA_H
#define PARTIDA_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
#include <fstream>
#include "mapa.h"
#include "sprites.h"
#include <SFML/Graphics/Texture.hpp>
#include "items.h"
#include <vector>
#include "stage.h"
#include <SFML/System/Clock.hpp>
#include "enemies.h"
#include "Shot.h"
#include "character.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Partida.h"

using namespace std;

class Partida {
public:
	Partida();
	void update();
	void draw(RenderWindow &w);
private:
	
	struct gun_data{
		string name,c_model;
		vector <int> values;		//order of vector: rounds per minute, penetration value, damage value, bullet deviation value, mag capacity, reload time
	};
	
	float enemies_respawn_time=3000;
	
	vector <gun_data> g_dv = get_gun_data("gun_data.txt");
	
	for(int i=0;i<g_dv.size();i++) {  
		cout << g_dv[i].name << endl;
		for(int k=0;k<6;k++) { 
			cout << g_dv[i].values[k] << endl;
		}
	}
	mapa m1;
	
	sprites a1;
	Texture* texture_enemy = new Texture; 
	*texture_enemy = a1.get_enemy_texture();;
	
	vector <enemies> ev;
	
	
	items it1 (g_dv[1].name,200,300);
	items it2 (g_dv[2].name,400,300);
	items it3 (g_dv[3].name,600,300);
	items it4 (g_dv[4].name,800,300);
	items it5 (g_dv[5].name,400,500);
	items it6 (g_dv[6].name,600,500);
	
	int item_in_hands=0;
	
	string s_name="pared.png";
	//Codigo para cargar la textura de la pared y sus sprites
	stage up_wall(s_name,0,0,1280,10);
	stage left_wall(s_name,0,0,10,720);
	stage down_wall(s_name,0,0,1280,10);
	stage right_wall(s_name,0,0,10,720);
	down_wall.move(0,710);
	right_wall.move(1270,0);
	
	vector <stage> objects;
	
	//Inicializacion de clases
	character c1(g_dv[item_in_hands].c_model);
	vector<Shot> vd;
	
	Clock colission_clock;
	Clock enemies_clock;
	Clock game_time_clock;
};

#endif

