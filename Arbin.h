#ifndef ARBIN_H_INCLUDED
#define ARBIN_H_INCLUDED

template <typename T>
class Arbin
{
private:
    // Definición de la estructura
    struct Nodo {
        T elemento;
        Arbin<T> * hijoIzq;
        Arbin<T> * hijoDer;
    };
    // Atributos de clase
    Nodo * raiz;
    // Método auxiliar
    int crear(T elemento);
    void vaciar();

public:
    Arbin(); // Constructor
    ~Arbin(); //Destructor
    void crearArbin(T elemento);
    bool esVacio();
    T raizArbin(); // pre: not esVacio
    Arbin<T> * subIzquierdo(); // pre: not esVacio
    Arbin<T> * subDerecho(); // pre: not esVacio
    bool pertenece(T elemento);
};

#endif // ARBIN_H_INCLUDED
