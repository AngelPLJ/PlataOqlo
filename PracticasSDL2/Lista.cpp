#include<iostream>
#include<string>
#include"Nodo.cpp"

using namespace std;

class Lista {
    private:
    Nodo *nodo;
    bool compararCadenas(string cadena1, string cadena2);
    Nodo * getPreTail();
    public:
    Lista();
    void addNodo();
    void addNodo(string dato);
    void sortList();
    bool deleteNodo(int posicion);
    int findNodo();
    void printList();
    void destroy();
    int lenght();
};

Lista::Lista()
{
    nodo = NULL;
}

int Lista::lenght()
{
    int tam = 0;
    Nodo *nodoAux = nodo;
    while(nodoAux != NULL)
    {
        nodoAux = nodoAux->getNodoSiguiente();
        tam++;
    }
    return tam;
}

bool Lista::deleteNodo(int posicion)
{
    if(posicion <= lenght())
    {
        Nodo *nodoAux = nodo;
        Nodo *nodoAnterior = NULL;
        int i = 1;
        if(posicion == 1)
        {
            nodo = nodo->getNodoSiguiente();
            delete nodoAux;
        } else {
            while (i != posicion)
            {
                nodoAnterior = nodoAux;
                nodoAux = nodoAux->getNodoSiguiente();
                i++;
            }
            nodoAnterior->setNodoSiguiente(nodoAux->getNodoSiguiente());
            delete nodoAux;
        }
        return true;
    } else return false;
}

void Lista::addNodo()
{
    //cout << "AddNode" << endl;
    if(nodo != NULL)
    {
        Nodo *nuevoNodo = new Nodo();
        Nodo *nodoAux = nodo;
        while(nodoAux->getNodoSiguiente() != NULL)
        {
            nodoAux = nodoAux->getNodoSiguiente();
        }
        nodoAux->setNodoSiguiente(nuevoNodo);
    } else {
        nodo = new Nodo();
    }
}

void Lista::addNodo(string dato)
{
    //cout << "AddNode" << endl;
    if(nodo != NULL)
    {
        Nodo *nuevoNodo = new Nodo(dato);
        Nodo *nodoAux = nodo;
        while(nodoAux->getNodoSiguiente() != NULL)
        {
            nodoAux = nodoAux->getNodoSiguiente();
        }
        nodoAux->setNodoSiguiente(nuevoNodo);
    } else {
        nodo = new Nodo(dato);
    }
}

void Lista::sortList()
{
    Nodo *nodoAux = nodo;
    Nodo *nodoSiguiente = nodoAux->getNodoSiguiente();
    Nodo *nodoAnterior;
    if(nodoSiguiente != NULL)
    {
        while(nodoSiguiente !=NULL)
        {
            if(nodoAux == nodo)
            {
                if(compararCadenas(nodoAux->getDato(), nodoSiguiente->getDato()))
                {
                    nodoAux->setNodoSiguiente(nodoSiguiente->getNodoSiguiente());
                    nodoSiguiente->setNodoSiguiente(nodoAux);
                    nodo = nodoSiguiente;
                    nodoAnterior = NULL;
                    nodoAux = nodo;
                    nodoSiguiente = nodoAux->getNodoSiguiente();
                } else {
                    nodoAnterior = nodoAux;
                    nodoAux = nodoAux->getNodoSiguiente();
                    nodoSiguiente = nodoAux->getNodoSiguiente();
                }
            } else if(compararCadenas(nodoAux->getDato(),nodoSiguiente->getDato()))
            {
                nodoAux->setNodoSiguiente(nodoSiguiente->getNodoSiguiente());
                nodoSiguiente->setNodoSiguiente(nodoAux);
                nodoAnterior->setNodoSiguiente(nodoSiguiente);
                nodoAnterior = NULL;
                nodoAux = nodo;
                nodoSiguiente = nodoAux->getNodoSiguiente();                
            } else {
                nodoAnterior = nodoAux;
                nodoAux = nodoAux->getNodoSiguiente();
                nodoSiguiente = nodoAux->getNodoSiguiente();
            }
        }
    }
}

bool Lista::compararCadenas(string cadena1, string cadena2)
{
    int i = 0;
    for(char caracter :  cadena1)
    {
        if(tolower(caracter) > tolower(cadena2[i])) return true;
        else if(tolower(caracter) < tolower(cadena2[i])) return false;
        else i++; 
    }
    return false;
}

void Lista::printList()
{
    cout << "PrintList" << endl;
    string cadena = "";
    Nodo *nodoAux = nodo;
    while(nodoAux != NULL)
    {
        cadena.append(nodoAux->getDato());
        nodoAux = nodoAux->getNodoSiguiente();
    }

    cout << cadena << endl;
}

void Lista::destroy()
{
    if(nodo != NULL)
    {
        if(nodo->getNodoSiguiente() != NULL)
        {
            Nodo *tailNodo = getPreTail();
            //cout << "Paso el pretail" << endl;
            int i = 0;
            while(nodo->getNodoSiguiente() != NULL)
            {
                //cout << tailNodo->getDato() << endl;
                tailNodo->deleteNodoSiguiente();
                if(tailNodo->getNodoSiguiente() == NULL)
                {
                    //cout << "Se borro el nodo siguiente" << endl;
                }
                tailNodo = getPreTail();
            }
            //cout << "Salio del while" << endl;
        }
        delete nodo;
        nodo = NULL;
    } else {
        cout << "La lista esta vacia, no se destruyo ningun nodo" << endl;
    }
}

Nodo * Lista::getPreTail()
{
    Nodo *nodoAux = nodo;
    if(nodoAux->getNodoSiguiente() != NULL)
    {
        while(nodoAux->getNodoSiguiente()->getNodoSiguiente() != NULL)
        {
            nodoAux = nodoAux ->getNodoSiguiente();
        }
        return nodoAux;
    } else return nodoAux; 
}


