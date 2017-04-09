#include <stdio.h>

int i, j;
int optimo (int a, int b);

void main () {
	printf ("Hola\n");

	i = optimo (2,5);

	printf ("%d\n", i);
}

int optimo (int a, int b) {
	int c;
	c = a * b;

	return c;
}
