#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define NBNOTESMAX 30
#define carre(x) (x)*(x)

int main() {
	int indice = 0; int note; int reponse; int nbsaisies = 0; int absence = 0; float somme = 0; float moyenne; int tri[NBNOTESMAX];
	 int notemax = 0; int notemin = 20; int tableau[NBNOTESMAX]; float somme2 = 0; float ecarttype; float compteur = 0; int n = 0;
	 int permutation = 1; int passage = 0; int classement[NBNOTESMAX]; int index[NBNOTESMAX];
	for (int i = 0; i < NBNOTESMAX; i++) {
		tableau[i] = -2;
	}
	while(nbsaisies < NBNOTESMAX) {
	reprendre:
		printf(" \n Entrez la note no %d : \n", nbsaisies+1);
		scanf_s("%d", &note);
		if (note < 0 || note>20) {
			printf("Eleve absent? Ou vous voulez arreter la saisie des notes? A/O/N \n");
			do {
				reponse = _getch();
				reponse = toupper(reponse);
			} while (reponse != 'A' && reponse != 'O' && reponse != 'N');
			switch (reponse)
				case 'A': {
					printf("Eleve absent");
					absence += 1;
					nbsaisies += 1;
					tableau[indice] = -1;
					break;
				case 'O':
					printf("Fin de la saisie \n");
					goto fini;         //on passe directement à fini pour ne pas entrer de nouvelles notes
					break;
				case 'N':
					printf("Reprendre la saisie");
					goto reprendre;   //on revient au début pour recommencer à entrer des notes sans prendre en compte la note que l'utilisateur venait d'entrer
					break;
			}
		}
		else {
			printf("La note numéro %d est %d \n", nbsaisies+1, note);
			nbsaisies += 1;
			somme += note;
			compteur += 1;
			tableau[indice] = note;
			if (note >= notemax){
				notemax = note;
			}
			if (note <= notemin) {
				notemin = note;
			}
		}
		indice += 1;
	}
fini: 
	printf("Le nombre de notes saisies est %d il y a %d absences \n", nbsaisies, absence);
	moyenne = somme / compteur;
	printf("La moyenne est %.2f \nLa note max est %d et la note min est %d \n", moyenne,notemax,notemin);
	for (int i = 0; i < indice; i++) {
		if (tableau[i] != -1) {
			somme2 += carre(tableau[i] - moyenne);
		}
	}
	float a = (1 / (compteur-1));
	ecarttype = sqrtf((a)*(somme2));
	printf("L'ecart type est %.2f \n", ecarttype);
	printf(" \n          No notes          Valeurs notes");
	for (int i = 0; i < NBNOTESMAX; i++) {
		printf("\n %10d         ", i+1);
		printf("%10d ", tableau[i]);
	}
	                                               // Trier les notes dans l'ordre et afficher le classement 
	for (int i = 0; i < NBNOTESMAX; i++) {
		classement[i] = tableau[i];
	}
	for (int i = 0; i < NBNOTESMAX; i++) {
		index[i] = i;
	}
		for (int j = 0; j < NBNOTESMAX; j++) {
			for(int i=0;i<NBNOTESMAX;i++) {
				if (classement[i] < classement[i + 1]) {
					int tmp = classement[i];               // On permute les valeurs du classement mais aussi des index
					classement[i] = classement[i + 1];
					classement[i + 1] = tmp;
					tmp = index[i];
					index[i] = index[i + 1];
					index[i + 1] = tmp;
				}
			}
		}
	printf("\n \n \n");
	printf("      Rang:     No Notes      Notes");
	for (int i = 0; i < NBNOTESMAX; i++) {
		printf("\n %10d", i+1);
		printf("%10d", index[i]+1);
		printf("%10d", classement[i]);
	}
	printf("\n Bye !");
}