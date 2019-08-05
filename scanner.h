#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED


typedef enum
{	CONSTANTE=0,
	IDENTIFICADOR=1,
	ERROR=2,
	FDC=3,
} TOKEN;

TOKEN scanner (FILE* f);
int transicion(char a, FILE* f);
bool hayToken(int estado);


#endif // SCANNER_H_INCLUDED
