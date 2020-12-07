#include<stdio.h>
#include<math.h>
float CM_A_PUL(float);
float POR_REST_(float,float);
float PUL_A_CM(float);

int main ()

{
    float CONTP=0;
    float CONTM=0;
    float CONTC=0;
    float ST,PUL,RELM,BETA,RESTO1,RESTO2,CUARTO,DELTA,DELTA_CM,PCM,RESTO3,RESTO4;
    float REL=0;


    printf("ingrese seccion transversal ");
    scanf("%f",&ST);

    PUL=CM_A_PUL(ST);

    REL=PUL+REL;




    if(REL>10)
    {   while(REL>=1)
            {
                REL--;
                CONTP++;
            };

        while(REL>=0.5)
            {
                REL=REL-0.5;
                CONTM=CONTM+0.5;
            };

        RELM=CONTP+CONTM;
        BETA=RELM+0.5;

        RESTO1=POR_REST_(REL,PUL);
        RESTO2=(POR_REST_(BETA,PUL))-100;

        printf("para un tubo de %.2f PUL \t\n\n se usa un tubo de %.2f pulgadas con un margen de error de %.2f \n\n O se puede usar un tubo de %.2f  con un margen de error de %.2f\n\n",PUL,RELM,RESTO1,BETA,RESTO2);

    }

    else
    {
        while(REL>=1)
        {
            REL--;
            CONTP++;
        };

        while(REL>=0.25)
        {
           REL=REL-0.25;
           CONTC=CONTC+0.25;


        };

        CUARTO=CONTP+CONTC;
        DELTA=CUARTO+0.25;
        DELTA_CM=PUL_A_CM(DELTA);
        PCM=(PUL_A_CM(CUARTO));
        RESTO3=100-(POR_REST_(PCM,ST));
        RESTO4=(POR_REST_(DELTA_CM,ST))-100;

        printf("para un tubo de %.2f PUL \t\n\n se usa un tubo de %.2f pulgadas con un margen de error de %.2f \n\n O se puede usar un tubo de %.2f  con un margen de error de %.2f\n\n",PUL,CUARTO,RESTO3,DELTA,RESTO4);

    };








};


float CM_A_PUL(float M)
{
    float C,R,D,P;
   C=M/3.14;
   R=sqrt(C);
   D=R*2;
   P=D/2.54;

   return P;

};

float POR_REST_(float Y,float Z)
{
    float N,F;

    N=Y*100;

    F=N/Z;

    return F;

};

float PUL_A_CM(float W)
{
    float T,Y,G;

    T=W*2.54;
    Y=T/2;
    G=(pow(Y,2))*3.14;

    return G;

}
