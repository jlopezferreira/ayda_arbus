#include <iostream>
#include <cassert>
#include "Arbin.h"

template <typename T>
Arbin<T>::Arbin()
{
    raiz = NULL;
    hijoIzq = NULL;
    hijoDer = NULL;
    padre = NULL;
}

template <typename T>
Arbin<T>::Arbin(Arbin * & padre)
{
    raiz = NULL;
    hijoIzq = NULL;
    hijoDer = NULL;
    padre = padre;
}

template <typename T>
Arbin<T>::~Arbin()
{
    vaciar();
}

template <typename T>
bool Arbin<T>::crearArbin(T elemento)
{
    if (esVacio()) {
        raiz = elemento;
        return true;
    }
    if(!subIzquierdo()->crearArbin(elemento))
        subDerecho()->crearArbin(elemento);
}

template <typename T>
bool Arbin<T>::esVacio()
{
    return raiz == NULL;
}

// pre: not esVacio
template <typename T>
T Arbin<T>::raizArbin()
{
    if (raiz != NULL)
        return raiz;
    else
        return NULL;
}

// pre: not esVacio
template <typename T>
Arbin<T> * Arbin<T>::subIzquierdo()
{
    assert(raiz != NULL);
    if (hijoIzq == NULL)
        hijoIzq = new Arbin;
    return hijoIzq;
}

// pre: not esVacio
template <typename T>
Arbin<T> * Arbin<T>::subDerecho()
{
    assert(raiz != NULL);
    if (hijoDer == NULL)
        hijoDer = new Arbin;
    return hijoDer;
}

template <typename T>
bool Arbin<T>::pertenece(T elemento)
{
    if (raiz != NULL) {
        if (raiz == elemento)
            return true;
        if (hijoIzq != NULL)
            if(subIzquierdo()->pertenece(elemento))
                return true;
        if (hijoDer != NULL)
            if(subDerecho()->pertenece(elemento))
                return true;
    }
    return false;
}

template <typename T>
bool Arbin<T>::esHoja()
{
    return (hijoIzq == NULL && hijoDer == NULL);
}

// Método auxiliar
template <typename T>
void Arbin<T>::vaciar()
{
    // TO-DO
    raiz = NULL;
}

template class Arbin<int>;
template class Arbin<float>;
