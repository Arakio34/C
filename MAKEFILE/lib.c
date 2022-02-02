#include <stdio.h>


int bite(){ //Je parle biensure de l'unité de quantification des données.
	printf(" Nathan il est tellement bo \n");
	return 0;
}
int count(){
	int i; 
	for( i=0;i< 10; i++ ){
		printf("%d",i);
		bite();
		
	}
	return 0;
}
