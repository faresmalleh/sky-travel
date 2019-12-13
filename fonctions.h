//#ifndef reservation_H_INCLUDED
//#define FONCTIONS_H_
#include <gtk/gtk.h>


typedef struct
{
char id[20];
char password[20];
char nom[20];
char prenom[20];
char e_mail [30];
int jour;
int mois;
int annee;
char num_tel[50];
char adresse [50];
char sexe[10];
int role;
}fiche;

void supprimerfiche(char id[],char password[],char nom[],char prenom[],char e_mail[],char num_tel[],int jour,int mois,int annee,char adresse[],char sexe []);
void modifierfiche(char id[],char password[],char nom[],char prenom[],char e_mail[],char num_tel[],int jour,int mois,int annee,char adresse[],char sexe [] );
void afficherfiche(GtkWidget *filistview);
void ajouterfiche(fiche fi);
void ajouter (char login [], char password[], int role);
void afficher();
int verifier(char login[], char password[]);

//#endif
