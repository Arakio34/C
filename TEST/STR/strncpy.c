#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *str1="123456789";
char *str2[10];

void main(){

	strncpy(str2,str1,2);
	printf("%s \n",str2);
} 
