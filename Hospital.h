
#ifndef TALLER_1_ESTRUCTURADEDATOS_HOSPITAL_H
#define TALLER_1_ESTRUCTURADEDATOS_HOSPITAL_H
#include <iostream>
#include "NodoPaciente.h"
using namespace std;

struct NodoServicio
{
    string nombre;
    NodoPaciente* paciente;
    NodoServicio* siguiente;

    NodoServicio(string n): nombre(n), paciente(nullptr), siguiente(nullptr) {}
};

class Hospital
{
private:
    NodoServicio* servicios;
    NodoServicio* buscarServicio(const string& nombre) const;

public:
    Hospital();
    ~Hospital();
    bool agregarPacienteAServicio(Paciente* p);
    void mostrarServicios();
    void mostrarPacientesPorServicio(string nombreServicio);
};



#endif //TALLER_1_ESTRUCTURADEDATOS_HOSPITAL_H
