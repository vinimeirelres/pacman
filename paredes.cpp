#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "paredes.h"
#include "mapa.h"

using namespace std;

paredes::paredes(){
    i=j=0;
}

void paredes::criar_paredes(ALLEGRO_BITMAP *p){
    mapa MAPA;
    for(int i=0; i<27; i++)
    {
        for(j=0; j<27; j++)
        {
            if(MAPA.m[i][j]=='1')
            {
                al_draw_scaled_bitmap(p, 18, 18, 18, 18, 26*j,26*i,30, 30, 0);
            }
        }
    }
}

paredes::~paredes(){
}
