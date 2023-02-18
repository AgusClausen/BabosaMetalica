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
#include "bala.h"
using namespace std;
using namespace sf;
int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(1280,720),"Babosa Metalica");
	mapa m1;
	character c1;
	int x;
	int y;
	vector<enemies> v;
	bala b1;
	w.setFramerateLimit(60);
	for(int i=0;i<20;i++){
		do{
			x = rand();
		} while(x<-1500 || x>1500);
		do{
			y = rand();
		} while(y<-1500 || y>1500);
		if(x%2==0){
			x = x*-1;
		}
		if(y%2==0){
			y = y*-1;
		}
		enemies e(x,y);
		v.push_back(e);
		cout << x << endl << y << endl;
	}
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			w.clear(Color(220, 220,180,255));
			if(e.type == Event::Closed){
				w.close();	
			}
		}
		m1.update(m1.coordenadas());
		c1.update();
		b1.update();
		for(int i=0;i<10;i++){
			v[i].update(m1.coordenadas());
			v[i].draw(w);
		}
		w.clear(Color(0,0,0,255));
		for(int i=0;i<10;i++){
			
			v[i].draw(w);
		}
		m1.draw(w);
		c1.draw(w);
		if(b1.update()==true){
			b1.draw(w);
		}
		w.display();
	}
	return 0;
}
