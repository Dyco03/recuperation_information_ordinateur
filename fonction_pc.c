#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction_pc.h"

int nbr_info(FILE *fichier,int nbr){  
	nbr=0;
	char ligne[300];
	rewind(fichier);
	while(fgets(ligne,sizeof(ligne),fichier)){
		nbr++;
	}
	return nbr;
}
information *recuperation(information pc[],FILE *fichier){
	char ligne[300];
	int nbr_ligne=0;
	nbr_ligne=nbr_info(fichier,nbr_ligne);
	pc=(information*)malloc(nbr_ligne*sizeof(information)); //premier allocation de pc
	int i=0;
	rewind(fichier);
	while((fgets(ligne,sizeof(ligne),fichier))!=NULL){
		sscanf(ligne,"%[^,],%[^,],%[^\n]",pc[i].etiquette,pc[i].modele,pc[i].mac);
		i++;
						
	}
	return pc;
}

information *trie(information pc[],const int indice){
	for(int i=1; i<indice; i++){
		for(int j=i+1; j<indice; j++){
			if(strcmp(pc[i].etiquette,pc[j].etiquette)>0){
				information temp;
				temp=pc[i];
				pc[i]=pc[j];
				pc[j]=temp;
			}
			else if(strcmp(pc[i].etiquette,pc[j].etiquette)==0){
				for(int k=1; k<indice; k++){
					for(int p=k+1; p<indice; p++){
						if(strcmp(pc[k].modele,pc[p].modele)>0){
							information temp;
							temp=pc[k];
							pc[k]=pc[p];
							pc[p]=temp;
						}
					}
				}
			}
		}
	}
	return pc;
}	
