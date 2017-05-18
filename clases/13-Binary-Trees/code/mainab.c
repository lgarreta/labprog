
#include <stdlib.h>
#include <stdio.h>
#include "arbolbin.h"
//---------------------------------------------------------
// Main
//---------------------------------------------------------

int main () {
	ArbolBin *arbolBin = NULL;

	arbolBin = adicionarBin (arbolBin, 5);
	arbolBin = adicionarBin (arbolBin, 7);
	arbolBin = adicionarBin (arbolBin, 3);
	arbolBin = adicionarBin (arbolBin, 1);
	arbolBin = adicionarBin (arbolBin, 9);

	dibujarBin (arbolBin);
	printf ("\n");
	printf ("longitudBin: %d \n", longitudBin (arbolBin));
	printf ("alturaBin: %d\n", alturaBin (arbolBin));

	printInorden (arbolBin);
	printNiveles (arbolBin);
}

