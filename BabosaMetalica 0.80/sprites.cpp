#include "sprites.h"

sprites::sprites() {
	tenemy1.loadFromFile("zombie.png");
	tpistol.loadFromFile("basicpistol.png");
	tar.loadFromFile("assaultrifle.png");
	tsniper.loadFromFile("sniper.png");
	trevolver.loadFromFile("magnumrevolver.png");
	tshotgun.loadFromFile("shotgun.png");
	tsmg.loadFromFile("smg.png");
	tbananagun.loadFromFile("bananagun.png");
	
	tg1.loadFromFile("g1.png");
	tg5.loadFromFile("g5.png");
	
	sshotgun.setTexture(tshotgun);
	sg1.setTexture(tg1);
	sg5.setTexture(tg5);
	
	
}

Texture sprites::get_enemy_texture (){
	return tenemy1;
}
Texture sprites::get_pistol_texture (){
	return tpistol;
}
Texture sprites::get_ar_texture (){
	return tar;
}
Texture sprites::get_sniper_texture (){
	return tsniper;
}
Texture sprites::get_revolver_texture (){
	return trevolver;
}
Texture sprites::get_shotgun_texture (){
	return tshotgun;
}
Texture sprites::get_smg_texture (){
	return tsmg;
}
Texture sprites::get_bananagun_texture (){
	return tbananagun;
}
