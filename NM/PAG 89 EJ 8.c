#include<stdio.h>
#include<stdlib.h>

int main()
{



    int i;
    srand(time(0));
    for(i=0;i<20;i++);
    printf("%8d",(rand()%9)+1);



}
