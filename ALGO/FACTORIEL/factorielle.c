#include <stdio.h>
#include <stdlib.h>
//Version corriger par SEB 
int factorielle(int a){
	if(a==1){
	    return 1 ;
	}
	else{
		return a * factorielle(a-1);
	}

}

// Version ++ corriger par SEB
int factorielle2(int a, int acc ){
	if(a==1){
	    return acc ;
	}
	else{
		return factorielle2(a-1, a*acc);
	}

}
// Version que j'avais trouver 

int factorielleTom(int a){
	if(a==2){
		return 2;
	}
	else{
		return a * factorielleTom(a-1);
	}
}


int main(int argc, char * argv[]){
	printf("%d\n",factorielle2(5,1));
	return 0;
}
