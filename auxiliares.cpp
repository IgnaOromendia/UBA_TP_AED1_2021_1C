#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
//pair<int,int> mp(int a, int b) {
//    return make_pair(a, b);
//}

// TEST
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

//tablero inicializarTablero(){
//    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
//    tablero out(ANCHO_TABLERO, fila);
//    return out;
//}

// AUXs
int aparicionesEnTablero(tablero t, casilla p) {
    int result = 0;
    for(int i = 0; i < t.size(); i++) {
        for(int j = 0; j < t[i].size();j++) {
            if (t[i][j] == p) {
                result++;
            }
        }
    }
    return result;
}

int pieza(tablero t, coordenada c){
    return (t[c.first][c.second]).first;
}

int color(tablero t, coordenada c){
    return t[c.first][c.second].second;
}

casilla setCasilla(int i, int j) {
    return make_pair(i,j);
}

int jugador(posicion p) {
    return p.second;
}

bool enRango(int x, int m1, int m2){
    return (m1 < x && x < m2) || (m2 < x && x < m1);
}

int contrincante(int j){
    return j==BLANCO ? NEGRO : BLANCO;
}
// PREDs
//EJERCICIO 1

bool piezasTorresValidas(tablero t){
    bool res=true;
    if((aparicionesEnTablero(t,cTORRE_B)<=2 + DIM - aparicionesEnTablero(t,cPEON_B))==false){
        res=false;
    }
    if((aparicionesEnTablero(t,cTORRE_N)<=2 + DIM - aparicionesEnTablero(t,cPEON_N))==false){
        res=false;
    }
    return res;
}

bool piezasAlfilesValidas(tablero t) {
    return aparicionesEnTablero(t,cALFIL_B) <= 2 && aparicionesEnTablero(t,cALFIL_N) <= 2;
}

bool piezasReyesValidas(tablero t){
    return (aparicionesEnTablero(t,cREY_B) + aparicionesEnTablero(t,cREY_N)) == 2 ;
}

bool piezasPeonesValidas(tablero t){
    return aparicionesEnTablero(t,cPEON_B) <= DIM && aparicionesEnTablero(t,cPEON_N) <= DIM;
}

bool cantidadValidaDePiezas(tablero t){
    return piezasPeonesValidas(t) && piezasReyesValidas(t) && piezasTorresValidas(t) && piezasAlfilesValidas(t);
}


bool casillaVacia(tablero t, coordenada c) {
    casilla c1 = make_pair(t[c.first][c.second].first,t[c.first][c.second].second);
    return c1 == cVACIA;
}

bool coordenadaEnRango(coordenada c) {
    return 0 <= c.first && c.first < DIM && 0 <= c.second && c.second < DIM;
}

bool piezaCorrecta(int p) {
    return (p >= PEON && p <= REY);
}

bool colorCorrecto(int c) {
    return (BLANCO == c || c == NEGRO);
}


bool casillasValidas(tablero t){
    bool result = false;
    for (int i= 0 ; i<DIM; i++){
        for(int j = 0; j<DIM; j++){
            coordenada c = setCoord(i,j);
            if (coordenadaEnRango(c)){
                if (casillaVacia(t,c) || (piezaCorrecta(pieza(t,c)) && colorCorrecto(color(t,c)))){
                    result = true;
                }
            }
        }
    }
    return result;
}


bool sinPeonesNoCoronados(tablero t){
    bool res=true;
    for(int i=0;i<t.size();i++){
        for(int j=0;j<t.size();j++){
            if(pieza(t,setCoord(0,i)) == PEON || pieza(t,setCoord(DIM-1,i)) == PEON ){
                res=false;
            }
        }
    }
    return res;
}


bool esMatriz(tablero t) {
    bool res = true;
    if (t.size() == DIM) {
        for (int i = 0; i < t.size();i++) {
            if (t[i].size() != t.size()) {
                res = false;
            }
        }
    }
    return res;
}


bool esTableroValido(tablero t){
    return esMatriz(t) && casillasValidas(t) && sinPeonesNoCoronados(t) && cantidadValidaDePiezas(t);
}


bool esJugadorValido(int j){
    return j==2 || j==1;
}

//ejercicio 2

