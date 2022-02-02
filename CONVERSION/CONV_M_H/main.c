#include <stdio.h>
#include <stdlib.h>
#include "Convertiseur_Seconde_Minute_en_Heure.h"


int main(){
     
    int seconde=0;
    int minute=0;
    int heure=0;
    int choix;
    int test;

    printf("Bienvenue dans le convertiseur de seconde / minute en heure.\n");
    while(test !=3){
        printf("Choisiser le mode soit :\n1 : minute => heure \n2 : seconde => heure \n");
        scanf("%d",&choix);
        if(choix==1){
            minuteEnHeure(&seconde, &minute, &heure);
            test=3;
        }

        else if(choix==2){
            secondeEnHeure(&seconde, &minute, &heure);
            test=3;
        }

        else if(choix!=1||choix!=2){
            printf("Veuillez faire un choix correct !\n");
            continue;
        }
    }
    return 0;
}

