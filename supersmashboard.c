#include "supersmashboard.h"

int main()
{

    int cantidadNodos;
    int condiciones[2]; // [Precio estrella, estrellas necesarias para ganar]
    int jugador[4];     // [Personalidad, Posicion, Monedas, Estrellas]
    cantidadNodos = obtenerInformacionBasica(condiciones, jugador);

    char tipoCasilla[cantidadNodos]; // [tipo, tipo, tipo, etc...]
    obtenerInformacionCasillas(cantidadNodos, tipoCasilla);

    int i;
    int tablero[cantidadNodos][cantidadNodos];
    int *filas[cantidadNodos];
    for (i = 0; i < cantidadNodos; i++)
    {
        filas[i] = tablero[i];
    }

    llenarTablero(cantidadNodos, filas);

    return 0;
}

int obtenerInformacionBasica(int *condiciones, int *jugador)
{
    FILE *punteroArchivo = fopen("tablero.in", "r");

    if (punteroArchivo)
    {
        int cantidad = 0;
        char linea[100];
        fscanf(punteroArchivo, "%i %i %i\n", &condiciones[0], &condiciones[1], &jugador[0]);

        while (!feof(punteroArchivo))
        {
            fgets(linea, 100, punteroArchivo);
            cantidad++;
        }

        fclose(punteroArchivo);
        return cantidad;
    }
    else
    {
        printf("No se pudo leer el archivo\n");
        fclose(punteroArchivo);
        return 0;
    }
}

void obtenerInformacionCasillas(int cantidad, char *tipoCasilla)
{
    FILE *punteroArchivo = fopen("tablero.in", "r");

    if (punteroArchivo)
    {
        int i;
        char linea[100];
        fgets(linea, 100, punteroArchivo);

        for (i = 0; i < cantidad; i++)
        {
            fgets(linea, 100, punteroArchivo);
            if (i < 9)
            {
                tipoCasilla[i] = linea[2];
            }
            else
            {
                tipoCasilla[i] = linea[3];
            }
        }

        fclose(punteroArchivo);
    }
    else
    {
        printf("No se pudo leer el archivo\n");
        fclose(punteroArchivo);
    }
}

void llenarTablero(int cantidad, int **tablero)
{
    FILE *punteroArchivo = fopen("tablero.in", "r");

    if (punteroArchivo)
    {
        int i, j;
        
        for (i = 0; i < cantidad; i++)
        {
            for (j = 0; j < cantidad; j++)
            {
                tablero[i][j] = 0;
            }
        }

        int tokenInt;
        char *token;
        char linea[100];
        fgets(linea, 100, punteroArchivo);
        for (i = 0; i < cantidad; i++)
        {
            fgets(linea, 100, punteroArchivo);
            token = strtok(linea, " ");
            printf("Nodo: %s\n", token);
            token = strtok(NULL, " ");
            printf("Tipo: %s\n", token);
            while (token != NULL)
            {
                token = strtok(NULL, " ");
                printf("Nodo sig: %s\n", token);
                tokenInt = stringToInt(token);
                printf("Nodo sig int: %d\n", tokenInt);
                tablero[i][tokenInt - 1] = 1;
            }
            printf("llegue\n");
            
        }
    }
    else
    {
        printf("No se pudo leer el archivo\n");
        fclose(punteroArchivo);
        return 0;
    }
}

int stringToInt(char string[])
{
    int i, numero;

    numero = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        numero = numero * 10 + string[i] - '0';
    }

    return numero;
}
