#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i,k,n;
	
	printf("Polinomun nokta sayýsýný gir: ");
	scanf("%d",&n);
	
	double L[n];
	double x[n];
	double y[n];
	double Px = 0;
	double x_degeri;
	
	printf("Polinoma x deðeri gir:");
	scanf("%lf", &x_degeri); //3 olarak aldýk problemde
	
	for(k=0; k < n; k++){
		printf("%d. noktanýn deðerini gir: ",k);
		scanf("%lf",&x[k]);
	}
	
	//x[0] = 2;
	//x[1] = 2.75;
	//x[2] = 4;
	
	for(k = 0; k < n; k++){
		L[k] = 1;
		for(i=0; i < n; i++){
			if(i != k){
				L[k] = L[k] * ((x_degeri - x[i]) / (x[k] - x[i]));
			}
		}
	}
	for(k = 0; k < n; k++){
		Px = Px + (L[k] * (1/x[k]));
	}
	printf("Px = %lf",Px);
}
