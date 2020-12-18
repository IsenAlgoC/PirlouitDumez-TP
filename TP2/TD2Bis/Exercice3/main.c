#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h>

int main() {
	int annee = 2018;
	bool bis;
	printf("Entrez l'année \n");
		scanf_s("%d", &annee);
	if (annee % 4 == 0) {
		if (annee % 100 == 0) {
			if (annee % 400 == 0) {
				bis = true;
			}
			else {
				bis = false;
			}
		}
		else {
			bis = true;
		}
	}
	else {
		bis = false;
	}

	if (bis==true){
		printf("L'année %d est une annee bissextile ",annee);
	}
	else {
		printf("L'année %d n'est pas une annee bissextile ", annee);
	}
	if (((annee % 100 == 0) && (annee % 400 == 0)) || ((annee % 4 == 0) && (annee % 100 != 0))) {
		printf("L'annee est bissextile");
	}
	else {
		printf("L'annee n'est pas bissextile");
	}
	

}