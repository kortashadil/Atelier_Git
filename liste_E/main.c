#include <stdio.h>
#include <string.h>
#include"liste.h"

int main()
{
vote v1={10,40,20,1},v2={10,30,40,1},v3={20,40,70,1},v4={20,40,40,1},v5={10,50,70,2},v6={10,40,50,1} ;
liste_E le1= {40,10,01,02,03,"droit",22,12,2022},le2= {00,34,40,11,22,"centre",23,12,2022},le3= {77,40,13,11,12,"gauche",22,12,2022},le4= {88,90,14,11,12,"droit",22,12,2022};
    int x,y,z,k,f,h,nb,tai;
    liste_E t[1000];

x =ajouterliste("liste.txt", le1);
x =ajouterliste("liste.txt", le2);
x =ajouterliste("liste.txt", le3);
x =ajouterliste("liste.txt", le4);

  if(x==1)
        printf("\najout de liste avec succés\n");
  else printf("\nechec ajout liste");


k =ajoutervote("vote.txt", v1);
k =ajoutervote("vote.txt", v2);
k =ajoutervote("vote.txt", v3);
k =ajoutervote("vote.txt", v4);
k =ajoutervote("vote.txt", v5);
k =ajoutervote("vote.txt", v6);

  if(k==1)
        printf("\najout de vote avec succés");
  else printf("\nechec ajout vote");

nb =nbv("vote.txt",88);
printf("\nle nombre de vote pour la liste de l'id 10 est %d\n",nb);
tai=0;
le_ordre("liste.txt","vote.txt",t,&tai);
printf("le nombre des liste est %d\n",tai);

/*liste_E le1= {40,10,01,02,03,"droit",22,12,2022},le2= {00,34,40,11,22,"centre",23,12,2022},le3= {77,40,13,11,12,"gauche",22,12,2022},le4= {88,90,14,11,12,"droit",22,12,2022};
nbv("vote.txt","40");
nbv("vote.txt","00");
nbv("vote.txt","77");
nbv("vote.txt","88");
}
liste_E le1= {40,10,01,02,03,"droit",22,12,2022},le2= {00,34,40,11,22,"centre",23,12,2022},le3= {77,40,13,11,12,"gauche",22,12,2022},le4= {88,90,14,11,12,"droit",22,12,2022};
int a=L_ordre("vote.txt");
if(a==0)
printf("erreur de tri");
else
printf("tri avec succès");
}*/

/*y=modifierliste("liste.txt",10, le2);
   if(y==1)
        printf("\nModification de liste avec succés");
   else printf("\nechec Modification liste");


h=modifiervote("vote.txt",10, v3);
   if(h==1)
        printf("\nModification de vote avec succés");
   else printf("\nechec Modification vote");


z=supprimerliste("liste.txt",1 );
    if(z==1)
        printf("\nSuppression de liste avec succés");
    else printf("\nechec Suppression liste");


f=supprimervote("vote.txt",1 );
    if(f==1)
        printf("\nSuppression de vote avec succés");
    else printf("\nechec Suppression vote");


le3=chercherliste("liste.txt",00 );
    if(le3.id_liste==-1)
        printf("liste introuvable");

v2=cherchervote("vote.txt",20 );
    if(v2.id_liste==-1)
        printf("vote introuvable");*/

    return 0;
}

