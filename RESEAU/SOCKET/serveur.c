#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

char *vide = NULL;



int main(){
	int socket_desc, client_sock , c , read_size;
	struct sockaddr_in server, client;
	char client_message[2000];

	
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

	while(( read_size = recv(client_sock, client_message, 2000, 0))>0){
		
		for(int i = 0 ; i<read_size ;i++){
			printf("%c",client_message[i]);
		}
		printf("\n");
		write(client_sock,client_message,read_size);
		
	}
	
	if(read_size == 0){
		puts("Le clients c'est déconecter");
		fflush(stdout);
	}
	else if(read_size == -1){
		perror("Lecture de la taille non réusit");
	}

	return 0;
}

