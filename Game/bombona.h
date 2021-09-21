#ifndef BOMBONA_H_INCLUDED
#define BOMBONA_H_INCLUDED
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "drawable.h"
#include "movable.h"

#include "spritesheet.h"
#include "sprite.h"

using namespace std;

class Bombona:public Sprite{
public:
    Bombona(SpriteSheet *sheet, int width = 64, int height = 64);
    void draw(SDL_Renderer * renderer);
    void move();
    void move (int dx, int dy);


    int randomBroj();

};
#endif // BOMBONA_H_INCLUDED


