#include<stdio.h>
int main ( int argc , char **argv , char**envp )
{

    int I = 0 ;
    while( *(envp+I) ) {
          puts ( *(envp+I)) ;
          I++;
    }


}
