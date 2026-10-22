
#ifndef TALLER_1_ESTRUCTURADEDATOS_COLAPACIENTES_H
#define TALLER_1_ESTRUCTURADEDATOS_COLAPACIENTES_H

#include "NodoPaciente.h"
#include <iostream>
#include "Paciente.h"
using namespace std;

class ColaPacientes
{
private:
    NodoPaciente* frente;
    NodoPaciente* fin;

public:
    ColaPacientes():frente(nullptr),fin(nullptr){}
    ~ColaPacientes();

    void enqueue(Paciente* p );
    Paciente* dequeue();
    void mostrar();
    bool estaVacia() const{ return frente == nullptr; };
    bool contieneId(const string& id) const;
};

#endif //TALLER_1_ESTRUCTURADEDATOS_COLAPACIENTES_H
