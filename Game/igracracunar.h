#ifndef IGRACRACUNAR_H_INCLUDED
#define IGRACRACUNAR_H_INCLUDED
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
#include "bombona.h"

using namespace std;

class IgracRacunar:public Sprite{
public:
    IgracRacunar(SpriteSheet *sheet, int width = 64, int height = 64);
    void draw(SDL_Renderer * renderer);
    void move();
    void move (int dx, int dy);

    //vraca jedan od random brojeva 1 2 4 8
    int randomBroj();
    void changeState();

    int st;
    int ubrzanje = 5;
    Bombona *b;

};
#endif // IGRAC_H_INCLUDED

