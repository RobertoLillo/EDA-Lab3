#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/********** Estructuras **********/

/********** Prototipos **********/
int obtenerInformacionBasica(int *condiciones, int *jugador);
void obtenerInformacionCasillas(int cantidad, char *tipoCasilla);
void llenarTablero(int cantidad, int **tablero);
int tipoDePoder(int *jugador, int **tablero, char *tipoCasilla);
int stringToInt(char string[]);
