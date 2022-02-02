#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>
#include<softPwm.h>
#include <mosquitto.h>



int pinServ = 21;
int i = 5;
int test = 0;
 int pression;
int state = 0;
struct mosquitto *mosqa;
int conte =0;
void my_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		pression=atoi(message->payload);
	}
	else{
		printf("%s (null)\n", message->topic);
	}
	fflush(stdout);
}

void my_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "mesure/iut/pres", 0);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void my_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	//printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
	//	printf(", %d", granted_qos[i]);
	}
	//printf("\n");
}

void my_log_callback(struct mosquitto *mosq, void *userdata, int level, const char *str)
{
	/* Pring all log messages regardless of level. */
	//printf("%s\n", str);
}

int main(int argc, char *argv[])
{
	char *host = "194.199.227.235";
	int port = 1139;
	int keepalive = 60;
	bool clean_session = true;
	struct mosquitto *mosq = NULL;

	wiringPiSetup();
	pinMode(pinServ,OUTPUT);

	mosquitto_lib_init();
	softPwmCreate(pinServ,6,100);

	mosq = mosquitto_new(NULL,clean_session,NULL);
	mosquitto_username_pw_set(mosq, "tom", "22011648");

	mosquitto_tls_set(mosq,"/home/pi/cafile/ca.crt",NULL,"/home/pi/cert/client.crt","/home/pi/key/client.key",NULL);
	mosquitto_tls_opts_set(mosq,1,NULL,NULL);
	mosquitto_tls_insecure_set(mosq,true);
	
	if(!mosq){
		fprintf(stderr, "Error: Out of memory.\n");
		return 1;
	}
	mosquitto_log_callback_set(mosq, my_log_callback);
	mosquitto_connect_callback_set(mosq, my_connect_callback);
	mosquitto_message_callback_set(mosq, my_message_callback);
	mosquitto_subscribe_callback_set(mosq, my_subscribe_callback);

	if(mosquitto_connect(mosq, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		return 1;
	}
	while(true){
		mosquitto_loop(mosq, -1, 1);
		if(pression > 800){
			printf("PRESSION : %d\n",pression);

			if( pression>=1020){
				softPwmWrite(pinServ,6);
			}
			else if(pression>=1013 && pression<1020){
				softPwmWrite(pinServ,13);
			}
			else if (pression>=1006 && pression<1013){
				softPwmWrite(pinServ,19);
			}
			else if (pression<1006){
				softPwmWrite(pinServ,26);
			}
			delay(2000);
		}		
	}
	
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	return 0;
}
