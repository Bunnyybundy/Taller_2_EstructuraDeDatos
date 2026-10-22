
#ifndef TALLER_1_ESTRUCTURADEDATOS_PILAHISTORIAL_H
#define TALLER_1_ESTRUCTURADEDATOS_PILAHISTORIAL_H

#include "Paciente.h"
#include <iostream>
using namespace std;

struct NodoHistorial
{
  Paciente* paciente;
  NodoHistorial* siguiente;
  NodoHistorial(Paciente* p) : paciente(p), siguiente(nullptr){}
};

class PilaHistorial
{
  private:
   NodoHistorial* cima;
  public:
    PilaHistorial():cima(nullptr){}
    ~PilaHistorial();

    void push(Paciente* p);
    Paciente* pop();
    void mostrar();
    bool estaVacia() const { return  cima == nullptr; }
};


#endif //TALLER_1_ESTRUCTURADEDATOS_PILAHISTORIAL_H
