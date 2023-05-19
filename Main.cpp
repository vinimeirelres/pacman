#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "map.h"

using namespace std;

const int SCREEN_W = 700;
const int SCREEN_H = 600;


int main(){

    paredes bloc;
    piso pis;
    mapa mapas;
    PacMario mario(mapas);

    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init()){
        fprintf(stderr, "failed to initialize allegro!\n");
        return 0;
    }

    bool termina = false;
    bool teclas [255]= {false};

    al_init_image_addon();
    al_install_keyboard();

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display){
        fprintf(stderr, "failed to create display!\n");
        return 0;
    }


    ALLEGRO_BITMAP  *pac;
    pac = al_load_bitmap("blocos.png");

    if(!pac){
        fprintf(stderr, "failed to create Pacman bitmap!\n");
        al_destroy_display(display);
        return 0;
    }



    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    event_queue = al_create_event_queue();

    while (!termina){


        if(!event_queue){
            fprintf(stderr, "failed to create event_queue!\n");
            al_destroy_bitmap(pac);
            al_destroy_display(display);
            return -1;
        }

        al_register_event_source(event_queue, al_get_display_event_source(display));
        al_register_event_source(event_queue, al_get_keyboard_event_source());

        ALLEGRO_EVENT ev;

        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                termina = true;
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                mario.viraEsq();
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
                mario.viraDir();
            }

        }else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            termina = true;
        }else if(ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_UP){
            mario.movimenta();
        }

        al_clear_to_color(al_map_rgb(0,0,0));

        bloc.criar_paredes(pac);
        pis.criar_piso(pac);
        mario.criar_pilulas(pac);
        mario.movimenta();
        mario.draw();

        al_flip_display();
    }


    al_destroy_bitmap(pac);
    al_destroy_display(display);

    return 0;
}
