#include <string.h>
#include<stdlib.h>
#include"fonctions.h"
#include <gtk/gtk.h>
#include <stdio.h>
void ajouter (char login[],char password[], int role)
{
    FILE *f;
    f=fopen("users.txt","a+");
    if(f!=NULL){//si le fichier est ouvert
        fprintf(f,"%s %s %d \n",login,password,role);
    }
    fclose(f);
}
void afficher()
{
    FILE *f;
    f=fopen("users.txt","r");
    char login[20],password[20];
    int role;
    while(fscanf(f,"%s %s %d",login,password,&role)!=EOF){
        fprintf(f,"%s %s %d", login,password,role);
    }
    fclose(f);
}
int verifier(char login[],char password[])
{
    FILE *f;
    int role;
    char login1[20];char password1[20];
    f=fopen("users.txt","r");//ouvrir le fichier users.txt et verifier
   
    while(fscanf(f,"%s %s %d", login1,password1,&role )!=EOF){//end of file si le ficher est terminer
        if (strcmp(login1,login)==0 && strcmp(password1,password)==0)
        {
            fclose(f);
            return (role);
        }
    }
    fclose(f);
    return 0;
}

void ajouterfiche(fiche fi)
{
	FILE *f;
	f = fopen("fiche.txt","a");
	if(f!=NULL){
		fprintf(f,"%s %s %s %s %s %s %d %d %d %s %s %d\n",fi.id,fi.password,fi.nom,fi.prenom,fi.e_mail,fi.num_tel,fi.jour,fi.mois,fi.annee,fi.adresse,fi.sexe,fi.role);
	}
	fclose(f);

}


void afficherfiche(GtkWidget *filistview)
{ 
enum {
       COL_ID,
       COL_PASSWORD,
       COL_NOM,
       COL_PRENOM,
       COL_E_MAIL, 
       COL_NUM_TEL,
       COL_JOUR,
       COL_MOIS,
       COL_ANNEE,
       COL_ADRESSE,
       COL_SEXE,
       NUM_COLS	
      };
char id[20],password[20],nom[20],prenom[20],e_mail[30],sexe[10],adresse[50],num_tel[50]; int jour,mois,annee,role;
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
GtkTreeIter *iter;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("fiche.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s %d\n",id,password,nom,prenom,e_mail,num_tel,&jour,&mois,&annee,adresse,sexe,&role)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
			  COL_ID, id,
		          COL_PASSWORD, password,                          
			  COL_NOM, nom,
		          COL_PRENOM, prenom,
		          COL_E_MAIL, e_mail,
			  COL_NUM_TEL,num_tel,
                          COL_JOUR,jour,
                          COL_MOIS,mois,
                          COL_ANNEE,annee,
			  COL_ADRESSE,adresse,
			  COL_SEXE,sexe,
                   
                       -1);}


       	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("id",celrender,"text",COL_ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("password",celrender,"text",COL_PASSWORD,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Nom",celrender,"text",COL_NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Prenom",celrender,"text",COL_PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("e_mail",celrender,"text",COL_E_MAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("num_tel",celrender,"text",COL_NUM_TEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
	
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("jour",celrender,"text",COL_JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("mois",celrender,"text",COL_MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("annee",celrender,"text",COL_ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Adresse",celrender,"text",COL_ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
	
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("sexe",celrender,"text",COL_SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	gtk_tree_view_set_model (GTK_TREE_VIEW(filistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}
//modifier client


void modifierfiche(char id[],char password[],char nom[],char prenom[],char e_mail[],char num_tel[],int jour,int mois,int annee,char adresse[],char sexe [] )
{char id1[20],password1[20],nom1[20],prenom1[20],e_mail1[30],adresse1[50],sexe1[10], num_tel1[50]; int jour1,mois1,annee1;

    FILE *f, *tmp;
    f=fopen("fiche.txt","r");
    tmp=fopen("tmp.txt","a+");
    while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s",id1,password1,nom1,prenom1,e_mail1,num_tel1,&jour1,&mois1,&annee1,adresse1,sexe1)!=EOF){
        if((strcmp(id,id1)!=0)){fprintf(tmp,"%s %s %s %s %s %s %d %d %d %s%s\n",id1,password1,nom1,prenom1,e_mail1,num_tel1,jour1,mois1,annee1,adresse1,sexe1);}
else fprintf(tmp,"%s %s %s %s %s %s %d %d %d %s %s\n",id,password,nom,prenom,e_mail,num_tel,jour,mois,annee,adresse,sexe);
}
fclose(f);
fclose(tmp);
remove("fiche.txt");
rename("tmp.txt","fiche.txt");
} 



void supprimerfiche(char id[],char password[],char nom[],char prenom[],char e_mail[],char num_tel[],int jour,int mois,int annee,char adresse[],char sexe [])
{    
    char idNU[20],passwordNU[20], nomNU[20],prenomNU[20],e_mailNU[30],sexeNU[10],adresseNU[50],num_telNU[50]; 
int jourNU,moisNU,anneeNU;
    
    FILE *f , *tmp;
    f=fopen("fiche.txt","r");
    tmp=fopen("tmp.txt","a+");
   while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s %s",idNU,passwordNU,nomNU,prenomNU,e_mailNU,num_telNU,&jourNU,&moisNU,&anneeNU,adresseNU,sexeNU)!=EOF){
        if((strcmp(id,idNU)!=0))
{fprintf(tmp,"%s %s %s %s %s %s %d %d %d %s %s\n",idNU,passwordNU,nomNU,prenomNU,e_mailNU,num_telNU,jourNU,moisNU,anneeNU,adresseNU,sexeNU);}
}
fclose(f);
fclose(tmp);
remove("fiche.txt");
rename("tmp.txt","fiche.txt");
}
