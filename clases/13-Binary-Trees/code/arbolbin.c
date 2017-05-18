
ArbolBin* crearNodoBin(int elem) {
  ArbolBin* nodoBin = (ArbolBin*) malloc (sizeof (ArbolBin));    // "new" is like "malloc"
  nodoBin->raiz = elem;
  nodoBin->izq = NULL;
  nodoBin->der = NULL;

  return(nodoBin);
}



/*
 Give a binary search tree and a number, inserts a new nodoBin
 with the given number in the correct place in the tree.
 Returns the new root pointer which the caller should
 then use (the standard trick to avoid using reference
 parameters).
*/


ArbolBin* adicionarBin(ArbolBin* nodoBin, int elem) {
  // 1. If the tree is empty, return a new, single nodoBin
  if (nodoBin == NULL) {
    return(crearNodoBin(elem));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (elem <= nodoBin->raiz) nodoBin->izq = adicionarBin(nodoBin->izq, elem);
    else nodoBin->der = adicionarBin(nodoBin->der, elem);

    return(nodoBin); // return the (unchanged) nodoBin pointer
  }
}
