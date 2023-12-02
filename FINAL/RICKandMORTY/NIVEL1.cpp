#include "NIVEL1.h"
#include "morty.h"
#include "personaje.h"
#include "arma.h"

bool continuidadnivel1(bool& continuar){
    Morty morty();
    personaje hepatitisB;
    string cara1 = ":/img/hepatitisb1.png";
    string cara2 = ":/img/hepatitisb2.png";
    string cara3 = ":/img/hepatitisb3.png";
    hepatitisB.constructor(600.0, 600.0, 0.0, 0.0, false, 405.0, 350.0, 1280.0, 722.0);
    hepatitisB.caras[1] = cara1; hepatitisB.caras[2] = cara2; hepatitisB.caras[3] = cara3;
    int vidaMorty = morty.getVida();
    while(vidaMorty >= 0){
        int vidaHepa = hepatitisB.getSalud();
        while(vidaHepa >= 0){
            double ang = hepatitisB.angAleatorio();
            hepatitisB.disparar(cara3, ang);
        }
    }

}
