#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <string.h>


#define TRUE 1
#define FALSE 0
#define PORT 8888


int main(){
	int opt = TRUE;
	int master_socket, addrlen,new_socket,client_socket[30],max_clients=30,activity,i,valread,sd,nbclient=0;;
	int max_sd;
	struct sockaddr_in address;

	char buffer[1025];

	fd_set readfds;
	char *message = "Serveur 1.0\n";

	for (i = 0; i < max_clients; i++){
		client_socket[i] = 0;
	}
	if((master_socket = socket(AF_INET, SOCK_STREAM , 0))==0){
		perror("Socket error");
		exit(EXIT_FAILURE);	
	}

	if(setsockopt(master_socket , SOL_SOCKET, SO_REUSEADDR, (char*)&opt,sizeof(opt)) < 0 ){
		perror("setsockopt");
		exit(EXIT_FAILURE);	
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr=INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(master_socket,(struct sockaddr *)&address,sizeof(address))<0){
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	printf("Ecoute sur le port %d \n",PORT);
	if(listen(master_socket,3)<0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	
	addrlen = sizeof(address);
	printf("En attente de connexion");
	

	while(TRUE){
		FD_ZERO(&readfds);

		FD_SET(master_socket, &readfds);
		max_sd = master_socket;

		for(i=0;i<max_clients;i++){
			sd=client_socket[i];
			if(sd>0){
				FD_SET(sd,&readfds);
			}

			if(sd>max_sd){
				max_sd = sd;
			}
		}

		activity = select(max_sd + 1 , &readfds, NULL,NULL,NULL);

		if((activity < 0) && (errno!=EINTR)){
			printf("select error");	
		}
		if(FD_ISSET(master_socket, &readfds)){
			if((new_socket = accept(master_socket,(struct sockaddr *)&address, (socklen_t *)&addrlen))<0){
				perror("accept");
				exit(EXIT_FAILURE);
			}
				
			printf("New connexion fd %d ip %s port %d \n" , new_socket,inet_ntoa(address.sin_addr),ntohs(address.sin_port));
			if(send(new_socket,message , strlen(message), 0) != strlen(message)){
				perror("send");
			}
			puts("Message envoyer");
			for(i=0;i<max_clients;i++){
				if(client_socket[i] == 0){
					client_socket[i]=new_socket;
					printf("Ajouter a la liste des socket");
					nbclient++;
					break;
				}
			}
		}
		if(nbclient<2){
			send(client_socket[0],"wait",strlen("wait"),0);	
		}	
		for(i=0;i<max_clients || nbclient<2;i++){
			sd = client_socket[i];
			if(FD_ISSET(sd, &readfds)){
				
				if((valread = read(sd , buffer , 1024))==0){
					getpeername(sd,(struct sockaddr *)&address , (socklen_t*)&addrlen);
					printf("Un des client c'est déconecter");
					nbclient--;
					close(sd);
					client_socket[i]=0;
				
				}
				else{
					if(i==0){
						strcat(buffer,"client")
						buffer[valread] = '\0';
						send(client_socket[0],buffer,strlen(buffer),0);
					}
					else{
						buffer[valread] = '\0';
						send(client_socket[1],buffer,strlen(buffer),0);
					}
				}
			}
		}
	}
	return 0;
}

