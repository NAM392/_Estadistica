

  /*   ESTADISTICA  */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>




int  INGRESO    ( int * , int );
int  ORDEN      ( int * , int );
int  MODA_NA    ( int * , int );
int  MAXIMO     ( int * , int );
int  MODAL_fi   ( int * , int );
int  BIMODAL   ( int * , int );
int  MINIMO     ( int * , int );
float  MAXIMO_FL  ( float * , int );
float  MINIMO_FL  ( float * , int );
int  MEDIANA    ( int );
void  TABLA     ( int * , int );
void AGRUPADOS   ( );
void NO_AGRUPADOS( );


int main()
{

    int OPCION;

    printf("\n\n\t\t\t\t\t UNIVERSIDAD TECNOLOGICA NACIONAL F.R. HAEDO \n  ");

    printf("\n\n\t\t\t\t\t   TECNICATURA UNIVERSITARIA EN PROGRAMACION \n  ");

    printf("\n\n\t\t\t\t\t\t TRABAJO PRACTICO DE ESTADISTICA \n  ");

    printf("\n\n\t\t\t ALUMNO : NICOLAS ALFREDO MINNICELLI \n  ");

    printf("\n\n\t\t\t LEGAJO : 25230 \n  ");

    printf("\n\n\t\t\t DOCENTE: LIC. VILMA GIUDICE \n\n\n  ");

    printf("\n\n\t\t\t INGRESE OPCION  -:  1 DATOS NO  AGRUPADOS :-  \n  ");

    printf("\n\n\t\t\t INGRESE OPCION  -:  2 DATOS AGRUPADOS :-  \n ");

    printf("\n\n\t\t\t\t\t LUEGO OPRIMA ENTER  \n ");

    scanf("%d",&OPCION);

    if(OPCION == 1){NO_AGRUPADOS();};
    if(OPCION == 2){AGRUPADOS();}







}


int INGRESO( int*VEC , int C )
{
    int I;

   for( I=0 ; I<C ; I++ ){
        printf("\n\t\t INGRESE EL DATO N %d\t", I+1 );
        scanf("%d", (VEC + I));
        }

    printf("  \n\n  ");

  /*  ESTA FUNCION ES PARA INGRESAR LOS DATOS DE LAS MUESTRAS NO AGRUPADAS */

}


int ORDEN( int * VEC , int C )
{
    int I , J , AUX;


   for(I=0 ; I<C-1 ; I++)
            for(J=0 ; J<C-I-1 ; J++)
                if( *(VEC + J) > *(VEC + J +1) ){

                     AUX           =  *(VEC + J);
                    *(VEC + J)     =  *(VEC + J + 1);
                    *(VEC + J + 1) =   AUX;
                }

         printf("\n\n\n");


         printf("\t\t\t\t\t    **DATOS ORDENADOS**\n\n");

                                /* MUESTRA */
        for(I=0 ; I<C ; I++){
            printf("\t\t\t\t\t\t %d.  %d \n\n" , I+1 ,  *(VEC + I));

           }
                  /*SE ORDENAN LOS DATOS DEL VECTOR DE LA MUESTRA Y LOS IMPRIME EN PANTALLA*/



}

int MODA_NA( int * VEC , int  C )
{

    int cont = 0 , cont_MODA = 0 , MODA = 0 , I;


    for(I=1 ; I<C ; I++){
        if( *(VEC+I) == *((VEC+I)-1) ){
            cont++;
            if(cont > cont_MODA){               /*BUSCA Y RETORNA LA MODA DE LOS DATOS NO AGRUPADOS */
                cont_MODA = cont;
                MODA = *(VEC+I);
            }
        }
        else{cont=0;};
    };


   return MODA;



}

int MAXIMO( int * VEC , int  C )
{
    int I , mayor=0 ;

    for(I=0 ; I<C ; I++){
        if( mayor < *(VEC+I) ){              /*BUSCA Y RETORNA EL DATO MAXIMO EN LAS MUESTRAS NO AGRUPADAS */
            mayor= *(VEC+I);
        }

    }

    return mayor;





}

int MINIMO ( int*VEC , int  C )
{
    int I , menor ;

    for(I=0 ; I<C ; I++){
        if( (*(VEC+I)) < menor){          /*BUSCA Y RETORNA EL DATO MINIMO EN LAS MUESTRAS NO AGRUPADAS */
            menor = *(VEC+I);

        }

    }

    return menor;

}

