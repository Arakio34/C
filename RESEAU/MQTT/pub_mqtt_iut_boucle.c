#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <mosquitto.h>

int main(){
	srand(time(NULL));
	int value,state;
	char message[3];
	struct mosquitto *mosqa;
	clock_t start_bcl,temps;
	
	mosquitto_lib_init();
	
	mosqa = mosquitto_new("test",true,NULL);
	mosquitto_username_pw_set(mosqa, "tom", "12072002");
	state = mosquitto_connect(mosqa,"194.199.227.235",1139,60);
	if(state!=0){
		printf("Une erreur est survenue !!! \n");
		mosquitto_destroy(mosqa);
		
	}
	for(;;){
		/*temps = clock()+3;
		start_bcl = clock();
		printf("%f %f",temps, start_bcl);
		while(temps>start_bcl){
			//printf("Waiting...\n");
		}*/
		sleep(3);
		value = rand()%11;
		sprintf(message,"%d",value);
		mosquitto_publish(mosqa, NULL, "test", 22, message, 0, false);
		printf("%d\n",value);
	}
	mosquitto_disconnect(mosqa);
	mosquitto_destroy(mosqa);

	mosquitto_lib_cleanup();
	return 0;
	}
