#include <stdio.h>
#include <stdlib.h>


typedef struct nodoBin {
    int data;
    struct nodoBin* left;
    struct nodoBin* right;
}TipoNodoBin;


/*
 Helper function that allocates a new nodoBin
 with the given data and NULL left and right
 pointers.
*/
struct nodoBin* crearNodoBin(int data) {
  struct nodoBin* nodoBin = new(struct nodoBin);    // "new" is like "malloc"
  nodoBin->data = data;
  nodoBin->left = NULL;
  nodoBin->right = NULL;

  return(nodoBin);
}

/*
 Give a binary search tree and a number, inserts a new nodoBin
 with the given number in the correct place in the tree.
 Returns the new root pointer which the caller should
 then use (the standard trick to avoid using reference
 parameters).
*/
struct nodoBin* insertarBin(struct nodoBin* nodoBin, int data) {
  // 1. If the tree is empty, return a new, single nodoBin
  if (nodoBin == NULL) {
    return(crearNodoBin(data));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= nodoBin->data) nodoBin->left = insertarBin(nodoBin->left, data);
    else nodoBin->right = insertarBin(nodoBin->right, data);

    return(nodoBin); // return the (unchanged) nodoBin pointer
  }
}

/*
 Given a binary search tree, print out
 its data elements in increasing
 sorted order.
*/
void imprimirBin(struct node* node) {
  if (node == NULL) return;

  imprimirBin(node->left);
  printf("%d ", node->data);
  imprimirBin(node->right);
}
//---------------------------------------------------------
// Main
//---------------------------------------------------------

int main () {
	TipoNodoBin *arbolBin = NULL;

	insertarBin (arbolBin, 5);
	insertarBin (arbolBin, 7);
	insertarBin (arbolBin, 3);
	insertarBin (arbolBin, 1);
	insertarBin (arbolBin, 9);

	imprimirBin (arbolBin);
}


