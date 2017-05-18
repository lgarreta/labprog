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

// Dibuja el arbol
void dibujarBin (ArbolBin *);

// Compute the number of nodes in a tree.
int longitudBin(ArbolBin* ); 
// Devuelve 1 o 0 si el elemento esta o no en el arbol
int buscarBin (ArbolBin*);
// Imprime la altura del arbol (raiz + altura mayor rama)
int alturaBin (ArbolBin *);
// Retorna el valor minimo
int minValor(ArbolBin* nodoBin); 

// Imprime en inorden (izq-raiz-der)
void printInorden (ArbolBin *);
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
