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
#include "Partida.h"
using namespace std;
using namespace sf;



	
int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Babosa Metalica");
	w.setFramerateLimit(60);
	
	
	Partida p;
	
	menu men;
	bool iniciar=false;
	
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
		
		
		
		p.update();
		p.draw(w);
		
		
		
		//Dibujado de varias cosas
		w.display();
	}
	return 0;
}

