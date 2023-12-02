#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <modelo.h>
#include <arma.h>
#include "QGraphicsItem"


class personaje : public modelo, public QGraphicsPixmapItem{
private:
    int salud=100;
public:
    personaje();
    int getSalud();
    void morir();
    void herido();
};

#endif // PERSONAJE_H
