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
    bool teclas [ALLEGRO_KEY_MAX]= {false};

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

    ALLEGRO_BITMAP* mar;
    mar = al_load_bitmap("pcmr.png");

    if(!mar){
        fprintf(stderr, "failed to create PacMario bitmap!\n");
        al_destroy_display(display);
        return 0;
    }else{
        mario.setbitmap(mar);
    }


    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    event_queue = al_create_event_queue();
    if(!event_queue){
            fprintf(stderr, "failed to create event_queue!\n");
            al_destroy_bitmap(pac);
            al_destroy_display(display);
            return -1;
        }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    while (!termina){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                termina = true;
            }else{
                teclas[ev.keyboard.keycode] = true;
            }
            }else if (ev.type == ALLEGRO_EVENT_KEY_UP){
                teclas[ev.keyboard.keycode] = false;
            }else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                termina = true;
            }
        if(mario.remainingpills == 0){
            termina = true;
        }

       al_clear_to_color(al_map_rgb(0,0,0));

        bloc.criar_paredes(pac);
        pis.criar_piso(pac);
        mario.criar_pilulas(pac);
        mario.update(teclas);
        mario.draw();

        al_flip_display();
    }


    al_destroy_bitmap(pac);
    al_destroy_bitmap(mar);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
