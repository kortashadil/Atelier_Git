#ifndef LISTE_H_INCLUDED
#define LISTE_H_I
#include <stdio.h>

typedef struct {
int j ;
int m ;
int a ;
}Date;

typedef struct  {
int id_liste;
int id_election ;
int id_electeur1 ;
int id_electeur2 ;
int id_electeur3 ;
char orientation [20] ;
Date dc;
int nvote;
}liste_E;

typedef struct {
int id_liste;
int id_election;
int vote;
int vote_b;
/*int nbvote;*/
}vote;

int ajouterliste(char *filename, liste_E le);
int ajoutervote(char *filename,vote v);
int modifierliste( char *filename, int id_liste, liste_E nouv);
int modifiervote( char *filename, int id_liste, vote nouv);
int supprimerliste(char *filename, int id_liste );
int supprimervote(char *filename, int id_liste );
liste_E chercherliste(char *filename, int id_liste);
vote cherchervote(char *filename, int id_liste);
int nbv(char *filename,int id_liste);
void le_ordre(char *liste,char *utilisateur,liste_E t[],int *taille);
/*int nbv(char *filename,char * filenamee);
int L_ordre(char *filename);*/
#endif // LISTE_H_INCLUDED
