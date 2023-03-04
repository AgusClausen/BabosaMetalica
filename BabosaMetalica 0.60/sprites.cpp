#include "sprites.h"

sprites::sprites() {
	tenemy1.loadFromFile("zombie.png");
	tshotgun.loadFromFile("shotgun.png");
	tg1.loadFromFile("g1.png");
	tg5.loadFromFile("g5.png");
	
	sshotgun.setTexture(tshotgun);
	sg1.setTexture(tg1);
	sg5.setTexture(tg5);
	
	
}

Texture sprites::get_enemy_texture (){
	return tenemy1;
}
