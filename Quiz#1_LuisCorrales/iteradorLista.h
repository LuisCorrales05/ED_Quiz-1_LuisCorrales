#ifndef ITERADORLISTA_H
#define	ITERADORLISTA_H

#include "std.h"
#include "nodo.h"

template <class T>
class iteradorLista {
public:
    iteradorLista(nodo<T>*);
    virtual ~iteradorLista();

    virtual bool masElementos() const;
    virtual T* proximoElemento();

private:
    nodo<T>* cursor;

};

template <class T>
iteradorLista<T>::iteradorLista(nodo<T>* primerNodo) {
    cursor = primerNodo;
}
template <class T>
bool iteradorLista<T>::masElementos() const {
    return (cursor != NULL);
}
template <class T>
T* iteradorLista<T>::proximoElemento() {
    T* r = NULL;
    if (masElementos()) {
        r = cursor->obtenerInfo();
        cursor = cursor->obtenerSiguiente();
    }
    return r;
}
template <class T>
iteradorLista<T>::~iteradorLista() {
}
#endif	/* ITERADORLISTA_H */

