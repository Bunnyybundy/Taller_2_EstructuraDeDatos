


#include "ColaPacientes.h"
#include <iostream>
using namespace std;

ColaPacientes::~ColaPacientes()
{
    while (frente)
    {
        NodoPaciente* temp = frente;
        frente = frente->siguiente;
        delete temp ->paciente;
        delete temp;
    }
}

void ColaPacientes::enqueue(Paciente* p )
{
    NodoPaciente* nuevo = new NodoPaciente(p);
    if (!frente)
    {
        frente = fin = nuevo;
    }else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}
Paciente* ColaPacientes::dequeue()
{
    if (!frente)return nullptr;
    NodoPaciente* temp = frente;
    Paciente* p = temp->paciente;
    frente = frente->siguiente;
    if (!frente) fin = nullptr;
    delete temp;
    return p;
}

void ColaPacientes::mostrar()
{
    NodoPaciente* actual = frente;
    int i = 1;
    while (actual)
    {
        cout << i++ << ". ";
        actual->paciente->mostrarInfo();
        cout << endl;
        actual = actual->siguiente;
    }
}

bool ColaPacientes::contieneId(const string &id) const {

    NodoPaciente* actual = frente;
    while (actual) {
        if (actual->paciente->getId() == id) return true;
        actual = actual->siguiente;
    }
    return false;
}
