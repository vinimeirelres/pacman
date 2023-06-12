#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "piso.h"
#include "mapa.h"

using namespace std;

piso::piso(){
    i=j=0;
}

void piso::criar_piso(ALLEGRO_BITMAP *p){
    mapa MAPA;
    for(int i=0; i<27; i++)
    {
        for(j=0; j<27; j++)
        {
            if(MAPA.m[i][j]=='0' || MAPA.m[i][j] == '2')
            {
                al_draw_scaled_bitmap(p, 54, 18, 18, 18, 26*j, 26*i, 28, 28, 0);
            }
        }
    }
}

piso::~piso(){
}

