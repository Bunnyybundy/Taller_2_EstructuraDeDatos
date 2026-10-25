
#ifndef TALLER_2_ESTRUCTURADEDATOS_ARBOLAVL_H
#define TALLER_2_ESTRUCTURADEDATOS_ARBOLAVL_H

#include "NodoAVL.h"
#include <string>
using namespace std;

class ArbolAVL
{
    private:
        NodoAVL* raiz;
        int cantidad;

        static int compararId(const string& a, const string& b);

        int obtenerAltura(NodoAVL* nodo) const;
        int obtenerBalance(NodoAVL* nodo) const;
        void actualizarAltura(NodoAVL* nodo);

        NodoAVL* rotarDerecha(NodoAVL* y);
        NodoAVL* rotarIzquierda(NodoAVL* x);
        NodoAVL* rotacionIzquierdaDerecha(NodoAVL* nodo);
        NodoAVL* rotacionDerechaIzquierda(NodoAVL* nodo);
        NodoAVL* balancear(NodoAVL* nodo);

        NodoAVL* insertar(NodoAVL* nodo, const Paciente& paciente, bool& insertado);
        NodoAVL* eliminar(NodoAVL* nodo, const string& id, bool& eliminado);
        NodoAVL* minimo(NodoAVL* nodo) const;
        const Paciente* buscarNombre(NodoAVL* nodo, const string& nombreMinuscula) const;

        void liberar(NodoAVL* nodo);
        void inorden(NodoAVL* nodo, string& salida) const;
        void preorden(NodoAVL* nodo, string& salida) const;
        void postorden(NodoAVL* nodo, string& salida) const;
        void factores(NodoAVL* nodo, string& salida) const;

        bool mostrarRotaciones;

    public:
        ArbolAVL();
        ~ArbolAVL();
        ArbolAVL(const ArbolAVL&) = delete;
        ArbolAVL& operator=(const ArbolAVL&) = delete;

        bool insertar(const Paciente& paciente);
        bool eliminar(const string& id);

        const Paciente* buscarPorId(const string& id, string& ruta) const;
        const Paciente* buscarPorId(const string& id) const;
        const Paciente* buscarPorNombre(const string& nombre) const;
        bool buscar(const string& id) const;

        void mostrarInorden() const;
        void mostrarPreorden() const;
        void mostrarPostorden() const;
        void mostrarFactoresBalance() const;

        int altura() const;
        int factorBalanceRaiz() const;
        int tamano() const;
        bool estaVacio() const;
        void activarMensajesRotacion(bool activar);

};

#endif //TALLER_2_ESTRUCTURADEDATOS_ARBOLAVL_H
