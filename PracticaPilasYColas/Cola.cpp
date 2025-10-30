#include <iostream>
#include <stdlib.h>
using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
};
bool cola_vacia(Nodo *frente){
    return (frente == NULL)? true : false;
}
void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    if (cola_vacia(frente)) {
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\tElemento " << n << " agregado a la cola correctamente." << endl;
}
void suprimirCola(Nodo *&frente, Nodo *&fin, int &n){
    n = frente->dato;
    Nodo *aux = frente;
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
    cout << "\tElemento " << n << " sacado de la cola correctamente." << endl;
}

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;
    cout<<"Digite un numero: "; cin>>dato;
    insertarCola(frente, fin, dato);
    cout<<"Digite un numero: "; cin>>dato;
    insertarCola(frente, fin, dato);
 // Eliminando elementos de la cola
    cout<<"Sacando elementos de la cola: "<<endl;
    while (frente != NULL){ 
        suprimirCola(frente, fin, dato);
        if (frente != NULL) {
            cout << dato << " , "; 
    } else {
            cout << dato << "." << endl; 
        }
    }
    return 0;
}