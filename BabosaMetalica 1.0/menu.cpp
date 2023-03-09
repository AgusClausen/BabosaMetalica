#include "menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

menu::menu() {
	t1.loadFromFile("main_menu.png");
	s1.setTexture(t1);
	s1.setPosition(0,0);
	t2.loadFromFile("records_screen.png");
	s2.setTexture(t2);
	s2.setPosition(0,0);
	t3.loadFromFile("death_screen.png");
	s3.setTexture(t3);
	s3.setPosition(0,0);
	fuente.loadFromFile("font.ttf");
	vt.resize(10);
	v.resize(10);
	
	rec.setFont(fuente);
	rec.setCharacterSize(26);
	rec.setFillColor({255,255,255});
	
	rec.setPosition(600,50);
	rec.setString("Records: ");
	
	tscore.setFont(fuente);
	tscore.setCharacterSize(40);
	tscore.setFillColor({255,255,255});
	
	tscore.setPosition(510,50);
	
	int aux=150;
	for(int i=0;i<10;i++) { 
		v[i]=0;
	}
	for(int i=0;i<10;i++){
		vt[i].setFont(fuente);
		vt[i].setCharacterSize(26);
		vt[i].setFillColor({255,255,255});
	}
	
	
	
	for(int j=0;j<vt.size();j++) { 
		vt[j].setPosition(580,aux);
		aux+=35;
	}
	
	
}
bool menu::start(Clock game_time,int enemy_kill_count,bool dead){
	ready=dead;
}
void menu::draw_death_screen (RenderWindow &w){
	
	tscore.setString("Puntaje: " + to_string(iscore));
	w.draw(s3);
	w.draw(tscore);
}
void menu::draw_main_menu (RenderWindow &w){
	w.draw(s1);
}
void menu::draw_records_screen (RenderWindow &w){
	w.draw(s2);
	w.draw(rec);
	for(int i=0;i<10;i++){
		if(v[i]>0){
			w.draw(vt[i]);
		}
	}
}

void menu::update(int score){
	iscore=score;
	fstream archi_bin("records_bin.bat", ios::binary | ios::in | ios::out | ios::ate);
	int aux;
	int n = archi_bin.tellg()/sizeof(aux);
	archi_bin.seekg(0);
	for(int i=0;i<n;i++) { 
		archi_bin.seekg(i*sizeof(aux));
		archi_bin.read(reinterpret_cast<char*>(&aux),sizeof(aux));
		v[i]=aux;
	}
	for(int i=0;i<v.size();i++) { 
		if(score>v[i]){
			aux=v[i];
			v[i]=score;
			score=aux;
		}
	}
	archi_bin.close();
	fstream archi_bin2("records_bin.bat", ios::binary | ios::in | ios::out | ios::trunc);
	for(int i=0;i<v.size();i++) { 
		aux=v[i];
		archi_bin2.seekp(i*sizeof(aux));
		archi_bin2.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	archi_bin2.close();
	
	
	for(int i=0;i<v.size();i++){
		vt[i].setString(to_string(i+1) + ": " + to_string(v[i]));
	}
}

void menu::delete_records(){
	fstream archi_bin("records_bin.bat", ios::binary | ios::trunc | ios::out);
	archi_bin.close();
	int aux;
	for(int i=0;i<10;i++) { 
		v[i]=0;
	}
	for(int i=0;i<v.size();i++) { 
		aux=0;
		archi_bin.seekp(i*sizeof(aux));
		archi_bin.write(reinterpret_cast<char*>(&aux),sizeof(aux));
	}
	
}


