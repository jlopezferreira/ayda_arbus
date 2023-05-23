#include <iostream>
#include <cassert>
#include "Arbin.h"

template <typename T>
Arbin<T>::Arbin()
{
    raiz = NULL;
}

template <typename T>
Arbin<T>::~Arbin()
{
    vaciar();
}

template <typename T>
void Arbin<T>::crearArbin(T elemento)
{
    switch (crear(elemento)) {
        case 1: raiz->hijoIzq->crearArbin(elemento); break;
        case 2: raiz->hijoDer->crearArbin(elemento); break;
        default: break;
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
        return raiz->elemento;
}

// pre: not esVacio
template <typename T>
Arbin<T> * Arbin<T>::subIzquierdo()
{
    assert(raiz == NULL);
    if (raiz != NULL)
        raiz->hijoIzq = new Arbin;
    return raiz->hijoIzq;
}

// pre: not esVacio
template <typename T>
Arbin<T> * Arbin<T>::subDerecho()
{
    assert(raiz == NULL);
    return raiz->hijoDer;
}

template <typename T>
bool Arbin<T>::pertenece(T elemento)
{
    if (raiz != NULL) {
        if (raiz->elemento == elemento)
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

template <typename T>
int Arbin<T>::crear(T elemento)
{
    if (raiz == NULL) {
        raiz = new Nodo;
        raiz->elemento = elemento;
        return 0;
    } else if (raiz->hijoIzq == NULL) {
        raiz->hijoIzq = new Arbin;
        return 1;
    } else if (raiz->hijoDer == NULL) {
        raiz->hijoDer = new Arbin;
        return 2;
    }
}

template class Arbin<int>;
template class Arbin<float>;
