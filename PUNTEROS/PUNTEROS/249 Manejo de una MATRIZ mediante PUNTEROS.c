#include<stdio.h>
int main ()
{
    int matrix[][5] = { { 10 , 12 , 14 , 16 , 18},
                        { 20 , 22 , 24 , 26 , 28},
                        { 30 , 32 , 34 , 36 , 38},
                        { 40 , 42 , 44 , 46 , 48} };
    int i , k ;

    /*  USANDO ARRAYS */

    for(i=0 ; i<4 ; i++ ){
        printf("\n\n\t\t\t");
    for (k=0 ; k < 5 ; k++)
         printf("%5d" , matrix[i][k]);
    }

    /* USANDO PUNTEROS */

    printf("\n\n\n\n");
    for( i=0 ; i<4 ; i++) {
        printf("\n\n\t\t\t");
        for(k=0 ; k<5 ; k++ )
            printf("%5d", *(*(matrix + i)+k));
    }

    printf("\n\n");
    printf("matrix = %p matriz+3 = %p\n ",matrix , matrix+3);
    printf("*matrix = %p *matriz+3 = %p\n ",*matrix , *matrix+3);
    printf("**matrix = %d  *(*(matriz+3)+2) = %d\n ",**matrix , *(*(matrix+3)+2));




}

