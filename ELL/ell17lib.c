#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include "ell17lib.h"

// Cette librairie permet le controle du motreur ELL17 de la marque Thorlabs

///////////////////////////////////////////
//DONE
///////////////////////////////////////////
void creat_inst(struct instruction_s list_instruction[NB_INST])
{
	list_instruction[0].commande = "bw\0";
	list_instruction[0].nb_octet = 3;

	list_instruction[1].commande = "fw\0";
	list_instruction[1].nb_octet = 3;
	
	list_instruction[2].commande = "gp\0";
	list_instruction[2].nb_octet = 3;

	list_instruction[3].commande = "ga\0";
	list_instruction[3].nb_octet = 4;

	list_instruction[4].commande = "is\0";
	list_instruction[4].nb_octet = 4;

	list_instruction[5].commande = "ms\0";
	list_instruction[5].nb_octet = 3;

	list_instruction[6].commande = "ca\0";
	list_instruction[6].nb_octet = 4;
	
	list_instruction[7].commande = "ho\0";
	list_instruction[7].nb_octet = 4;
	
	list_instruction[8].commande = "go\0";
	list_instruction[8].nb_octet = 3;

	list_instruction[9].commande = "in\0";
	list_instruction[9].nb_octet = 3;

	list_instruction[10].commande = "gj\0";
	list_instruction[10].nb_octet = 3;


	list_instruction[11].commande = "i1\0";
	list_instruction[11].nb_octet = 3;

	list_instruction[12].commande = "i2\0";
	list_instruction[12].nb_octet = 3;

	list_instruction[13].commande = "ma\0";
	list_instruction[13].nb_octet = 11;
	
	// L'instruction mr (move relative) permet de deplacer 
	// le moteur en lui donnant une distance a parourire.
	// La valeur ce donne en Hexadecimal et le pas minimum de 50 um 
	// s'obtient avec la valeur "00000034"
	list_instruction[14].commande = "mr\0";
	list_instruction[14].nb_octet = 11;
	
	list_instruction[15].commande = "us\0";
	list_instruction[15].nb_octet = 3;

	list_instruction[16].commande = "c1\0";
	list_instruction[16].nb_octet = 3;

	list_instruction[17].commande = "c2\0";
	list_instruction[17].nb_octet = 3;

	list_instruction[18].commande = "s1\0";
	list_instruction[18].nb_octet  = 3;
	
	list_instruction[19].commande = "s2\0";
	list_instruction[19].nb_octet = 3;

	list_instruction[20].commande = "gs\0";
	list_instruction[20].nb_octet = 3;

	list_instruction[21].commande = "gv\0";
	list_instruction[21].nb_octet = 3;

	list_instruction[22].commande = "b1\0";
	list_instruction[22].nb_octet = 7;
	
	list_instruction[23].commande = "b2\0";
	list_instruction[23].nb_octet = 7;

	list_instruction[24].commande = "f1\0";
	list_instruction[24].nb_octet = 7;

	list_instruction[25].commande = "f2\0";
	list_instruction[25].nb_octet = 7;

	list_instruction[26].commande = "so\0";
	list_instruction[26].nb_octet = 11;

	list_instruction[28].commande = "sj\0";
	list_instruction[28].nb_octet = 3;

	list_instruction[29].commande = "sv\0";
	list_instruction[29].nb_octet = 5;
}

void traitement_message(char * message_brute, struct message_s * message)
{
	message->donnees = malloc(sizeof(char*)*message->nb_champ_donne);
	int sommeur = 0; 
	for(int i = 0; i< message->nb_champ_donne;i++)
	{
		message->donnees[i] = malloc(sizeof(char)*message->taille_champ[i]);

		for(int y = 0 ; y < message->taille_champ[i];y++,sommeur++)
		{
			message->donnees[i][y] = message_brute[sommeur];
		}
	}
}


void affichage_message(struct message_s message)
{
	for(int i = 0; i< message.nb_champ_donne;i++)
	{
		printf("Donne numeros %d : %s\n",i,message.donnees[i]);
	}
	
}

