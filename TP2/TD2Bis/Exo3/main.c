#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main() {
	srand((unsigned)time(NULL));
	int secret = rand();
	int nb = 0;
	int tentatives = 0;
	while (nb != secret) {
		printf("Choisis un nombre \n");
			scanf_s("%d", &nb);
			tentatives += 1;
		if (nb < secret) {
			printf("Plus \n");
			
		}
		if (nb > secret)
			printf("Moins \n");
		if (nb == secret) {
			printf("Tu as trouve en %d essais !",tentatives);
			}
	}
}