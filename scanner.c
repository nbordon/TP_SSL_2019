#include <stdio.h>
#include <stdbool.h>
#include "scanner.h"

static int tabla[8][5] =
{
/* TT  |     L  D  O  Es FDC */ 
/* 0  */    {1 ,2 ,3 ,0 ,7 },
/* 1  */    {1 ,1 ,4 ,4 ,4 },
/* 2  */    {5 ,2 ,5 ,5 ,5 },
/* 3  */    {6 ,6 ,3 ,6 ,6 },
/* 4+ */    {99,99,99,99,99},
/* 5+ */    {99,99,99,99,99},
/* 6+ */    {99,99,99,99,99},
/* 7+ */    {99,99,99,99,99},
};

int transicion (char a, FILE* f)
{

    if(isalpha(a)) return 0;

    if(isdigit(a)) return 1;

    if(isspace(a)) return 3;

    if(feof(f)) return 4;

    else return 2;

}

bool haytoken(int estado)
{
    if(estado == 4) return true;

    if(estado == 5) return true;

    if(estado == 6) return true;

    if(estado == 7) return true;

    else  return false;
};

TOKEN scanner (FILE* f)
{
    int estado	= 0;
	int columna	= 0;
    char a 		= '\0';
    do
    {
    	a = fgetc(f);
    	columna	= transicion(a,f);
    	estado	= tabla[estado][columna];

	}while(!haytoken(estado));

	if(estado == 4)
	{
        ungetc(a, f);
        return IDENTIFICADOR;
    }
	
    if(estado == 5)
	{
        ungetc(a, f);
        return CONSTANTE;
    }
	
    if(estado == 6)
        return FDC;
	
    if(estado == 7)
	{
        ungetc(a, f);
        return ERROR;
    }
}
