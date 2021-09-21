#include "igracracunar.h"

IgracRacunar ::IgracRacunar(SpriteSheet *sheet, int width, int height):Sprite(sheet,width,height){
    spriteRect->x = randomBroj() * 4;
    spriteRect->y = randomBroj() *8;
    setState(randomBroj());
}

void IgracRacunar :: draw(SDL_Renderer * renderer){
    if(state&LEFT) {
        sheet->drawFrame("walk_left", currentFrame, spriteRect, renderer);
    } else if(state&RIGHT) {
        sheet->drawFrame("walk_right", currentFrame, spriteRect, renderer);
    } else if(state&UP) {
        sheet->drawFrame("walk_up", currentFrame, spriteRect, renderer);
    } else if(state&DOWN) {
        sheet->drawFrame("walk_down", currentFrame, spriteRect, renderer);
    } else if(state == STOP) {
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

void IgracRacunar::move(int dx, int dy) {
    spriteRect->x += ubrzanje*dx;
    spriteRect->y += ubrzanje*dy;

    ///ograniceno kretanje
    if (spriteRect->x < 0){
        spriteRect->x = 0;
        changeState();
    }
    else if (spriteRect->x > 640 - spriteRect->w){
        spriteRect->x = 640-spriteRect->w;                  //640 sirina prozora
        changeState();
    }
    if ( spriteRect->y < 0){
        spriteRect->y =0;
        changeState();
    }
    else if (spriteRect->y > 480 - spriteRect->h){          //480 visina prozora
        spriteRect->y = 480 - spriteRect->h;
        changeState();
    }


}

void IgracRacunar::move() {
     if(state != 0) {
        if(state & 1) {
            move(-1, 0);
        }
        if(state & 2) {
            move(1, 0);
        }
        if(state & 4) {
            move(0, -1);
        }
        if(state & 8) {
            move(0, 1);
        }
    }
}

int IgracRacunar::randomBroj(){
        srand(time(NULL));
        int br = rand() % 4;
        switch(br){
        case 0:
            return 1;
            break;
        case 1:
            return 2;
            break;
        case 2:
            return 4;
            break;
        case 3:
            return 8;
            break;
        default:
            return 0;
            cout << "Doslo je do greske!!";
        }

}

void IgracRacunar::changeState(){
    do {
        st = randomBroj();
        break;
    }while(st == state);
        setState(st);

}

