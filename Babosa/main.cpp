#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.h"
#include "enemies.h"
#include "caja.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Ejemplo de SFML");
	character c1;
	enemies e1;
	caja bo;
	w.setFramerateLimit(60);
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		c1.update();
		e1.update();
		
		w.clear(Color(220, 220,180,255));
		c1.draw(w);
		e1.draw(w);
		bo.draw(w);
		w.display();
	}
	return 0;
}
