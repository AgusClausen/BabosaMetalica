#include "Partida.h"
#include "enemies.h"
#include "Shot.h"
#include "stage.h"
#include "character.h"
#include "mapa.h"
#include "items.h"
#include "sprites.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

Partida::Partida() {
	
}

struct gun_data{
	string name,c_model;
	vector <int> values;		//order of vector: rounds per minute, penetration value, damage value, bullet deviation value, mag capacity, reload time
};

vector <gun_data> get_gun_data(string s){
	vector <string> v ;
	string line;
	ifstream archive (s);
	while(getline (archive,line)){
		v.push_back(line);
	}
	archive.close();
	vector <gun_data> vd (7);
	int j=0;
	for(int i=0;i<vd.size();i++) {  
		vd[i].name = v[j];
		++j;
		vd[i].c_model=v[j];
		j++;
		for(int k=0;k<6;k++) { 
			vd[i].values.push_back(stoi(v[j]));
			j++;
		}
	}
	return vd;
}
	
//Bool para ver si una bala colisiona con un enemigo
bool collision (Shot &d, enemies &e1){
	Vector2f pd = d.seePos();
	Vector2f pe = e1.seePos();
	Vector2f v = pd-pe;
	if (e1.is_alive()==true){
		return sqrt(v.x*v.x+v.y*v.y)<23; 
	}else return false;
}		

//Bool para que las balas que estan fuera de pantalla se eliminen	
bool out_of_screen(Shot &d) {
	Vector2f p = d.seePos();
	if (p.x<0 or p.x>1280) return true;
	if (p.y<0 or p.y>720) return true;
	return false;
}
		
//bool para chequear si las balas tienen que traspasar el enemigo o no
bool piercing_value_check(Shot &d){
	if (d.shot_must_appear()==false) return true;
}
			
			
//Funcion para borrar enemigos muertos
bool enemie_is_dead(enemies &e) {
	if (e.is_alive()==true){return false;}
}
			
int check_grab(items &it, character &c, vector<gun_data>gdv,int item){
	if (it.check()==true){
		Vector2f pd = it.seePos();
		Vector2f pe = c.seePos();
		Vector2f v = pd-pe;
		if (sqrt(v.x*v.x+v.y*v.y)<23){
			string s=it.get_name();
			int gih;//gun in hands
			for(int i=0;i<gdv.size();i++) {  
				if (gdv[i].name==s){
					gih=i;
					c.change_weapon(gdv[i].c_model,gdv[i].values[2],gdv[i].values[1],gdv[i].values[3],gdv[i].values[0]);
					it.eliminate();
					return gih;
				}
			}
		}
	}
	return item;
}


void Partida::update () {
	m1.update(m1.coordenadas());
	it1.update(m1.coordenadas());
	c1.update(objects);
	
	item_in_hands = check_grab(it1,c1,g_dv,item_in_hands);
	
	for(enemies &e : ev) e.update(m1.coordenadas());
	//Generar balas
	
	
	if(enemies_clock.getElapsedTime().asMilliseconds()>enemies_respawn_time){
		int rx;
		int ry;
		ry=rand()%(720);
		rx=rand()%(1280);
		while (rx<1040 && rx> 240 && ry>60 && ry<660){
			ry=rand()%(720);
			rx=rand()%(1280);
		}
		cout << rx << endl << ry << endl << enemies_respawn_time << endl;
		enemies e(rx,ry,1,texture_enemy);
		enemies_clock.restart();
		ev.push_back(e);
		
		enemies_respawn_time-=20;
	}
	
	
	
	if(c1.mustshoot()) {
		if (c1.get_name()=="g5.png"){
			for(int i=0;i<9;i++) {
				vd.push_back(c1.shotgen(m1.coordenadas()));
			}
		}else vd.push_back(c1.shotgen(m1.coordenadas()));
	}
	
	
	for(Shot &d : vd) d.update(m1.coordenadas());
	
	//Borrar balas fuera de pantalla y que colisionan
	
	auto it = remove_if(vd.begin(),vd.end(),out_of_screen);
	vd.erase(it,vd.end());
	
	
	auto it2 = remove_if(vd.begin(),vd.end(),piercing_value_check);
	vd.erase(it2,vd.end());
	
	
	//Borrar enemigos que mueren 
	auto it3 = remove_if(ev.begin(),ev.end(),enemie_is_dead);
	ev.erase(it3,ev.end());
	
	for(enemies &e : ev){
		for(Shot &d : vd){
			if(collision(d,e)&&colission_clock.getElapsedTime().asMilliseconds()>75){
				e.get_damage(d.show_damage());
				colission_clock.restart();
				d.shot_colliding();
			}
		}
	}
}


void Partida::draw(RenderWindow &w){
	w.clear(Color(220, 220,180,255));
	
	m1.draw(w);
	
	if (it1.check()==true){
		it1.draw(w);
	}
	
	c1.draw(w);
	
	for(Shot &d : vd){
		d.draw(w);
	}
	
	for(enemies &e : ev){
		if(e.is_alive()==true){
			e.draw(w);
		}
	}
}
