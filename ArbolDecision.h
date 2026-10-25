

#ifndef TALLER_2_ESTRUCTURADEDATOS_ARBOLDECISION_H
#define TALLER_2_ESTRUCTURADEDATOS_ARBOLDECISION_H

#include "Paciente.h"
#include <string>
using namespace std;

class ArbolDecision
{
  private:

    struct Nodo
    {
        int pregunta;
        string servicio;
        bool esHoja;
        Nodo* si;
        Nodo* no;

        Nodo(int pregunta);
        Nodo(const string& servicio);
    };

    Nodo* raiz;

    Nodo* construirArbol();
    void liberarArbol(Nodo* nodo);

    void preorden(Nodo* nodo) const;
    void inorden(Nodo* nodo) const;
    void postorden(Nodo* nodo) const;
    void mostrarNodo(Nodo* nodo) const;

    bool responder(int pregunta, const Paciente& paciente) const;

    string textoPregunta(int pregunta) const;
    string textoRespuesta(int pregunta, bool respuesta) const;

public:
    ArbolDecision();
    ~ArbolDecision();
    ArbolDecision(const ArbolDecision&) = delete;
    ArbolDecision& operator=(const ArbolDecision&) = delete;

    static bool datosValidos(const Paciente& paciente, string& motivo);

    string determinarServicio(const Paciente& paciente, string& ruta) const;
    string determinarServicio(const Paciente& paciente) const;

    void mostrarPreorden() const;
    void mostrarInorden() const;
    void mostrarPostorden() const;
};

#endif