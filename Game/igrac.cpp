#include "igrac.h"

Igrac ::Igrac(SpriteSheet *sheet, int width, int height):Sprite(sheet,width,height){
}

void Igrac :: draw(SDL_Renderer * renderer){
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


void Igrac::move(int dx, int dy) {
    spriteRect->x += 2*dx;
    spriteRect->y += 2*dy;
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

void Igrac::move() {
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

void Igrac::save(){
    ofstream myfile;
    myfile.open("save/file.txt");
    myfile << spriteRect->x << "\n" << spriteRect->y << "\n";
}

void Igrac::load(){
    ifstream myfile;
    myfile.open("save/file.txt");

    if(!myfile.is_open()){
        exit(EXIT_FAILURE);
    }
    myfile >> spriteRect->x;
    myfile >> spriteRect->y;
}

