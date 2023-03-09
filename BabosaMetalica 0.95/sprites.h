#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#ifndef SPRITES_H
#include "Shot.h"
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
