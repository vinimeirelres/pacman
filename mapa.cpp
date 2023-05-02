#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "map.h"

using namespace std;


void pilulas::criar_pilulas(ALLEGRO_BITMAP *p)
{
    //int m[24][24];
    map MAPA;
    for(int i=0; i<40; i++)
    {
        for(j=0; j<45; j++)
        {
            if(MAPA.m[i][j]=='0')
            {
                al_draw_bitmap_region(p, 90, 18, 5, 5, (18*j)+7, (18*i)+7, 0);//pilulas
            }
        }
    }

}

void paredes::criar_paredes(ALLEGRO_BITMAP *p)
{
    map MAPA;
    for(int i=0; i<40; i++)
    {
        for(j=0; j<45; j++)
        {
            if(MAPA.m[i][j]=='1')
            {
                al_draw_bitmap_region(p, 18, 18, 18, 18, 18*j, 18*i, 0);//paredes
            }
        }
    }
}

void piso::criar_piso(ALLEGRO_BITMAP *p)
{
    map MAPA;
    for(int i=0; i<40; i++)
    {
        for(j=0; j<45; j++)
        {
            if(MAPA.m[i][j]=='0')
            {
                al_draw_bitmap_region(p, 54, 18, 18, 18, 18*j, 18*i, 0);//pisos
            }
        }
    }
}