bool cantidadPiezasAlInicio(tablero t){
    return aparicionesEnTablero(t,setCasilla(TORRE,NEGRO)) == 2  && aparicionesEnTablero(t,setCasilla(TORRE,BLANCO)) == 2  &&
           aparicionesEnTablero(t,setCasilla(ALFIL,NEGRO)) == 2  && aparicionesEnTablero(t,setCasilla(ALFIL,BLANCO)) == 2  &&
           aparicionesEnTablero(t,setCasilla(PEON,NEGRO)) == DIM && aparicionesEnTablero(t,setCasilla(PEON,BLANCO)) == DIM;
}


bool piezaEnCoordenada(tablero t, coordenada c, int pza, int col) {
    return pieza(t,c) == pza && color(t,c) == col;
}

bool reyesEnCoordenadas(tablero t) {
    return piezaEnCoordenada(t,setCoord(0,4),REY,NEGRO) && piezaEnCoordenada(t,setCoord(DIM - 1,4),REY,BLANCO);
}

bool torresEnCoordenadas(tablero t){
    coordenada c1 = setCoord(0,0);
    coordenada c2 = setCoord(0,DIM-1);
    coordenada c3 = setCoord(DIM-1,0);
    coordenada c4 = setCoord(DIM-1,DIM-1);
    return piezaEnCoordenada(t,c2,TORRE,NEGRO) && piezaEnCoordenada(t,c1,TORRE,NEGRO) && piezaEnCoordenada(t,c3,TORRE,BLANCO) && piezaEnCoordenada(t,c4,TORRE,BLANCO);
}

bool alfilesEnCoordenadas(tablero t){
    coordenada c1 = setCoord(0,2);
    coordenada c2 = setCoord(0,DIM-3);
    coordenada c3 = setCoord(DIM - 1,2);
    coordenada c4 = setCoord(DIM - 1,DIM-3);
    return piezaEnCoordenada(t,c1,ALFIL,NEGRO) && piezaEnCoordenada(t,c2,ALFIL,NEGRO) && piezaEnCoordenada(t,c3,ALFIL,BLANCO) && piezaEnCoordenada(t,c4,ALFIL,BLANCO);
}

bool peonesEnCoordenadas(tablero t) {
    bool res = true;
    for(int i = 0; i < DIM; i++){
        if (!piezaEnCoordenada(t,setCoord(1,i),PEON,NEGRO) || !piezaEnCoordenada(t,setCoord(6,i),PEON,BLANCO)) {
            res = false;
        }
    }
    return res;
}

bool piezasEnCoordenadas(tablero t){
    return (peonesEnCoordenadas(t) && torresEnCoordenadas(t) && alfilesEnCoordenadas(t) && reyesEnCoordenadas(t));
}

//ejercicio 3


bool movimientoPeonValido(tablero t, int color, coordenada o, coordenada d) {
    return pieza(t,o) == PEON && (d.second == o.second) && ((color == BLANCO && d.first == (o.first - 1)) || (color == NEGRO && d.first == (o.first + 1)));
}

bool mueveEnHorizontal(coordenada o, coordenada d) {
    return abs(o.first - d.first) == 0 && abs(o.second - d.second) == 1;
}

bool mueveEnVertical(coordenada o, coordenada d) {
    return abs(o.first - d.first) == 1 && abs(o.second - d.second) == 0;
}

bool mueveEnDiagonal(coordenada o, coordenada d) {
    return abs(o.first - d.first) == 1 && abs(o.second - d.second) == 1;
}

bool movimientoReyValido(tablero t,coordenada o, coordenada d) {
    return (pieza(t, o) == REY) && (mueveEnDiagonal(o, d) || mueveEnVertical(o, d) || mueveEnHorizontal(o, d));
}

bool mueveParaAbajoIzquierda(tablero t, coordenada o, coordenada d, int i, int j, bool result) {
    if (!casillaVacia(t,setCoord(o.first + i,o.second - j))) {
        result = false;
    }
    return result;
}
bool mueveParaArribaDerecha(tablero t, coordenada o, coordenada d, int i, int j, bool result) {
    if (!casillaVacia(t,setCoord(o.first - i,o.second + j))) {
        result = false;
    }
    return result;
}

bool mueveParaAbajoDerecha(tablero t, coordenada o, coordenada d, int i, int j, bool result) {
    if (!casillaVacia(t,setCoord(o.first + i,o.second + j))) {
        result = false;
    }
    return result;
}

