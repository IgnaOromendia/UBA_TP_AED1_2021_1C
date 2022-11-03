#include <algorithm>
#include "ejercicios.h"
//#include "auxiliares.cpp"
#include "auxiliares.h"
#include <iostream>

using namespace std;

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {
    bool resp = false;
    if(p.first.size() > 1) {
        if (esJugadorValido(jugador(p)) && esTableroValido(p.first)) {
            resp = true;
        }
    }
    return resp;
}


// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    return piezasEnCoordenadas(p.first) && cantidadPiezasAlInicio(p.first) && jugador(p) == BLANCO;
}

// EJERCICIO 3
vector <coordenada> casillasAtacadas ( posicion const &p, int j ) {
    vector <coordenada> cA;
    for(int i = 0; i < DIM; i++) {
        for(int k = 0; k < DIM; k++) {
            for (int l = 0; l < DIM; l++) {
                for (int n = 0; n < DIM; n++) {
                    coordenada c = setCoord(i, k);
                    coordenada a = setCoord(l, n);
                    if(color(p.first, a) != j && color(p.first, c) == j){
                        if (casillaAtacada(p.first,c,a)){
                            if (!pertenece(a,cA)){
                                cA.push_back(a);
                            }
                        }
                    }
                }
            }
        }
    }
    return cA;
}
// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {
    return posicionSiguiente(p1,p2,o,d);
}

// EJERCICIO 5


void ordenarTablero ( posicion &p ) {
    tablero tOrdenado;
    for (int i = 0; i < p.first.size(); i++) {
        tOrdenado.push_back(ordenarFila(p.first[i]));
    }
    p.first = tOrdenado;
}

// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    j = quienGano(p);
    return (esEmpate(p) && j == 0 ) || (esJaqueMate(p) && j== contrincante(jugador(p)));
}
// EJERCICIO 7
bool hayJaqueDescubierto (posicion const &p ) {
    return alMoverQuedaEnJaque(p);
}
// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    ejecutarSecuencia(p,s);
}


// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    vector<secuencia> vMov;
    vMov.push_back(movimientoPosibleParaJaque(p,vMov));
    int indiceMin = indiceDelMinio(vMov);
    return vMov[indiceMin].size();
}
