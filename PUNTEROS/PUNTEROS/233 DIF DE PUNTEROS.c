#include<stdio.h>
int main()
{
    float *p , *q ;
    int A ;
    p = (float *) 0x2000 ;
    q = (float *) 0x200A ;
    A = q - p ;
    printf("\n\n %d \t %p  \t  %p \t ", A , q ,p);







}