int MEDIANA( int C )
{
    int m , aux , div ;


    if ( C%2 == 0 ){
          aux = (C/2) + (C/2) + 1 ;     /*BUSCA Y RETORNA LA MEDIANA EN LAS MUESTRAS NO AGRUPADAS */
          m = aux/2;
          return m-1;                   /*DIFIERE ENTRE LOS TAMANOS DE LAS MUESTRAS PARES DE LAS IMPARES */
    }
    else {
           m =(C + 1) / 2 ;
           return m-1 ;

    };
}

int MODAL_fi( int * VEC , int  C )
{

    int cont = 0 , cont_MODA = 0 , MODA = 0 , I , X ;




    for(I=1 ; I<C ; I++){


        if( cont_MODA < (*(VEC+I))  ){

            cont_MODA = (*(VEC+I)) ;             /*SE GUARDA EL NUMERO CUYA FRECUENCIA SEA MAYOR*/
            MODA = I ;                            /*SE GUARDA I , ESTA NOS SERVIRA PARA TODAS LAS OPERACIONES QUE SE NECESITES*/

        }

    };



   return MODA;



}

int BIMODAL( int * VEC , int  C ){






    int cont = 0 , cont_MODA = 0 , MODA = 0 , I , X ;




    for(I=1 ; I<C ; I++){


        if( cont_MODA < (*(VEC+I))  ){

            cont_MODA = (*(VEC+I)) ;             /*SE GUARDA EL NUMERO CUYA FRECUENCIA SEA MAYOR*/
            MODA = I ;                            /*SE GUARDA I , ESTA NOS SERVIRA PARA TODAS LAS OPERACIONES QUE SE NECESITES*/

        }

    };



    for(I=1 ; I<C ; I++){
            if(MODA == (*(VEC+I))){
               cont++;
               }
    }

    if(cont==1){
        return 2;
    }
    else{
        return 0;
    };









}
float VARIANZA( float*MX , int*fi , float MC , int C , int CAN)
{


    int I;

    float V;

    for(I=0 ; I<C ; I++){
       V=  (pow(((*(MX + I )) - MC) , 2)) * (*(fi+I)) + V ;    /*FUNCION POW SIRVE PARA REALIZAR POTENCIACIONES*/

    }

    V=V/(CAN-1) ;

    return V;




}

float MODA_AGRUPADOS(int AB , int CD ,float INICIO , float FIN  )
{
    float MO=0;

    MO = ((AB*FIN) + (CD*INICIO)) / (CD + AB) ;
    return MO ;

}

float MEDIANA_AGRUPADOS(float INICIO , int BC , int F_PRE , float LON )
{

    float ME=0;

    ME= INICIO + (((float)BC/(float)F_PRE)*LON );  /*SE CASTEA LAS VARIABLES DE TIPO INT A FLOAT PARA MAYOR EXACTITUD DEL RESULTADO*/
    return ME;


}
float MAXIMO_FL( float * VEC , int  C )
{
    int I ;
    float mayor=0 ;

    for(I=0 ; I<C ; I++){               /*SE CREO FUNCION MAXIMO_FL PARA ENCONTRAR EL MAXIMO DE LAS MUESTRAS DE FLOAT*/
        if( mayor < *(VEC+I) ){
            mayor= *(VEC+I);

        }

    }
    return mayor;
}

float MINIMO_FL( float*VEC , int  C )
{
    int I ;
    float  menor ;

    for(I=0 ; I<C ; I++){
        if( *(VEC+I) < menor){     /*SE CREO FUNCION MINIMO_FL PARA ENCONTRAR EL MINIMO DE LAS MUESTRAS DE FLOAT*/
            menor = *(VEC+I);

        }

    }
    return menor;
}


