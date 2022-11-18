#include<stdio.h>
#include"liste.h"
#include<string.h>
int ajouterliste(char * filename,liste_E le ){
    FILE * f=fopen(filename,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d %d %d %d %s\n",le.id_liste,le.id_election,le.id_electeur1,le.id_electeur2,le.id_electeur3,le.dc.j,le.dc.m,le.dc.a,le.orientation);
        fclose(f);
        return 1;
    }
    else return 0;

}
int ajoutervote(char * filename2,vote v){
     FILE * f=fopen(filename2,"a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d\n",v.id_liste,v.id_election,v.vote,v.vote_b);
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
        while(fscanf(f,"%d %d %d %d %d %d %d %d %s\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation)!=EOF)
        {
            if(le.id_liste== id_liste)
            {
                fprintf(f2,"%d %d %d %d %d %d %d %d %s\n",nouv.id_liste,nouv.id_election,nouv.id_electeur1,nouv.id_electeur2,nouv.id_electeur3,nouv.dc.j,nouv.dc.m,nouv.dc.a,nouv.orientation);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s\n",le.id_liste,le.id_election,le.id_electeur1,le.id_electeur2,le.id_electeur3,le.dc.j,le.dc.m,le.dc.a,le.orientation);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

int modifiervote( char * filename, int id_liste, vote nv )
{
    int tr=0;
    vote v;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d\n",&v.id_liste,&v.id_election,&v.vote,&v.vote_b)!=EOF)
        {
            if(v.id_liste== id_liste)
            {
                fprintf(f2,"%d %d %d %d\n",nv.id_liste,nv.id_election,nv.vote,nv.vote_b);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d\n",v.id_liste,v.id_election,v.vote,v.vote_b);

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
        while(fscanf(f,"%d %d %d %d %d %d %d %d %s\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation)!=EOF)
        {
            if(le.id_liste= id_liste)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s\n",le.id_liste,le.id_election,le.id_electeur1,le.id_electeur2,le.id_electeur3,le.dc.j,le.dc.m,le.dc.a,le.orientation);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimervote(char * filename, int id_liste)
{
    int tr=0;
    vote v;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d\n",&v.id_liste,&v.id_election,&v.vote,&v.vote_b)!=EOF)
        {
            if(v.id_liste= id_liste)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d\n",v.id_liste,v.id_election,v.vote,v.vote_b);
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
        while(tr==0&& fscanf(f,"%d %d %d %d %d %d %d %d %s\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation)!=EOF)
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

vote cherchervote(char * filename, int id_liste)
{
    vote v;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d\n",&v.id_liste,&v.id_election,&v.vote,&v.vote_b)!=EOF)
        {
            if(v.id_liste== id_liste)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        v.id_liste=-1;
    return v;

}


int nbv(char * filename,int id_liste)
{
vote v ;
int nvote=0;
FILE * f=fopen(filename,"r");
if(f!=NULL)
{
    while (fscanf(f,"%d %d %d %d\n",&v.id_liste,&v.id_election,&v.vote,&v.vote_b) != EOF)
      {
            if ((v.id_liste==id_liste)&&(v.vote==1))

             nvote++;
       }
       fclose(f);}
       return nvote;
}

void le_ordre(char *liste,char *utilisateur,liste_E t[],int *taille)
{

int i,j,max;
liste_E tampon ;
liste_E le ;
FILE * f=fopen(liste,"r");
if(f!=NULL)
{
  while( fscanf(f,"%d %d %d %d %d %d %d %d %s\n",&le.id_liste,&le.id_election,&le.id_electeur1,&le.id_electeur2,&le.id_electeur3,&le.dc.j,&le.dc.m,&le.dc.a,le.orientation)!=EOF)
   { 
      t[*taille].id_liste=le.id_liste;


      t[*taille].nvote=nbv(liste,le.id_liste);
(*taille)++;


   }


fclose(f);}

for (i=0;i<*taille-1;i++)

{

max=i ;

for (j=i+1;j<*taille;j++) 
{

if (t[j].nvote>t[max].nvote)

max=j;

}

tampon=t[i];

t[i]=t[max];

t[max]=tampon;

}
for (i=0;i<*taille;i++){
    printf("%d %d\n",t[i].id_liste,t[i].nvote);
}
}


/*int nbv(char *filename,char *filenamee)
{
vote v;
FILE *f=fopen("vote","r");
FILE *f2=fopen("nv.txt","w");
if (f==NULL || f2==NULL)
return 0;
else
{
while (fscanf(f,"%d %d",&v.id_liste,&v.nbvote)!=EOF){
if (strcmp(v.id_liste,.id_liste)!=0)
fprintf(f2,"%d %d",v.id_liste,v.nbvote);
else 
{
v.nbvote++;
fprintf(f2,"%d %d",v.id_liste,v.nbvote);
}}
fclose(f);
fclose(f2);
remove(filename);
rename("nv.txt",filename);
return 1;
}}

int L_ordre (char *filename)
{
int max=0;
vote aux;
vote t[100];
vote v;
int x=0;
int y=0; 
int i,j;
FILE *f=fopen("vote","r");
FILE *f2=fopen("nv.txt","w");
if(f==NULL || f2==NULL)
return 0;
else
{
while(fscanf(f,"%d %d",&v.id_liste,&v.nbvote)!=EOF){
t[y]=v;
y++;
}
for(i=0;i<y-1;i++)
{
max=i;
for(j=i+1;j<y;j++)
{
if(t[j].nbvote>t[max].nbvote)
max=j;
}
aux=t[i];
t[i]=t[max];
t[max]=aux;
}
while(x<y)
{
fprintf(f2,"%d %d",t[x].id_liste,t[x].nbvote);
x++;
}
}
fclose(f);
fclose(f);
remove(filename);
rename("nv.txt",filename);
return 1;
}*/

