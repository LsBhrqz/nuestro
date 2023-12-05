#ifndef ARMA_H
#define ARMA_H
#include "modelo.h"

class arma : public modelo
{

public:
    bool impacto(int tiempoExplosion);
    void impacto();
    void ubicarMorty(double coordXmorty, double coordYmorty, double coordInx, double coordIny);

};


#endif // ARMA_H
