#include <iostream>
#include <string>

using namespace std;

class Nodo {
    private:
    string dato;
    Nodo *nodoSiguiente;
    public:
    Nodo();
    Nodo(string dato);
    void setDato();
    string getDato();
    void setNodoSiguiente(Nodo *nodo);
    Nodo* getNodoSiguiente();
    void deleteNodoSiguiente();
};

Nodo::Nodo()
{
    dato = " ";
    nodoSiguiente = NULL;
}

Nodo::Nodo(string dato)
{
    this->dato = dato;
    nodoSiguiente = NULL;
}

void Nodo::setNodoSiguiente(Nodo *nodo)
{
    nodoSiguiente = nodo;
}

string Nodo::getDato()
{
    return dato;
}

Nodo *Nodo::getNodoSiguiente()
{
    return nodoSiguiente;
}

void Nodo::deleteNodoSiguiente()
{
    if(nodoSiguiente != NULL)
    {
        delete nodoSiguiente;
        nodoSiguiente = NULL;
    } else {
        cout << "El nodo siguiente esta vacio" << endl;
    }
}

