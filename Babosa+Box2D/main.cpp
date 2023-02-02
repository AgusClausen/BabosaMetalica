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

bool wall_colition (Shot &d, enemies &e1){
	Vector2f pd = d.seePos();
	Vector2f pe = e1.seePos();
	Vector2f v = pd-pe;
	return sqrt(v.x*v.x+v.y*v.y)<26; 
}
		
	
	
//Bool para que las balas que estan fuera de pantalla se eliminen	
bool out_of_screen(Shot &d) {
	Vector2f p = d.seePos();
	if (p.x<0 or p.x>1280) return true;
	if (p.y<0 or p.y>720) return true;
	return false;
}
	

int main(int argc, char *argv[]){
	
	RenderWindow w(VideoMode(1280,720),"Babosa Metalica");
	///mundo b2World
	b2World * world = new b2World(b2Vec2(0.f,0.f));
	w.setVerticalSyncEnabled(true);
	string s_name="pared.png";
	//Codigo para cargar la textura de la pared y sus sprites
	stage up_wall(s_name,0,0,1280,10,0,0,world);
	stage left_wall(s_name,0,0,10,720,0,0,world);
	stage down_wall(s_name,0,0,1280,10,0,710,world);
	stage right_wall(s_name,0,0,10,720*2,1270,0,world);
	vector <stage> objects;
	objects.push_back (up_wall);
	objects.push_back (left_wall);
	objects.push_back (down_wall);
	objects.push_back (right_wall);
	
	//Inicializacion de clases
	character c1 (world);
	enemies e1;
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
		e1.update();
		
		//Generar balas
		if(c1.mustshoot()) vd.push_back(c1.shotgen());
		
		for(Shot &d : vd) d.update();
		for(Shot &d : vd){//
			//if  Para hacer que las balas enemigas hagan da�o (Falta programar)
		}//
		
		auto it = remove_if(vd.begin(),vd.end(),out_of_screen);
		vd.erase(it,vd.end());
		
		for(Shot &d : vd) {
			if(collision(d,e1)&&colission_clock.getElapsedTime().asMilliseconds()>100){
				e1.get_damage(d.show_damage());
				colission_clock.restart();
			}
		}
		///mundo y f�sicas de box2D invisibles
		
		world->Step(1/60,8,8);
		world->ClearForces();
		//Dibujado de varias cosas
		w.clear(Color(220, 220,180,255));
		c1.draw(w);
		
		up_wall.draw(w);
		left_wall.draw(w);
		down_wall.draw(w);
		right_wall.draw(w);
		
		
		for(Shot &d : vd) d.draw(w);
		
		
		if (e1.is_alive()==true){
		e1.draw(w);
		}
		
		w.display();
	}
	return 0;
}

