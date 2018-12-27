#include "supersmashboard.h"

int main()
{
    // Informacion basica para el juego
    int cantidadNodos;
    int condiciones[2]; // [Precio estrella, estrellas necesarias para ganar]
    int jugador[4];     // [Personalidad, Posicion, Monedas, Estrellas]
    cantidadNodos = obtenerInformacionBasica(condiciones, jugador);

    // Obtencion del tipo de cada nodo
    char tipoCasilla[cantidadNodos]; // [tipo, tipo, tipo, etc...]
    obtenerInformacionCasillas(cantidadNodos, tipoCasilla);

    // Matriz de adyacencia: 0 no hay conexion, 1 si hay conexion
    int i, j;
    int tablero[cantidadNodos][cantidadNodos];
    int *filas[cantidadNodos];
    for (i = 0; i < cantidadNodos; i++)
    {
        filas[i] = tablero[i];
    }
    llenarTablero(cantidadNodos, filas);

    imprimirMatrizAdyacencia(cantidadNodos, filas);

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

        int tokenInt, largo;
        char *token;
        char linea[100];
        fgets(linea, 100, punteroArchivo);
        for (i = 0; i < cantidad; i++)
        {
            fgets(linea, 100, punteroArchivo);
            token = strtok(linea, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            while (token != NULL)
            {
                largo = strlen(token);
                if (token[largo - 1] == '\n')
                {
                    token[largo - 1] = '\0';
                }
                tokenInt = stringToInt(token);
                tablero[i][tokenInt - 1] = 1;
                token = strtok(NULL, " ");
            }
        }
    }
    else
    {
        printf("No se pudo leer el archivo\n");
        fclose(punteroArchivo);
    }
}

void tipoDePoder(int cantidad, int *jugador, int **tablero, char *tipoCasilla)
{
    // cantidad: cantidad de nodos del tablero
    // jugador: [personalidad, posicion, monedas, estrellas]
    // tablero: matriz Cantidad X Cantidad
    // tipoCasilla: [tipo, tipo, tipo, etc...]

    int numeroProbabilidad = (rand() % 100) + 1; // Numeros del 1 al 100

    if (numeroProbabilidad <= 30)
    {
        // El jugador gana una moneda
        jugador[2] = jugador[2] + 1; 
    }
    else if (numeroProbabilidad >= 31 && numeroProbabilidad <= 40)
    {
        // El jugador se teletransporta
        int posicionNueva;
        int verificador = 0;
        while (verificador = 0)
        {
            posicionNueva = (rand() % cantidad) + 1; // Numero de 1 a cantidad
            if (posicionNueva != jugador[1])
            {
                jugador[1] = posicionNueva;
                verificador = 1;
            }
        }
    }
    else if (numeroProbabilidad == 41)
    {
        // EL jugador gana una estrella
        jugador[3] = jugador[3] + 1;
    }
    else if (numeroProbabilidad >= 42 && numeroProbabilidad <= 46)
    {
        // Se cambia el sentido de los caminos
        int i, j;
        int tableroAux[cantidad][cantidad];
        for (i = 0; i < cantidad; i++)
        {
            for (j = 0; j < cantidad;j++)
            {
                tableroAux[j][i] = tablero[i][j];
            }
        }
        tablero = tableroAux;
    }
    else if (numeroProbabilidad >= 47 && numeroProbabilidad <= 51)
    {
        // Se agrega un camino
        int nodo1, nodo2;
        int verificador = 0;
        while (verificador = 0)
        {
            nodo1 = (rand() % cantidad) + 1; // Numero de 1 a cantidad
            nodo2 = (rand() % cantidad) + 1; // Numero de 1 a cantidad
            if (tablero[nodo1][nodo2] == 0)
            {
                tablero[nodo1][nodo2] = 1;
            }
        }
    }
    else if (numeroProbabilidad >= 52 && numeroProbabilidad <= 56)
    {
        // Se elimina un camino
        int i, nodo1, nodo2, cantidadCaminos, contador;
        int verificador = 0;
        while (verificador = 0)
        {
            cantidadCaminos = 0;
            nodo1 = (rand() % cantidad) + 1; // Numero de 1 a cantidad
            for (i = 0; i < cantidad; i++)
            {
                if (tablero[nodo1][i] == 1)
                {
                    cantidadCaminos++;
                }
            }
            if (cantidadCaminos > 0)
            {
                contador = (rand() % cantidadCaminos) + 1;
                for (i = 0; i < cantidad; i++)
                {
                    if (tablero[nodo1][i] == 1)
                    {
                        contador--;
                    }
                    if (contador == 0)
                    {
                        nodo2 = i;
                    }
                }
                tablero[nodo1][nodo2] = 0;
                verificador = 1;
            }
        }
    }
    else if (numeroProbabilidad >= 57 && numeroProbabilidad <= 76)
    {
        // Se intercambia el tipo de dos casillas
        char tipoAux;
        int tipo1, tipo2;
        int verificador = 0;
        while (verificador = 0)
        {
            tipo1 = (rand() % cantidad) + 1;
            tipo2 = (rand() % cantidad) + 1;
            if (tipo1 != tipo2)
            {
                tipoAux = tipoCasilla[tipo2];
                tipoCasilla[tipo2] = tipoCasilla[tipo1];
                tipoCasilla[tipo1] = tipoAux;
                verificador = 1; 
            }
        }
    }
    else // (77 <= numeroProbabilidad <= 100)
    {
        // No ocurre ningun cambio
    }
}

void imprimirMatrizAdyacencia(int cantidad, int **tablero) 
{
    int i, j;
    printf("\nMatriz de adyancencia:\n  1 2 3 4 5 6 7 8 9 0 1\n");
    for (i = 0; i < cantidad; i++)
    {
        if (i < 9)
        {
            printf("%d ", i + 1);
        }
        else
        {
            printf("%d ", i - 9);
        }

        for (j = 0; j < cantidad; j++)
        {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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
