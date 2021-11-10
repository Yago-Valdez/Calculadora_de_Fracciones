#include <stdio.h>
struct racional{
	int numerador;
	int denominador;
};
void leer(struct racional *fraccion, int n);
struct racional suma(struct racional *fraccion, int n);
struct racional resta(struct racional *fraccion, int n);
struct racional multiplicacion(struct racional *fraccion, int n);
struct racional division(struct racional *fraccion, int n);
void leer(struct racional *fraccion,int n){
	for(int z = 0; z < n; z++){
		printf("\n \n Ingrese el %d racional \n ",z+1);
		printf(" Numerador> ");
		scanf("%d",&fraccion[z].numerador);
		printf("  Denominador> ");
		scanf("%d",&fraccion[z].denominador);
	}
}
struct  racional suma(struct racional *fraccion,int n){
	struct racional suma;
	suma.numerador = 0;
	suma.denominador = 1;
	for(int z = 0; z < n; z++){
		suma.numerador		= (suma.denominador * fraccion[z].numerador) + (suma.numerador * fraccion[z].denominador);
		suma.denominador 	= suma.denominador * fraccion[z].denominador;
	}
	return suma;
}
struct  racional resta(struct racional *fraccion,int n){
	int aux = 0 ,aux2 = 0 ;
	struct racional resta;
	resta.numerador = 0;
	resta.denominador = 1;
	for(int z = 0; z < n; z++){
		aux  = (resta.denominador * fraccion[z].numerador);
		aux2 = (resta.numerador * fraccion[z].denominador);
		resta.numerador		= aux - aux2;
		resta.denominador 	= resta.denominador * fraccion[z].denominador;
	}
	return resta;
}
struct racional multiplicacion(struct racional *fraccion,int n){
	struct racional multi;
	multi.numerador = 1;
	multi.denominador = 1;
	for(int z = 0; z < n; z++){
		multi.numerador = multi.numerador  * fraccion[z].numerador;
		multi.denominador = multi.denominador * fraccion[z].denominador;
	}
	return multi;
}
struct racional division(struct racional *fraccion,int n){
	struct racional divisor;
	int aux = 0,aux2 = 0;
	divisor.numerador = 1;
	divisor.denominador = 1;
	for(int z = 0; z < n; z++){
		if(z==0){
			divisor.numerador 	= fraccion[z].denominador;
			divisor.denominador = fraccion[z].numerador;
		}else{
			aux 	= divisor.denominador * fraccion[z].denominador;
			aux2	= divisor.numerador * fraccion[z].numerador;
			printf("\n %d * %d = %d  \n",divisor.numerador,fraccion[z].denominador,aux);
			printf("%d * %d = %d \n ",divisor.denominador,fraccion[z].numerador,aux2);
			divisor.numerador 	= aux;
			divisor.denominador = aux2;
		}
	}
	return divisor;
}
int main(int argc, char *argv[]) {
	int n_racionales = 0 , x = 0;	
	printf("Con cunatos numeros va atrabajar>");
	scanf("%d",&n_racionales);
	struct racional fraccion[n_racionales];
	struct racional regresos;
	while(x != 6){
		printf(" \n-------------Menu---------\n");
		printf(" 1.Ingrese dos valores \n");
		printf(" 2.Suma \n");
		printf(" 3.Resta \n");
		printf(" 4.Multiplicacion \n");
		printf(" 5.Division \n");
		printf(" 6.Salir \n");
		scanf("%d",&x);
		switch(x){
			case 1 :
					leer(fraccion,n_racionales);
					break;
			case 2 :
					printf("La suma es de :");
					regresos = suma(fraccion,n_racionales);
					printf("%d/%d \n",regresos.numerador,regresos.denominador);
					break;
			case 3 :
					printf("La resta es de :");
					regresos = resta(fraccion,n_racionales);
					printf("%d/%d \n",regresos.numerador,regresos.denominador);
					break;
			case 4 :
					printf("La multiplicacion es de :");
					regresos = multiplicacion(fraccion,n_racionales);
					printf("%d/%d \n",regresos.numerador,regresos.denominador);
					break;
			case 5:
					printf("La division es de :");
					regresos = division(fraccion,n_racionales);
					printf("%d/%d \n",regresos.numerador,regresos.denominador);
					break;
		}	
	}	
	return 0;
}

