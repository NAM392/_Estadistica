#include<stdio.h>
#include<math.h>

float Hipotenusa_(int,int);

int main()
{

    int EKIS=0;
    int YE=0;
    int ACUME=0;
    int ACUMY=0;
    int CORDX=0;
    int CORDY=0;
    int CONT=1;
    float DIST=0;
    int SALX=0;
    int SALY=0;



    while(EKIS>=0)
        {
              printf("ingrese coordenadas X Y ");
              scanf("%d %d",&EKIS ,&YE);

            if(CONT>1&&CONT%2==0)
            {
                SALX=SALX+EKIS;
                SALY=SALY+YE;
                CORDX=ACUME+EKIS;
                CORDY=YE-ACUMY;

                DIST=Hipotenusa_(CORDX,CORDY)+DIST;

            }
            else if (CONT>=1)

                    {
                     ACUME=SALX-EKIS;
                     ACUMY=YE-SALY;

                        if(CONT>1)
                            {
                                DIST=Hipotenusa_(ACUME,ACUMY)+DIST;


                            };

                    };


                    CONT++;


        }

        printf("%.2f",DIST-Hipotenusa_(CORDX,CORDY));



        }
float Hipotenusa_(X,Y)
{

float CF,CS,RC;
CF=pow(X,2);
CS=pow(Y,2);
RC=sqrt(CF+CS);


return RC;





}
