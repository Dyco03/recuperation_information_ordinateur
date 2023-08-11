#ifndef FONCTION__PC_H
#define FONCTION__PC_H
#include <stdio.h>
typedef struct information{
	char etiquette[30];
	char modele[30];
	char mac[30];

}information;

int nbr_info(FILE *fichier,int nbr); //c'est le nombre d'information (nombre de lignes)

information *recuperation(information pc[],FILE *fichier);//la recuperation des informations qui etait deja dans info_pc.csv

information *trie(information pc[],const int indice);//trie de toutes les informations

#endif 
