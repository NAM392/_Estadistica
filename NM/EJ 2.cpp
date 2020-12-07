#include<stdio.h>

int main()

{

	int A =0;
	int B=0;
	int C=0;
	int D=0;
	int E=0;
	
	//se nesecitan 5 variables

	
	printf("ingrese 5 numeros=");
	
			scanf("%d %d %d %d %d", &A,&B,&C,&D,&E);

    		
		
	
	if (A>B && A>C && A>D && A>E)
        {
        printf(" EL MAYOR ES %d",A);}
	
	else{
	
	       if (B>C && B>D && B>E)
	       {printf("EL MAYOR ES %d",B);
	       }
	       
	       else {
		          if (C>D && C>E){
	      	   		printf("EL MAYOR ES %d",C);
	      								}
	      				if(D>E)	
						  {printf("EL MAYOR ES %d",D);}
						else		
						printf("EL MAYOR ES %d",E);	
				}
	      
	  }
	
	      
	
	
	
	
	
	








}
