
#include "Hospital.h"
#include <iostream>
using namespace std;

Hospital::Hospital() : servicios(nullptr)
{
    string nombres[] = {
        "Urgencias","Medicina General","Cardiologia",
        "Neurologia","Traumatologia","Cirugia",
        "Pediatria","Hospitalizacion"
    };

    NodoServicio* ultimo = nullptr;
    for (int i = 0; i < 8; i++) {
        NodoServicio* nuevo = new NodoServicio(nombres[i]);
        if (!servicios)
        {
            servicios = nuevo;
            ultimo = nuevo;
        }else{
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }
}

Hospital::~Hospital() {
    NodoServicio* actualServicio = servicios;
    while (actualServicio) {
        NodoServicio* siguienteServicio = actualServicio->siguiente;

        NodoPaciente* actualPaciente = actualServicio->paciente;
        while (actualPaciente) {

            NodoPaciente* siguientePaciente = actualPaciente->siguiente;
            delete actualPaciente->paciente;
            delete actualPaciente;
            actualPaciente = siguientePaciente;
        }

        delete actualServicio;
        actualServicio = siguienteServicio;
    }
}

NodoServicio *Hospital::buscarServicio(const string &nombre) const {
    NodoServicio* actual = servicios;
    while (actual)
    {
        if (actual->nombre == nombre) return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

bool Hospital::agregarPacienteAServicio(Paciente* p) {
    NodoServicio* servicio = buscarServicio(p->getServicio());
    if (!servicio) return false;

    NodoPaciente* nuevo = new NodoPaciente(p);
    nuevo->siguiente = servicio->paciente;
    servicio->paciente = nuevo;
    return true;
}

void Hospital::mostrarServicios()
{
    cout << "=== SERVICIOS ===" << endl;
    NodoServicio* actual = servicios;
    int i = 1;
    while (actual)
    {
        cout << i << "." << actual->nombre << endl;
        actual = actual->siguiente;
        i++;
    }

    cout << "Seleccionar opcion: ";
    int opcion;
    cin >> opcion;

    actual = servicios;
    i = 1;
    while (actual && i < opcion) {
        actual = actual->siguiente;
        i++;
    }

    if (!actual) {
        cout << "Opcion invalida." << endl;
        return;
    }

    mostrarPacientesPorServicio(actual->nombre);
}

void Hospital::mostrarPacientesPorServicio(string nombreServicio) {

    NodoServicio* servicio = buscarServicio(nombreServicio);
    if (!servicio) {
        cout << "Servicio no encontrado." << endl;
        return;
    }

    cout <<"=== ESTADO " << servicio->nombre << " ===" << endl;
    NodoPaciente* actual = servicio->paciente;
    if (!actual) {
        cout << "No hay pacientes en este servicio." << endl;
        return;
    }

    while (actual) {
        actual->paciente->mostrarInfo();
        actual = actual->siguiente;
    }
}
