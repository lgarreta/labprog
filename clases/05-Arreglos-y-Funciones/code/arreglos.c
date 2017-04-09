#include <stdio.h>
int main () {
	int i; float valor;
	int   ai  [] = {2,4,6,8};
	float af [4];

	for (i=0; i < 4; i++) 
		printf ("El valor %d es %d\n", i, ai [i]);

		printf ("Digite valor %d: ", i);
		scanf ("%f", &valor);
		af [i] = valor;
	}
	return 1;
}
