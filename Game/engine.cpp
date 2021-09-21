#include "engine.h"


Engine::Engine(string title) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_INPUT_FOCUS);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    ///dodavanje slike gore pre Title
    SDL_Surface* icon = IMG_Load("resources/creatures/pecurka.png");
    SDL_SetWindowIcon(window, icon);


}

void Engine::addTileset(Tileset *tileset, const string &name) {
    tilesets[name] = tileset;}

void Engine::addTileset(istream &inputStream, const string &name) {
    addTileset(new Tileset(inputStream, renderer), name);
}

void Engine::addTileset(const string &path, const string &name) {
    ifstream tilesetStream(path);
    addTileset(tilesetStream, name);
}

Tileset* Engine::getTileset(const string &name) {
    return tilesets[name];
}

void Engine::addDrawable(Drawable *drawable) {
    drawables.push_back(drawable);
}

void Engine::run() {
    initPlayers();

    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;

    bool running = true;
    SDL_Event event;
    while(running) {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                igrac->save();
                running = false;
            } else {
                for(size_t i = 0; i < eventListeners.size(); i++) {
                    eventListeners[i]->listen(event);
                }
            }
        }
        ///================================================= prelazi na sledeci nivo
        ispitivanjeKolizija();
        if (g->kolizijaBombona(igrac, b) == 5){
            drawables.clear();                                                      // brisem sve sto je nacrtano da bih crtala novo
            addTileset("resources/tilesets/tileset2.txt", "default");
            ifstream levelStream("resources/levels/level2.txt");

            Level *mojnivo = new Level(levelStream, getTileset("default"));
            addDrawable(mojnivo);
            nexLevel();
            break;
        }

        for(size_t i = 0; i < movables.size(); i++) {
            movables[i]->move();

        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++) {
                drawables[i]->draw(renderer);
        }

        ///=================================================ispis na ekran
        drawScore(g->scor, renderer);

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}

void Engine::nexLevel(){
    initPlayers();
    igracRacunar->ubrzanje = 8;
    igracRacunar2->ubrzanje =4;
    bool running = true;
    SDL_Event event;

    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;


        while(running) {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                igrac->save();
                running = false;
            } else {
                for(size_t i = 0; i < eventListeners.size(); i++) {
                    eventListeners[i]->listen(event);
                }
            }
        }
        ispitivanjeKolizija();
        if (g->kolizijaBombona(igrac, b) == 5){             ///==================================prelazi na sedeci nivo
            drawables.clear();
            addTileset("resources/tilesets/tileset3.txt", "default");
            ifstream levelStream("resources/levels/level3.txt");
            addDrawable(new Level(levelStream, getTileset("default")));
            nexLevel2();
            break;
        }


        for(size_t i = 0; i < movables.size(); i++) {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++) {
            drawables[i]->draw(renderer);
        }

        ///=================================================ispis na ekran
        drawScore(g->scor, renderer);

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}

void Engine::initPlayers(){
    ///================================================= bombona
    ifstream spriteSheetStream3("resources/creatures/bombona_sheet.txt");
    sheet3 = new SpriteSheet(spriteSheetStream3, renderer);
    b = new Bombona(sheet3);
    b->spriteRect->x = b->randomBroj();
    b->spriteRect->y = b->randomBroj();
    p3 = new Player(b);
    drawables.push_back(p3);


    ifstream spriteSheetStream("resources/creatures/sprite_sheet.txt");
    sheet = new SpriteSheet(spriteSheetStream, renderer);

    ///=========================== kreiranje figure
    igrac = new Igrac(sheet);
    igrac->load();
    igrac->setFrameSkip(4);

    ///============================ igrac korisnik
    p = new Player(igrac);
    drawables.push_back(p);
    movables.push_back(p);
    eventListeners.push_back(p);

    ///====================================== igrac racunar
    ifstream spriteSheetStream2("resources/creatures/sprite_sheet2.txt");
    sheet2 = new SpriteSheet(spriteSheetStream2, renderer);
    igracRacunar = new IgracRacunar(sheet2);
    igracRacunar->setFrameSkip(4);
    p2 = new Player(igracRacunar);
    drawables.push_back(p2);
    movables.push_back(p2);

    ///===================================== jos jedan igrac racunar
    igracRacunar2 = new IgracRacunar(sheet2);
    igracRacunar2->setFrameSkip(4);
    p4 = new Player(igracRacunar2);
    drawables.push_back(p4);
    movables.push_back(p4);

    ///===================================== jos jedan igrac racunar
    igracRacunar3 = new IgracRacunar(sheet2);
    igracRacunar3->setFrameSkip(4);
    p5 = new Player(igracRacunar3);
    drawables.push_back(p5);
    movables.push_back(p5);
    igracRacunar->ubrzanje = 7;

    ///=============================== kreiram grupu igraca
    //nad kojima cu detektovati koliziju i kojima ce biti ograniceno kretanje
    g = new Group();

}

void Engine::nexLevel2(){
    initPlayers();
    igracRacunar->ubrzanje = 10;
    igracRacunar2->ubrzanje = 6;
    bool running = true;
    SDL_Event event;

    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;


        while(running) {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                igrac->save();
                running = false;
            } else {
                for(size_t i = 0; i < eventListeners.size(); i++) {
                    eventListeners[i]->listen(event);
                }
            }
        }
        ///====================================== kolizije
        ispitivanjeKolizija();
        g->kolizijaBombona(igrac, b);
        for(size_t i = 0; i < movables.size(); i++) {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++) {
            drawables[i]->draw(renderer);
        }

        ///=================================================ispis na ekran
        drawScore(g->scor, renderer);

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}

void Engine::drawScore(int rezultat, SDL_Renderer* renderer){
    TTF_Font* font = TTF_OpenFont("font/comicbd.ttf", 24);
    SDL_Color white = {255, 255, 255};
    stringstream ss;
    ss << "Trenutni rezultat [ " << rezultat << " ]";
    SDL_Surface* sm = TTF_RenderText_Solid(font, ss.str().c_str(), white);
    SDL_Texture* poruka = SDL_CreateTextureFromSurface(renderer, sm);
    SDL_Rect poruka_box; //create a rect
    poruka_box.x = 320-sm->w/2;
    poruka_box.y = 480-sm->h;
    poruka_box.w = sm->w;
    poruka_box.h = sm->h;
    SDL_RenderCopy(renderer, poruka, NULL, &poruka_box);
}

void Engine :: ispitivanjeKolizija(){
    g->kolizijaAutomatskihIgraca(igracRacunar, igracRacunar2);
    g->kolizijaAutomatskihIgraca(igracRacunar, igracRacunar3);
    g->kolizijaAutomatskihIgraca(igracRacunar2, igracRacunar3);
    g->kolizija(igrac, igracRacunar);
    g->kolizija(igrac, igracRacunar2);
    g->kolizija(igrac, igracRacunar3);
    g->kolizijaBombonaAutomatskiIgrac(igracRacunar, b);
    g->kolizijaBombonaAutomatskiIgrac(igracRacunar2, b);
    g->kolizijaBombonaAutomatskiIgrac(igracRacunar3, b);


}
Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
