#include <stdlib.h>
#include <stdio.h>
#define carre(x) (x)*(x)

int main() {
	int Nb = 5;
	int a; int b; 
	a = carre(Nb);
	b = carre(Nb + 1);    // ne fonctionne pas car il n'y a pas de parenthèses à la macro, donc elle calcule Nb +1*Nb +1
	                      // il faut en rajouter pour que la macro respecte l'ordre de priorité des calculs
	printf("%d", b);      
}
