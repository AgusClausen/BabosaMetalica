#include "hud.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Text.hpp>
#include "enemies.h"
using namespace std;
using namespace sf;
hud::hud() {
	fuente.loadFromFile("font.ttf");
	datos.resize(4);
	for(int i=0;i<4;i++){
		datos[i].setFont(fuente);
		datos[i].setCharacterSize(20);
		datos[i].setFillColor({255,255,255});
	}
	datos[0].setPosition(5,665);
	datos[0].setString("VIDA:");
		
	datos[1].setPosition(55,665);
	datos[1].setString("100");
		
	datos[2].setPosition(5,695);
	datos[2].setString("MUNICIÓN:");
		
	datos[3].setPosition(100,695);
	datos[3].setString("infinita");
	Text a;
}

void hud::update(){
	
};
void hud::draw(RenderWindow &w){
	for(int i=0;i<4;i++){
		w.draw(datos[i]);
	}
}
