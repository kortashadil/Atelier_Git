#include<stdio.h>
#include<string.h>
#include"liste.h"
int ajouterliste(char * filename,liste_E le ){
    FILE * f=fopen(filename,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d %d %d %d %s %d\n",le.id_liste,le.id_election,le.id_electeur1,le.id_electeur2,le.id_electeur3,le.dc.j,le.dc.m,le.dc.a,le.orientation,le.nbvote);
        fclose(f);
        return 1;
    }
    else return 0;

}
int ajoutervote(char * filename,vote v){
     FILE * f=fopen(filename,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d\n",v.id_electeur1,v.choix);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifierliste( char * filename, int id_liste, liste_E nouv )
{
    int tr=0;
    liste_E le;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %d %d %s %d\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation,&le.nbvote)!=EOF)
        {
            if(le.id_liste== id_liste)
            {
                fprintf(f2,"%d %d %d %d %d %d %d %d %s %d\n",nouv.id_liste,nouv.id_election,nouv.id_electeur1,nouv.id_electeur2,nouv.id_electeur3,nouv.dc.j,nouv.dc.m,nouv.dc.a,nouv.orientation,nouv.nbvote);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s %d\n",le.id_liste,le.id_election,le.id_electeur1,le.id_electeur2,le.id_electeur3,le.dc.j,le.dc.m,le.dc.a,le.orientation,le.nbvote);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

int modifiervote( char * filename, int id_electeur1, vote nv )
{
    int tr=0;
    vote v;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d\n",&v.id_electeur1,&v.choix)!=EOF)
        {
            if(v.id_electeur1== id_electeur1)
            {
                fprintf(f2,"%d %d\n",nv.id_electeur1,nv.choix);
                tr=1;
            }
            else
                fprintf(f2,"%d  %d\n",v.id_electeur1,v.choix);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nv.txt", filename);
    return tr;

}

int supprimerliste(char * filename, int id_liste)
{
    int tr=0;
    liste_E le;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %d %d %s %d\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation,&le.nbvote)!=EOF)
        {
            if(le.id_liste= id_liste)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s %d\n",le.id_liste,le.id_election,le.id_electeur1,le.id_electeur2,le.id_electeur3,le.dc.j,le.dc.m,le.dc.a,le.orientation,le.nbvote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimervote(char * filename, int id_electeur1)
{
    int tr=0;
    vote v;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d\n",&v.id_electeur1,&v.choix)!=EOF)
        {
            if(v.id_electeur1= id_electeur1)
                tr=1;
            else
                fprintf(f2,"%d %d\n",v.id_electeur1,v.choix);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nv.txt", filename);
    return tr;
}


liste_E chercherliste(char * filename, int id_liste)
{
    liste_E le;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %d %d %d %d %s %d\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation,&le.nbvote)!=EOF)
        {
            if(le.id_liste== id_liste)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        le.id_liste=-1;
    return le;

}

vote cherchervote(char * filename, int id_electeur1)
{
    vote v;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d\n",&v.id_electeur1,&v.choix)!=EOF)
        {
            if(v.id_electeur1== id_electeur1)
                tr=1;
        }
    } 
    fclose(f);
    if(tr==0)
        v.id_electeur1=-1;
    return v;

}


/*int nbv(char *filename,int id_liste)
{
vote v;
int nbvote;
FILE *f=fopen(filename,"r");
if (f!=NULL )

 {
  while (fscanf(f,"%d %d %d %d %d",&v.id_liste,&v.id_election,&v.vote,&v.vote_b,&v.nbvote)!=EOF)
  {
   if ((v.id_liste==id_liste))
   {
    v.nbvote++;
    fprintf(f,"%d %d %d %d %d",v.id_liste,v.id_election,v.vote,v.vote_b,v.nbvote);
   }
fclose(f);
return nbvote;
 }
}


int le_ordre(char *filename,char *filenamee,liste_E t[],int *taille)
{

int i,j,max;
liste_E tampon ;
liste_E le ;
FILE * f=fopen(filename,"r");
if(f!=NULL)
{
  while( fscanf(f,"%d %d %d %d %d %d %d %d %s %d\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation,&le.nbvote)!=EOF)
  { 
    t[*taille].id_liste=le.id_liste;
    t[*taille].nbvote=nbv(filenamee,le.id_liste);
    (*taille)++;
  }
fclose(f);
}

for (i=0;i<*taille-1;i++)
{
  max=i ;
  for (j=i+1;j<*taille;j++) 
  {

   if (t[j].nbvote>t[max].nbvote)
    max=j;
  }
tampon=t[i];
t[i]=t[max];
t[max]=tampon;

}
for (i=0;i<*taille;i++)
{
printf("%d %d\n",t[i].id_liste,t[i].nbvote);
}
}

return 0;
}*/


int nbv(char * filename,int id_liste)
{
vote v ;
int nbvote=0;
FILE * f=fopen(filename,"r");
if(f!=NULL)
 {
    while (fscanf(f,"%d %d\n",&v.id_electeur1,&v.choix) != EOF)
      {
            if (v.choix==id_liste)

             nbvote++;
       }
       fclose(f);
 }
printf("le nombre de vote pour la liste ayant un id %d est %d\n",id_liste,nbvote);
       return nbvote;
}
int le_ordre(char *filename,char *filenamee,liste_E t[],int *taille)
{
*taille=0;
int i,j,max;

liste_E tampon ;
liste_E le ;
FILE * f=fopen(filename,"r");
if(f!=NULL){
  while( fscanf(f,"%d %d %d %d %d %d %d %d %s %d\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation,&le.nbvote)!=EOF)
   { 
      t[*taille].id_liste=le.id_liste;

      t[*taille].nbvote=nbv(filenamee,le.id_liste);
(*taille)++;

   }

fclose(f);}

for (i=0;i<*taille-1;i++)

{

max=i ;

for (j=i+1;j<*taille;j++)
{

if (t[j].nbvote>t[max].nbvote)

max=j;

}

tampon=t[i];

t[i]=t[max];

t[max]=tampon;

}
for (i=0;i<*taille;i++){
    printf("%d %d\n",t[i].id_liste,t[i].nbvote);}
return *taille ;
}

