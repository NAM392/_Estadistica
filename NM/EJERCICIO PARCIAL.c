#include<stdio.h>
#include<math.h>

float COORD_AL_CENTRO(float,float);


int RONDA=0;
int CONT=0;
int PUNT_P,PUNT_I;
float DIST_P,DIST_I,X,Y;



int main()

{

    while(CONT<10)
    {        printf("\tINGRESE COORDENADAS X E Y \n");
             scanf("%f %f",&X,&Y);

            if(CONT%2==0)
            {
               DIST_P=COORD_AL_CENTRO(X,Y);
               RONDA++;

            }
            else
            {
                DIST_I=COORD_AL_CENTRO(X,Y);
                RONDA++;



            }

            if (RONDA%2==0)
            {
               if(DIST_P>DIST_I)
               {
                   PUNT_I=PUNT_I+10;
                   printf("RONDA GANADA POR JUGADOR B \n");


               }
                else
                    {
                        if(DIST_I>DIST_P)
                        {
                            PUNT_P=PUNT_P+10;
                            printf("RONDA GANADA POR JUGADOR A\n");
                        }
                        else
                        {
                            printf("RONDA EMPATADA\n");
                            PUNT_P=PUNT_P+5;
                            PUNT_I=PUNT_I+5;
                        };
                    };
                };

                CONT++;

    };

    if (PUNT_I>PUNT_P)
    {

        printf("EL GANADOR FUE EL JUGADOR B CON %d PUNTOS \n",PUNT_I);
    }
    else
        {   if(PUNT_P>PUNT_I)
                {
                    printf("EL GANADOR FUE EL JUGADOR A CON %d PUNTOS\n",PUNT_P);
                }
             else
             {
                 printf("HUBO EMPATE");
             };
        };
}


















float COORD_AL_CENTRO(float X,float Y)
{
  float C,H;
  C=(pow(X,2))+(pow(Y,2));
  H=sqrt(C);

  return H;



}


