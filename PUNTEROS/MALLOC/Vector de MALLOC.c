#include<stdio.h>
#include<stdlib.h>



int main()
{

    int * vector_1 ;


    int CAN , I  , J  , AUX ;


    printf(" ingrese tamanio vector  ");
    scanf("%d",&CAN);


    vector_1 = (int*)malloc( CAN*sizeof(int));

    printf("  \t\t %d  ANTES    %p \n" , CAN*sizeof (vector_1) ,vector_1 );


        for( I=0 ; I<CAN ; I++ ){
        printf("\n\t\t ingrese datos del vector\t");
        scanf("%d", (vector_1 + I));
        }

       /* ORDENAMIENTO */

        for(I=0 ; I<CAN-1 ; I++)
            for(J=0 ; J<CAN-I-1 ; J++)
                if( *(vector_1 + J) < *(vector_1 + J +1) ){

                     AUX                =  *(vector_1 + J);

                    *(vector_1 + J)     =  *(vector_1 + J + 1);

                    *(vector_1 + J + 1) =  AUX;

                }





        for(I=0 ; I<CAN ; I++){
             printf("\n\n  %d DESPUES  %p" , *(vector_1 + I) , (vector_1 + I));

           }



    printf("  \n\n\t\t %d DESPUES %p \n" , CAN*sizeof (vector_1) ,vector_1 );



        free(vector_1);


}
