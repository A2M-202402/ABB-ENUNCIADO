#ifndef ABB_ESTRUCTURA_PRIVADA_H_
#define ABB_ESTRUCTURA_PRIVADA_H_

#include <stdlib.h>

//ESTE ARCHIVO NO ES PARA EL USUARIO
//
//NO TE QUIERO VER INCLUYENDO ESTO EN TU PROGRAMA

typedef struct nodo {
	void *elemento;
	struct nodo *izq;
	struct nodo *der;
} nodo_t;

struct abb {
	size_t nodos;
	nodo_t *raiz;
	int (*comparador)(void *, void *);
};

#endif // ABB_ESTRUCTURA_PRIVADA_H_
