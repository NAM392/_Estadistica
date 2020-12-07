#include<stdio.h>
#include<string.h>

struct SUPER {
    char NOMBRE[20];
    long int DNI;
    int PUNTOS;


};


int main()
{
    struct SUPER SUP , SUX , RES ;
    FILE*SP , *SAUX  , *RF;
    long int aux;
    int N , flag=0 ;
    SP = fopen("supermercado.dat" , "rb");
    RF = fopen("resultado.dat" , "wb");
    SAUX = fopen("supermercado.dat" , "rb");
    fread(&SUP , sizeof(SUP) , 1 , SP);
    fread(&SUX , sizeof(SUX) , 1 , SAUX);

   while(!feof(SP)){
    int PUNTOS= 0;
       aux = SUP.DNI;
       rewind(SAUX);
       fread(&SUX , sizeof(SUX) , 1 , SAUX);
       while(!feof(SAUX)){
            if(aux == SUX.DNI){
                PUNTOS = PUNTOS + SUX.PUNTOS;
            }
            fread(&SUX , sizeof(SUX) , 1 , SAUX);
       }
       rewind(SAUX);
       fseek(RF , 0L , SEEK_END);
       N = ftell(RF);
       /// siempre crea e ingresa al == 0
       if(N == 0){
            strcpy(RES.NOMBRE , SUP.NOMBRE);
            RES.DNI = SUP.DNI;
            RES.PUNTOS = PUNTOS;
            fwrite(&RES , sizeof(RES) , 1 ,RF );
            /// cierro wb
            fclose(RF);
       }
       else {
            /// segundo y demas ingresan por aca
            /// leer para asegurarse que el dni no este
            RF = fopen("resultado.dat" , "rb");
            fread(&RES , sizeof(RES) , 1 ,RF );
            while(!feof(RF)){
                 ///preguntar si se encuentra el dni
                if(RES.DNI == SUP.DNI ){
                    flag=1;
                }
                fread(&RES , sizeof(RES) , 1 ,RF );
            }
            rewind(RF);
            fclose(RF);
            /// si dni existe saltea la escritura
            if(flag == 0){
                /// ingresa por aca es porque el dni no se encontraba
                RF = fopen("resultado.dat" , "ab");
                strcpy(RES.NOMBRE , SUP.NOMBRE);
                RES.DNI = SUP.DNI;
                RES.PUNTOS = PUNTOS;
                fwrite(&RES , sizeof(RES) , 1 ,RF );
                fclose(RF);
            }

       }
       fread(&SUP , sizeof(SUP) , 1 , SP);
    }
    rewind(RF);
    /// lees el resultado final ya armado por eso el rb
    RF = fopen("resultado.dat" , "rb");
    fread(&RES , sizeof(RES) , 1 ,RF );
    while(!feof(RF)){
        printf("\n   %s    %d    %d   \n" , RES.NOMBRE , RES.DNI , RES.PUNTOS);
        fread(&RES , sizeof(RES) , 1 ,RF );
    }
}