bool mueveParaArribaIzquierda(tablero t, coordenada o, coordenada d, int i, int j, bool result) {
    if (!casillaVacia(t,setCoord(o.first - i,o.second - j))) {
        result = false;
    }
    return result;
}

bool movimientoAlfilValido(tablero t, coordenada o, coordenada d){
    bool result = false;
    if(pieza(t,o) == ALFIL && abs(d.first-o.first) == abs(d.second-o.second)){
        result  = true;
        int diferencia_abs1 = abs(d.first-o.first);
        int diferencia_abs2 = abs(d.second - o.second);
        for (int i = 0; i < diferencia_abs1; i++) {
            if (enRango(i, 0, diferencia_abs1)) {
                for (int j = 0; j < diferencia_abs2; j++) {
                    if (enRango(j, 0, diferencia_abs2) && (abs(i) == abs(j))) {
                        if(d.first > o.first && d.second > o.second) {
                            result = mueveParaAbajoDerecha(t, o, d, i, j, result);
                        }else if (d.first > o.first && o.second > d.second) {
                            result = mueveParaAbajoIzquierda(t,o,d,i,j,result);
                        }else if(d.first < o.first && d.second < o.second){
                            result = mueveParaArribaIzquierda(t,o,d,i,j,result);
                        }else if(d.first < o.first && d.second > o.second){
                            result = mueveParaArribaDerecha(t,o,d,i,j,result);
                        }
                    }
                }
            }
        }
    }
    return result;
}

bool movimientoTorreValido(tablero t, coordenada o, coordenada d){
    bool resV = false;
    bool resH = false;
    if (pieza(t,o) == TORRE){
        if (d.second == o.second) {
            resV = true;
            if (d.first < o.first){ //para arriba
                for(int i= o.first-1 ;i>d.first ;i--){
                    if(enRango(i,o.first,d.first)){
                        if(!casillaVacia(t,setCoord(i,o.second))){
                            resV=false;
                        }
                    }
                }
            }else if (d.first > o.first){  //para abajo
                for(int i= o.first+1 ;i<d.first ;i++){
                    if(enRango(i,o.first,d.first)){
                        if(!casillaVacia(t,setCoord(i,o.second))){
                            resV=false;
                        }
                    }
                }
            }
        }else if (d.first == o.first) {
            resH = true;
            if (d.second > o.second){ //para la derecha
                for(int i = o.second +1; i < d.second; i++) {
                    if (enRango(i,o.second,d.second)) {
                        if (!casillaVacia(t,setCoord(o.first,i))) {
                            resH = false;
                        }
                    }
                }
            }else if(d.second < o.second){ // para izquierda
                for(int i = o.second - 1; i > d.second; i--) {
                    if (enRango(i,o.second,d.second)) {
                        if (!casillaVacia(t,setCoord(o.first,i))) {
                            resH = false;
                        }
                    }
                }
            }
        }
    }
    return resH || resV;
}

bool movimientoPiezaValido(tablero t, coordenada o, coordenada d){
    return (movimientoPeonValido(t, color(t,o),o,d) || movimientoAlfilValido(t,o,d) || movimientoTorreValido(t,o,d) || movimientoReyValido(t,o,d));
}


bool capturaPeonValida(tablero t, coordenada o, coordenada d){
    return ((color(t,o)==BLANCO && d.first - o.first == -1 && (d.second == o.second -1 || d.second == o.second+1)) || (color(t,o)==NEGRO && d.first - o.first == 1 && (d.second == o.second -1 || d.second == o.second+1)));
}

bool casillaAtacada(tablero t, coordenada o, coordenada d){
    return !casillaVacia(t,o) && ((pieza(t,o) != PEON && movimientoPiezaValido(t,o,d)) || (pieza(t,o) == PEON && capturaPeonValida(t,o,d)));
}



//EJERCICIO 4


bool enLineaFinalInicial(coordenada c){
    return (c.first==0 || c.first==DIM-1);
}

bool piezaCorrectaEnDestino(posicion p, posicion q, coordenada o, coordenada d){
    return color(p.first,o) == color(q.first,d) && ((enLineaFinalInicial(d) && pieza(q.first,d) == TORRE) || !enLineaFinalInicial(d)  && pieza(q.first,d) == pieza(p.first,o));
}

