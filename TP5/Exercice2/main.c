#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAILLEINITIALE 10


int main() {
	TABLEAU tab = newArray();
	printf("Le nombre d'elements dans le tableau est %d :", tab.eltsCount); //on affiche le nombre d'element, c'est a dire de valeurs non nulles dans le tableau
	printf("\nTaille : %d", tab.size); //on affiche la taille du tableau
	displayElements(&tab, 1, 10); //On affiche tout le tableau initial
	setElement(&tab, 1, 5);   
	setElement(&tab, 2, 7);
	setElement(&tab, 13, 8); // Le tableau est initialement de taille 10 donc il est agrandi pour placer 8 à la position 13( en appelant la fonction incrementArraySize dans la fonction setElement
	//printf("\nOn insère 5 à la position 1, puis 7 à la position 2 puis 8 à la position 13");
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf("\nTaille : %d", tab.size);
	displayElements(&tab, 1, tab.size); // On a ajouté les 3 valeurs et on affiche le tableau
	setElement(&tab, 1, 3);
	setElement(&tab, 7, 6);
	setElement(&tab, 23, 2);
	setElement(&tab, 22, 9);
	setElement(&tab, 24, 8);
//	printf("\nOn insère 3 à la position 1, puis 6, puis 2 a la position 23 puis 9 à la position 22");
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nTaille : %d", tab.size);
	displayElements(&tab, 1, tab.size); //on a ajouté les 4 valeurs et on affiche le tableau
	deleteElements(&tab, 2, 4);   // on supprime les elements entre la 2eme et la 7eme valeur
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nTaille : %d", tab.size);
	displayElements(&tab, 1, tab.size);// on affiche le tableau apres avoir supprime les elements
	setElement(&tab, 23, 2);
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nTaille : %d", tab.size);
	displayElements(&tab, 1, tab.size);
	deleteElements(&tab, 15,8); //on supprime les elements entre la 8eme et la 15eme valeur
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nTaille : %d", tab.size);
	displayElements(&tab, 1, tab.size); //on affiche le tableau 
	printf("\nOn affiche le tableau entre la position 5 et 9");
	displayElements(&tab,5,9); //on affiche le tableau entre la position 5 et 9
}