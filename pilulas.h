#ifndef PILULAS_H
#define PILULAS_H

#include "mapa.h"

class pilulas{
public:
    pilulas();
    ~pilulas();
    void criar_pilulas(ALLEGRO_BITMAP*, mapa*);
private:
    int i;
    int j;
};

#endif // PILULAS_H
