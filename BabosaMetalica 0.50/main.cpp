#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "Shot.h"
#include "enemies.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include "menu.h"
#include "stage.h"
#include "mapa.h"
#include <fstream>
#include "items.h"
using namespace std;
using namespace sf;

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
	
vector <enemies> generate_enemies(vector<enemies>ev){
	int ex=200;
	int ey=500;
	int type=1;
	for(int i=0;i<3;i++) { 
		enemies e(ex,ey,type);
		ex+=200;
		ev.push_back(e);
	}
	return ev;
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


	
int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Babosa Metalica");
	
	vector <gun_data> g_dv = get_gun_data("gun_data.txt");
	
	for(int i=0;i<g_dv.size();i++) {  
		cout << g_dv[i].name << endl;
		for(int k=0;k<6;k++) { 
			cout << g_dv[i].values[k] << endl;
		}
	}
	mapa m1;
	
	vector <enemies> ev;
	
	enemies e1(150,400,1);
	
	ev.push_back(e1);
	
	ev = generate_enemies(ev);
	
	items it1 (g_dv[4].name,470,300);
	
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
	
	menu men;
	
	Clock colission_clock;
	Clock enemies_clock;
	
	bool iniciar=false;
	
	w.setFramerateLimit(60);
	
	
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			w.clear(Color(220, 220,180,255));
			if(e.type == Event::Closed)
				w.close();	
		}
		while (iniciar==false){
			if (!Keyboard::isKeyPressed(Keyboard::Key::Space)){
				men.draw(w);
				w.display();
			}else{iniciar=true;}
		}
		//Iniciar personaje y enemigos
		
		
		
		
		
		
		m1.update(m1.coordenadas());
		it1.update(m1.coordenadas());
		c1.update(objects);
		
		item_in_hands = check_grab(it1,c1,g_dv,item_in_hands);
		
		for(enemies &e : ev) e.update(m1.coordenadas());
		//Generar balas
		
		
		if(enemies_clock.getElapsedTime().asMilliseconds()>5000){
			int rx=rand()%(2,1);
			int rxval;
			if (rx==1){
				rxval=rand()%(601,1);
			}
			if (rx==2){
				rxval=rand()%(1270,801);
			}
			enemies e(600,200,1);
			enemies_clock.restart();
			ev.push_back(e);
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
		
		
		//Dibujado de varias cosas
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
		
		w.display();
	}
	return 0;
}

