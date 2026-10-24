
#ifndef TALLER_2_ESTRUCTURADEDATOS_ARBOLAVL_H
#define TALLER_2_ESTRUCTURADEDATOS_ARBOLAVL_H

#include "NodoAVL.h"

class ArbolAVL
{
    private:
        NodoAVL* raiz;
        NodoAVL* insertar(NodoAVL* nodo, const Paciente& paciente);
        int obtenerAltura(NodoAVL* nodo) const;
        int obtenerBalance(NodoAVL* nodo) const;

    public:
        ArbolAVL();
        ~ArbolAVL();

    void insertar(const Paciente& paciente);
    bool buscar(const string& id) const;
    void mostrarInorde() const;
};


#endif //TALLER_2_ESTRUCTURADEDATOS_ARBOLAVL_H
