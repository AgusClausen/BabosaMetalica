#include "sprites.h"

sprites::sprites() {
	tenemy1.loadFromFile("zombie.png");
	tshotgun.loadFromFile("shotgun.png");
	tg1.loadFromFile("tg1.png");
	tg5.loadFromFile("tg5.png");
	senemy1.setTexture(tenemy1);
	sshotgun.setTexture(tshotgun);
	sg1.setTexture(tg1);
	sg5.setTexture(tg5);
}

