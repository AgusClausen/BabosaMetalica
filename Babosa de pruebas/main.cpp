#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "enemies.h"
#include "mapa.h"
#include <SFML/System/Vector2.hpp>
using namespace std;
using namespace sf;
int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Babosa Metalica");
	mapa m1;
	character c1;
	enemies e1;
	w.setFramerateLimit(60);
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			w.clear(Color(220, 220,180,255));
			if(e.type == Event::Closed){
				w.close();	
			}
		}
		m1.update();
		c1.update();
		e1.update();
		w.clear(Color(220,220,180,255));
		m1.draw(w);
		c1.draw(w);
		e1.draw(w);
		w.display();
	}
	return 0;
}
