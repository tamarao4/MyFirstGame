#include "player.h"

Player::Player(Sprite *sprite) : Drawable(), Movable(), KeyboardEventListener() {
    this->sprite = sprite;
}

void Player::draw(SDL_Renderer *renderer) {
    sprite->draw(renderer);
}

void Player::move() {
    sprite->move();
}

void Player::move(int dx, int dy) {
    sprite->move(dx, dy);
}

void Player::listen(SDL_KeyboardEvent &event) {
    if(event.type == SDL_KEYDOWN) {
        if(event.keysym.sym == SDLK_LEFT or event.keysym.sym == SDLK_a) {
            sprite->setState(sprite->getState()|Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT or event.keysym.sym == SDLK_d) {
            sprite->setState(sprite->getState()|Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP or event.keysym.sym == SDLK_w) {
            sprite->setState(sprite->getState()|Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN or event.keysym.sym == SDLK_s) {
            sprite->setState(sprite->getState()|Sprite::DOWN);
        } else if(event.keysym.sym == SDLK_q) {
            if(tergetAcceleration < 1){
                tergetAcceleration = 1;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
            } else{
                tergetAcceleration--;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
                cout<<"Smanjili ste ubrzanje"<<endl;
            }
        } else if(event.keysym.sym == SDLK_e) {
            if(tergetAcceleration >= sprite->maxUbrzanje){
                tergetAcceleration = sprite->maxUbrzanje;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
            } else{
                tergetAcceleration++;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
                cout<<"Povecali ste ubrzanje"<<endl;
            }
        }
    } else if (event.type == SDL_KEYUP) {
        if(event.keysym.sym == SDLK_LEFT or event.keysym.sym == SDLK_a) {
            sprite->setState(sprite->getState()&~Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT or event.keysym.sym == SDLK_d) {
            sprite->setState(sprite->getState()&~Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP or event.keysym.sym == SDLK_w) {
            sprite->setState(sprite->getState()&~Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN or event.keysym.sym == SDLK_s) {
            sprite->setState(sprite->getState()&~Sprite::DOWN);
        } else if(event.keysym.sym == SDLK_q) {
            if(tergetAcceleration < 1){
                tergetAcceleration = 1;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
            } else{
                tergetAcceleration--;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
                cout<<"Smanjili ste ubrzanje"<<endl;
            }
        } else if(event.keysym.sym == SDLK_e) {
            if(tergetAcceleration >= sprite->maxUbrzanje){
                tergetAcceleration = sprite->maxUbrzanje;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
            } else{
                tergetAcceleration++;
                sprite->maxUbrzanje = tergetAcceleration;
                sprite->ubrzanje = sprite->maxUbrzanje;
                cout<<"Povecali ste ubrzanje"<<endl;
            }
        }
    }

}
