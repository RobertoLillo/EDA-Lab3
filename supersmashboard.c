#include "supersmashboard.h"

int main() {

    int cantidadNodos;
    int condiciones[2]; // [Precio estrella, estrellas necesarias para ganar]
    int jugador[4];     // [Personalidad, Posicion, Monedas, Estrellas]
    cantidadNodos = obtenerInformacionBasica(condiciones, jugador);

    printf("Cantidad: %i, Condiciones: %i &i, Jugador: %i", cantidadNodos, condiciones[0], condiciones[1], jugador[0]);

    return 0;
}

int obtenerInformacionBasica(int* condiciones, int* jugador) {
    FILE* punteroArchivo = fopen("tablero.in", "r");
    int cantidad;
    if (punteroArchivo) {
        fscanf(punteroArchivo, "%i %i %i\n", &condiciones[0], &condiciones[1], &jugador[0]);

        while (!feof(punteroArchivo)) {
            cantidad++;
        }

        return cantidad;

    } else {
        printf("No se pudo leer el archivo\n");
        return 0;
    }
}
