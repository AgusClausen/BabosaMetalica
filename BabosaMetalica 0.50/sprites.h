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
	 Texture tenemy1, tshotgun, tg1, tg5;
	 Sprite senemy1, sshotgun, sg1, sg5;
	 
	 
	public:
	sprites();
};

#endif

