#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dict {
	char palIngles  [50];
	char palEspanol [50];
};
typedef struct Dict tipoDict;

void guardarComoBinario (char *nombreArchivoText, char *nombreArchivoBin) {
	FILE *manejadorTxt;
	FILE *manejadorBin;

	char lineaTexto [200];
	char *palInglesTmp; 
	char *palEspanolTmp;

	tipoDict dictTmp;

	manejadorTxt = fopen (nombreArchivoText, "r"); 
	manejadorBin = fopen (nombreArchivoBin, "wb"); 
	
	while (fgets (lineaTexto, 200, manejadorTxt) !=NULL) {
		palInglesTmp  = strtok (lineaTexto, ":");
		palEspanolTmp = strtok (NULL, "\n");

		//printf ("<%s>:<%s>\n", palInglesTmp, palEspanolTmp);

		if (strlen (palInglesTmp)<50 && strlen (palEspanolTmp)<50) {
			strcpy (dictTmp.palIngles, palInglesTmp);
			strcpy (dictTmp.palEspanol, palEspanolTmp);
			fwrite (&dictTmp, sizeof (dictTmp), 1, manejadorBin);
		}
	} 
	fclose (manejadorTxt);
	fclose (manejadorBin);
}

void leerBinarioInicio (char *nombreArchivoBin) {

	FILE *manejadorBin;
	manejadorBin = fopen (nombreArchivoBin, "r"); 
	tipoDict dictTmp;
	int longitudBytes = sizeof (tipoDict);

	fseek (manejadorBin, 0, SEEK_SET);
	while (fread (&dictTmp, longitudBytes, 1, manejadorBin) == 1) {
		printf ("<%s>:<%s>\n", dictTmp.palIngles, dictTmp.palEspanol);
	}
	fclose (manejadorBin);
}

void leerBinarioMitad (char *nombreArchivoBin) {
	FILE *manejadorBin;
	manejadorBin = fopen (nombreArchivoBin, "r"); 
	tipoDict dictTmp;
	int longitudBytes = sizeof (tipoDict);

	fseek (manejadorBin, 12000*longitudBytes, SEEK_SET);
	while (fread (&dictTmp, longitudBytes, 1, manejadorBin) == 1) {
		printf ("<%s>:<%s>\n", dictTmp.palIngles, dictTmp.palEspanol);
	}
	fclose (manejadorBin);
}
int main (int argc, char * argv[]){
	guardarComoBinario ("palabras.txt", "palabras.bin");
	leerBinarioMitad ("palabras.bin");
	return 0;
}
