#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(casillasAtacadasTEST, atacadasDelJugadorActual) {
	tablero t = {
            {cVACIA, cREY_N, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
	posicion p = make_pair(t, BLANCO);

	int j = BLANCO;

	vector<coordenada> esperado = { 
		make_pair(6,3), make_pair(5,3), make_pair(5,4), make_pair(5,5), make_pair(6,5), make_pair(7,5), make_pair(7,4), make_pair(7,3), //Rey Blanco en (6,4)
		make_pair(3,4), make_pair(3,6)	//Peon Blanco en (4,5)
	};
	
	vector<coordenada> atacadas = casillasAtacadas(p, j);
	EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}

TEST(casillasAtacadasTEST, atacadasDelContrincante) {
	tablero t = {
            {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
	posicion p = make_pair(t, BLANCO);

	int j = NEGRO;

	vector<coordenada> esperado = {
		make_pair(0,0), make_pair(0,2), make_pair(1,0), make_pair(1,1), make_pair(1,2), //Rey Negro en (0,1)
		make_pair(4,5), make_pair(4,7) //Peon Negro en (3,6)

	};

	vector<coordenada> atacadas = casillasAtacadas(p, j);
	EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}

TEST(casillasAtacadasTEST, leDanMasa) {
    tablero t = {
            {cALFIL_N, cREY_N, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B},
            {cTORRE_N, cPEON_B,cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cALFIL_N, cTORRE_N,cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cPEON_N, cVACIA ,   cVACIA  , cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA ,   cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA,    cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA,   cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA,   cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);

    int j = NEGRO;

    vector<coordenada> esperado = {
            make_pair(1,1), make_pair(1,3), make_pair(4,0), make_pair(3,3), make_pair(4,2), make_pair(1,2)
    };

    vector<coordenada> atacadas = casillasAtacadas(p, j);
    EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}

TEST(casillasAtacadasTEST, alfilTodoContemplado) {
    tablero t = {
            {cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B},
    };
    posicion p = make_pair(t, NEGRO);

    int j = NEGRO;

    vector<coordenada> esperado = {
            make_pair(2,2), make_pair(4,2), make_pair(4,4), make_pair(2,4), make_pair(0,1),make_pair(1,0),make_pair(1,1)
    };

    vector<coordenada> atacadas = casillasAtacadas(p, j);
    EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}

//en el 7 hay una torre re falopera que hace un movimiento re de tryhard y gegea al blanco re ez.
//linea 342. Hay que arreglar la hostilidad de la torre
//nerf torre pls
