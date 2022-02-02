
#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>
#include<softPwm.h>
#include<mosquitto.h>



int r,g,b,state,test,temperature = 0;
int red = 0;
int green =3;
int blue = 2;
int i = 5;
struct mosquitto *mosqa;
void my_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		temperature=atoi(message->payload);
		printf("%s\n",(char *)message->payload);	
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
		mosquitto_subscribe(mosq, NULL, "mesure/iut/temp", 0);
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
	pinMode(red,OUTPUT);
	pinMode(green,OUTPUT);
	pinMode(blue,OUTPUT);
	
	softPwmCreate(red,0,100);
	softPwmCreate(blue,0,100);
	softPwmCreate(green,0,100);
	
	mosquitto_lib_init();
	
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
		printf("TEMPERATURE : %d\n",temperature);
		if(temperature>=30){
			softPwmWrite(red,0);
			softPwmWrite(blue,0);
			softPwmWrite(green,100);
			}
		else if(temperature>=25 && temperature<30){
			softPwmWrite(red,0);
			softPwmWrite(blue,0);
			softPwmWrite(green,0);
			}
		else if(temperature>=20 && temperature<25){
			softPwmWrite(red,0);
			softPwmWrite(blue,0);
			softPwmWrite(green,10);
			}
		else if(temperature>=15 && temperature<=20){
			softPwmWrite(red,70);
			softPwmWrite(blue,0);
			softPwmWrite(green,75);
		}
		else if(temperature>=10 && temperature<=15){
			softPwmWrite(red,60);
			softPwmWrite(blue,10);
			softPwmWrite(green,100);
			}
		else if(temperature>=5 && temperature<=10){
			softPwmWrite(red,30);
			softPwmWrite(blue,60);
			softPwmWrite(green,50);
			}
			delay(500);
				
		}	
			
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	return 0;
}
