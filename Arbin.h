#ifndef ARBIN_H_INCLUDED
#define ARBIN_H_INCLUDED

template <typename T>
class Arbin
{
private:
    // Definición de la estructura
    struct Nodo {
        T elemento;
        Nodo * hijo;
        Nodo * hija;
    };
    // Atributos de clase
    Nodo * raiz;

public:
    Arbin(); // Constructor
    ~Arbin(); //Destructor
    void crearArbin(T elemento);
    bool esVacio();
    T raizArbin(); // pre: not esVacio
    Arbin * subIzquierdo(); // pre: not esVacio
    Arbin * subDerecho(); // pre: not esVacio
    bool pertenece(T elemento);
};

#endif // ARBIN_H_INCLUDED
