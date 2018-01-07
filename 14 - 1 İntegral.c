#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double a,b,h,x,total,result;
	int n,i;
	
	printf("a ve b noktalarini gir: ");
	scanf("%lf %lf",&a,&b);
	
	printf("kac parcaya boleceksin? ");
	scanf("%d",&n);
	
	h = (b-a) / n;
	
	total = 0;
	
	total = (pow(a,2) + 5 * a + 4) + (pow(b,2) + 5 * b + 4);
	
	for(i = 1; i <= n -1; i++){
		x = a + i * h;
		total = total + (2*(pow(x,2) + 5 * x + 4));
	}
	result = (total * h) / 2;
	printf("Integralin sonucu: %lf",result);
}
