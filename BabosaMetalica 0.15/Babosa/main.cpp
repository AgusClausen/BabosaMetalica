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


bool colition (Shot &d, enemies &e1){
	Vector2f pd = d.seePos();
	Vector2f pe = e1.seePos();
	Vector2f v = pd-pe;
	return sqrt(v.x*v.x+v.y*v.y)<25; 
}

bool out_of_screen(Shot &d) {
	Vector2f p = d.seePos();
	if (p.x<0 or p.x>1280) return true;
	if (p.y<0 or p.y>720) return true;
	return false;
}
	

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Ejemplo de SFML");
	
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
		c1.update();
		e1.update();
		
		if(c1.mustshoot()) vd.push_back(c1.shotgen());
		
		for(Shot &d : vd) d.update();
		for(Shot &d : vd){//
			//if  Para hacer que las balas enemigas hagan daño
		}//
		
		auto it = remove_if(vd.begin(),vd.end(),out_of_screen);
		vd.erase(it,vd.end());
		
		for(Shot &d : vd) {
			if(colition(d,e1)){
				alive=false;
			}
		}
		
		w.clear(Color(220, 220,180,255));
		c1.draw(w);
		if (alive==true){
		e1.draw(w);
		}
		for(Shot &d : vd) d.draw(w);
		w.display();
	}
	return 0;
}

