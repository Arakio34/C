#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include "ell17lib.h"



void my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

int main(int argv, char ** argc)
{



	const char * nom_tty = "/dev/ttyUSB0";
	int port_serie = open(nom_tty, O_RDWR);
	struct termios tty;

	struct instruction_s inst_all[NB_INST];
	creat_inst(inst_all);

	struct message_s message_all[NB_MSG], reponseIN, reponseGJ;
	creat_msg(message_all);
	reponseIN = message_all[0];
	reponseGJ = message_all[4];

	
	char * reponse;
	reponse = malloc(sizeof(char)*256);
	printf("------------DEBUTS DE LA CONFIGURATION-----------------\n");
	parametrage(nom_tty, port_serie, &tty);

	printf("------------FIN DE LA CONFIGURATION-----------------\n\n");

	printf("------------DEBUTS DU PROGRAMME PRINCIPAL----------------\n");

	envoie(reponse,0,tty,port_serie,&inst_all[9], NULL);	
	traitement_message(reponse,&reponseIN);
	affichage_message(reponseIN);

	envoie(reponse,0,tty,port_serie,&inst_all[2],NULL);	
	traitement_message(reponse,&reponseGJ);
	affichage_message(reponseGJ);

	envoie(NULL,0,tty,port_serie,&inst_all[13],"00000034");

	printf("------------FIN DU PROGRAMME PRINCIPAL----------------\n\n");
	
	printf("------------SEQUENCE DE FIN----------------\n\n");
	close(port_serie);	
	free(reponse);
	printf("Nous somme maintenant deconnecté du port serie : \"%s\"\n",nom_tty);

	return 0;
}

