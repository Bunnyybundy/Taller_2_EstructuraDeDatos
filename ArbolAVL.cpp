
#include "ArbolAVL.h"

ArbolAVL::ArbolAVL()
{
    raiz = nullptr;
}
int ArbolAVL::obtenerAltura(NodoAVL* nodo) const
{
    if (nodo == nullptr)
    {
        return 0;
    }
    return nodo->altura;
}
int ArbolAVL::obtenerBalance(NodoAVL* nodo) const
{
    if (nodo == nullptr)
    {
        return 0;
    }
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}