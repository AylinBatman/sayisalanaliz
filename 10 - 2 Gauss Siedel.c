#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n; //n bilinmeyen sayýsýný gösteriyor
	
	printf("Kac tane bilinmeyen var? ");
	scanf("%d",&n);
	
	double a[n+1][n+1];
	
	a[1][1] = 5;
	a[1][2] = 2;
	a[1][3] = 1;
	a[2][1] = 1;
	a[2][2] = 2;
	a[2][3] = 1;
	a[3][1] = 2;
	a[3][2] = 1;
	a[3][3] = 4;

	
	double b[n+1];
	
	b[1] = 12;
	b[2] = 8;
	b[3] = 16;
	
	double x[n+1];
	double x0[n+1];
	
	int i;
	
	for(i = 1; i <= n; i++){
		x[i] = 0;
		x0[i] = 0;
	}

	int k = 1; //k kaçýncý iterasyonda olduðunu gösteriyor, sayaç
	int nmax = 100; //nmax en fazla kaç defa iterasyon olacaðýný gösteriyor	

	double hata = 0.001;//hata töleransý

	int j,sayac;
	double temp1 = 0;
	//double temp2 = 0;
	while(k <= nmax){
		for(i = 1; i <= n; i++){
			temp1 = 0;
			//temp2 = 0;
			for(j = 1; j <= i-1; j++){	
				temp1 = temp1 + (a[i][j] * x[j]);
			}
			for(j = i+1; j <= n; j++){	
				//temp2 = temp2 + (a[i][j] * x0[j]);
				temp1 = temp1 + (a[i][j] * x0[j]);
			}
			//x[i] = (b[i] - (temp1 + temp2)) / a[i][i];
			x[i] = (b[i] - (temp1)) / a[i][i];
			printf("%.7f \t",x[i]);
		}
		printf("\n");	
		for(sayac = 0,i = 1; i <= n; i++){
			if(fabs(x[i] - x0[i]) < hata)
				sayac++;	
		}
		if(sayac == 3){
			for(i = 1; i <= n ; i++)
				printf("%.0f \t",x[i]);
				printf("\n%d. iterasyonda buldum.",k);
			break;
		}
		for(i = 1; i <= n; i++){
			x0[i] = x[i];
		}		
		k =  k + 1;
	}
	if(k > nmax)
		printf("%d defa döndüm bulamadým.",k);
}
