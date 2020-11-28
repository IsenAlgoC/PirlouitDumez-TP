#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define TAILLEAJOUT 5;



int InitTab(int* tab, int size) {
	if ((tab == NULL) || (size < 0)) {
		return(-1);
	}
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
		return(0);
	}
}


int afficheTab(int* tab, int size, int nbElts) {
	printf("\n");
	if ( ((nbElts > size) || (size < 0)) || (tab == NULL) ) {
		printf("Impossible d'afficher le tableau");
		return(-1);
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", *(tab + i));
		}
		return(0);
	}
}


int* ajouterElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if ( (tab != NULL) && (size != NULL) && (nbElts != NULL) ) {
		if (*size > * nbElts) {                   // S'il y a assez de place, pas besoin de realloc on ajoute directement la valeur element au dernier element 
			printf("\n Assez de place");
			*(tab + *nbElts) = element;
			*nbElts = *nbElts + 1;
			return(tab);
		}
		else {
			printf(" \n Plus de place");
			int ajout = TAILLEAJOUT;
			int* tmp = tab; //on sauvegarde le pointeur en cas d'échec de la réalloc
			tab = (int*) realloc(tab, (*size + ajout ) * (sizeof(int)));
			if (tab != NULL) { // On vérifie que la realloc a marché, si oui on peut déplacer tab à l'adresse prévue et modifier les différents compteurs
			                      // Cela  permet de ne pas modifier la valeur de tab si la realoc n'a pas fonctionné
				*size = *size + TAILLEAJOUT;
				*(tab + *nbElts) = element;
				*nbElts = *nbElts + 1;
				return(tab);
			}
			else {
				tab = tmp;       // si la réalloc n'a pas fonctionné, on récupère le pointeur d'origine
				printf("La reallocation n'a pas fonctionné correctement");
				return(NULL);
			}
		}
	}
}