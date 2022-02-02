
#include <stdio.h>
#include <stdlib.h>

void secondeEnHeure(int* seconde, int* minute, int* heure){
    int entrer;
    printf("Donner la valeur en seconde a convertire sous le format\nH:M:S\n");
    scanf("%d", &entrer);
    if(entrer>=3600){
        *heure=entrer/3600;
        entrer= entrer-(3600 * *heure);
        printf("%d H ",*heure);
    }

    if(entrer>=60){
        *minute=entrer/60;
        entrer= entrer-(60 * *minute);
        printf("%d m ",*minute);
    }
    *seconde = entrer;
    printf("%d s\n",*seconde);
}


void minuteEnHeure(int* seconde, int* minute, int* heure){
    int entrer;
    printf("Donner la valeur en minutes a convertire sous le format\nH:M:S\n");
    scanf("%d", &entrer);
    if(entrer>=60){
        *heure=entrer/60;
        entrer=entrer-(60 * *heure);
        printf("%d H ",*heure);
    }
    *minute = entrer;
    printf("%d m\n",*minute);
}

