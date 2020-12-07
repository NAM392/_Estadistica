/*   PUNTEROS A STRING */

#include<stdio.h>
void leer ( char*);
void imprimir( char*);

int main ()
{

    char palabra[10];
    leer ( palabra );
    imprimir ( palabra );

}
void leer ( char * frase)
{
    scanf("%s", frase);
}
void imprimir ( char * frase)
{
    printf("%s", frase );
}
