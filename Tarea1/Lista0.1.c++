#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Persona {
private:
    string _nombre;
    string _apellido;
    int _edad;
    int _id;

public:
    // Constructor
    Persona(string n, string a, int e, int i) 
        : _nombre(n), _apellido(a), _edad(e), _id(i) {}

    int getId() const { return _id; }
    
    void mostrar() const {
        std::cout << "[ID: " << std::setw(3) << _id 
                  << " | Nombre: " << _nombre << " " << _apellido
                  << " | Edad: " << std::setw(2) << _edad << "]";
    }
};

template <typename T>
struct Nodo {
    T datos;
    Nodo<T>* siguiente;
    Nodo<T>* anterior; 
    
    Nodo(const T& d) : datos(d), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaSimple {
private:
    Nodo<T>* cabeza;
    
    void liberarMemoria() {
        Nodo<T>* actual = cabeza;
        Nodo<T>* siguiente = nullptr;
        while (actual != nullptr) {
            siguiente = actual->siguiente;
            delete actual; 
            actual = siguiente;
        }
        cabeza = nullptr;
    }

public:
    ListaSimple() : cabeza(nullptr) {}
    ~ListaSimple() { liberarMemoria(); }
    void insertar(const T& dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void mostrar() const {
        cout << "\n--- Lista simple ---\n";
        if (cabeza == nullptr) {
            cout << "Lista vacia.\n";
            return;
        }
        
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            temp->datos.mostrar();
            cout << " -> ";
            temp = temp->siguiente;
        }
       cout << "NULL\n";
    }
};
// -------------------------------------------------------------------
template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    
    void liberarMemoria() {
        Nodo<T>* actual = cabeza;
        Nodo<T>* siguiente = nullptr;
        while (actual != nullptr) {
            siguiente = actual->siguiente;
            delete actual; 
            actual = siguiente;
        }
        cabeza = nullptr;
        cola = nullptr;
    }

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}
    ~ListaDoble() { liberarMemoria(); }
    void insertar(const T& dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;   // Antiguo último -> Nuevo nodo
            nuevoNodo->anterior = cola;    //  Nuevo nodo -> Antiguo último
            cola = nuevoNodo;              //  Actualiza el puntero de la cola
        }
    }

    void mostrar() const {
        cout << "\n--- Lista doble ---\n";
        if (cabeza == nullptr) {
            cout << "Lista vacia.\n";
            return;
        }
        
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            cout << "<- ";
            temp->datos.mostrar();
            cout << " ->";
            temp = temp->siguiente;
        }
       cout << "NULL\n";
    }
};

int main() {
    ListaSimple<Persona> listaSimple;
    ListaDoble<Persona> listaDoble;

    // Crear objetos Persona (Nombre, Apellido, Edad, ID)
    Persona p1("Maria", "Corina", 25, 01);
    Persona p2("Radoski", "Gomez", 30, 02);
    Persona p3("Anabella", "Perez", 22, 03);

    
    cout << "Lista simple\n";
    listaSimple.insertar(p1); 
    listaSimple.insertar(p2); 
    listaSimple.insertar(p3); 
    listaSimple.mostrar();
   

    cout << "Lista doble\n";
    listaDoble.insertar(p1); 
    listaDoble.insertar(p2); 
    listaDoble.insertar(p3); 
    listaDoble.mostrar();

    cout << "Fue liberada la memoria";
    
    return 0;
}