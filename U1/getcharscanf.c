#include<stdio.h>
int main()
{
       int A,B;  //REPRESENTACIONES CON PRINTF
       A=130;
       B=7;
       printf("\nDivision entera \t %d / %d =%d",A,B,A/B);
       printf("\nResto de Division Entera %d %% %d =%d",A,B,A%B);
       printf("\nDivision Real \t\t %d / %d =%.2f",A,B,(float) A/B);



       unsigned char J;        //distintos tipos de resultados con CHAR ver
       J='Ñ';
       printf("\n\n %10c %10d %10o %10X",J,J,J,J);



        int K,Z;
        K=2;
        Z=++K;

        int L,M;
        L=3;
        M=L++;         //preincremento y postincremento

        printf("\n\n\npreincremento %d , postincremento %d",Z,M);








   unsigned char R;
   printf("\n\n\tcaracter=");
   R=getchar();
   printf("ASCII=%d",R);





          float BASE,ALTURA,SUPERFICIE;
          printf("\n\n\nBASE=");
          scanf("%f",&BASE);
          printf("ALTURA=");
          scanf("%f",&ALTURA);            //uso de funcion scanf entrada de teclado
          SUPERFICIE=BASE*ALTURA/2;
          printf("SUPERFICIE=%.2f",SUPERFICIE);



























































            }
