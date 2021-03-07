#include <stdio.h>
#include <math.h>

int main (){
	int a,b,c;
	if ((scanf ("%d%d%d", &a , &b , &c)) == 3) {

		if ((a+b <= c) || (a+c <= b) || (b+c <= a)) printf("INVALIDO\n");
		else { 

			if ((a == b) && (b == c)) printf("EQUILATERO ");
	    	else if (((a == b) && (c != b)) || ((a==c) && (c!=b)) || ((b==c) && (a != b))) printf("ISOSCELES ");
	        else if ((a*a == b*b + c*c) || (c*c == b*b + a*a) || (b*b == a*a + c*c)) printf("RETANGULO ");
	        else printf("ESCALENO ");

			int perimetro = a+b+c; float semiperimetro = (float)perimetro / 2;
			printf("%d ", perimetro);

			float area = sqrt(semiperimetro * (semiperimetro - a) * (semiperimetro - b) * (semiperimetro - c));
			printf("%.2f\n", area);
		}
	}
	else {}
	return 0;
}