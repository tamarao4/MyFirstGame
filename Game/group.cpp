#include "group.h"


Group::Group(){

}


///primenjujem formulu za koliziju kruga jer moje pecurke lice na krug
//https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection

void Group::kolizija(Igrac* igracKorisnik, IgracRacunar* igracRacunar){
    int xKorisnik = igracKorisnik->spriteRect->x;
    int xRacunar = igracRacunar->spriteRect->x;
    int yKorisnik = igracKorisnik->spriteRect->y;
    int yRacunar = igracRacunar->spriteRect->y;

    int x = xKorisnik - xRacunar;
    int y = yKorisnik - yRacunar;
    int distanca = sqrt(x*x + y*y);

    if ( distanca < 16+16 ){
        cout<< "Uhvacen!\n";
        scor =0;
        cout << scor;
        //case fuju za 5-6 slucajeva, i ond random uzmem da izaberem gde da stane
        int slucaj = igracRacunar->randomBroj();
        switch(slucaj) {
            case 1:
                igracRacunar->spriteRect->x = 2;
                igracRacunar->spriteRect->y = 4;
                break;
            case 2:
                igracRacunar->spriteRect->x = 200;
                igracRacunar->spriteRect->y = 480;
                break;
            case 4:
                igracRacunar->spriteRect->x =400;
                igracRacunar->spriteRect->y = 400;
                break;
            case 8:
                igracRacunar->spriteRect->x = 170;
                igracRacunar->spriteRect->y = 15;
                break;
            default:
                igracRacunar->spriteRect->x = 23;
                igracRacunar->spriteRect->y = 232;
        }
    }
}

int  Group::kolizijaBombona(Igrac* igracKorisnik, Bombona* b){
    int xKorisnik = igracKorisnik->spriteRect->x;
    int xB = b->spriteRect->x;
    int yKorisnik = igracKorisnik->spriteRect->y;
    int yB = b->spriteRect->y;

    int x = xKorisnik - xB;
    int y = yKorisnik - yB;
    int distanca = sqrt(x*x + y*y);

    if ( distanca < 16+16 ){
        cout<< "BOMBOOOOOOOOOOOOOOOOONA!\n";
        scor ++;
        cout << scor;
        //case fuju za 5-6 slucajeva, i ond random uzmem da izaberem gde da stane

        b->spriteRect->x = b->randomBroj()*10;
        b->spriteRect->y = b->randomBroj() *8;


        }
    return scor;
}

void  Group::kolizijaBombonaAutomatskiIgrac(IgracRacunar* igracRacunar, Bombona* b){

    int xIR = igracRacunar->spriteRect->x;
    int xB = b->spriteRect->x;
    int yIR = igracRacunar->spriteRect->y;
    int yB = b->spriteRect->y;

    int x = xIR - xB;
    int y = yIR - yB;
    int distanca = sqrt(x*x + y*y);

    if ( distanca < 16+16 ){
        cout<< "ukrao ti je bombonu -------------------------------!\n";
        scor --;
        cout << scor;
        //case fuju za 5-6 slucajeva, i ond random uzmem da izaberem gde da stane

        b->spriteRect->x = b->randomBroj()*8;
        b->spriteRect->y = b->randomBroj() *10;
        igracRacunar->spriteRect->x = 170;
        igracRacunar->spriteRect->y = 15;


        }
}

void Group::kolizijaAutomatskihIgraca(IgracRacunar* igracRacunar1, IgracRacunar* igracRacunar2){
    int xRacunar1 = igracRacunar1->spriteRect->x;
    int xRacunar2 = igracRacunar2->spriteRect->x;
    int yRacunar1 = igracRacunar1->spriteRect->y;
    int yRacunar2 = igracRacunar2->spriteRect->y;

    int x = xRacunar1 - xRacunar2;
    int y = yRacunar1 - yRacunar2;
    int distanca = sqrt(x*x + y*y);

    if ( distanca < 16+16 ){
        cout<< "Uhvacen!\n";
        scor =0;
        cout << scor;
        //case fuju za 5-6 slucajeva, i ond random uzmem da izaberem gde da stane
        int slucaj = igracRacunar1->randomBroj();
        switch(slucaj) {
            case 1:
                igracRacunar1->spriteRect->x = 2;
                igracRacunar1->spriteRect->y = 4;
                igracRacunar2->spriteRect->x = 200;
                igracRacunar2->spriteRect->y = 400;
                break;
            case 2:
                igracRacunar1->spriteRect->x = 200;
                igracRacunar1->spriteRect->y = 480;
                igracRacunar2->spriteRect->x = 20;
                igracRacunar2->spriteRect->y = 40;
                break;
            case 4:
                igracRacunar1->spriteRect->x =400;
                igracRacunar1->spriteRect->y = 400;
                igracRacunar2->spriteRect->x = 200;
                igracRacunar2->spriteRect->y = 352;
                break;
            case 8:
                igracRacunar1->spriteRect->x = 170;
                igracRacunar1->spriteRect->y = 15;
                igracRacunar2->spriteRect->x = 10;
                igracRacunar2->spriteRect->y = 52;
                break;
            default:
                igracRacunar1->spriteRect->x = 23;
                igracRacunar1->spriteRect->y = 232;
                igracRacunar2->spriteRect->x = 2;
                igracRacunar2->spriteRect->y = 32;
        }


    }
}
