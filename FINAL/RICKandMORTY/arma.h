#ifndef ARMA_H
#define ARMA_H
#include "modelo.h"

class arma : public modelo{
public:
    bool impacto(int tiempoExplosion);
    bool impacto();
    bool impacto(double _coordXenemigo, double _coordYenemigo);
};


#endif // ARMA_H
