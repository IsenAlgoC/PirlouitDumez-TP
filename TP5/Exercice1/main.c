#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define TAB2SIZE 20;
#define TAILLEAJOUT 5;
int main() {
	// Déclaration des variables 
	int MyTab1[10]; int* MyTab2 = NULL; int tabSize = TAB2SIZE; int nbElts = 20 ;
	// Initalisation & affichage de MyTab1
	InitTab(MyTab1, 10);
	printf("Tab1 est :");
	afficheTab(MyTab1, 10, 6);

	// Allocation dynamique du tableau
	MyTab2 = (int *) malloc(sizeof(int) * tabSize);
	if (MyTab2 == NULL) {
		printf("Memoire insuffisante");
		exit(0);
	}
	// On initialise MyTab2 avec 20 zéros puis on remplit ses valeurs de 1 à 20
	InitTab(MyTab2, nbElts);
	for (int i = 0; i <20; i++) {
		*(MyTab2 + i) = i + 1;
	}
	printf(" \n Tab2 est :");
	afficheTab(MyTab2, 20, nbElts);
	// On effectue deux fois la fonction realloc à la suite, et on affiche le tableau à la fin
	printf(" \n Dernier element du tableau :  %d", *(MyTab2+nbElts-1));
	ajouterElementDansTableau(MyTab2, &tabSize, &nbElts, 3);
	printf(" \n Dernier element du tableau apres l'ajout : %d", *(MyTab2 + nbElts -1));
	printf(" \n Il y a %d elements dans le tableau, la taille du tableau est maintenant de %d", nbElts, tabSize);
	ajouterElementDansTableau(MyTab2, &tabSize, &nbElts, 5);
	printf(" \n Dernier element du tableau apres l'ajout : %d", *(MyTab2 + nbElts -1));
	printf(" \n Il y a %d elements dans le tableau, la taille du tableau est maintenant de %d", nbElts, tabSize);
	afficheTab(MyTab2, tabSize, nbElts);
	free(MyTab2); // On n'a plus besoin de MyTab2 donc on libère l'espace en mémoire
 }