#include "pocetniekran.h"

PocetniEkran::PocetniEkran(string title) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);        //renderer koristi hardverdsko ubrzanje??? da li promeniti flag1

    ///dodavanje slike gore pre Title
    SDL_Surface* icon = IMG_Load("pozadine/pecurka.png");
    SDL_SetWindowIcon(window, icon);

    background_surface = SDL_LoadBMP("pozadine/pozadina.bmp");
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

}


void PocetniEkran:: run(){
    bool running = true;
    SDL_Event event;



    ///Glavna petlja od koje pocinje ucitavanje prozora
    while(running) {

            while( SDL_PollEvent( &event ) ){
                switch( event.type ){
                    ///====================================sta je uneto sa tastaature poziva fju i dalje poziva fje
                    case SDL_KEYUP:
                        tasteri( &event.key );
                        break;

                    case SDL_QUIT:
                        //izlazi na X preko klika misem
                        running = false;
                        break;
                    default:
                        break;
                }

        SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background_texture, NULL, NULL);


        TTF_Font* font = TTF_OpenFont("font/comicbd.ttf", 28);
        pocetakIgreTekst(font, renderer);
        informacijeTekst(font, renderer);
        izlazakIzIgreTekst(font, renderer);

        ///==================================================== za prikaz inforamacija
        if (info == true){
            background_surface = SDL_LoadBMP("pozadine/pozadina1.bmp");
            background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);
            SDL_RenderCopy(renderer, background_texture, NULL, NULL);
        }


        SDL_RenderPresent(renderer);
    }
}
}
void PocetniEkran::ekranIgrice(){

    Engine *eng = new Engine("Game");

    eng->addTileset("resources/tilesets/tileset1.txt", "default"); /** Dodavanje novog tileset-a. */

    ifstream levelStream("resources/levels/level1.txt");
    eng->addDrawable(new Level(levelStream, eng->getTileset("default"))); /** Dodavanje novog nivoa. */

    eng->run(); /** Pokretanje glavne petlje igre. */
    delete eng; /** Oslobadjanje memorije koju je zauzela instanca Engine klase. */

}

void PocetniEkran::tasteri( SDL_KeyboardEvent *key ){
        /* Is it a release or a press? */
        if( key->type == SDL_KEYUP ){
            if(key->keysym.sym == SDLK_KP_ENTER || key->keysym.sym == SDLK_p){
                zatvoriPocetniEkran();
                ekranIgrice();
            }
            if(key->keysym.sym == SDLK_ESCAPE){
                zatvoriPocetniEkran();
            }

            if (key->keysym.sym == SDLK_i){
                cout << "printace iformacije na ekranu\n";
                info = true;
            }
            if (key->keysym.sym == SDLK_BACKSPACE || key->keysym.sym == SDLK_b){
                background_surface = SDL_LoadBMP("pozadine/pozadina.bmp");
                background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);
                info = false;

            }
        }
}

void PocetniEkran::pocetakIgreTekst(TTF_Font *font, SDL_Renderer *renderer){
    SDL_Color white = {74, 37, 0};
    stringstream ss;
    ss << "Pocetak igre      [   ENTER  ]";
    SDL_Surface* sm = TTF_RenderText_Solid(font, ss.str().c_str(), white);
    SDL_Texture* poruka = SDL_CreateTextureFromSurface(renderer, sm);
    SDL_Rect poruka_box; //create a rect
    poruka_box.x = sm->w/2;
    poruka_box.y = sm->h;
    poruka_box.w = sm->w;
    poruka_box.h = sm->h;
    SDL_RenderCopy(renderer, poruka, NULL, &poruka_box);

}
void PocetniEkran::izlazakIzIgreTekst(TTF_Font *font, SDL_Renderer *renderer){
    SDL_Color white = {74, 37, 0};
    stringstream ss;
    ss << "Izlaz iz igre     [    ESC   ]";
    SDL_Surface* sm = TTF_RenderText_Solid(font, ss.str().c_str(), white);
    SDL_Texture* poruka = SDL_CreateTextureFromSurface(renderer, sm);
    SDL_Rect poruka_box; //create a rect
    poruka_box.x = sm->w/2;
    poruka_box.y = 230-sm->h;
    poruka_box.w = sm->w;
    poruka_box.h = sm->h;
    SDL_RenderCopy(renderer, poruka, NULL, &poruka_box);

}
void PocetniEkran::informacijeTekst(TTF_Font *font, SDL_Renderer *renderer){
    SDL_Color white = {74, 37, 0};
    stringstream ss;
    ss << "Informacije       [     i    ]";
    SDL_Surface* sm = TTF_RenderText_Solid(font, ss.str().c_str(), white);
    SDL_Texture* poruka = SDL_CreateTextureFromSurface(renderer, sm);
    SDL_Rect poruka_box; //create a rect
    poruka_box.x = sm->w/2;
    poruka_box.y = 150-sm->h;
    poruka_box.w = sm->w;
    poruka_box.h = sm->h;
    SDL_RenderCopy(renderer, poruka, NULL, &poruka_box);

}
void PocetniEkran::zatvoriPocetniEkran(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(background_texture);
    SDL_FreeSurface(background_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}



PocetniEkran::~PocetniEkran(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(background_texture);
    SDL_FreeSurface(background_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

