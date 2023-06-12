#ifndef PACMARIO_H
#define PACMARIO_H

#include "mapa.h"
#include "pilulas.h"
#include "allegro5/allegro_font.h"

class PacMario{
public:
    PacMario(mapa &mapa);
    ~PacMario();
    void setbitmap(ALLEGRO_BITMAP*);
    void movimenta(bool*, ALLEGRO_TIMER*);
    void draw();
    void update(bool*, ALLEGRO_TIMER*);
    void criar_pilulas(ALLEGRO_BITMAP*);
    int remainingpills = 309;


private:
    int x;
    int y;
    char direcao;
    int velocidade;
    int score;
    ALLEGRO_BITMAP *pacmario_bitmap;
    mapa *meumapa;
    pilulas p;
    ALLEGRO_FONT* score_font=NULL;

};

#endif // PACMARIO_H
