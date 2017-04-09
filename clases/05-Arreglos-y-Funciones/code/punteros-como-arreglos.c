#include <stdio.h>
#include <stdlib.h>
/* ContrucciOn de un arreglo dinAmico de n datos */
int ma1n () {
	int i, n, a1 [] = {2,4,6,8};
	int *p1, *p2; // equivalente a int *p1
	
	p1 = a1; // p1 apunta a la misma dir que a1
	for (i=0; i<4; i++)
		printf ("%d\n", p1 [i]);

	scanf ("%d", &n); // Lee el número de valores

	p2 = (int *)malloc (n * sizeof (int));
	for (i=0; i < n; i++)
		scanf ("%d", &p1 [i]);
	
	return 0;
}
