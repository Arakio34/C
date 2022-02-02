#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

#define LONGUEUR_MAX 40

int main(){
	int a;
	char citation[] = "Par son système de codage, il était éventuellement possible de représenter un code de différentes manières en UTF-8, ce qui pouvait poser un problème de sécurité : un programme mal écrit peut accepter un certain nombre de représentations UTF-8, normalement invalides selon la RFC 36298 et dans les spécifications (maintenant équivalentes entre elles) publiées par l’ISO 10646 et Unicode ; mais ce n’était pas le cas selon la spécification originale, qui permettait de les convertir comme un seul et même caractère.Ainsi, un logiciel détectant certaines chaînes de caractères (pour prévenir les injections SQL, par exemple) pouvait échouer dans sa tâche (ce n’est plus le cas si la conformité du codage avec la définition stricte et normalisée d’UTF-8 est vérifiée avant toute chose).Prenons un exemple tiré d’un cas réel de virus attaquant des serveurs HTTP du Web en 2001 ((en)Crypto-Gram: July 15, 2000 [archive] Microsoft IIS and PWS Extended Unicode Directory Traversal Vulnerability [archive] Microsoft IIS 4.0/5.0 Web Directory Traversal Vulnerability [archive]). Une séquence à détecter pourrait être « /../ » représentée en ASCII (a fortiori en UTF-8) par les octets « 2F 2E 2E 2F » en notation hexadécimale. Cependant, une manière malformée de coder cette chaîne en UTF-8 serait « 2F C0 AE 2E 2F », appelée aussi en anglais overlong form (forme superlongue). Si le logiciel n’est pas soigneusement écrit pour rejeter cette chaîne, en la mettant par exemple sous forme canonique, une brèche potentielle de sécurité est ouverte. Cette attaque est appelée directory traversal.Les logiciels acceptant du texte codé en UTF-8 ont été blindés pour rejeter systématiquement ces formes longues car non conformes à la norme : soit le texte entier est rejeté ; mais parfois les séquences invalides sont remplacées par un caractère de substitution (généralement U+FFFD si l’application accepte et traite ce caractère normalement ; parfois un point d’interrogation ou le caractère de contrôle de substitution SUB U+001A de l’ASCII, qui peuvent poser d’autres problèmes de compatibilité) ; moins souvent, ces séquences interdites sont éliminées silencieusement (ce qui est très peu recommandé).";

	FILE *fichier = fopen("test","w+");
	if(fichier==NULL){
		printf("Erreur dans l'ouverture ou la création du fichier \n");
	
	}
	else{

		fprintf(fichier,"%s\n",citation);
		afficheFichier(fichier);
		
		//viderFichier(fichier);
		a=nbChar(fichier);
		printf("nb char : %d \n",a);
	
		afficheFichier(fichier);	
		fclose(fichier);
	}
	return 0; 
}

