#include <iostream>
using namespace std;

struct Nodo {
    int matricula;
    Nodo* izq;
    Nodo* der;
    Nodo(int m): matricula(m), izq(nullptr), der(nullptr) {}
};

class BST {
    Nodo* raiz;

    Nodo* insertarRec(Nodo* nodo, int m) {
        if (!nodo) return new Nodo(m);
        if (m < nodo->matricula) nodo->izq = insertarRec(nodo->izq, m);
        else nodo->der = insertarRec(nodo->der, m);
        return nodo;
    }

    bool buscarRec(Nodo* nodo, int m) {
        if (!nodo) return false;
        if (nodo->matricula == m) return true;
        if (m < nodo->matricula) return buscarRec(nodo->izq, m);
        return buscarRec(nodo->der, m);
    }

public:
    BST(): raiz(nullptr) {}
    void insertar(int m) { raiz = insertarRec(raiz, m); }
    bool buscar(int m) { return buscarRec(raiz, m); }
};

int main() {
    BST arbol;
    // Matrículas
    int matriculas[] = {2025001, 2024005, 2021003, 2023008, 2022002, 2020009, 2021004};
    for (int m : matriculas) arbol.insertar(m);

    cout << "Sistema de busqueda de estudiantes\n";
    cout << "Ingrese el numero de matricula para buscar: ";
    int busq;
    if (!(cin >> busq)) {
        cout << "Entrada no valida\n";
        return 0;
    }

    if (arbol.buscar(busq)) cout << "La matricula " << busq << " Se encuentra en el arbol.\n";
    else cout << "La matricula " << busq << " No se encuentra.\n";
    return 0;
}