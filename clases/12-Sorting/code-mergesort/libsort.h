// Sorts the array "a" of length "n
// Returns a new sorted array
int *sort1 (int *a, int n); 
void sort2 (int *a, int ini, int end); 

// Merges two arrays "a" and "b" of length "na" and "nb"
// Returns a new array with sorted elements from "a" and "b"
int* merge (int *a, int *b, int na, int nb); 

// Splits the array "a" from position "ini" to "end"
// Returns the new array
int *split (int *a, int ini, int end); 

// Partitions the array "a" around a pivot
// Lower values before the pivot and higher values after it.
// It returns the position of the pivot
int partition (int *a, int low, int high );

// Prints the array "a" of length "n"
void printArray (int *a, int n); 
