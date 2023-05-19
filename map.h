#ifndef MAP_H
#define MAP_H

class mapa{
public:
   mapa();
   ~mapa();
   char m[28][28];
};

class pilulas{
public:
    pilulas();
    ~pilulas();
    void criar_pilulas(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;


};

class paredes{
public:
    paredes();
    ~paredes();
    void criar_paredes(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;
};

class piso{
public:
    piso();
    ~piso();
    void criar_piso(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;
};

class PacMario{
public:
    PacMario();
    ~PacMario();
    void movimenta();
    void viraEsq();
    void viraDir();
    void comePil();
    void draw();

private:
    int x;
    int y;
    char direcao;
    int velocidade;
    int score;
    ALLEGRO_BITMAP *pacmario_bitmap;
};

#endif
