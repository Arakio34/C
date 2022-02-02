#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

char *vide = NULL;
int verifLoginMdp(char * loginmdp, char * userenter);



int main(){
    char * login = "test";
    char * mdp = "test";
    char * vraie="0";
    char * faux="1";
	int socket_desc, client_sock , c , read_size;
	struct sockaddr_in server, client;
	char client_message[2000];
    int test = 0;

	
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1){
		printf("Impossible de créer un file descriptor");
	}
	puts("La socket a été créer");
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(64000);
	if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server))<0){
		perror("Paramétrage non réussit. Erreur");
		return 1;	
	}
	puts("Parametrage effectuer");
	listen(socket_desc,3);
	puts("En attente de connexion...");
	c = sizeof(struct sockaddr_in);
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	
	if(client_sock < 0){
		perror("Imposible de ce connecter au client");
		return 1;
	}
	puts("Connexion accepter");

	//LOG
	read_size = recv(client_sock, client_message, 2000, 0);	
    printf("%s\n",client_message);    
    if(read_size == 0){
		puts("Le clients c'est déconecter");
		fflush(stdout);
	}
	else if(read_size == -1){
		perror("Lecture de la taille non réusit");
	}
    
    if(verifLoginMdp(client_message,login)!=0)
        test++;

    //MDP
	read_size = recv(client_sock, client_message, 2000, 0);		
    printf("%s\n",client_message);
    if(read_size == 0){
		puts("Le clients c'est déconécter");
		fflush(stdout);
	}
	else if(read_size == -1){
		perror("Lecture de la taille non réusit");
	}

    if(verifLoginMdp(client_message,mdp)!=0)
        test++;

    if(test==0)
        write(client_sock,vraie,1);
    else
        write(client_sock,faux,1);
		
    fflush(stdout);

	return 0;
}


int verifLoginMdp(char * loginmdp, char * userenter){
    int verif;
    verif = strcmp(loginmdp,userenter);
    return verif;   
}