// Cree les different types de message 
void creat_msg(struct message_s list_messages[NB_MSG])
{
	// in 8 
	list_messages[0].nb_champ_donne = 8;
	list_messages[0].taille_champ = malloc(sizeof(int)*list_messages[0].nb_champ_donne);


	int tab1[] = {3,2,8,4,2,2,4,8};
	for(int i = 0; i < list_messages[0].nb_champ_donne ; i++)
	{
	
		list_messages[0].taille_champ[i] = tab1[i];
	}
	// gs 2
	list_messages[1].nb_champ_donne = 2;
	list_messages[1].taille_champ = malloc(sizeof(int)*list_messages[1].nb_champ_donne);

	int tab2[] = {3,2};
	for(int i = 0; i < list_messages[1].nb_champ_donne;i++)
	{
	
		list_messages[1].taille_champ[i] = tab2[i];
	}

	// i1 i2 i3 ... 8
	list_messages[2].nb_champ_donne = 8;
	list_messages[2].taille_champ = malloc(sizeof(int)*list_messages[2].nb_champ_donne);

	int tab3[] = {3,1,1,4,4,4,4,4};

	for(int i = 0; i < list_messages[2].nb_champ_donne;i++)
	{
	
		list_messages[2].taille_champ[i] = tab3[i];
	}

	// c1 c2 c3 ... 4
	list_messages[3].nb_champ_donne = 4;
	list_messages[3].taille_champ = malloc(sizeof(int)*list_messages[3].nb_champ_donne);

	int tab4[4]= {3,2,4,513};

	for(int i = 0; i < list_messages[3].nb_champ_donne;i++)
	{
	
		list_messages[3].taille_champ[i] = tab4[i];
	}

	// gj go 
	list_messages[4].nb_champ_donne = 2;
	list_messages[4].taille_champ = malloc(sizeof(int)*list_messages[4].nb_champ_donne);

	int tab5[2]= {3,8};

	for(int i = 0; i < list_messages[4].nb_champ_donne;i++)
	{
	
		list_messages[4].taille_champ[i] = tab5[i];
	}



}

// Crée toute les instruction possible

// Fonction permetent d'envoyer des instruction 
void envoie(char * reponse, int numero_moteur, struct termios tty, int port_serie, struct instruction_s * inst, char * data)
{
	char msg_total[inst->nb_octet];
	char read_buff[256];
	int nb_byte;
	mise_en_forme(numero_moteur,msg_total,*inst,data);

	printf("\n LE MESSAGE %s\n",msg_total);
	write(port_serie, msg_total,sizeof(msg_total));

	if(reponse == NULL)
	{
		return;
	}

	nb_byte = read(port_serie, &read_buff,sizeof(read_buff));
	for(int i = 0; i<nb_byte; i++)
	{
		if(i==nb_byte)
		{
			reponse[i]='\0';
		}
		reponse[i] = read_buff[i];	
	}	
}


void mise_en_forme(int numero, char * msg_total, struct instruction_s msg_partiel, char * data)
{
	if(numero < 9)
	{
		msg_total[0] = numero + '0';
	}
	else
	{
		msg_total[0] = numero + 'A';
	}

	for(int i = 1; i<3 ; i++)
	{
		msg_total[i] = msg_partiel.commande[i-1];
	}

	if(data==NULL)
	{
		return;
	}
	for(int y = 3; y<msg_partiel.nb_octet ; y++)
	{
		msg_total[y] = data[y-3];
	}

}


// Fonction de parametrage de la liaisons serie.

void parametrage(const char * nom_tty, int port_serie, struct termios * tty)
{

	if (port_serie < 0) 
	{
   		 printf("Error %i from open: %s\n", errno, strerror(errno));
	}
	else
	{
		printf("Nous somme bien connecté au port serie : \"%s\"\n",nom_tty);
	}
	
	// Récupération de la configuration du tty
	if(tcgetattr(port_serie, tty) != 0) 
	{
		printf("Erreur numéros %i lors de la récupération des attribue : %s\n", errno, strerror(errno));
	}
	else
	{
		printf("Récupération des attribue réusite.\n");
	}

	// Configuration du lien serie
	// Pas de pariter
	tty->c_cflag &= ~PARENB;
	// 1 bit de stop
	tty->c_cflag &= ~CSTOPB;
	// bits pas data
	tty->c_cflag |= CS8;
	// Désactivation du flux RTS/CTS
	tty->c_cflag &= ~CRTSCTS; 
  	tty->c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
	tty->c_iflag &= ~(IXON | IXOFF | IXANY);
	tty->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
	tty->c_oflag &= ~OPOST; 
  	tty->c_oflag &= ~ONLCR;
	tty->c_lflag &= ~ECHO; // Disable echo
	tty->c_lflag &= ~ECHOE; // Disable erasure
	tty->c_lflag &= ~ECHONL; // Disable new-line echo
	tty->c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT 
	tty->c_cc[VTIME] = 10; 	
	tty->c_cc[VMIN] = 0;
	cfsetispeed(tty, B9600);
	cfsetospeed(tty, B9600);

	if (tcsetattr(port_serie, TCSANOW, tty) != 0) 
	{
	    printf("Erreur numéros %i lors de la configuration des attribus: %s\n", errno, strerror(errno));
	}
	else
	{
		printf("Aucune erreur lors de l'attributation des caractéristique\n");
	}
}
