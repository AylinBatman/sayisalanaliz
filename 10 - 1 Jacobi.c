#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n; //n bilinmeyen sayýsýný gösteriyor
	
	printf("Kac tane bilinmeyen var? ");
	scanf("%d",&n);
	
	double a[n+1][n+1];
	
	a[1][1] = 8;
	a[1][2] = 2;
	a[1][3] = 3;
	a[2][1] = 1;
	a[2][2] = -9;
	a[2][3] = 2;
	a[3][1] = 2;
	a[3][2] = 3;
	a[3][3] = 6;

	
	double b[n+1];
	
	b[1] = 30;
	b[2] = 1;
	b[3] = 31;
	
	double x[n+1];
	double x0[n+1];
	
	int i;
	
	for(i = 1; i <= n; i++){
		x[i] = 0;
		x0[i] = 0;
	}

	int k = 1; //k kaçýncý iterasyonda olduðunu gösteriyor, sayaç
	int nmax = 100; //nmax en fazla kaç defa iterasyon olacaðýný gösteriyor	

	double hata = 0.01; //hata töleransý

	int j,sayac;
	double temp;
	
	while(k <= nmax){
		for(i = 1; i <= n; i++){
			temp = 0;
			for(j = 1; j <= n; j++){
				if(j != i){
					temp = temp + (a[i][j] * x0[j]);
				}
			}
			x[i] = (b[i] - temp) / a[i][i];
			printf("%.3f \t",x[i]);
		}
		printf("\n");	
		for(sayac = 0,i = 1; i <= n; i++){
			if(fabs(x[i] - x0[i]) < hata)
				sayac++;	
		}
		if(sayac == n){
			for(i = 1; i <= n ; i++)
				printf("%.0f \t",x[i]);
			printf("\n%d. iterasyonda buldum.",k);
			break; // while'ýn dýþýna atýyor
		}
		for(i = 1; i <= n; i++){
			x0[i] = x[i];
		}			
		k =  k + 1;
	}
	if(k > nmax)
		printf("%d defa döndüm bulamadým.",k);
}
