#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5

struct persona {
char nombre[100];
unsigned int edad [1];

};
void CARGAR(struct persona [] , int );
//void ORDENAR(struct persona [] , int );
void MIRAR(struct persona [] , int );



int main()
{
    struct persona p [N];

    CARGAR(p,N);

   // ORDENAR(p,N);

    MIRAR(p,N);



}
void CARGAR(struct persona p [] , int L)
{
    int I;

       /* for(I=0 ; I<L ; I++)
        {
            p[I].edad=rand()%100+18;

        } */


      p[0].edad=20;







        strcpy(p[0].nombre,"josesito");
        strcpy(p[1].nombre,"pedrito");
        strcpy(p[2].nombre,"sanson");
        strcpy(p[3].nombre,"ricardo");
        strcpy(p[4].nombre,"rubencito");
        strcpy(p[5].nombre,"ernestito");
        strcpy(p[6].nombre,"davidcito");
        strcpy(p[7].nombre,"alejandro");
        strcpy(p[8].nombre,"che");
        strcpy(p[9].nombre,"trotsky");




}

/*void ORDENAR (struct persona p [] , int L) {

    int i, j;
    struct persona aux;


     for(i=0; i<L-1; i++) {
        for(j=0; j<L-i-1; j++) {
            if (p[j].edad > p[j+1].edad ) {

                aux      =  p[j];
                p[j]     =  p[j+1];
                p[j+1]   =  aux;


            }
        }
    }
}
*/
MIRAR (struct persona p [] , int L)
{

    /*int I;

    for(I=0 ; I<L ; I++)
    {

        printf("\t\t EDAD\t %d \t\t NOMBRE\t %s ",p[I].edad,p[I].nombre);

}*/


                printf("%d",p[0].edad );






}
