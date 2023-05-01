#ifndef MAP_H
#define MAP_H

class map
{
private:
    char m[48][48]=
    {
        "1111111111111111111111111111111111111111111111",
        "10000000000100000000001",            //0 - Pilulas
        "10111011110101111011101",            //1 - Paredes;
        "10111011110101111011101",
        "10000000000000000000001",
        "10111010111111101011101",
        "10000010000100001000001",
        "10111011110101111011101",
        "10111010000000001011101",
        "10111010111011101011101",
        "10000000100000100000001",
        "10111010100000101011101",
        "10111010111111101011101",
        "10111010000000001011101",
        "10111010111111101011101",
        "10000000000100000000001",
        "10111011110101111011101",
        "10001000000000000010001",
        "11101010111111101010111",
        "10000010000100001000001",
        "10111111110101111111101",
        "10000000000000000000001",
        "11111111111111111111111",
    };
    friend class pilulas;
    friend class paredes;
    friend class piso;
};

class pilulas
{
public:
    void criar_pilulas(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;


};
class paredes
{
public:
    void criar_paredes(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;
};
class piso
{
public:
    void criar_piso(ALLEGRO_BITMAP *p);
private:
    int i;
    int j;
};
#endif

