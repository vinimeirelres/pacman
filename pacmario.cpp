#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "pacmario.h"



using namespace std;

PacMario::PacMario(mapa &mapa){
     x = 13;
     y = 13;
     direcao = 'b';
     velocidade = 1;
     score = 0;

     this->meumapa = &mapa;
}

PacMario::~PacMario(){
    al_destroy_bitmap(pacmario_bitmap);
    al_destroy_font(score_font);
    delete this->meumapa;
}

void PacMario::setbitmap(ALLEGRO_BITMAP* p){
    this->pacmario_bitmap = p;
}

void PacMario::movimenta(bool* teclas, ALLEGRO_TIMER* timer){
    int nextX = x;
    int nextY = y;

    if(teclas[ALLEGRO_KEY_UP]){
        nextY -= velocidade;
    }else if(teclas[ALLEGRO_KEY_DOWN]){
        nextY += velocidade;
    }else if(teclas[ALLEGRO_KEY_LEFT]){
        nextX -= velocidade;
    }else if(teclas[ALLEGRO_KEY_RIGHT]){
        nextX += velocidade;
    }

    if(nextX >= 0 && nextX < 28 && nextY >= 0 && nextY < 28){

        if(meumapa->m[nextY][nextX] == '0'){
            score++;
            remainingpills--;
            meumapa->m[nextY][nextX] = '2';
        }

        if(meumapa->m[nextY][nextX] != '1'){
            x = nextX;
            y = nextY;
        }
    }
}



void PacMario::draw() {
    al_draw_bitmap(pacmario_bitmap,x*26, y*26, 0);


    this->score_font = al_create_builtin_font();
    int fontsize = 24;
    ALLEGRO_COLOR color = al_map_rgb(255,255, 255);
    al_draw_textf(score_font,color, 760, 300, ALLEGRO_ALIGN_CENTER, "Score:", score);
    al_draw_textf(score_font,color, 780, 315, ALLEGRO_ALIGN_CENTER, "%d", score);
}

void PacMario::update(bool* teclas, ALLEGRO_TIMER* timer){
    movimenta(teclas, timer);
}

void PacMario::criar_pilulas(ALLEGRO_BITMAP* bit){
    p.criar_pilulas(bit,this->meumapa);
}
