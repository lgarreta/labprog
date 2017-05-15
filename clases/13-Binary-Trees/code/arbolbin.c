#include <stdio.h>
#include <stdlib.h>
#include "arbolbin.h"

/*
 Helper function that allocates a new nodoBin
 with the given data and NULL left and right
 pointers.
*/
ArbolBin* crearNodoBin(int data) {
  ArbolBin* nodoBin = (ArbolBin*) malloc (sizeof (ArbolBin));    // "new" is like "malloc"
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


ArbolBin* insertarBin(ArbolBin* nodoBin, int data) {
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
void printBin(ArbolBin* nodoBin) {
  if (nodoBin == NULL) return;

  printBin(nodoBin->left);
  printf("%d ", nodoBin->data);
  printBin(nodoBin->right);
}

/*
 Compute the number of nodes in a tree.
*/
int longitudBin(ArbolBin* nodoBin) {
  if (nodoBin==NULL) {
    return(0);
  } else {
    return(longitudBin(nodoBin->left) + 1 + longitudBin(nodoBin->right));
  }
}

/*
 Compute the "maxProfundidad" of a tree -- the number of nodes along
 the longest path from the root nodoBin down to the farthest leaf nodoBin.
*/
int maxProfundidad(ArbolBin* nodoBin) {
  if (nodoBin==NULL) {
    return(0);
  }
  else {
    // compute the depth of each subtree
    int lDepth = maxProfundidad(nodoBin->left) + 1;
    int rDepth = maxProfundidad(nodoBin->right) + 1;

    // use the larger one
    if (lDepth > rDepth) 
		return(lDepth);
    else 
		return(rDepth);
  }
}

int esHoja (ArbolBin *nodoBin) {
	return (nodoBin->left == NULL & nodoBin->right == NULL);
}

/*
 Given a non-empty binary search tree,
 return the minimum data value found in that tree.
 Note that the entire tree does not need to be searched.
*/
int minValor(ArbolBin* nodoBin) {
  ArbolBin* current = nodoBin;

  // loop down to find the leftmost leaf
  while (current->left != NULL) {
    current = current->left;
  }

  return(current->data);
}

/*
 Given a binary tree, print its
 nodes according to the "bottom-up"
 postorder traversal.
*/
void printPostorder(ArbolBin* nodoBin) {
  if (nodoBin == NULL) return;

  // first recur on both subtrees
  printBin(nodoBin->left);
  printBin(nodoBin->right);

  // then deal with the nodoBin
  printf("%d ", nodoBin->data);
}

/*
 Change a tree so that the roles of the
 left and right pointers are swapped at every nodoBin.

 So the tree...
       4
      / \
     2   5
    / \
   1   3

 is changed to...
       4
      / \
     5   2
        / \
       3   1
*/
void espejoBin(struct nodoBin* nodoBin) {
  if (nodoBin==NULL) {
    return;
  }
  else {
    struct nodoBin* temp;

    // do the subtrees
    espejoBin(nodoBin->left);
    espejoBin(nodoBin->right);

    // swap the pointers in this nodoBin
    temp = nodoBin->left;
    nodoBin->left = nodoBin->right;
    nodoBin->right = temp;
  }
}
//---------------------------------------------------------
// Main
//---------------------------------------------------------

int main () {
	ArbolBin *arbolBin = NULL;

	arbolBin = insertarBin (arbolBin, 5);
	arbolBin = insertarBin (arbolBin, 7);
	arbolBin = insertarBin (arbolBin, 3);
	arbolBin = insertarBin (arbolBin, 1);
	arbolBin = insertarBin (arbolBin, 9);

	dibujarBin (arbolBin);
	printf ("\n");
	printf ("longitudBin: %d \n", longitudBin (arbolBin));
	printf ("maxProfundidad: %d\n", maxProfundidad (arbolBin));
	printf ("minValor: %d\n", minValor (arbolBin));

	printPostorder (arbolBin);
}


