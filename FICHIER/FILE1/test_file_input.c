#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	int valueOfFile = 0;
       	
	fp = fopen("/home/tom/Bureau/PROJET_C/File_5/dossier/test.txt","rb");
	
	if(fp)
	{
	  while(1)
	  {
	    valueOfFile = fgetc(fp);
	    if(valueOfFile==EOF) break;
	    else printf("%c",valueOfFile);		 
	  }
	  fclose(fp);
	}
	return 0;	
	}




	
