#include <stdio.h>
#include <stdlib.h>

int main() {
	float tampon = 0;
	float a = 0;
	float b = 0;
	float c = 0;
	float hauteurmax = 55;
	float largeurmax = 35;
	float profondeurmax = 25;
	int continuer = 1;
	do {
		printf("Entrez les 3 dimensions de la valise");
		scanf_s("%f", &a);
		scanf_s("%f", &b);
		scanf_s("%f", &c);
		printf("%f \n", a);
		if (c > b) {
			tampon = c;
			c = b;
			b = tampon;
		}
		if (b > a) {
			tampon = b;
			b = a;
			a = tampon;
		}
		if (c > b) {
			tampon = c;
			c = b;
			b = tampon;
		}
		printf("La hauteur est %f la largeur vaut %f et la profondeur vaut %f \n", a, b, c);
		if ((a <= hauteurmax) && (b <= largeurmax) && (c <= profondeurmax))
		{
			printf("La valise est valide");
		}
		else {
			printf("La valise n'est pas valide");
		}

		printf("Tapez 1 si vous voulez continuer sinon un autre chiffre");
		scanf_s("%d", &continuer);
	}
		while(continuer == 1);
}