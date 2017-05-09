#include "sort.h"
#define N 10

int main() {
    int a[N] = {3,1,4,1,5,9,2,6,5,4};
	int *s;
    
    s = mergesort(a, N);

	printArray (s, N);
}
