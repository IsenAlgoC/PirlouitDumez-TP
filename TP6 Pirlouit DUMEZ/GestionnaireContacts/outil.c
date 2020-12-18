#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom :Dumez                   Prénom :Pirlouit                        */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compléter code ici pour tableau
	// int idx;
	if (rep->nb_elts < MAX_ENREG)      //s'il y a la place pour mettre un contact de plus
	{
		compact(enr.tel);
		*(rep->tab + rep->nb_elts) = enr;      //on ajoute enr a la suite 
		rep->nb_elts++;                        // on incremente le nombre d'element
		modif = true;
	}
	else {
		return(ERROR);
	}

	
#else
#ifdef IMPL_LIST

	bool inserted = false;
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}

	}
	else {
		SingleLinkedListElem* tmp = rep->liste->head;
		int pos = 0;
		while ((tmp != NULL) && (est_sup(enr, tmp->pers))) { //tant qu'on est pas arrivé a la queue et que
                                                                               // l'element qu'on veut insérer est apres dans l'ordre alphabetique que l'element pos
				tmp = tmp->next;                                               //on passe a l'élément suivant
				pos++;
			}
		if (InsertElementAt(rep->liste,pos,enr) != 0) {       //on insere le nouveau contact a la position pos dans la liste
		rep->nb_elts += 1;
		modif = true;
		rep->est_trie = true;                                 //on a donc ajoutez au bon endroit le contact et le repertoire est déjà trié
		return(OK);
		}
	}


#endif
	
#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	// compléter code ici pour tableau
	if (rep->nb_elts >= 1)		/* s'il y a au moins un element ds le tableau */
	{						/* et que l'indice pointe a l'interieur */
		if (indice < rep->nb_elts) {
			for (int i = indice; i < rep->nb_elts; i++) {   //on decale les elements apres l'element supprimée de un vers la gauche
				*(rep->tab + i) = *(rep->tab + i + 1);       // on va donc "ecraser" la valeur enr a l'indice souhaité
			}
		}
	}
		rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
		modif = true;

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// code à compléter ici
	printf("Voici le repertoire :");
	printf("| %s", enr.nom);
	printf("| %s", enr.prenom);
	printf("| %s", enr.tel);



} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// code à compléter ici
	// comme fonction affichage_enreg, mais avec présentation alignées des infos
	printf("\n| %-30s", enr.nom);  //affiche sur 30 cases en collant à gauche
	printf("| %-30s", enr.prenom);
	printf("| %-20s", enr.tel);
	

} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	// code à compléter ici
	int i = 0;  //Version " a la main " sans utiliser strcmp
	/*while (enr1.nom[i] == enr2.nom[i]) {    //tant que les deux lettres sont égales
		i++;
		if (i >= MAX_NOM) {                 // si les deux noms sont identiques, on considere que le enr1 n'est pas sup à enr2
			return(false);
		}
	}
	if (enr1.nom[i] < enr2.nom[i]) {        //si la lettre a l'indice i de nom1 est avant celle de nom2, on return false
			return(false);
		}
		else {
			return(true);    // sinon nom1 est avant nom 2
		}
 */
	if (strcmp(enr1.nom, enr2.nom) > 0) {  //si le premier nom est avant le deuxieme dans l'ordre alphabetique on renvoie true
		return true;
	}
	else {
		if (strcmp(enr1.prenom, enr2.prenom) > 0) {  //si le premier prenom est avant le deuxieme dans l'ordre alphabetique on renvoie true
			return true;
		}
		else {
			return false;
		}

	}
}

 
/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB 
	// ajouter code ici pour tableau
	Enregistrement tmp; 
	for (int i = 0; i < rep->nb_elts-1; i++) {  //tri a bulle pour ranger dans l'ordre alphabétique
		for (int j = 0; j < rep->nb_elts-i-1; j++) {
			if (est_sup(*(rep->tab+j), *(rep->tab + j+1))) { //si le nom en haut est superieur a celui d en dessous on inverse
				tmp = *(rep->tab+j);                         //on permute les noms a l'aide d'une variable tampon
				*(rep->tab+j) = *(rep->tab + j+1);
				*(rep->tab + j+1) = tmp;
			}
		}
	}
	//printf("\n noms tries\n");

	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif


	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;		


