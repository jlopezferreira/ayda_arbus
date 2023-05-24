#ifndef ARBIN_H_INCLUDED
#define ARBIN_H_INCLUDED

template <typename T>
class Arbin
{
private:
    // Definici�n de la estructura
    // Atributos de clase
    T raiz;
    Arbin<T> * hijoIzq;
    Arbin<T> * hijoDer;
    Arbin<T> * padre;
    // M�todo auxiliar
    void vaciar();

public:
    Arbin(); // Constructor
    Arbin(Arbin * & padre); // Constructor
    ~Arbin(); //Destructor
    bool crearArbin(T elemento);
    bool esVacio();
    T raizArbin(); // pre: not esVacio
    Arbin<T> * subIzquierdo(); // pre: not esVacio
    Arbin<T> * subDerecho(); // pre: not esVacio
    bool pertenece(T elemento);

    bool esHoja();
    int altura();
    int cantidadNodos();
    int operator== (Arbin<T> & otroArbol);
};

#endif // ARBIN_H_INCLUDED
