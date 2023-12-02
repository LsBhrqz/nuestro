#include <personaje.h>

void personaje::disparar(string cara, double angulo){
    double animEnemigo = 100;
    int j = 1;
    for(int i = 0 ; i<= animEnemigo; i++){
        if(i%10 == 0){
            if(personaje.caras[j] == cara){
                arma bola;
                bola.constructor(600.0, 600.0, angulo, 30, false, 20, 20, 1280, 722);
                bola.jump();
                bool desaparecer = bola.impacto();
                if(desaparecer){
                    //delete bola
                }
            }
            j++;
        }
    }
}

void personaje::morir(){
    //explosión de muerte y terminación de nivel
}

void personaje::herido(){
    salud -= 5;
}

int personaje::getSalud(){
    return salud;
}