bool pertenece(coordenada c, vector<coordenada> C) {
    bool result = false;
    for(int i = 0; i < C.size();i++) {
        if (c == C[i]) {
            result = true;
        }
    }
    return result;
}


bool posicionesIgualesExceptoEn(posicion p, posicion q, vector<coordenada> C){
    bool res= true;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            coordenada c=setCoord(i,j);
            if(coordenadaEnRango(c)){
                if(!pertenece(c,C)){
                    if (pieza(p.first,c)!=pieza(q.first,c) || color(p.first,c)!=color(q.first,c)) {
                        res = false;
                    }
                }
            }
        }
    }
    return res;
}

bool esMovimientoValido(posicion p, coordenada o, coordenada d){
    return jugador(p) == color(p.first,o) && !casillaVacia(p.first,o) && casillaVacia(p.first,d) && movimientoPiezaValido(p.first,o,d);
}

bool esCapturaValida(posicion p, coordenada o, coordenada d){
    return (!casillaVacia(p.first,o))  && (!casillaVacia(p.first,d))  && (color(p.first,o) != color(p.first,d)) &&  casillaAtacada(p.first,o,d);
}

bool posicionSiguiente (posicion p, posicion q, coordenada o, coordenada d){
    vector<coordenada> c = {o, d};
    return posicionesIgualesExceptoEn(p,q, c) && casillaVacia(q.first,o) && (esMovimientoValido(p,o,d) || esCapturaValida(p,o,d)) && piezaCorrectaEnDestino(p,q,o,d);
}

//EJERCICIO 5


void swap(vector<casilla> &v, int i, int j) {
    casilla copia = v[i];
    v[i] = v[j];
    v[j] = copia;
}

int indiceCasillaMinDesde(vector<casilla> v, int d) {
    int iMin = d;
    casilla minima;
    minima.first = 4;
    minima.second = 1;
    for(int i = d; i < v.size(); i++) {
        if (minima.first > v[i].first && v[i].first != 0) {
            minima = v[i];
            iMin = i;
        }
    }
    return iMin;
}

vector<casilla> ordenarFila(vector<casilla> fila) {
    vector<casilla> filaOrdenada = fila;
    for(int i = 0; i < fila.size();i++) {
        if (filaOrdenada[i].first != 0) {
            int minimo = indiceCasillaMinDesde(filaOrdenada,i);
            swap(filaOrdenada,i,minimo);
        }
    }
    return filaOrdenada;
}

//EJERCICIO 6

int quienGano (posicion p){
    int ganador = 0;
    if (esJaqueMate(p)){
        ganador = contrincante(jugador(p));
    }
    return ganador;
}


bool atacaAlRey(posicion p, coordenada o) {
    bool result = false;
    for(int i = 0; i < DIM;i++) {
        for(int j = 0; j < DIM;j++) {
            coordenada d = setCoord(i,j);
            if (coordenadaEnRango(d)) {
                if( pieza(p.first,d) == REY && color(p.first,d) == jugador(p) && esCapturaValida(p,o,d)){
                    result = true;
                }
            }
        }
    }
    return result;
}

bool jugadorEnJaque(posicion p, int j) {
    bool result = false;
    posicion q;
    q.first = p.first;
    q.second = j;
    for(int i = 0; i < DIM;i++) {
        for(int j = 0; j < DIM;j++) {
            coordenada o = setCoord(i,j);
            if (coordenadaEnRango(o) && (color(q.first,o) == contrincante(j)) && atacaAlRey(q,o)) {
                result = true;
            }
        }
    }
    return result;
}

bool tienenMovimiento (posicion p, vector<coordenada> piezas){
    bool result = false;
    for (int i=0;i<piezas.size();i++){
        for(int j=0; j< DIM;j++){
            for(int k = 0; k < DIM;k++) {
                if (pertenece(piezas[i],piezas)) {
                    coordenada d = setCoord(j,k);
                    if(coordenadaEnRango(d) && (esMovimientoValido(p,piezas[i],d) || esCapturaValida(p,piezas[i],d))){
                        result = true;
                    }
                }
            }
        }
    }
    return result;
}

