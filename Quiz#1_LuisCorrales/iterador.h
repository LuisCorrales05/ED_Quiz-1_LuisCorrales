#ifndef ITERADOR_H
#define	ITERADOR_H

#include "nodo.h"

template <class T>
class iterador {
public:
    iterador();

    virtual bool masElementos() const = 0;
    virtual T* proximoElemento() = 0;
};

#endif	/* ITERADOR_H */


