#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "file.h"

// Créer un jeux du juste prix avec :
// - counteur de coup 
// - niveau de difficulter
// - proposition de continuer

int choixDifficulter();
int generationNombre(int difficulter);
void jeux(int nbAleatoire,int nbMax);
int rejouer();
int conteur=0;


int main(){
    srand(time(NULL));
    int nbAleatoire;
    int nbMax;
    int replay=2;

    while(replay==2){
        conteur=0;
        int difficulter = choixDifficulter();
        nbMax=difficulter;
        nbAleatoire = generationNombre(difficulter);
        jeux(nbAleatoire,nbMax);
        replay=rejouer();
    }
}

int choixDifficulter(){
    int difficulter = 0;
    int choix;
    printf("Bonjour. Pour lancer une partie vous devez choisire une difficulter\n");
    while (difficulter==0){
        
        printf("1 : Facile 2 : Normal 3 : Difficile\n");
        scanf("%d",&choix);

        switch(choix){
            case 1:
            difficulter = 100;
            printf("Vous avez choisit le mode facile ! Bonne chance.\n");
            break;
            ;
            case 2:
            difficulter = 1000;
            printf("Vous avez choisit le mode medium ! Bonne chance.\n");
            break;
            ;
            case 3:
            difficulter = 10000;
            printf("Vous avez choisit le mode difficile !  Vous ètes un dur vous bonne chance!\n");
            break;
            ;
            default:
            printf("Vous devez choisire une valeur correct !\n");
            continue;
            ;
        }
    }
    return difficulter;
}


int generationNombre(int difficulter){
    int nbRand;
    switch (difficulter)
    {
        case 100:
            nbRand=rand()%100;
            break;
        
        case 1000:
            nbRand=rand()%1000;
            break;

        case 10000:
            nbRand=rand()%10000;
            break;
    }
    return nbRand;
}

void jeux(int nbAleatoire,int nbMax){
    int nbRepMax=nbMax/10;
    int nbRep=0;
    int reponse;
    while(nbAleatoire!=reponse){
        conteur++;
        printf("Proposer un nombre entre 1 et %d\n", nbMax);
        scanf("%d",&reponse);
        if(reponse==nbAleatoire){
            printf("Bien jouer tu as gagner !\n");
            continue;
        }
        else if(reponse>nbAleatoire){
            printf("%d est trop grand !\n",reponse);
        }
        else if(reponse<nbAleatoire){
            printf("%d est trop petit !\n",reponse);
        }
        nbRep++;
        if(nbRep==nbRepMax){
            printf("Vous avez perdue désoler...\n");
            break;
        }
    }
}

int rejouer(){
    int rep=0;
    while(rep==0){
        printf("Le score est de : %d\n",conteur);
        printf("Voulez vous re faire une partie ?\n 1=non  ||  2=oui\n");
        scanf("%d",&rep);
        switch (rep)
        {
            case 1:
                break;

            case 2:
                break;

            default:
                printf("Saisissez un nombre valide ! \n");
                break;
        }
    }
    conteur=0;
    return rep;
}