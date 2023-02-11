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
using namespace std;
using namespace sf;
//Bool para ver si una bala colisiona con un enemigo
bool collision (Shot &d, enemies &e1){
	Vector2f pd = d.seePos();
	Vector2f pe = e1.seePos();
	Vector2f v = pd-pe;
	return sqrt(v.x*v.x+v.y*v.y)<23; 
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
	
//Funcion para generar enemigos
enemies generate_enemies(int x, int y, vector<enemies> ev){
	enemies e(x,y);
	return e;
}
	
//Funcion para borrar enemigos muertos
bool enemie_is_dead(enemies &e) {
	if (e.is_alive()==true){return false;}
}

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Babosa Metalica");
	
	
	vector <enemies> ev;
	
	enemies e1 = generate_enemies(200,200,ev);
	ev.push_back(e1);
	enemies e2 = generate_enemies(400,200,ev);
	ev.push_back(e2);
	
	string s_name="pared.png";
	//Codigo para cargar la textura de la pared y sus sprites
	stage up_wall(s_name,0,0,1280,10);
	stage left_wall(s_name,0,0,10,720);
	stage down_wall(s_name,0,0,1280,10);
	stage right_wall(s_name,0,0,10,720);
	down_wall.move(0,710);
	right_wall.move(1270,0);
	
	vector <stage> objects;
	objects.push_back (up_wall);
	objects.push_back (left_wall);
	objects.push_back (down_wall);
	objects.push_back (right_wall);
	
	//Inicializacion de clases
	character c1;
	vector<Shot> vd;
	
	menu men;
	
	Clock colission_clock;
	
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
		
		c1.update(objects);
		
		for(enemies &e : ev) e.update();
		//Generar balas
		
		if(c1.mustshoot()) vd.push_back(c1.shotgen());
		
		//ev.push_back(
		
		for(Shot &d : vd) d.update();
		
		//Borrar balas fuera de pantalla y que colisionan
		
		auto it = remove_if(vd.begin(),vd.end(),out_of_screen);
		vd.erase(it,vd.end());
		
		auto it2 = remove_if(vd.begin(),vd.end(),piercing_value_check);
		vd.erase(it2,vd.end());
		
		//Borrar enemigos que mueren FALTA HACER QUE DEJEN DE RECIBIR BALAS CUANDO MUEREN
		auto it3 = remove_if(ev.begin(),ev.end(),enemie_is_dead);
		ev.erase(it3,ev.end());
		
		for(Shot &d : vd){
			for(enemies &e : ev){
				if(collision(d,e)&&colission_clock.getElapsedTime().asMilliseconds()>75){
					e.get_damage(d.show_damage());
					colission_clock.restart();
					d.shot_colliding();
				}
			}
		}
		//Dibujado de varias cosas
		w.clear(Color(220, 220,180,255));
		
		c1.draw(w);
		
		up_wall.draw(w);
		left_wall.draw(w);
		down_wall.draw(w);
		right_wall.draw(w);
		
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

