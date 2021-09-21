#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

#include "igrac.h"
#include "igracracunar.h"
#include "level.h"
#include "bombona.h"



/** \brief Klasa koja je zadu�ena za detekciju kolizije, i dektekciju da li je igrac u okviru prozora.
 */
class Group {
public:
    Group();
    int scor = 0;
    void kolizija(Igrac *igracKorisnik, IgracRacunar* igracRacunar);
    int kolizijaBombona(Igrac *igracKorisnik, Bombona* b);
    void  kolizijaBombonaAutomatskiIgrac(IgracRacunar* ir, Bombona* b);
    void kolizijaAutomatskihIgraca(IgracRacunar *igracRacunar1, IgracRacunar *igracRacunar2);


};


#endif // GROUP_H
