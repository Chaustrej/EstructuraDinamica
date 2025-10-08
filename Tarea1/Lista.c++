#include <iostream>
#include <iomanip> //
#include <string>

using namespace std;

struct Persona {
    string nombre;
    string apellido;
    int edad;
    int id;
};

struct Nodossimple {
    Persona dato;
    Nodossimple* siguiente;
};

struct NodoDoble {
    Persona dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

typedef Nodossimple* ListaSimple; // 
typedef NodoDoble* ListaDoble; // 

void insertarSimple(ListaSimple& lista, Persona p) {
    Nodossimple* nuevoNodo = new Nodossimple;
    nuevoNodo->dato = p;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
    cout << "->Persona:'" <<p.nombre <<"' (id:" <<p.id<<") agregada a la Lista Simple.\n";
}


void mostrarSimple(ListaSimple lista) {
    cout << "\n--- Lista Simplemente Enlazada\n";
    if (lista == nullptr) {
        std::cout << "La lista esta vacia.\n";
        return;
    }
    Nodossimple* temp = lista;
    while (temp != nullptr) {
       cout << "[ID: " << setw(3) << temp->dato.id 
                  << " | Nombre: " << setw(15) << temp->dato.nombre 
                  << " | apellido: " << setw(15) << temp->dato.apellido
                  << " | Edad: " << setw(2) << temp->dato.edad << "] -> ";
        temp = temp->siguiente;
    }
   cout << "NULL\n";
}
void liberarMemoriaSimple(ListaSimple& lista) {
    Nodossimple* actual = lista;
    Nodossimple* siguiente;
    while (actual != nullptr) {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    lista = nullptr;
}

void insertarDoble(ListaDoble& lista, const Persona& p) {
    NodoDoble* nuevoNodo = new NodoDoble;
    nuevoNodo->dato = p;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (lista == nullptr) {
        lista = nuevoNodo;
    } else {
        NodoDoble* ultimo = lista;
        while (ultimo->siguiente != nullptr) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
    }
    cout << "-> Persona '" <<p.nombre<< "' (id: "<< p.id<< ") agregada a la Lista Doble.\n";
}

void mostrarDoble(ListaDoble lista) {
   cout << "\n-Lista Doblemente Enlazada-\n";
    if (lista == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }
    NodoDoble* temp = lista;
    while (temp != nullptr) {
       cout << "<-ID: " << setw(3) << temp->dato.id 
                  << " Nombre: " << setw(15) << temp->dato.nombre 
                   << " Apellido: " << setw(15) << temp->dato.apellido 
                  << " Edad: " << setw(2) << temp->dato.edad << "] ->";
        temp = temp->siguiente;
    }
    cout << "NULL";
}
void liberarMemoriaDoble(ListaDoble& lista) {
    NodoDoble* actual = lista;
    NodoDoble* siguiente;
    while (actual != nullptr) {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    lista = nullptr;
}

int main() {
    ListaSimple listaSimple = nullptr; 
    ListaDoble listaDoble = nullptr;

    Persona p1 = {"Alicia","Nazaret", 30, 0};
    Persona p2 = {"Juan","Chaustre", 25, 1};
    Persona p3 = {"Maroa","Sanchez", 40, 2};
    
    // Prueba LSE (Insertar al inicio)
    cout << "\n--- insentar lista simple ---\n";
    insertarSimple(listaSimple, p1); 
    insertarSimple(listaSimple, p2); 
    insertarSimple(listaSimple, p3); 
    mostrarSimple(listaSimple); 

    // Prueba LDE (Insertar al final)
    cout << "\ninsertar lista doble\n";
    insertarDoble(listaDoble, p1); 
    insertarDoble(listaDoble, p2); 
    insertarDoble(listaDoble, p3); 
    mostrarDoble(listaDoble); 

    liberarMemoriaSimple(listaSimple);
    liberarMemoriaDoble(listaDoble);
    cout << "\nMemoria liberada manualmente.\n";

    return 0;
}