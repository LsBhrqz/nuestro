#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <modelo.h>
#include <arma.h>

class personaje : public modelo{
private:
    int salud;
public:
    int getSalud();
    void disparar(string cara, double angulo);
    void morir();
    void herido();
};

#endif // PERSONAJE_H
