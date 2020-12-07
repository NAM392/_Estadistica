#include<stdio.h>
int main()

{

 	int A,B,C,D,E;
	 
	D=0;
	
	printf("INGRESE UN NUMERO DE 3 CIFRAS");
	scanf("%d",&D);
	 
	A= D/100;
	B= (D/10)%10;
    C= D%10;
    E= A*B*C;
	 	
	
	 	
	if (E==D) {
		printf("EL PRODUCTO ES IGUAL %d ",D);
	}
	else { 
		printf("EL PRODUCTO ES DESIGUAL %d y %d",E,D);
	};			
	
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 







}
