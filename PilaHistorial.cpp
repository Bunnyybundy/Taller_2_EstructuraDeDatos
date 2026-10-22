

#include "PilaHistorial.h"

PilaHistorial::~PilaHistorial()
{
    while (cima)
    {
        NodoHistorial* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

void PilaHistorial::push(Paciente* p)
{
    NodoHistorial* nuevo = new NodoHistorial(p);
    nuevo->siguiente = cima;
    cima = nuevo;
}

Paciente* PilaHistorial::pop()
{
    if (!cima) return nullptr;
    NodoHistorial* temp = cima;
    Paciente* p = temp->paciente;
    cima = cima->siguiente;
    delete temp;
    return p;
}

void PilaHistorial::mostrar()
{
    cout << " === HISTORIAL DE ATENCIONES === " << endl;
    NodoHistorial* actual = cima;
    if (!actual)
    {
        cout << "No hay atenciones registradas." << endl;
        return;
    }while (actual)
    {
        actual->paciente->mostrarInfo();
        cout << endl;
        actual = actual->siguiente;
    }
}