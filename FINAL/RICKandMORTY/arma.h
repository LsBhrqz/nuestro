#ifndef ARMA_H
#define ARMA_H
#include "modelo.h"

class arma : public modelo{

public:
    bool impacto(int tiempoExplosion);
    void impacto();
    bool impacto(double _coordXenemigo, double _coordYenemigo, double anchoEnemigo, double altoEnemigo);

};


#endif // ARMA_H
