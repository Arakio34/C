#ifndef __ELL17__LIB__H__
#define  __ELL17__LIB__H__
#define NB_MSG 5
#define NB_INST 30  

struct instruction_s{
	char * commande;
	int nb_octet;
};

struct message_s {
	int nb_champ_donne;
	char ** donnees;
	int * taille_champ;
};
void affichage_message(struct message_s message);
void creat_inst(struct instruction_s list_instruction[NB_INST]);
void creat_msg(struct message_s list_messages[NB_MSG]);

void envoie(char * reponse, int numero_moteur, struct termios tty, int port_serie, struct instruction_s * inst,char * data);

void mise_en_forme(int numero, char * msg_total, struct instruction_s msg_partiel, char * data);

void parametrage(const char * nom_tty, int port_serie, struct termios * tty);

void traitement_message(char * message_brute, struct message_s * message);

#endif