void TABLA(int*VEC , int  C )  /*VER PORQUE NO ME SALE UNIMODAL , BIMODAL ETC*/
{


        int * MEDITA;

        int  I  , J  , cont=1 , ACUM=0  , AUX , MEDIA=0 , p , l , k , ME=0;

        MEDITA= (int*)malloc(C*sizeof(int));


       printf("\n\n\t\tDATOS\t\tfi\t\tFi\t\tfri\t\tFri\n" );


        for(I=0 ; I<C ; I++){
           if( (*(VEC + I ))  == (*(VEC + (I+1) ))){
                    cont ++;

                    (*(MEDITA + I )) = cont;


            }
            else if(cont>1){
                    MEDIA = ((*(VEC + I )) * cont ) +  MEDIA ;
                     printf("\n\n\t\t%d\t\t%d\t\t%d\t\t%d/%d\t\t%d/%d\n",(*(VEC + I )) , cont , l=ACUM=ACUM+cont , cont , C , l , C , (*(MEDITA + I )) = cont );

                    cont=1 ;

            }
            else {
                    MEDIA = (*(VEC + I )) + MEDIA;
                    cont=1;
                    printf("\n\n\t\t%d\t\t%d\t\t%d\t\t%d/%d\t\t%d/%d\n",(*(VEC + I )) , 1 , k=ACUM=ACUM+1 , 1 , C , k , C , (*(MEDITA + I )) = cont );
            };

        };

        printf("\t\t\n\n \n\n LA  MEDIA ES  %d \n\n\n  ", ME=MEDIA / C );








}

