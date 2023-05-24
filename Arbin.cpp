#include <iostream>
#include <cassert>
#include "Arbin.h"

template <typename T>
Arbin<T>::Arbin()
{
    raiz = NULL;
    hijoIzq = NULL;
    hijoDer = NULL;
}

template <typename T>
Arbin<T>::~Arbin()
{
    vaciar();
}

template <typename T>
void Arbin<T>::crearArbin(T elemento)
{
    if (raiz != NULL) {
        if (hijoIzq == NULL)
            hijoIzq = new Arbin;
        if (hijoIzq->esVacio())
            hijoIzq->crearArbin(elemento);
        if (hijoDer == NULL)
            hijoDer = new Arbin;
        if (hijoDer->esVacio())
            hijoDer->crearArbin(elemento);
    } else {
        raiz = elemento;
    }
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
    assert(raiz == NULL);
    return hijoIzq;
}

// pre: not esVacio
template <typename T>
Arbin<T> * Arbin<T>::subDerecho()
{
    assert(raiz == NULL);
    return hijoDer;
}

template <typename T>
bool Arbin<T>::pertenece(T elemento)
{
    if (raiz != NULL) {
        if (raiz == elemento)
            return true;
        if(subIzquierdo()->pertenece(elemento))
            return true;
        if(subDerecho()->pertenece(elemento))
            return true;
    }
    return false;
}

template <typename T>
void Arbin<T>::vaciar()
{
    // TO-DO
    raiz = NULL;
}

template class Arbin<int>;
template class Arbin<float>;
