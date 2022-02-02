#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(){
	int sock;
	struct sockaddr_in server;
	char message[1000] , server_reply[2000];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1){
		printf("Erreur dans la création des socket");
	}
	puts("La socket a été créer");

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(64000);

	if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
		perror("Erreur lors de la connexion");
		return 1;
	}
	puts("Nous somme connecter !");
	
	while(1){
		for(int i = 0; i<1000;i++){
	//		printf("%d\n",i);
			server_reply[i]=0;
		}
		printf("Entrer un  message...\n");
		scanf("%s",message);

		if (send(sock, message, strlen(message),0) < 0){
			puts("L'envoie du message a echouer");
			return 1;
		}

		if(recv(sock, server_reply, 2000,0)<0){
			puts("La reception a echouer ...");
			break;
		}
		puts("Reponse du serveur :");
		puts(server_reply);
	}
	close(sock);
	return 0;
}
