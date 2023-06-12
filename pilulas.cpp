#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "pilulas.h"
#include "mapa.h"

using namespace std;

pilulas::pilulas(){
    i=j=0;
}

void pilulas::criar_pilulas(ALLEGRO_BITMAP *p, mapa* MAPA){
    for(int i=0; i<27; i++)
    {
        for(j=0; j<27; j++)
        {
            if(MAPA->m[i][j]=='0')
            {
                al_draw_scaled_bitmap(p, 90, 18, 5, 5, (26*j)+10, (26*i)+10, 7, 7, 0);
            }
        }
    }

}

pilulas::~pilulas(){
}
