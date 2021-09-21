#include "bombona.h"

Bombona ::Bombona(SpriteSheet *sheet, int width, int height):Sprite(sheet,width,height){

}

void Bombona :: draw(SDL_Renderer * renderer){
    if(state == STOP) {
        sheet->drawFrame("walk_down", 0, spriteRect, renderer);
    }

    frameCounter++;
    if(frameCounter%frameSkip == 0) {
        currentFrame++;
        if(currentFrame >= 9) {
            currentFrame = 0;
        }
        frameCounter = 0;
    }
}

void Bombona::move(int dx, int dy) {

    ///ograniceno kretanje
    if (spriteRect->x < 0){
        spriteRect->x = 0;
    }
    else if (spriteRect->x > 640 - spriteRect->w){
        spriteRect->x = 640-spriteRect->w;                  //640 sirina prozora

    }
    if ( spriteRect->y < 0){
        spriteRect->y =0;

    }
    else if (spriteRect->y > 480 - spriteRect->h){          //480 visina prozora
        spriteRect->y = 480 - spriteRect->h;
    }


}

void Bombona::move() {

}

int Bombona::randomBroj(){
        srand(time(NULL));
        int br = rand() % 40;
        return br;


}


