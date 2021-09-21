#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <string>
#include <sstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "drawable.h"
#include "movable.h"
#include "tileset.h"
#include "level.h"
#include "spritesheet.h"
#include "sprite.h"

#include "eventlistener.h"

#include "igrac.h"
#include "player.h"
#include "igracracunar.h"
#include "group.h"
#include "bombona.h"

using namespace std;

/** \brief Klasa koja je zadužena za upravljanje svim entitetima u igri.
 */
class Engine {
private:
    map<string, Tileset*> tilesets;
    vector<Drawable*> drawables;
    vector<Movable*> movables;
    vector<EventListener*> eventListeners;
    SpriteSheet *sheet;
    SpriteSheet *sheet2;
    SpriteSheet *sheet3;

    Igrac *igrac;
    IgracRacunar *igracRacunar;
    IgracRacunar *igracRacunar2;
    IgracRacunar *igracRacunar3;
    Group *g;
    Player *p;
    Player *p2;
    Bombona *b;
    Player *p3;     //bombona
    Player *p4;
    Player *p5;

    SDL_Window *window;
    SDL_Renderer *renderer;
    int frameCap = 60;


public:
    Engine(string title);
    void addTileset(Tileset *tileset, const string &name);
    void addTileset(istream &inputStream, const string &name);
    void addTileset(const string &path, const string &name);
    Tileset* getTileset(const string &name);
    void addDrawable(Drawable* drawable);


    void run();
    void nexLevel();
    void nexLevel2();

    void initPlayers();

    void drawScore(int score, SDL_Renderer* renderer);
    void ispitivanjeKolizija();

    virtual ~Engine();


};

#endif // ENGINE_H_INCLUDED
