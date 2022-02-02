#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>

int main(){
	int state;
	struct mosquitto *mosqa;
	
	mosquitto_lib_init();
	
	mosqa = mosquitto_new("test",true,NULL);
	mosquitto_username_pw_set(mosqa, "tom", "12072002");
	state = mosquitto_connect(mosqa,"localhost",1883,60);
	if(state!=0){
		printf("Une erreur est survenue !!! \n");
		mosquitto_destroy(mosqa);
		
	}
	mosquitto_publish(mosqa, NULL, "test", 22, "this is the voice", 0, false);
	
	mosquitto_disconnect(mosqa);
	mosquitto_destroy(mosqa);

	mosquitto_lib_cleanup();
	return 0;
	}
