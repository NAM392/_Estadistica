#include<stdio.h>
#include<string.h>

#define CH 50

#define PAT 10

#define VIAJE 5


struct fecha{
    int DIA;
    int MES;
    int ANIO;

};

struct viajecamion {
	char patente[PAT];
	char ciudad_origen[CH];
	char ciudad_destino[CH];
	float peso_transportado;
	struct fecha fecha_viaje;
};



void ingreso( struct viajecamion[] , int );
void muestra_patentes( struct viajecamion   [] , int );
void mas_viaje_realizado( struct viajecamion[] , int );
void muestra_viaje_fecha( struct viajecamion[] , int );
unsigned int DIAS ( struct fecha) ;


int main()
{
    struct viajecamion CAMION [VIAJE];

    ingreso( CAMION, VIAJE );
    muestra_patentes( CAMION , VIAJE );
    mas_viaje_realizado( CAMION , VIAJE );
    muestra_viaje_fecha( CAMION , VIAJE );


}


void ingreso( struct viajecamion CAMION[] , int VC )
{
    int I;

    for(I=0 ; I<VC ; I++)
        {
            printf("\n\n");
            fflush(stdin);
            printf("INGRESE PATENTE  : ");
            gets(CAMION[I].patente);
            fflush(stdin);
            printf("INGRESE C. ORIGEN  : ");
            gets(CAMION[I].ciudad_origen);
            fflush(stdin);
            printf("INGRESE C.DESTINO  : ");
            gets(CAMION[I].ciudad_destino);
            fflush(stdin);
            printf("INGRESE PESO TRANSPORTADO  : ");
            scanf("%f",&CAMION[I].peso_transportado);
            printf("INGRESE FECHA FORMATO DD-MM-AA  : ");
            scanf("%d-%d-%d",&CAMION[I].fecha_viaje.DIA , &CAMION[I].fecha_viaje.MES ,&CAMION[I].fecha_viaje.ANIO );

        }


}
void muestra_patentes( struct viajecamion CAMION[] , int VC )
{
    struct viajecamion AUX;
    int I , J ;
    int cont=0;

    for(I=0 ; I<VC-1 ; I++)
        for(J=0 ; J<VC-I-1 ; J++)
            if(strcmp(CAMION[J].patente , CAMION[J+1].patente) > 0)

                    {
                        AUX         =  CAMION[J];
                        CAMION[J]   =  CAMION[J+1];
                        CAMION[J+1] =  AUX;

                    };


    printf("\n\n\t\tPATENTE\t\t%s\t\t\n",CAMION[0].patente);

    for(I=1 ; I<VC ; I++){


        if(strcmp(CAMION[I].patente , CAMION[I-1].patente)!= 0 ){

            printf("\n\n\t\tPATENTE\t\t%s\t\t\n",CAMION[I].patente);

        }

   }

}
void mas_viaje_realizado( struct viajecamion CAMION[] , int VC )
{

    int I;
    int cont=0;
    int MAYOR=0;
    int POS=0;



      for(I=1 ; I<VC ; I++){

         if(strcmp(CAMION[I].patente , CAMION[I-1].patente)== 0 ){
                cont++;
            if( MAYOR < cont){

                MAYOR   = cont;
                  POS   =  I;
                }
           }
         else {cont=0;};

     }

     printf("\n\n\tel numero que mas se repite es %s\n\n",CAMION[POS].patente);






}
unsigned int DIAS(struct fecha date)
{

    long X ;
    X= 365*date.ANIO + 31*date.MES + date.DIA ;
    return X;



}


void muestra_viaje_fecha( struct viajecamion CAMION[] , int VC )
{
    struct viajecamion AUX;
    int I , J;


    for(I=0 ; I<VC-1 ; I++)
        for(J=0 ; J<VC-I-1 ; J++)
                if ( (DIAS(CAMION[J].fecha_viaje)) == (DIAS(CAMION[J+1].fecha_viaje) )  ) {
                    if(CAMION[J].peso_transportado < CAMION[J+1].peso_transportado){


                            AUX         =   CAMION[J];
                            CAMION[J]   =   CAMION[J+1];
                            CAMION[J+1] =   AUX;
                     }
                };

                for(I=0 ; I<VC ; I++){

                    printf("\n\n\n\t%s\t\t%f\t\t\n ",CAMION[I].patente , CAMION[I].peso_transportado);
                };



}
