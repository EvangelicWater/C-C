#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

#define CANTIDAD_ALUMNOS 5
#define CANTIDAD_MATERIAS 5
#define MAXIMA_CALIFICACION 100
#define MINIMA_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100
int main()
{
    int x;
    printf("+----------");
    for (x = 0; x < CANTIDAD_MATERIAS + 1; x++)
    {
        printf("+--------");
    }
    printf("+\n");
}

