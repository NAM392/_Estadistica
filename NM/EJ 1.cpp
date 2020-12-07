#include<stdio.h>

int main()

{
	int A =0;
	int B=0;
	int C=0;
	
	printf("ingrese 3 numeros=");
	
			scanf("%d %d %d", &A,&B,&C);

    		if (A>B && A>C)
	printf("%d es MAYOR",A);
	
	else {
	       if (B>C) 
	       printf("%d es MAYOR",B);
	       
	       else
	       printf("%d es MAYOR",C);
	   }

	
	
	return 0;
	
	
	
	
	
	
	
}
