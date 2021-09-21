#ifndef IGRAC_H_INCLUDED
#define IGRAC_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>


#include "drawable.h"
#include "movable.h"

#include "spritesheet.h"
#include "sprite.h"

using namespace std;

class Igrac:public Sprite{
public:
    Igrac(SpriteSheet *sheet, int width = 64, int height = 64);
    void draw(SDL_Renderer * renderer);
    void move();
    void move (int dx, int dy);

    void load();
    void save();
};
#endif // IGRAC_H_INCLUDED
