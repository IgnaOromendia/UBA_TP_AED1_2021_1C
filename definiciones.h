#ifndef AJEDREZLITE_DEFINICIONES_H
#define AJEDREZLITE_DEFINICIONES_H

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// DEFINICIONES DE TIPO
// DEFINICIONES DE TIPO
typedef pair < int, int > casilla;
typedef vector < vector < casilla > > tablero;
typedef pair < tablero, int > posicion;
typedef pair < int, int > coordenada;
typedef vector < pair < coordenada, coordenada > > secuencia;

// CONSTANTES ÚTILES


#define  DIM        8
#define  VACIO      0
#define  BLANCO     1
#define  NEGRO      2

#define  PEON       1
#define  ALFIL      2
#define  TORRE      3
#define  REY        4

#define ANCHO_TABLERO 8

#define cVACIA make_pair(VACIO, VACIO)

#define cREY_N make_pair(REY, NEGRO)
#define cREY_B make_pair(REY, BLANCO)

#define cTORRE_N make_pair(TORRE, NEGRO)
#define cTORRE_B make_pair(TORRE, BLANCO)

#define cALFIL_N make_pair(ALFIL, NEGRO)
#define cALFIL_B make_pair(ALFIL, BLANCO)

#define cPEON_N make_pair(PEON, NEGRO)
#define cPEON_B make_pair(PEON, BLANCO)

#endif  //AJEDREZLITE_DEFINICIONES_H

