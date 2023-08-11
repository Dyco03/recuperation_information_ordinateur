#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction_pc.h"

int main(){
	/*************************/
	FILE* fichier;
	fichier=fopen("info_pc.csv","a+");
	if(fichier==NULL){
		printf("erreur de flux");
		exit(1);
	}
	/*************************/
	rewind(fichier);
	char test[200];//sert a tester si les etiquettes,modeles sont deja existant
	if(fgets(test,200,fichier)==NULL){
	fprintf(fichier,"etiquette,modele,mac\n");
	}
	
	/*************************/
	int nbr_recup=0;
	nbr_recup=nbr_info(fichier,nbr_recup);
	information *pc=NULL;
	pc=recuperation(pc,fichier);
	
	/*************************/
	int choix;
	printf("Combien d'information voulez-vous entrer?:");scanf("%d",&choix);
	getchar();//pour prendre le '\n'
	printf("Vous allez entrer les informations.\n");
	/*************************premier teste*/
	int nbr_total=nbr_recup + choix;
	pc=realloc(pc,nbr_total*sizeof(information));  //deuxieme allocation de pc
	/*************************/
	for(int i=nbr_recup, j=1; i<nbr_total; i++, j++){
		printf("pc%d\n",j);
		printf("Entrer les informations.\n");
		printf("Etiquette:");fgets(pc[i].etiquette,30,stdin);
		pc[i].etiquette[strcspn((pc[i].etiquette),"\n")]='\0';//pour supprimer les caracteres de fin de chaines
		printf("Modele:");fgets(pc[i].modele,30,stdin);	
		pc[i].modele[strcspn((pc[i].modele),"\n")]='\0';
		printf("Mac:");fgets(pc[i].mac,30,stdin);
		pc[i].mac[strcspn((pc[i].mac),"\n")]='\0';
		system("clear");
	}
	/*********************************/
	fclose(fichier);
	fichier=fopen("info_pc.csv","w+");
	if(fichier==NULL){
		printf("erreur de flux");
		exit(1);
	}
	/*********************************/
	pc=trie(pc,nbr_total);
	/*********************************/
	
	for(int i=0; i<nbr_total; i++){//ajout de toutes les informations dans informations.csv
		fprintf(fichier,"%s,%s,%s\n",pc[i].etiquette,pc[i].modele,pc[i].mac);
	}
	printf("Enregistrement effectue\n");
	fclose(fichier);
	return 0;
}
