#include<stdio.h>
#include<stdlib.h>
int main( int argc , char *argv[])
{
    int I;

    for(I=0 ; I<atoi(argv[1]) ; I++)
        puts ( argv[2] ) ;
}