#ifdef IMPL_TAB
							// ajouter code ici pour tableau
	ind_fin = rep->nb_elts;
	strcpy_s(tmp_nom, MAX_NOM * sizeof(char), nom);
	for (unsigned i = 0; i < strlen(tmp_nom); i++) {   // on met en majuscule le nom a chercher 
		tmp_nom[i] = toupper(tmp_nom[i]);
	}
	while ((i < ind_fin) && (!trouve)) {     //tant qu'on arrive pas a la fin du tableau
		strcpy_s(tmp_nom2, MAX_NOM * sizeof(char), ((rep->tab) + i)->nom);   //on copie le ième nom du repertoire
		for (unsigned j = 0; j < strlen(tmp_nom2); j++) {        //on met en majuscule le nom venant du repertoire
			tmp_nom2[j] = toupper(tmp_nom2[j]); 
		}
		if (strcmp(tmp_nom, tmp_nom2) == 0) {   //si les deux noms sont identiques
			trouve = true;
		}
		else {
			i++;
		}
	}
	
#else
#ifdef IMPL_LIST
							// ajouter code ici pour Liste
	ind_fin = rep->liste->size;
	SingleLinkedListElem* tmp = rep->liste->head;
	for (int i = 0; i < ind; i++) {
		tmp = tmp->next;
	}
	strcpy_s(tmp_nom, MAX_NOM * sizeof(char), nom);
	for (unsigned i = 0; i < strlen(tmp_nom); i++) {   // on met en majuscule le nom a chercher 
		tmp_nom[i] = toupper(tmp_nom[i]);
	}
	while ((i < ind_fin) && (!trouve)) {                               //rechercher le mot tant qu'on arrive pas a la queue
		strcpy_s(tmp_nom2, MAX_NOM * sizeof(char), tmp->pers.nom);
		for (unsigned j = 0; j < strlen(tmp_nom2); j++) {            //on met le ième mot de la liste en majuscule
			tmp_nom2[j] = toupper(tmp_nom2[j]);
		}
		if (strcmp(tmp_nom, tmp_nom2) == 0) {         //si on trouve le nom recherché dans la liste
			trouve = true;
		}
		else {
			i++;
			tmp = tmp->next;            //on passe à l'élément suivant dans la liste
		}
	}

#endif
#endif

	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char* s)
{
	// compléter code ici
	int nbElemSupp = 0;              
	unsigned i = 0;
	unsigned taille = strlen(s);
	//printf("taille de la chaine : %d " ,taille);
	while (47 > s[taille - 1] || s[taille - 1] > 58) {   //on reduit la taille de la chaine tant que le dernier caractere est non numérique
		taille--;                                        // pour ne pas considerer les tirets en fin de chaine qui créerait des bugs par exemple
	}
	//printf("taille de la chaine : %d ", taille);

	while (i < taille-1) {
		if ((47 > s[i]) || (58 < s[i])) {     //on verifie si le caractere est non numerique (non compris dans l'intervalle de A à Z en code ASCII
			//printf(" pas un nombre : %c", s[i]);
			nbElemSupp++;                     //le nombre d'element supprimé augmente de 1
			for (unsigned j = i; j < taille-1; j++) {  //on decale tout vers la gauche pour ecraser la valeur a supprimer
				*(s + j) = *(s + j + 1);
			}
		}
		else {
			i++;
		}
	}
	s[taille - nbElemSupp] = '\0';   //on ferme la chaine apres le dernier caractère numerique
	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	char buffer[sizeof(Enregistrement) + 2];   // taille d'un enregistrement + les deux ";"
	err = fopen_s(&fic_rep, nom_fichier, "w");
	if ((err == 0) && (fic_rep != 0) ) {
		//printf("The file was opened");
		for (int i = 0; i < rep->nb_elts; i++) {
			sprintf_s(buffer, sizeof(Enregistrement), "%s;%s;%s\n", ((rep->tab) + i)->nom, ((rep->tab) + i)->prenom, ((rep->tab) + i)->tel);
			fputs(buffer, fic_rep);
		}
	}
	else {
		printf("The file was not opened");
		return(err);
	}

	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	char buffer[sizeof(Enregistrement) + 2];   // taille d'un enregistrement + les deux ";"
	err = fopen_s(&fic_rep, nom_fichier, "w");
	if ((err == 0) && (fic_rep != 0)) { //si le fichier s'est ouvert correctement
		printf("The file was opened");
		SingleLinkedListElem *tmp=rep->liste->head ;
		for (int i = 0; i < rep->nb_elts; i++) {
			sprintf_s(buffer, sizeof(Enregistrement), "%s;%s;%s\n", (tmp->pers.nom) , (tmp->pers.prenom) , (tmp->pers.tel ));
			fputs(buffer, fic_rep);
			tmp = tmp->next;
		}
	}
	else {
		printf("The file was not opened");
		return(err);
	}


#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{

			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
														// ajouter code implemention liste
#endif
#endif
				Enregistrement new;
				if (lire_champ_suivant(buffer, &idx, new.nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, new.prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, new.tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
				InsertElementAt(rep->liste, num_rec, new);
			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */