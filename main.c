/*
TP00 – 2019
Título: Un Escaner Elemental
Grupo 4
Integrantes:
Bordón Pedro Nicolás	142084-7
Del Pin Matías			169009-7
Lucchesi Maximiliano	163312-0
Sánchez Javier			129462-3
*/

#include <stdio.h>
#include <stdbool.h>
#include "scanner.h"

int main()
{
    int errores = 0;
    int constantes = 0;
    int identificadores = 0;
    int token;

    FILE *f;

    f = fopen ("lexemas.txt","r");

    if(f == NULL)
    {
        printf("No se pudo leer el archivo.\n");
        return 1;
    }
    else
    {


       do
       {
            token = scanner(f);
            switch(token)
            {
                case CONSTANTE:
					printf("Constante entera\n");
					constantes ++;
					break;
                case IDENTIFICADOR:
					printf("Identificador\n");
					identificadores ++;
					break;
                case ERROR:
					printf("Error\n");
					errores ++;
					break;
            }
       }while(token == CONSTANTE || token == IDENTIFICADOR || token == ERROR);


        printf("----\nTotales:");
        printf("\nIdentificadores: %i\nConstantes enteras: %i\nErrores: %i\n",identificadores,constantes,errores);


    }


    return EXIT_SUCCESS;
}
