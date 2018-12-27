#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/********** Estructuras **********/

/********** Prototipos **********/
int obtenerInformacionBasica(int *condiciones, int *jugador);
void obtenerInformacionCasillas(int cantidad, char *tipoCasilla);
void llenarTablero(int cantidad, int **tablero);
void tipoDePoder(int cantidad, int *jugador, int **tablero, char *tipoCasilla);
void imprimirMatrizAdyacencia(int cantidad, int **tablero);
int stringToInt(char string[]);