bool hayMovimientosLegales(posicion p){
    bool res=false;
    vector<coordenada> movibles;
    for(int i=0;i<p.first.size();i++){
        for(int j=0;j<p.first.size();j++){
            coordenada c=setCoord(i,j);
            if(coordenadaEnRango(c) && piezaCorrecta(pieza(p.first,c)) && (color(p.first, c) == jugador(p))){
                movibles.push_back(c);
            }
        }
    }
    if(movibles.size()>=0 &&  tienenMovimiento(p,movibles)){
        res=true;
    }
    return res;
}


bool soloHayReyes(tablero t){
    bool result = false;
    for(int i= 0;i<t.size();i++){
        for(int j = 0; j< t.size();j++){
            coordenada c = setCoord(i,j);
            if (coordenadaEnRango(c)){
                result = (casillaVacia(t,c) || pieza(t,c) == REY);
            }
        }
    }
    return result;
}


bool esEmpate(posicion p){
    return (soloHayReyes(p.first) || (!jugadorEnJaque(p,p.second) && !hayMovimientosLegales(p)));
}

bool esPosicionValida(posicion p){
    return esJugadorValido(jugador(p)) && esTableroValido(p.first);
}

bool loPoneEnJaque(posicion p, coordenada o, coordenada d) {
    bool result = false;
    posicion q;
    if (esPosicionValida(q)) {
        result = posicionSiguiente(p,q,o,d) && jugador(p) == jugador(q) && jugadorEnJaque(q,q.second);
    }
    return result;
}

bool esJugadaLegal(posicion p, coordenada o, coordenada d){
    return (esMovimientoValido(p,o,d) || esCapturaValida(p,o,d)) && (!loPoneEnJaque(p,o,d));
}

bool existeMovimientoParaSalirDelJaque(posicion p) {
    bool result = false;
    for(int i= 0;i< DIM;i++){
        for(int j = 0; j< DIM;j++){
            coordenada o = setCoord(i,j);
            for(int k= 0;k < DIM;k++){
                for(int n = 0; n < DIM;n++){
                    coordenada d = setCoord(k,n);
                    if (o != d) {
                        if (coordenadaEnRango(o) && coordenadaEnRango(d)) {
                            result = color(p.first,o) == jugador(p) && esJugadaLegal(p,o,d);
                        }
                    }
                }
            }
        }
    }
    return result;
}

bool esJaqueMate(posicion p){
    return (jugadorEnJaque(p,p.second) && (!existeMovimientoParaSalirDelJaque(p)));
}

// Ejercicio 7


posicion moverPieza(posicion p, coordenada o, coordenada d) {
    posicion q = p;
    if (esPosicionValida(p)) {
        if (esMovimientoValido(p,o,d) || esCapturaValida(p,o,d)) {
            q.first[o.first][o.second] = cVACIA;
            if ((d.first == DIM - 1 || d.first == 0) && pieza(p.first,o) == PEON){
                casilla c = setCasilla(TORRE,color(p.first,o));
                q.first[d.first][d.second] = c;
            } else {
                q.first[d.first][d.second] = p.first[o.first][o.second];
            }
        }
    }
    return q;
}



bool alMoverQuedaEnJaque(posicion p) {
    bool result = false;
    for(int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            for (int k = 0; k < DIM; k++){
                for (int l = 0; l < DIM; l++){
                    coordenada o = setCoord(i,j);
                    coordenada d = setCoord(k,l);
                    if (color(p.first,o) == jugador(p) && (o != d)) {
                        posicion q1 = moverPieza(p,o,d);
                        if (posicionSiguiente(p,q1,o,d) && jugadorEnJaque(q1,contrincante(q1.second))) {
                            result = true;
                        }
                    }
                }
            }
        }
    }
    return result;
}

//ejercicio 8


pair<coordenada, coordenada> unicaMovidaPosibleDeJugador(posicion p){
    coordenada c1;
    coordenada c2;
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            for(int k=0; k<DIM; k++){
                for(int l=0; l<DIM; l++){
                    c1 = setCoord(i,j);
                    c2 = setCoord(k,l);
                    if(esJugadaLegal(p,c1,c2) && (color(p.first,c1) == p.second) && (c1 != c2)){
                        posicion q = moverPieza(p,c1,c2);
                        if (!jugadorEnJaque(q,q.second)){
                            return make_pair(c1,c2);
                        }
                    }
                }
            }
        }
    }
    c1= setCoord(-1,-1);
    c2 = setCoord(-1,-1);
    return make_pair(c1,c2);
}


