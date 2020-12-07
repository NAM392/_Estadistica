        #include<stdio.h>

int main()


{
    int BI=0;
    int CHORI=0;


    printf("ingrese anni ");
    scanf("%d",&BI) ;

    if  (BI%4==0){

         CHORI=CHORI+BI;}

            if (BI%100==0)

            {CHORI=CHORI-BI;}

                if  (BI%400==0){

                    CHORI=CHORI+BI;}

                      if (CHORI>0)
                        {printf("EL ANNI %d ES BISIESTO",CHORI);}
                      else {printf("EL ANNI NO ES BISIESTO");};
    };








