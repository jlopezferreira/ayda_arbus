#include <iostream>
#include "Arbin.h"

using namespace std;

int main()
{
    Arbin<int> arbin;
    int num;
    cout << "Ingrese cantidad de numeros: " << endl;
    cin >> num;
    for (int i = 1; i <= num; i++)
        arbin.crearArbin(i);

    cout << "Ingrese numero a buscar: " << endl;
    cin >> num;
    if (arbin.pertenece(num))
        cout << "Pertenece el numero " << num << endl;
    else
        cout << "No pertenece el numero " << num << endl;
    return 0;
}
