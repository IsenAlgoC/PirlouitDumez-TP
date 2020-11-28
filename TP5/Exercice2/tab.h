#pragma once

typedef struct Tableau {
	int* elt;  // le tableau d'entier
	int size;  // la taille du tableau
	int eltsCount; // le nombre d'élements dans ce tableau
} TABLEAU;

TABLEAU newArray();

int incrementArraySize(TABLEAU* tab, int incrementValue);

int setElement(TABLEAU* tab, int pos, int element);

int displayElements(TABLEAU* tab, int startPos, int endPos);

int deleteElements(TABLEAU* tab, int startPos, int endPos);
