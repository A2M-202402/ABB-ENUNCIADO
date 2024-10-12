#ifndef ABB_H_
#define ABB_H_
#include <stdlib.h>
#include <stdbool.h>

typedef struct abb abb_t;

/**
 * Crea un ABB con un comparador.
 */
abb_t *abb_crear(int (*comparador)(void *, void *));

/**
 * Destruye el abb.
 */
void abb_destruir(abb_t *abb);

/**
 * Destruye el abb aplicando el destructor a los elementos del usuario.
 */
void abb_destruir_todo(abb_t *abb, void (*destructor)(void *));

/**
 * Inserta el elemento. Devuelve true si pudo o false si no pudo.
 */
bool abb_insertar(abb_t *abb, void *elemento);

/**
 * Quita el elemento buscado del arbol. Si lo encuentra y encontrado no es NULL,
 * almacena el puntero.
 *
 * Devuelve true si pudo quitar el elemento.
 */
bool abb_quitar(abb_t *abb, void *buscado, void **encontrado);

/**
 * Busca un elemento en el abb. Si lo encuentra lo devuelve. Caso contrario
 * devuelve NULL.
 */
void *abb_obtener(abb_t *abb, void *elemento);

/**
 * Devuelve la cantidad de elementos en el abb.
 */
size_t abb_cantidad(abb_t *abb);

/**
 * Recorre los elementos del abb en el orden específico y aplica la función f a
 * cada uno.
 *
 * Si la función f devuelve false, se deja de iterar.
 *
 * Devuelve la cantidad de veces que fue invocada la función f.
 */
size_t abb_iterar_inorden(abb_t *abb, bool (*f)(void *, void *), void *ctx);
size_t abb_iterar_preorden(abb_t *abb, bool (*f)(void *, void *), void *ctx);
size_t abb_iterar_postorden(abb_t *abb, bool (*f)(void *, void *), void *ctx);

/**
 * Rellena el vector de punteros con los elementos del abb siguiendo un orden
 * dado. Tamaño indica la capacidad del vector.
 *
 * Devuelve la cantidad de elementos guardados en el vector.
 */
size_t abb_vectorizar_inorden(abb_t *abb, void **vector, size_t tamaño);
size_t abb_vectorizar_preorden(abb_t *abb, void **vector, size_t tamaño);
size_t abb_vectorizar_postorden(abb_t *abb, void **vector, size_t tamaño);

#endif // ABB_H_
