#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "Shot.h"
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Ejemplo de SFML");
	
	character c1;
	vector<Shot> vd;
	
	w.setFramerateLimit(60);
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		c1.update();
		if(c1.mustshoot()) vd.push_back(c1.shotgen());
		
		for(Shot &d : vd) d.update();
		for(Shot &d : vd){//
			//if  Para hacer que las balas enemigas hagan daño
		}//
		
		w.clear(Color(220, 220,180,255));
		c1.draw(w);
		for(Shot &d : vd) d.draw(w);
		w.display();
	}
	return 0;
}

