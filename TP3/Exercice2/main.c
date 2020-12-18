#include <stdlib.h>
#include <stdio.h>

int main() {
	int octet; int bits; 
	unsigned int nb = 2868838400;
	octet = sizeof(nb);
	bits = octet * 8;
	printf("%d octets et %d bits", octet, bits);
	for (int i = 1; i <= bits; i++) {
		if (nb & 1) {
			printf("bits %3d : ON \n", i);   //si le bit vaut 1, on affiche ON
		}
		else {
			printf("bits %3d : OFF \n", i);  //si le bit vaut 0, on affiche OFF
		}
		nb = nb >> 1; //on decale d'un bit pour passer au suivant
	}
	printf("Bye");
}