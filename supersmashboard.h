#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/********** Estructuras **********/
typedef struct Nodo {
    int casilla;
    struct Nodo *sgte;
} nodo;

typedef struct Lista {
    int largo;
    nodo *inicio;
    struct Lista *sgte;
    struct Lista *ant;
} lista;

typedef struct {
    int alto;
    int ancho;
    int cantidadDeListas;
    lista *matrix;
} matriz;

/********** Prototipos **********/
int obtenerInformacionBasica(int *condiciones, int *jugador);
void obtenerInformacionCasillas(int cantidad, char *tipoCasilla);
void llenarTablero(int cantidad, int **tablero);
void buscarPosicionInicial(int cantidad, char *tipoCasilla, int *jugador);
void tipoDeEfecto(int cantidad, int *jugador, int **tablero, char *tipoCasilla);
void imprimirDatosJuego(int cantidad, int *condiciones);
void imprimirDatosJugador(int *jugador);
void imprimirMatrizAdyacencia(int cantidad, int **tablero);
void imprimirTiposCasilla(int cantidad, char *tipoCasilla);
int stringToInt(char string[]);
void insertarEnLista(lista *actual, int elemento);
lista borrarLista(lista actual);
void imprimirLista(nodo *lista);
matriz insertarListaEnMatriz(matriz actual, lista *ingresar);