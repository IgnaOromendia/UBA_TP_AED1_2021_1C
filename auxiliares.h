#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);



vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );

//auxs

int jugador(posicion p);


bool esJugadorValido(int j);
bool esTableroValido(tablero t);


//ejercicio 2

bool cantidadPiezasAlInicio(tablero t);
bool piezasEnCoordenadas(tablero t);


//ejercicio 3
bool casillaAtacada(tablero t, coordenada o, coordenada d);
int contrincante(int j);
int color(tablero t, coordenada c);
bool pertenece(coordenada c, vector<coordenada> C);


//ejercicio  4
bool posicionSiguiente (posicion p, posicion q, coordenada o, coordenada d);


//ejercicio 5
vector<casilla> ordenarFila(vector<casilla> fila) ;


//EJERCICIO 6

bool esEmpate(posicion p);
bool esJaqueMate(posicion p);
int quienGano (posicion p);


//EJERCICIO 7
bool alMoverQuedaEnJaque(posicion p);


//EJERCICIO 8
void ejecutarSecuencia(posicion &p, secuencia s);


//EJERCICIO 9
int indiceDelMinio(vector<secuencia> v);
secuencia movimientoPosibleParaJaque(posicion p, vector<secuencia> vMov);


#endif //AJEDREZLITE_AUXILIARES_H

