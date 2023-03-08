#ifndef SPRITES_H
#define SPRITES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Shot.h"
#include <SFML/System/Clock.hpp>
#include <vector>
#include "stage.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
using namespace std;
class sprites {
	 Texture tenemy1, tpistol ,tar ,tsniper ,trevolver ,tshotgun ,tsmg ,tbananagun , tg1, tg5;
	 Sprite sshotgun, sg1, sg5;
	 
	 
	public:
	sprites();\
	Texture get_enemy_texture ();
	Texture get_pistol_texture ();
	Texture get_ar_texture();
	Texture get_sniper_texture ();
	Texture get_revolver_texture ();
	Texture get_shotgun_texture ();
	Texture get_smg_texture ();
	Texture get_bananagun_texture ();
};

#endif

