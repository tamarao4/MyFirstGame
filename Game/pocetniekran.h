#ifndef POCETNIEKRAN_H_INCLUDED
#define POCETNIEKRAN_H_INCLUDED
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "drawable.h"
#include "movable.h"
#include "tileset.h"

#include <fstream>
#include <string>
#include <strstream>
#include <iostream>
#include <string>
#include <sstream>

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "eventlistener.h"

#include "engine.h"

using namespace std;

class PocetniEkran {

public:


    int frameCap = 60;
    PocetniEkran(string title);
    void addDrawable(Drawable* drawable);

    void run();

    virtual ~PocetniEkran();

    void listen(SDL_KeyboardEvent &event);

    void ekranIgrice();
    void tasteri(SDL_KeyboardEvent *key);
    void zatvoriPocetniEkran();
    void pocetakIgreTekst(TTF_Font *font, SDL_Renderer *renderer);
    void izlazakIzIgreTekst(TTF_Font *font, SDL_Renderer *renderer);
    void informacijeTekst(TTF_Font *font, SDL_Renderer *renderer);
    void prikaziInformacije(TTF_Font *font, SDL_Renderer *renderer);

    SDL_Window* window = NULL;
    SDL_Surface* background_surface = NULL;
    SDL_Texture* background_texture = NULL;
    SDL_Renderer* renderer = NULL;

    bool info = false;

};

#endif // PLAYER_H_INCLUDED

