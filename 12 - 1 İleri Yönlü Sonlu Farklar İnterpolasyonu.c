#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n,i,j;
	
	printf("nokta sayisini gir?");
	scanf("%d",&n);
	
	double x[n];
	double y[n][n];
	double x_value = 1.1;
	//double x_value;
	double px;
	
	double toplam, carpim;
	
/*	printf("x degerini gir: ");
	scanf("%lf",&x_value);
	
	for(i = 0; i < n; i++){
		printf("x %d gir: ",i);
		scanf("%lf",&x[i]);
		printf("y %d de gir bari burada: ",i);
		scanf("%lf",&y[i][0]);
	}
	
*/	
	y[0][0] = 0.7651977;
	y[1][0] = 0.6200860;
	y[2][0] = 0.4554022;
	y[3][0] = 0.2818186;
	y[4][0] = 0.1103623;
	
	x[0] = 1.0;
	x[1] = 1.3;
	x[2] = 1.6;
	x[3] = 1.9;
	x[4] = 2.2;
		
	for(i = 1; i < n; i++){
		for(j=0; j < n - i; j++)
			y[j][i] = ((y[j+1][i-1] - y[j][i-1]) / (x[i+j] - x[j]));
	}
	toplam = 0;
	
	for(i = 1; i < n; i++){
		carpim = 1;
		for(j = 0; j <= i -1; j++){
			carpim = carpim * (x_value - x[j]);
		}
		toplam = toplam + (carpim * y[0][i]);
	}
	px = y[0][0] + toplam;
	printf("%lf",px);
}

