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
#include "sprites.h"
#include "hud.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Sounds.h"
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
bool enemy_is_dead(enemies &e) {
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
bool check_damage(character c,vector <enemies> ev,Clock colission_clock){
	for(enemies &e : ev){
		Vector2f pd = e.seePos();
		Vector2f pe = c.seePos();
		Vector2f v = pd-pe;
		if ((sqrt(v.x*v.x+v.y*v.y)<35)&&(colission_clock.getElapsedTime().asMilliseconds()>500)&&e.is_alive()==true){
		cout << "-10" << endl;
		colission_clock.restart();
		return true;
	}
	return false;
}
}


	
int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Babosa Metalica");
	w.setFramerateLimit(60);
	
	Sounds gun_grab("grab_weapon.wav");///
	Sounds hit("shot_hitting.wav");///
	Sounds kill("kill.wav");///
	Sounds rev_load("revolver_load.wav");///
	
	
	float enemy_hp = 40;
	int enemy_kill_count= 0;
	int generate_item_count= 0;
	float enemies_respawn_time=3000;
	
	
	
	vector <gun_data> g_dv = get_gun_data("gun_data.txt");
	
	for(int i=0;i<g_dv.size();i++) {  
		cout << g_dv[i].name << endl;
		for(int k=0;k<6;k++) { 
			cout << g_dv[i].values[k] << endl;
		}
	}
	mapa m1;
	hud h1;
	sprites a1/*,g1,g2,g3,g4,g5,g6,g7*/;
	Texture* texture_enemy = new Texture; 
	*texture_enemy = a1.get_enemy_texture();
	
	vector <enemies> ev;
	vector <int> is_enemy_dead;
	
	Texture* texture_pistol = new Texture; 
	Texture* texture_ar = new Texture; 
	Texture* texture_sniper = new Texture; 
	Texture* texture_revolver = new Texture; 
	Texture* texture_shotgun = new Texture; 
	Texture* texture_smg = new Texture; 
	Texture* texture_bananagun = new Texture; 
	
	*texture_pistol = a1.get_pistol_texture();
	*texture_ar = a1.get_ar_texture();
	*texture_sniper = a1.get_sniper_texture();
	*texture_revolver = a1.get_revolver_texture();
	*texture_shotgun = a1.get_shotgun_texture();
	*texture_smg = a1.get_smg_texture();
	*texture_bananagun = a1.get_bananagun_texture();
	
	//items nit;//new item
	int drop_rate;
	int gn;//gun number
	
	vector <items> voi;
	
	
	int item_in_hands=0;
	int item_in_hands_aux=0;
	
	
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
	Clock enemies_spawn_clock;
	Clock game_time;
	
	
	bool iniciar=false;
	
	
	
	
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			w.clear(Color(220, 220,180,255));
			if(e.type == Event::Closed)
				w.close();	
		}
		if (c1.is_alive()==false) iniciar=false;
		while (iniciar==false){
			if (!Keyboard::isKeyPressed(Keyboard::Key::Space)){
				men.draw(w);
				w.display();
			}else{iniciar=true;}
		}
		//Iniciar personaje y enemigos
		
		
		
		
		
		
		m1.update(m1.coordenadas());
		h1.update(c1);
		
		for(int i=0;i<voi.size();i++){
			voi[i].update(m1.coordenadas());
		}
		
		c1.update(objects);
		
		for(int i=0;i<voi.size();i++){
			item_in_hands_aux = item_in_hands;///
			item_in_hands = check_grab(voi[i],c1,g_dv,item_in_hands);
			if(item_in_hands_aux!=item_in_hands&&item_in_hands!=3){///
				gun_grab.play_sound();///
			}else{///
				if(item_in_hands_aux!=item_in_hands){rev_load.play_sound();}///
			}///  
		}
		
		for(enemies &e : ev) e.update(m1.coordenadas(),c1.seePos());
		bool checking=check_damage(c1,ev,colission_clock);
		if(checking==true){
			colission_clock.restart();
			c1.get_damage(10);
		}
		//Generar balas
		
		
		if(enemies_respawn_time>200 &&enemies_spawn_clock.getElapsedTime().asMilliseconds()>5000){
			enemies_respawn_time-=100;
			if(enemy_hp<70){
				enemy_hp +=2;
			}
			enemies_spawn_clock.restart();
		}
		
		if(enemies_clock.getElapsedTime().asMilliseconds()>enemies_respawn_time){
			int rx;
			int ry;
			ry=rand()%(720);
			rx=rand()%(1280);
			while (rx<1040 && rx> 240 && ry>60 && ry<660){
				ry=rand()%(720);
				rx=rand()%(1280);
			}
			enemies e(rx,ry,1,texture_enemy, enemy_hp);
			enemies_clock.restart();
			ev.push_back(e);
			is_enemy_dead.push_back(0);
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
		
		auto it_shot_out = remove_if(vd.begin(),vd.end(),out_of_screen);
		vd.erase(it_shot_out,vd.end());
		
		
		auto it_shot_col = remove_if(vd.begin(),vd.end(),piercing_value_check);
		vd.erase(it_shot_col,vd.end());
		
		
		//Contar cuantos enemigos estan muertos
		for(int i=0;i<ev.size();++i){
			if(ev[i].is_alive()==false&&is_enemy_dead[i]<3){
				is_enemy_dead[i]+=1;
				for(int i=0;i<is_enemy_dead.size();i++){
					if(is_enemy_dead[i]==1){
						enemy_kill_count+=1;
						kill.play_sound();///
						cout << enemy_kill_count << endl;
						if ((drop_rate=rand()%100)<=10){
							switch(gn=rand()%6){
							case 0: {items nit(texture_pistol, ev[i].seePos().x, ev[i].seePos().y,"basicpistol.png");
							voi.push_back(nit);
							break;
							}
							case 1: {items nit(texture_ar, ev[i].seePos().x, ev[i].seePos().y,"assaultrifle.png");
							voi.push_back(nit);
							break;
							}
							case 2: {items nit(texture_sniper, ev[i].seePos().x, ev[i].seePos().y,"sniper.png");
							voi.push_back(nit);
							break;
							}
							case 3: {items nit(texture_revolver, ev[i].seePos().x, ev[i].seePos().y,"magnumrevolver.png");
							voi.push_back(nit);
							break;
							}
							case 4: {items nit(texture_shotgun, ev[i].seePos().x, ev[i].seePos().y,"shotgun.png");
							voi.push_back(nit);
							break;
							}
							case 5: {items nit(texture_smg, ev[i].seePos().x, ev[i].seePos().y,"smg.png");
							voi.push_back(nit);
							break;
							}
							}
						}
						if(enemy_kill_count!=generate_item_count){
							ev[i].seePos();
							generate_item_count=enemy_kill_count;
							
						}
					}
				}
			}
		}
		
		
		
		
		//Borrar enemigos que mueren 
		auto it_enemy = remove_if(ev.begin(),ev.end(),enemy_is_dead);
		ev.erase(it_enemy,ev.end());
		
		for(enemies &e : ev){
			for(Shot &d : vd){
				if(collision(d,e)&&d.get_clock().getElapsedTime().asMilliseconds()>75){
					e.get_damage(d.show_damage());
					d.restart_clock();
					d.shot_colliding();
					hit.play_sound();///
					
				}
			}
		}
		
		
		//Dibujado de varias cosas
		w.clear(Color(110, 110,110,50));
		m1.draw(w);
		h1.draw(w);
		
		
		for(int i=0;i<voi.size();i++){
			if(voi[i].check()==true)
			voi[i].draw(w);
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
	delete texture_enemy;
	return 0;
}

