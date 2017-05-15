#ifndef ARBOLBIN_H
#define ARBOLBIN_H
typedef struct nodoBin ArbolBin;

struct nodoBin {
    int raiz;
    ArbolBin *izq;
    ArbolBin *der;
};


ArbolBin *crearNodoBin (int raiz);
void printInorden (ArbolBin *);
void dibujarBin (ArbolBin *);
#endif
