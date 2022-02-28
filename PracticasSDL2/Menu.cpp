#include<iostream>
#include<string>
#include"Lista.cpp"

using namespace std;

class Menu {
    private:
    Lista miLista;
    public:
    Menu();
    void mostrarMenu();
};

Menu::Menu()
{
}

void Menu::mostrarMenu()
{
    int opcion;
    string datosDeEntrada;
    int posicion;
    bool salida;
    salida = false;
    opcion = 0;
    datosDeEntrada = "";
    while(salida != true)
    {
        cout << "Ingrese el numero de la accion que desee realizar" << endl;
        cout << "1) Agregar nodo \n2) Eliminar nodo \n3) Mostrar lista \n4) Ordenar la lista \n5) Eliminar lista \n6) Salir" << endl;
        cin >> opcion;
        switch(opcion)
        {   case 1:
                cin >> datosDeEntrada;
                if(datosDeEntrada.empty())
                    miLista.addNodo();
                else
                    miLista.addNodo(datosDeEntrada);
                break;
            case 2:
                cin >> posicion;
                if(miLista.deleteNodo(posicion))
                    cout << "Nodo eliminado" << endl;
                else
                    cout << "No se pudo eliminar el nodo" << endl;
                break;
            case 3:
                miLista.printList();
                break;
            case 4:
                miLista.sortList();
                break;
            case 5:
                miLista.destroy();
                break;
            case 6:
                salida = true;
                cout << "Saliendo" << endl;
                miLista.destroy();
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }

    }
}