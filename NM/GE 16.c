#include<stdio.h>

int main()


{
    int ENTE =1007;

    int LALA=0;

    int PRIMO;

    int NUM,DIV;
    int CONTP=0;








    while (ENTE>999 && ENTE<10000 || LALA==5){


            printf("INGRESE NUMERO\n");
            scanf("%d",&ENTE);


      for(NUM=1000;NUM<10000;NUM++){



                            PRIMO=1;

                            for(DIV=2;DIV<NUM;DIV++){



                                if(!(NUM%DIV)){
                                    PRIMO=0 ; }
                                                    };


                                      };


                                        };


                            if (PRIMO){
                                      CONTP++;
                                     LALA=LALA+NUM;


                                      printf("lala %d",NUM);


                                                        };
                printf("FIN DEL PROGRAMA");

}