void AGRUPADOS()
{

    float * vector_1 ;

    int * fi ;
                                            /*DECLARACION DE PUNTEROS*/
    int * Fi ;

    float * MAR_CLASS ;

    float * MIN_CLASE ;

    float * MAX_CLASE ;



    int  CONT=0 , ACUM=0 , l  , CAN  , L ;

    int   I ,  J ,  CAN_GRUPO  , GUARDAR=0 , V=0 , MODAL , POSMODAL ,
    FREC_PREMED , PREMODAL , AB , CD , BC , cont=0   ,  X   ;

    float LON_C ,  AUX , RANGO   , MARCA_CLASE , ALFA=0 , MAX , MIN ,
        BETA=0 , EQUIS=0 , K , NUM , E , MED_MARC_CLASS , VAR , MO , INICIO_MODAL , FIN_MODAL , ME ;




    printf(" \n\t\t INGRESE TAMANO DE LA MUESTRA  ");
    scanf("%d",&CAN);

     printf("\n\t\t INGRESE CANTIDAD DE GRUPOS  ");
     scanf("%d",&CAN_GRUPO);


                                                /*PUNTEROS DE MEMORIA DINAMICA*/

     vector_1    =  (float*)malloc( CAN*sizeof(float));   /*VECTOR PRINCIPAL QUE GUARDA TODOS LOS DATOS*/

     fi          =  (int*)malloc( CAN_GRUPO*sizeof(int));   /*VECTOR DE LA FRECUENCIA */

     Fi          =  (int*)malloc( CAN_GRUPO*sizeof(int));    /*VECTOR DE LA FRECUENCIA ACUMULADA*/

     MAR_CLASS   =  (float*)malloc( CAN_GRUPO*sizeof(float));  /*VECTOR DE LA MARCA DE CLASE*/

     MAX_CLASE   =  (float*)malloc( CAN_GRUPO*sizeof(float));   /*VECTOR DE LOS FINALES DE CADA CLASE*/

     MIN_CLASE   =  (float*)malloc( CAN_GRUPO*sizeof(float));   /*VECTOR DE LOS PRINCIPIOS DE CADA CLASE*/


        printf("\n\t\tINGRESE DATOS CON FORMATO 1.1 ");
        printf("\n\n\n");

        for( I=0 ; I<CAN ; I++ ){
        printf("\n\t\t INGRESE EL DATO N %d\t", I+1 );
        scanf("%f", (vector_1 + I));
        }

       /* ORDENAMIENTO */

        for(I=0 ; I<CAN-1 ; I++)
            for(J=0 ; J<CAN-I-1 ; J++)
                if( *(vector_1 + J) > *(vector_1 + J +1) ){

                     AUX                =  *(vector_1 + J);

                    *(vector_1 + J)     =  *(vector_1 + J + 1);

                    *(vector_1 + J + 1) =  AUX;

                }



         printf("\n\n\n");


         printf("\t\t\t\t\t    **DATOS ORDENADOS**\n\n");

                                /* MUESTRA ORDENADA */
        for(I=0 ; I<CAN ; I++){
            printf("\t\t\t\t\t\t %d.  %.2f \n\n" , I+1 ,  *(vector_1 + I));

           }




     MAX = (MAXIMO_FL( vector_1 , CAN ) );
     MIN = (MINIMO_FL( vector_1 , CAN) );

     RANGO = (MAX - MIN);



     LON_C = RANGO / (CAN_GRUPO - 1) ;


    ALFA = MIN;
    BETA = MIN + LON_C;
    MARCA_CLASE=((MIN+BETA)/2);
    E=0.01;             /* VARIABLE "E" DE ERROR DE FLOAT */

    printf("\n\n\t\tCLASES\t\t\tMARCA DE CLASE\t\tfi\t\tFi\t\tfri\t\tFri  \n" );

    for(I=0 ; I<CAN ; I++){

        for(K=0 ; K< (*(vector_1 +  CAN_GRUPO-1)) ; K=K+0.1 ){   /* K COMPARA DE A DECIMAS PARA MAYOR EXACTITUD EN CASO DE DECIMALES*/

            NUM =(*(vector_1 + I)) - K ;

            if(NUM<E && NUM>-E && cont!= CAN_GRUPO){   /* POR DEFICIENCIAS DEL LENGUAJE C ESTE NO PERMITE DISTINGUIR CON EXACTITUD ENTRE UN FLOAT == FLOAT , POR ENDE SE DEBE USAR UNA VARIABLE DE ERROR "E" */

                    cont++;       /*VARIABLE QUE NOS PERMITE CONTROLAR QUE NO SE EXCEDA EN LA CANTIDAD SOLICITADA DE CLASES*/


                for(l=0 ; l<CAN ; l++){

                    if((*(vector_1 + l)) >= ALFA && (*(vector_1 + l)) < BETA ){   /* PERMITE DISTINGUIR ENTRE LOS NUMEROS QUE SE ENCUENTRAN DENTRO Y FUERA DE LA CLASE DETERMINADA*/

                            CONT ++;
                            ACUM++ ;

                        }

                };

            printf("\n\n\t %d [ %.2f  a %.2f ) \t\t\t%.2f\t\t%d\t\t%d\t\t%d / %d\t\t%d / %d \n"  , cont , ALFA , BETA , MARCA_CLASE , ACUM-GUARDAR , CONT , (ACUM-GUARDAR) ,CAN , CONT , CAN ,
            (*( MAX_CLASE + V )) = BETA  , (*( MIN_CLASE + V )) = ALFA  ,  (*(fi+V))= (ACUM-GUARDAR)  , (*(Fi + V)) = CONT ,  (*(MAR_CLASS + V)) = MARCA_CLASE ) ;

            V++;  /*ESTE ES LA VARIABLE QUE SUMA A LOS VECTORES DE PUNTEROS LA CANTIDAD DE GRUPOS  */



            EQUIS= EQUIS + MARCA_CLASE*(ACUM-GUARDAR);


            ALFA=BETA;                  /*COMIENZO DE LA CLASE*/
            BETA=BETA + LON_C;          /*FIN DE LA CLASE*/
            MARCA_CLASE=MARCA_CLASE+LON_C;
            GUARDAR=ACUM;                  /*LA FUNCION GUARDAR ES LA QUE NOS AYUDA A RESTAR Y ASI OBTENER fi*/

        }

        }
    }


       if((BIMODAL (fi , V )) == 2){



      printf("\n\n\n");

      printf("\n\t\t\t\t\t# EL RANGO ES %.2f  \n\n",RANGO);

      printf("\n\t\t\t\t\t# EL MINIMO ES %.2f  \n\n",MIN);

      printf("\n\t\t\t\t\t# EL MAXIMO ES %.2f  \n\n",MAX);

      printf("\n\t\t\t\t\t# LA LONGITUD DE CLASE ES  %.2f\n\n",LON_C );



    printf("\n\t\t\t\t\t# LA MEDIA DE LA MARCA DE CLASES ES  %.2f  \n\n  " ,MED_MARC_CLASS = EQUIS/CAN);




    MODAL =(*(fi + MODAL_fi(fi,V)));
    POSMODAL=(*(fi + ((MODAL_fi(fi,V))+1)));
    PREMODAL=(*(fi + ((MODAL_fi(fi,V))-1)));

    AB= MODAL - PREMODAL ;
    CD= MODAL - POSMODAL ;


    INICIO_MODAL = (*(MIN_CLASE + MODAL_fi(fi,V)));

    FIN_MODAL = (*(MAX_CLASE + MODAL_fi(fi,V)));


    FREC_PREMED = (*(Fi + MODAL_fi(fi,V))) - (*(Fi + ((MODAL_fi(fi,V))-1))) ;

    BC = (CAN/2)-FREC_PREMED;

    printf("\n\t\t\t\t\t# LA FRECUENCIA PREMEDIANA ES   %d  \n\n " , FREC_PREMED );


    printf("\n\n\t  [ %.2f  a %.2f ) \t\t\t%.2f\t\t%d\t\tPREMODAL \n"  , (*(MIN_CLASE + ((MODAL_fi(fi,V))-1))) , (*(MAX_CLASE + ((MODAL_fi(fi,V))-1)))  ,  (*(MAR_CLASS + ((MODAL_fi(fi,V))-1))) , PREMODAL  );

    printf("\n\n\t  [ %.2f  a %.2f ) \t\t\t%.2f\t\t%d\t\tMODAL \n"  , INICIO_MODAL , FIN_MODAL  , (*(MAR_CLASS + ((MODAL_fi(fi,V)))))  , (*(fi + MODAL_fi(fi,V))) ) ;

    printf("\n\n\t  [ %.2f  a %.2f ) \t\t\t%.2f\t\t%d\t\tPOSMODAL \n"  , (*(MIN_CLASE + ((MODAL_fi(fi,V))+1))) , (*(MAX_CLASE + ((MODAL_fi(fi,V))+1)))  , (*(MAR_CLASS + ((MODAL_fi(fi,V))+1)))  , POSMODAL );

    printf("\n\n" );


    VAR = VARIANZA( MAR_CLASS , fi , MED_MARC_CLASS , CAN_GRUPO , CAN ); /* INVOCACION FUNCION VARIANZA */

    printf("\n\t\t\t\t\t# LA VARIANZA ES   %.2f \n\n " , VAR);


    printf("\n\t\t\t\t\t# EL DESVIO STANDARD ES  %.2f  \n\n " , sqrt(VAR));  /*FUNCION SQRT ES RAIZ CUADRADA*/

    MO = MODA_AGRUPADOS(AB ,CD ,INICIO_MODAL , FIN_MODAL ); /* INVOCACION FUNCION MODA_AGRUPADOS */


    printf("\n\t\t\t\t\t# LA MODA ES  %.2f  \n\n " , MO );


    ME=MEDIANA_AGRUPADOS(INICIO_MODAL , BC , FREC_PREMED , LON_C ); /* INVOCACION FUNCION MEDIANA_AGRUPADOS */


    printf("\n\t\t\t\t\t# LA MEDIANA ES  %.2f  \n\n " , ME );

    printf("\n\n\n");

    printf("OPRIMA ENTER PARA SALIR");

    fflush(stdin);


    getchar();

    free(MIN_CLASE) , free(MAX_CLASE) , free(MAR_CLASS) , free(vector_1) , free(Fi) , free(fi);


    }
    else {
        printf("\n\n **LA MUESTRA ES BIMODAL**\t");
        printf("\n\n\n");
        printf("OPRIMA ENTER PARA SALIR");
        fflush(stdin);
        getchar();

    }

}

