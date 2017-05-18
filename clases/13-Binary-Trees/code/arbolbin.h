#ifndef ARBOLBIN_H
#define ARBOLBIN_H
typedef struct nodoBin ArbolBin;

struct nodoBin {
    int raiz;
    ArbolBin *izq;
    ArbolBin *der;
};

ArbolBin *crearNodoBin (int raiz);
ArbolBin *adicionarBin(ArbolBin* nodoBin, int raiz);

// Dibuja el arbol. Esta funcion está implementada en "dibujarbin.c"
void dibujarBin (ArbolBin *);

// Imprime en inorden (izq-raiz-der)
void printInorden (ArbolBin *);

// Compute the number of nodes in a tree.
int longitudBin(ArbolBin* ); 

// Devuelve 1 o 0 si el elemento esta o no en el arbol
int buscarBin (ArbolBin *ab, int elem);
// Imprime la altura del arbol (raiz + altura mayor rama)
int alturaBin (ArbolBin *ab);


// Compara si dos arboles binarios son iguales. Retorna 0 (falso) o 1 (verdad)
int igualesBin (ArbolBin *ab1, ArbolBin *ab2);

// Retorna 0 (falso) o 1 (verdad) si el arbol está balanceado
// Un arbol binario esta balanceado si sus dos hijos están balanceados y
// la altura de los hijos difiere en máximo 1.
int balanceadoBin (ArbolBin *ab);

// Imprime por niveles
void printNiveles (ArbolBin *);


/* Cambia la estructura del arbol
 Si el arbos es:
       4
      / \
     2   5
    / \
   1   3

 este cambia a:
       4
      / \
     5   2
        / \
       3   1
*/
void espejoBin (ArbolBin *);



#endif
