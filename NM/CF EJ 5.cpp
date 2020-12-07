#include<stdio.h>
int main()

{
	int A,B,C,D,E,F;
	printf("INGRESE 6 NUMEROS =");
	 scanf("%d %d %d %d %d %d",&A,&B,&C,&D,&E,&F);

	if(A>B && B>E && E>F )
	  {printf("LA SERIE ES DECRECIENTE");}
	   else {
	  	     if(F>E && E>B && B>A){
	   	       printf("LA SERIE ES CRECIENTE");
				             }
	        else {
	        	printf("LA SERIE NO ES CREC NI DECRE");};
	       }









	   return 0; }









