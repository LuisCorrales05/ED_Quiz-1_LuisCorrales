#ifndef LISTA_H
#define	LISTA_H
#include "PersonaLibro.h"

#include "iteradorLista.h"
#include "nodo.h"
#include "std.h"

template <class T>
class lista {
public:
    lista();
    lista(const lista& orig);
    lista(ifstream&);
    virtual ~lista();

    virtual bool vacio() const;
    virtual int numElementos() const;
    virtual void agregar(T*);
    virtual void eliminar();
    virtual void agregarInicio(T*);
    virtual void agregarFinal(T*);
    virtual iteradorLista<T>* obtenerIterador() const;
    virtual string toString() const;
    virtual bool actualizarNodo(int posicion, T* nuevaInfo);
    virtual bool eliminarNodo(int posicion);

    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, lista*);
    static bool serialize(ofstream&, lista*);






private:
    nodo<T>* primerNodo;
    nodo<T>* ultimoNodo;
    int k;

};
template<class T>
lista<T>::lista() {
    primerNodo = NULL;
    ultimoNodo = NULL;
    k = 0;
}
template<class T>
lista<T>::~lista() {
}
template<class T>
bool lista<T>::vacio() const {
    return primerNodo == NULL;
}
template<class T>
int lista<T>::numElementos() const {
    return k;
}
template<class T>
void lista<T>::agregar(T* nuevaInfo) {

    // Cuando se agrega un elemento a una lista
    // que está inicialmente vacía, hay que fijar
    // el apuntador al último nodo.

    bool iniciandoLista = vacio();

    primerNodo = new nodo<T>(nuevaInfo, primerNodo);
    if (iniciandoLista) {
        ultimoNodo = primerNodo;
    }
    k++;
}
template<class T>
void lista<T>::eliminar()
{
    if (!vacio()) {
        iteradorLista<T>* i = obtenerIterador();
        while (i->masElementos()) {
            T* e = i->proximoElemento();
            delete e;
        }
        delete i;
    }
}
template<class T>
void lista<T>::agregarInicio(T* nuevaInfo) {
    agregar(nuevaInfo);
}
template<class T>
void lista<T>::agregarFinal(T* nuevaInfo) {
    if (!vacio()) {

        // Si la lista no está vacía, la operación no afecta
        // al primer nodo, pero se debe actualizar el apuntador
        // al último nodo.

        ultimoNodo->fijarSiguiente(new nodo<T>(nuevaInfo, NULL));
        ultimoNodo = ultimoNodo->obtenerSiguiente();
        k++;

    }
    else {

        // Si la lista está vacía, agregar al inicio o
        // al final es la misma operación.

        agregar(nuevaInfo);
    }
}


template<class T>
iteradorLista<T>* lista<T>::obtenerIterador() const {
    return new iteradorLista<T>(primerNodo);
}

template<class T>
string lista<T>::toString() const {
    stringstream r;
    nodo<T>* cursor = primerNodo;
    bool esPrimerElemento = true;
    while (cursor != NULL) {
        if (!esPrimerElemento) {
            r << "\n";
        }
        r << cursor->obtenerInfo()->toString();
        cursor = cursor->obtenerSiguiente();
        esPrimerElemento = false;
    }
    return r.str();
}

template<class T>
bool lista<T>::actualizarNodo(int posicion, T* nuevaInfo) {
    if (posicion < 0 || posicion >= k) {
        // La posición está fuera de los límites de la lista.
        return false;
    }

    nodo<T>* cursor = primerNodo;
    for (int i = 0; i < posicion; ++i) {
        cursor = cursor->obtenerSiguiente();
    }

    cursor->fijarInfo(nuevaInfo);
    return true;
}

template<class T>
bool lista<T>::eliminarNodo(int posicion) {
    if (posicion < 0 || posicion >= k) {
        // La posición está fuera de los límites de la lista.
        return false;
    }

    if (posicion == 0) {
        // Eliminar el primer nodo de la lista
        nodo<T>* temp = primerNodo;
        primerNodo = primerNodo->obtenerSiguiente();
        delete temp;
    }
    else {
        // Eliminar un nodo diferente al primero
        nodo<T>* cursor = primerNodo;
        for (int i = 0; i < posicion - 1; ++i) {
            cursor = cursor->obtenerSiguiente();
        }

        nodo<T>* temp = cursor->obtenerSiguiente();
        cursor->fijarSiguiente(temp->obtenerSiguiente());
        delete temp;
    }

    k--;
    return true;
}
template<class T>
lista<T>:: lista(ifstream& entrada){
    deserialize(entrada, this);
}

template<class T>
bool lista<T>::guardar(ofstream& salida) {
    return serialize(salida, (lista*)this);
}



// Este método deserializa (lee) la información de los clientes desde el archivo de entrada
// y utiliza el constructor de cliente para crear los objetos correspondientes.
template<class T>
void lista<T>::deserialize(ifstream& entrada, lista* g) {
    int cantCl = -1;
    int i = 0;
    entrada.read((char*)&cantCl, sizeof(cantCl));

    while (entrada.good() && i < cantCl) {
        try {
            Persona* cl = NULL;

            if (!entrada.good())
                throw - 1;

            cl = new Persona(entrada);

            if (cl != NULL)
                g->agregarFinal(cl);
        }
        catch (int) {
            cout << "Ocurrió un error de lectura en el archivo" << endl;
        }
        i++;
    }
}
template<class T>
bool lista<T>::serialize(ofstream& salida, lista* g) {
    int cantClientes = 1;
    iteradorLista<T>* i = g->obtenerIterador();
    //cantClientes = g->totalClientes();

    salida.write((char*)&cantClientes, sizeof(1));

    while (i->masElementos() && salida.good()) {
        Persona* cl = (Persona*)i->proximoElemento();
        cl->guardar(salida);
    }
    return salida.good();
}


#endif	/* LISTA_H */

