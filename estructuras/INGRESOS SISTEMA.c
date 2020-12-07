#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 3
#define F 3


struct fecha{
    int dia;
    int mes;
    int anio;
};

struct usuario {
	char email[100];
	struct fecha ingresos[F];
};

void usuario_mas_ingreso_mail(struct usuario[] , int );
void mails_ultima_fecha (struct usuario[] , int );
void ultima_conexion (struct usuario[] , int );
unsigned int DIAS(struct fecha);


int main()
{

    struct usuario USU [N];

    usuario_mas_ingreso_mail(USU , N);
    mails_ultima_fecha(USU , N);
    ultima_conexion(USU , N);









}

void usuario_mas_ingreso_mail(struct usuario USU [] , int L )
{
    int I ;
    int J ;
    int MAYOR=0 , POS=0 , cont=0 ;
    struct usuario AUX;

    /*INGRESOS*/

      for(I=0 ; I<L ; I++){
        for(J=0 ; J < F ; J++ ){
            USU[I].ingresos[J].dia=-1;
            USU[I].ingresos[J].mes=-1;
            USU[I].ingresos[J].anio=-1;
      }
   };


    for(I=0 ; I<L ; I++){

        printf("ingrese e-mail  : ");
        fflush(stdin);
        gets(USU[I].email);
        fflush(stdin);
        for(J=0 ; J<F ; J++){
            printf("ingrese fecha con formato DD-MM-AA  : ");
            scanf("%d-%d-%d",&USU[I].ingresos[J].dia , &USU[I].ingresos[J]. mes , &USU[I].ingresos[J].anio);

                    }


    }

    /*ORDENAMIENTO*/

    for(I=0 ; I<L-1 ; I++)
        for(J=0 ; J<J-I-1 ; J++)
            if(strcmp(USU[J].email , USU[J+1].email ) > 0){


                        AUX = USU[J];
                        USU[J] = USU[J+1];
                        USU[J+1] = AUX;

           }

           /* MAYOR INGRESO MAIL */

           for(I=1 ; I<L ; I++){

                if(strcmp(USU[I].email , USU[I-1].email )== 0 ){
                    cont++;
                    if(MAYOR<cont){
                        MAYOR = cont;
                        POS = I;
                    }

                   }
                else{cont=0;};
            };


            printf("\n\nel email del que mayor veces ingreso fue %s ", USU[POS].email);


}

void mails_ultima_fecha(struct usuario USU [] , int L )
{

    int I , J ;
    unsigned int ULTIMA_FECHA = 0 ;
    int UF;


    printf("\n\n\t mail \t\t %s \t\t ultima fecha %d-%d-%d\n\n", USU[0].email , USU[0].ingresos[F-1].dia , USU[0].ingresos[F-1]. mes , USU[0].ingresos[F-1].anio  );

    for(I=1 ; I<L ; I++){

        if(strcmp(USU[I].email , USU[I-1].email)!= 0){

             printf("\n\n\t mail \t\t %s \t\t ultima fecha %d-%d-%d\n\n", USU[I].email , USU[I].ingresos[F-1].dia , USU[I].ingresos[F-1]. mes , USU[I].ingresos[F-1].anio  );
                      }


                }

}



void ultima_conexion(struct usuario USU [] , int L )
{
    int I , J ;
    unsigned int MENOR_fecha =0 ;
    int POS_menor =0 ;





    for(I=0 ; I<L ; I++){
        if(DIAS(USU[I].ingresos[J]) > 0 ){
                    if(DIAS(USU[I].ingresos[F-1]) < MENOR_fecha ){
                        MENOR_fecha = DIAS(USU[I].ingresos[F-1]);
                        POS_menor = I ;

                    }
                 }
           }


    printf("el usuario que hace mas tiempo que no entra es %s\t\tfecha\t\t%d-%d-%d ",USU[POS_menor].email , USU[POS_menor].ingresos[F-1].dia ,USU[POS_menor].ingresos[F-1].mes , USU[POS_menor].ingresos[F-1].anio);
}


unsigned int DIAS (struct fecha date)
{
    long X;

    X=((date.anio*365) + (date.mes*31) + date.dia );

    return X;


}

