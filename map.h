#ifndef MAP_H
#define MAP_H

class map
{
public:
   map();
   char m[28][28];
};

class pilulas
{
public:
    pilulas();
    void criar_pilulas(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;


};

class paredes
{
public:
    paredes();
    void criar_paredes(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;
};

class piso
{
public:
    piso();
    void criar_piso(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;
};
#endif
