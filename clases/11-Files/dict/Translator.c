#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char * argv[]){
	FILE *manejador;
	char * palabra= argv[1];
	char  linea [100];
	char *s1, *s3, *res;
	manejador= fopen ("palabras.dict", "r");
	printf("\n");
	//printf("¨¨¨¨//Diccionario Vrrronik//¨¨¨¨\n\n");
	while (!feof(manejador)){
		res= fgets(linea,80,manejador);
		/*
		s1= strtok(linea, " : ");
		s3= strtok(NULL, "");
		if (res ==NULL){
			break;
		} 
		else if (strcmp(palabra,s1)==0) {
			printf("%s %s \n",s1, s3);
		}
	*/
	}
	fclose (manejador);
	return 0;
}
