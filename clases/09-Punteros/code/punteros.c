
#include <stdio.h>
#include <stdlib.h>

int i,j,k;

void f1 () {
	int *p;
	p = (int *)malloc (sizeof(int));

	*p = 5;

	printf ("%d", *p);
}

void f2 () {
	int *q [3];

	// q [0] = 1;  // Error
	q [0] = (int *)malloc (3*sizeof(int));
	q[0][0] = 22;
	q[0][1] = 33;
	q[0][2] = 44;

	for (i = 0; i < 3; i++)
		printf ("%d ", q[0][i]);
}

void iniciar (int filas, int cols, int **mat) {
	for (int i=0; i < filas ; i++) 
		mat [i] = (int *)malloc (cols*sizeof(int ));


	for (int i=0; i < filas ; i++) {
		for (int j=0; j < cols ; j++) 
			mat [i][j] = i*j;
	}
}

void imprimir (int filas, int cols, int **mat) {
	for (int i=0; i < filas ; i++) {
		for (int j=0; j < cols ; j++) 
			printf ("%d\t ", mat [i][j]);
		printf ("\n");
	}
}

void f3 () {
	int **z;

	z = (int **)malloc (7*sizeof(int *));

	iniciar (7,7, z);
	imprimir (7,7, z);
}


int main () {
	//f1 ();
	//f2 ();
	f3 ();
}
