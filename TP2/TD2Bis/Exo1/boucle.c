#include <stdio.h>
#include <stdlib.h>

int main() {
	int somme2 = 0;
	int somme3 = 0;
	int n = 100;
	int i = 0;
	int j = 2;
	int k = 1;
	
	while (j <= n) {
		somme2 += j;
		j += 1;
	}
	do  {
		k += 1;
		somme3 += k;
	} 
	while (k <= n-1);

	printf("La somme avec le while vaut %d \n", somme2);
	printf("La somme avec le do while vaut %d \n", somme3);

	
 

	unsigned short int somme = 0;
	int m = 0;
	unsigned short int somme5 = 0;
	unsigned short int SommeMax = 65535;
	int p = 1;
	int a = 0;
	while ((somme < SommeMax) && (SommeMax - somme >= p + 1)) {
		p += 1;
		somme += p;
	}
	printf("n vaut au maximum %d pour sommeMax valant %u et la somme des n vaut %d", p, SommeMax, somme);
	do {
		printf("Entrez une valeur pour n");
		scanf_s("%d", &a);
	}
	while (p <= a);
	for (i = 2; i <= a; i++) {
		somme5 += i;
	}
	printf("La somme de 2 a %d vaut %d", a, somme5);
	
}