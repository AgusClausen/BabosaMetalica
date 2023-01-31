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
	
	
	//Codigo para cargar la textura de la pared y sus sprites
	Texture wall;
	wall.loadFromFile("pared.png");
	Sprite up_wall(wall);
	Sprite left_wall(wall);
	Sprite down_wall(wall);
	Sprite right_wall(wall);
	up_wall.setTextureRect(IntRect(0,0,1280,10));
	left_wall.setTextureRect(IntRect(0,0,10,720));
	down_wall.setTextureRect(IntRect(0,0,1280,10));
	down_wall.move(0,710);
	right_wall.setTextureRect(IntRect(0,0,10,720));
	right_wall.move(1270,0);
	
	
	//Inicializacion de clases
	character c1;
	enemies e1;
	vector<Shot> vd;
	menu men;
	
	
	bool alive=true;
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
		c1.update();
		e1.update();
		
		//Generar balas
		if(c1.mustshoot()) vd.push_back(c1.shotgen());
		
		for(Shot &d : vd) d.update();
		for(Shot &d : vd){//
			//if  Para hacer que las balas enemigas hagan daño (Falta programar)
		}//
		
		auto it = remove_if(vd.begin(),vd.end(),out_of_screen);
		vd.erase(it,vd.end());
		
		for(Shot &d : vd) {
			if(collision(d,e1)){
				alive=false;
			}
		}
		
		//Dibujado de varias cosas
		w.clear(Color(220, 220,180,255));
		c1.draw(w);
		
		w.draw(up_wall);
		w.draw(left_wall);
		w.draw(down_wall);
		w.draw(right_wall);
		
		
		for(Shot &d : vd) d.draw(w);
		
		
		if (alive==true){
		e1.draw(w);
		}
		
		w.display();
	}
	return 0;
}