void NO_AGRUPADOS()
{
    int * vector_1 ;


    int CAN , I  , J  ,MAX , MIN ;


    printf(" \n\t\t INGRESE TAMANO DE LA MUESTRA  ");
    scanf("%d",&CAN);


    vector_1 = (int*)malloc( CAN*sizeof(int));


    INGRESO( vector_1 , CAN);
    ORDEN  ( vector_1 , CAN);


    printf("\n\t\t\t\t\t# LA MUESTRA TIENE  %d  ELEMENTOS  \n\n " , CAN );
    printf("\n\t\t\t\t\t# LA MODA ES %d  \n\n " , MODA_NA( vector_1 , CAN) );
    printf("\n\t\t\t\t\t# EL MINIMO ES %d  \n\n " , MIN = (MINIMO( vector_1 , CAN) ) );
    printf("\n\t\t\t\t\t# EL MAXIMO ES %d  \n\n " , MAX = (MAXIMO( vector_1 , CAN) ) );
    printf("\n\t\t\t\t\t# EL RANGO ES %d  \n\n " , MAX-MIN );
    printf("\n\t\t\t\t\t# LA MEDIANA ES %d Y SE ENCUENTRA EN LA POSICION %d  \n\n " , *(vector_1 +(MEDIANA ( CAN ) )) , (MEDIANA ( CAN ) +1 ) );

    printf("\n\n\n");

    TABLA  ( vector_1 , CAN);

    printf("OPRIMA ENTER PARA SALIR");

    fflush(stdin);

    getchar();

    free(vector_1);

}

