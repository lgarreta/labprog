#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dict {
	char palIngles  [50];
	char palEspanol [50];
};
typedef struct Dict tipoDict;

struct Nodo {
	tipoDict info;
	struct Nodo *siguiente;
};

typedef struct Nodo tipoNodo;

tipoNodo *lista=NULL;

tipoNodo *crearNodo (tipoDict dict) {
	tipoNodo *nodo = (tipoNodo *)malloc (sizeof (tipoNodo));

	strcpy (nodo->info.palIngles, dict.palIngles);
	strcpy (nodo->info.palEspanol, dict.palEspanol);
	

	nodo->siguiente = NULL;
	return nodo;
}

tipoNodo* adicionarLista (tipoNodo *lista, tipoDict dict) {
	tipoNodo *nuevoNodo = crearNodo (dict);

	if (lista==NULL) {
		lista = nuevoNodo;
	}else {
		tipoNodo *aptNodo = lista;
		while (aptNodo->siguiente != NULL) {
			aptNodo = aptNodo->siguiente;
		}
		aptNodo->siguiente = nuevoNodo;
	}
	return lista;
}


int buscarPosInsertar (tipoNodo *lista, char *palabra) {
	int pos = 1;
	tipoNodo *aptNodo = lista;
	while (aptNodo != NULL) {
		if (strcmp (palabra, aptNodo->info.palIngles) > 0) {
			pos++;
			aptNodo = aptNodo->siguiente;
		}
		else
			break;
	}
	return pos;
}



void imprimirLista (tipoNodo *lista) {
	printf ("impLis:%s", lista->info.palIngles);
	if (lista==NULL) printf ("Lista vacia");
	tipoNodo *aptNodo = lista;
	while (aptNodo != NULL) {
		printf ("<%s>::<%s>\n", aptNodo->info.palIngles, aptNodo->info.palEspanol);
		aptNodo = aptNodo->siguiente;
	}
}

tipoNodo* cargarDictToLista (char *nombreArchivoBin, tipoNodo *lista) {
	FILE *manejadorBin;
	manejadorBin = fopen (nombreArchivoBin, "r"); 
	tipoDict dictTmp;
	int longitudBytes = sizeof (tipoDict);

	while (fread (&dictTmp, longitudBytes, 1, manejadorBin) == 1) {
		lista = adicionarLista (lista, dictTmp);
	}
	fclose (manejadorBin);

	return lista;
}

int main (int argc, char * argv[]){
	tipoNodo *lista=NULL;
	lista = cargarDictToLista ("palabras.bin", lista);
	imprimirLista (lista);
	return 0;
}
