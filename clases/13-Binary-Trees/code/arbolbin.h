#ifndef ARBOLBIN_H
#define ARBOLBIN_H
typedef struct nodoBin ArbolBin;

struct nodoBin {
    int data;
    ArbolBin *left;
    ArbolBin *right;
};


ArbolBin *crearNodoBin (int data);
void dibujarBin (ArbolBin *);
#endif
