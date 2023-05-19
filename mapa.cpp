#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "map.h"

using namespace std;

mapa::mapa(){

    char aux[28][28]={
        "111111111111111111111111111",
        "100000000000000000000000001",            //0 - Pilulas e Piso;
        "101010101010101010101010101",            //1 - Paredes;
        "101010101010101010101010101",            //2 - Pilulas Vazias;
        "101010101010101010101010101",
        "101010101010101010101010101",
        "101010101010101010101010101",
        "101010101010101010101010101",
        "101010101010101010101010101",
        "101010101010101010101010101",
        "101010101010101010101010101",
        "101000000000000000000000101",
        "101001111111101111111100101",
        "100001000000222000000100001",
        "111101000000222000000101111",
        "100001111111111111111100001",
        "101000000000000000000010101",
        "101011111011111011111010101",
        "101000100010001000100010101",
        "101010101010101010101000101",
        "101010101010101010100010101",
        "100010001000100020101010001",
        "111111111111111111111111111",
    };
    int i, j;

    for (i=0; i<28; i++){
        for(j=0; j<28; j++){
            m[i][j]= aux[i][j];
        }
    }
}

mapa::~mapa(){
}

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

// b = baixo; c = cima; e = esquerda; d = direita

PacMario::PacMario(mapa &mapa){
     x = 1;
     y = 1;
     direcao = 'b';
     velocidade = 1;
     score = 0;

     al_init_image_addon();

     this->pacmario_bitmap = al_load_bitmap("pcmr.png");
     this->meumapa = &mapa;

     if(!pacmario_bitmap){
        fprintf(stderr, "failed to creat PacMario bitmap!\n");
     }

}

PacMario::~PacMario(){
    //al_destroy_bitmap(pacmario_bitmap);
    //delete this->meumapa;
}

void PacMario::movimenta(){
    int nextX = x;
    int nextY = y;

    switch (direcao) {
        case 'c':
            nextY -= velocidade;
            break;
        case 'b':
            nextY += velocidade;
            break;
        case 'e':
            nextX -= velocidade;
            break;
        case 'd':
            nextX += velocidade;
            break;
    }

    if(nextX >= 0 && nextX < 28 && nextY >= 0 && nextY < 28){
        char nextCell = meumapa->m[nextY][nextX];

        if(nextCell == '1'){
            score++;
            meumapa->m[nextY][nextX] = '2';
        }
    }

    x = nextX;
    y = nextY;


}

void PacMario::viraEsq(){
    if (direcao == 'c'){
        direcao = 'e';
    }else{
        direcao = direcao - 1;
    }
}

void PacMario::viraDir(){
    if (direcao == 'd'){
        direcao = 'c';
    }else{
        direcao = direcao + 1;
    }
}

void PacMario::comePil() {
    if(meumapa->m[y][x] == '1'){
        meumapa->m[y][x] = '2';
        score++;
    }

}

void PacMario::draw() {
    al_draw_bitmap(pacmario_bitmap,x*26, y*26, 0);
}

void PacMario::update(){
    movimenta();
}

void PacMario::criar_pilulas(ALLEGRO_BITMAP* bit){
    p.criar_pilulas(bit,this->meumapa);
}
