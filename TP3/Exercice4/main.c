#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	// Déclaration des variables
	unsigned int w = 192, x = 168, y = 129, z = 10, adresse = 0, adresse_reseau = 0, adresse_broadcast;
	unsigned long long int IPv4MaskLenght = pow(2, 32) - 1, notmask; 
	int n = 24, i; 

	for (i = 0; i < (32 - n); i++)
	{
		IPv4MaskLenght -= pow(2, i);
	}
	notmask = ~IPv4MaskLenght;  //on calcule le complément du mask pour calculer l'adresse broadcoast
	adresse = w; // On écrit l'adresse
	adresse <<= 8;
	adresse += x;
	adresse <<= 8;
	adresse += y;
	adresse <<= 8;
	adresse += z;
	w = adresse; //on trie par octet pour donner les adresses
	w >>= 24;

	x = adresse;
	x >>= 16;
	x -= w * pow(2, 8);


	y = adresse;
	y >>= 8;
	y -= (w * pow(2, 16) + x * pow(2, 8));

	z = adresse;
	z -= (w * pow(2, 24) + x * pow(2, 16) + y * pow(2, 8));
	printf("Adresse machine : %u.%u.%u.%u\n", w, x, y, z); //on affiche l'adresse machine

	adresse_reseau = (adresse) & (IPv4MaskLenght); 
	w = adresse_reseau; // on stock l'adresse réseau dans les variables
	w >>= 24;

	x = adresse_reseau;
	x <<= 8;
	x >>= 24;

	y = adresse_reseau;
	y <<= 16;
	y >>= 24;

	z = adresse_reseau;
	z <<= 24;
	z >>= 24;

	printf("Adresse reseau : %u.%u.%u.%u\n", w, x, y, z); //on affiche l'adresse reseau

	adresse_broadcast = adresse_reseau | notmask; 
	w = adresse_broadcast;
	w >>= 24;

	x = adresse_broadcast;
	x <<= 8;
	x >>= 24;

	y = adresse_broadcast;
	y <<= 16;
	y >>= 24;

	z = adresse_broadcast;
	z <<= 24;
	z >>= 24;

	printf("Adresse broadcoast : %u.%u.%u.%u", w, x, y, z); //on affiche l'adresse broadcast

	return 0;
}