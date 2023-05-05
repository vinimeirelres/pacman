#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "map.h"

using namespace std;

const int SCREEN_W = 700;
const int SCREEN_H = 600;


int main()
{
    pilulas pil;
    paredes bloc;
    piso pis;



    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return 0;
    }
    bool termina = false;
    bool teclas [255]= {false};

    al_init_image_addon();
    al_install_keyboard();

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return 0;
    }


    ALLEGRO_BITMAP  *pac;
    pac = al_load_bitmap("blocos.png");
    if(!pac)
    {
        fprintf(stderr, "failed to create Pacman bitmap!\n");
        al_destroy_display(display);
        return 0;
    }
    while (!termina)
    {
        //int i,j;
        map MAPA;


        ALLEGRO_EVENT_QUEUE *event_queue = NULL; //Fila de Eventos

        event_queue = al_create_event_queue();
        if(!event_queue)
        {
            fprintf(stderr, "failed to create event_queue!\n");
            al_destroy_bitmap(pac);
            al_destroy_display(display);
            return -1;
        }

        al_register_event_source(event_queue, al_get_display_event_source(display));
        al_register_event_source(event_queue, al_get_keyboard_event_source());//Evento de Teclado




        ALLEGRO_EVENT ev;

        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)   //Tecla X Liberada
        {

            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                termina = true;
            }


        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            termina =true;
        }

        bloc.criar_paredes(pac);
        pis.criar_piso(pac);
        pil.criar_pilulas(pac);



        /* for(i=0; i<24; i++){
                  for(j=0; j<24; j++){
                      if(MAPA.m[i][j]=='0'){
                          al_draw_bitmap_region(pac, 90, 18, 5, 5, (18*j)+7, (18*i)+7, 0);//pilulas    //DENTRO DAS CLASSES
                      }
                  }
              }
              for(i=0; i<24; i++){
                  for(j=0; j<24; j++){
                      if(MAPA.m[i][j]=='1'){
                          al_draw_bitmap_region(pac, 18, 18, 18, 18, 18*j, 18*i, 0);//blocos
                      }
                  }
              }*/


        al_flip_display();
    }



    //al_flip_display();
    //al_rest();

    al_destroy_bitmap(pac);
    al_destroy_display(display);
    al_destroy_display(display);
    return 0;
}