secuencia completarSecuencia(posicion p,secuencia s) {
    secuencia sCompleta;
    posicion q = p;

    for(int i = 0; i < s.size(); i++) {
        sCompleta.push_back(s[i]);
        q = moverPieza(q, s[i].first, s[i].second);
        q.second = contrincante((q.second));
        pair<coordenada, coordenada> jugada = unicaMovidaPosibleDeJugador(q);
        sCompleta.push_back(jugada);
        q = moverPieza(q, jugada.first, jugada.second);
        q.second = contrincante((q.second));

    }
    return sCompleta;
}

void ejecutarSecuencia(posicion &p, secuencia s) {
    posicion q = p;
    s = completarSecuencia(p,s);

    for(int i = 0; i < s.size();i++) {
        q = moverPieza(q, s[i].first, s[i].second);
        q.second = contrincante((q.second));

    }
    p = q;
}

//EJERCICIO 9

int indiceDelMinio(vector<secuencia> v) {
    int iMin = 0;
    for (int i = 0; i < v.size();i++) {
        if (v[iMin].size() > v[i].size()) {
            iMin = i;
        }
    }
    return iMin;
}


secuencia movimientosPosibles(posicion p) {
    secuencia v;
    for(int i = 0; i < DIM; i++) {
        for(int j = 0;j < DIM;j++) {
            for(int k = 0; k < DIM; k++) {
                for(int l = 0; l < DIM;l++) {
                    coordenada o = setCoord(i,j);
                    coordenada d = setCoord(k,l);
                    if (esJugadaLegal(p,o,d) && o != d) {
                        v.push_back(make_pair(o, d));
                    }
                }
            }
        }
    }
    return v;
}

bool contiene(vector<secuencia> v, pair<coordenada, coordenada> mov, int k) {
    bool result = false;
    for (int i = 0; i < v.size();i++) {
        if (v[i][k-1] == mov) {
            result = true;
        }
    }
    return result;
}

secuencia filtrarMovimientos(secuencia s, vector<secuencia> v, int k) {
    secuencia modificada;
    for (int i = 0; i < s.size();i++) {
        if (!contiene(v,s[i],k)) {
            modificada.push_back(s[i]);
        }
    }
    return modificada;
}



// Por cada pieza, la cantidad de secuencia posibles, y q no se hayan ya hecho
int cantMovimientosPosibles(posicion p, vector<secuencia> v, int k) {
    secuencia movimientos;
    if (k == 0) {
        movimientos = movimientosPosibles(p);
    } else if (k == 1) {
        movimientos = movimientosPosibles(p);
        movimientos = filtrarMovimientos(movimientos,v,k);
    } else if (k == 2) {
        movimientos = movimientosPosibles(p);
        movimientos = filtrarMovimientos(movimientos,v,k);
    }
    return movimientos.size();
}


secuencia movimientoPosibleParaJaque(posicion p, vector<secuencia> vMov) {
    posicion q = p;
    secuencia mov;
    pair<coordenada, coordenada> jugada;
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            for(int k = 0; k < DIM; k++) {
                for(int l = 0; l < DIM; l++) {
                    coordenada o = setCoord(i,j);
                    coordenada d = setCoord(k,l);
                    if (jugada.first != setCoord(-1,-1) && jugada.second != setCoord(-1,-1) && esJugadaLegal(q,o,d) && mov.size() < 3 && !esJaqueMate(q) && color(q.first, o) == jugador(q)) {
                        if (cantMovimientosPosibles(q,vMov,mov.size()) > 0) {
                            q = moverPieza(q,o,d);
                            mov.push_back(make_pair(o,d));
                        }
                        q.second = contrincante(jugador(q));
                        jugada = unicaMovidaPosibleDeJugador(q);
                        if(jugada.first != setCoord(-1,-1) && jugada.second != setCoord(-1,-1)){
                            q = moverPieza(q,jugada.first,jugada.second);
                            q.second = contrincante(jugador(q));
                        }
                    }
                }
            }
        }
    }
    return mov;
}






