#include "ArbolAVL.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;
 
namespace {
 
    bool soloDigitos(const string& s)
    {
        if (s.empty()) return false;
        for (char c : s)
        {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }
 
    string sinCerosIzquierda(const string& s)
    {
        size_t i = 0;
        while (i + 1 < s.size() && s[i] == '0') i++;
        return s.substr(i);
    }
 
    string paciente_a_texto(const Paciente& p)
    {
        return p.getNombre() + " (" + p.getId() + ")";
    }
}
 
ArbolAVL::ArbolAVL() : raiz(nullptr), cantidad(0), mostrarRotaciones(true) {}
 
ArbolAVL::~ArbolAVL()
{
    liberar(raiz);
    raiz = nullptr;
}
 
void ArbolAVL::liberar(NodoAVL* nodo)
{
    if (nodo == nullptr) return;
    liberar(nodo->izquierda);
    liberar(nodo->derecha);
    delete nodo;
}
 
void ArbolAVL::activarMensajesRotacion(bool activar)
{
    mostrarRotaciones = activar;
}
 
int ArbolAVL::compararId(const string& a, const string& b)
{
    if (soloDigitos(a) && soloDigitos(b))
    {
        string x = sinCerosIzquierda(a);
        string y = sinCerosIzquierda(b);
        if (x.size() != y.size()) return x.size() < y.size() ? -1 : 1;
        int c = x.compare(y);
        return c < 0 ? -1 : (c > 0 ? 1 : 0);
    }
    int c = a.compare(b);
    return c < 0 ? -1 : (c > 0 ? 1 : 0);
}
 
// ---------------- Altura y balance ----------------
 
int ArbolAVL::obtenerAltura(NodoAVL* nodo) const
{
    if (nodo == nullptr) return 0;
    return nodo->altura;
}
 
int ArbolAVL::obtenerBalance(NodoAVL* nodo) const
{
    if (nodo == nullptr) return 0;
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}
 
void ArbolAVL::actualizarAltura(NodoAVL* nodo)
{
    int hi = obtenerAltura(nodo->izquierda);
    int hd = obtenerAltura(nodo->derecha);
    nodo->altura = 1 + (hi > hd ? hi : hd);
}
 
int ArbolAVL::altura() const { return obtenerAltura(raiz); }
int ArbolAVL::factorBalanceRaiz() const { return obtenerBalance(raiz); }
int ArbolAVL::tamano() const { return cantidad; }
bool ArbolAVL::estaVacio() const { return raiz == nullptr; }
 
// ---------------- Rotaciones ----------------
 
NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* y)
{
    NodoAVL* x = y->izquierda;
    NodoAVL* t2 = x->derecha;
 
    x->derecha = y;
    y->izquierda = t2;
 
    actualizarAltura(y);
    actualizarAltura(x);
    return x;
}
 
NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* x)
{
    NodoAVL* y = x->derecha;
    NodoAVL* t2 = y->izquierda;
 
    y->izquierda = x;
    x->derecha = t2;
 
    actualizarAltura(x);
    actualizarAltura(y);
    return y;
}
 
NodoAVL* ArbolAVL::rotacionIzquierdaDerecha(NodoAVL* nodo)
{
    nodo->izquierda = rotarIzquierda(nodo->izquierda);
    return rotarDerecha(nodo);
}
 
NodoAVL* ArbolAVL::rotacionDerechaIzquierda(NodoAVL* nodo)
{
    nodo->derecha = rotarDerecha(nodo->derecha);
    return rotarIzquierda(nodo);
}
 
NodoAVL* ArbolAVL::balancear(NodoAVL* nodo)
{
    actualizarAltura(nodo);
    int balance = obtenerBalance(nodo);
 
    if (balance > 1)
    {
        if (obtenerBalance(nodo->izquierda) >= 0)
        {
            if (mostrarRotaciones)
                cout << "  [AVL] Rotacion simple derecha en nodo " << nodo->paciente.getId() << endl;
            return rotarDerecha(nodo);
        }
        if (mostrarRotaciones)
            cout << "  [AVL] Rotacion doble izquierda-derecha en nodo " << nodo->paciente.getId() << endl;
        return rotacionIzquierdaDerecha(nodo);
    }
 
    if (balance < -1)
    {
        if (obtenerBalance(nodo->derecha) <= 0)
        {
            if (mostrarRotaciones)
                cout << "  [AVL] Rotacion simple izquierda en nodo " << nodo->paciente.getId() << endl;
            return rotarIzquierda(nodo);
        }
        if (mostrarRotaciones)
            cout << "  [AVL] Rotacion doble derecha-izquierda en nodo " << nodo->paciente.getId() << endl;
        return rotacionDerechaIzquierda(nodo);
    }
 
    return nodo;
}

NodoAVL* ArbolAVL::insertar(NodoAVL* nodo, const Paciente& paciente, bool& insertado)
{
    if (nodo == nullptr)
    {
        insertado = true;
        return new NodoAVL(paciente);
    }
 
    int cmp = compararId(paciente.getId(), nodo->paciente.getId());
    if (cmp < 0)
    {
        nodo->izquierda = insertar(nodo->izquierda, paciente, insertado);
    }
    else if (cmp > 0)
    {
        nodo->derecha = insertar(nodo->derecha, paciente, insertado);
    }
    else
    {
        insertado = false;   // ID duplicado
        return nodo;
    }
 
    if (!insertado) return nodo;
    return balancear(nodo);
}
 
bool ArbolAVL::insertar(const Paciente& paciente)
{
    bool insertado = false;
    raiz = insertar(raiz, paciente, insertado);
    if (insertado) cantidad++;
    return insertado;
}
 
NodoAVL* ArbolAVL::minimo(NodoAVL* nodo) const
{
    while (nodo != nullptr && nodo->izquierda != nullptr)
    {
        nodo = nodo->izquierda;
    }
    return nodo;
}
 
NodoAVL* ArbolAVL::eliminar(NodoAVL* nodo, const string& id, bool& eliminado)
{
    if (nodo == nullptr) return nullptr;
 
    int cmp = compararId(id, nodo->paciente.getId());
    if (cmp < 0)
    {
        nodo->izquierda = eliminar(nodo->izquierda, id, eliminado);
    }
    else if (cmp > 0)
    {
        nodo->derecha = eliminar(nodo->derecha, id, eliminado);
    }
    else
    {
        eliminado = true;
 
        if (nodo->izquierda == nullptr || nodo->derecha == nullptr)
        {
            NodoAVL* hijo = nodo->izquierda != nullptr ? nodo->izquierda : nodo->derecha;
            delete nodo;
            return hijo;   // puede ser nullptr; el padre se encarga de rebalancear
        }

        // Dos hijos: se reemplaza por el sucesor inorden
        NodoAVL* sucesor = minimo(nodo->derecha);
        nodo->paciente = sucesor->paciente;
        bool aux = false;
        nodo->derecha = eliminar(nodo->derecha, sucesor->paciente.getId(), aux);
    }
 
    return balancear(nodo);
}
 
bool ArbolAVL::eliminar(const string& id)
{
    bool eliminado = false;
    raiz = eliminar(raiz, id, eliminado);
    if (eliminado) cantidad--;
    return eliminado;
}

const Paciente* ArbolAVL::buscarPorId(const string& id, string& ruta) const
{
    ruta = "";
    NodoAVL* actual = raiz;
    while (actual != nullptr)
    {
        if (!ruta.empty()) ruta += " -> ";
        ruta += actual->paciente.getId();
 
        int cmp = compararId(id, actual->paciente.getId());
        if (cmp == 0) return &actual->paciente;
        actual = (cmp < 0) ? actual->izquierda : actual->derecha;
    }
    return nullptr;
}
 
const Paciente* ArbolAVL::buscarPorId(const string& id) const
{
    string ruta;
    return buscarPorId(id, ruta);
}
 
bool ArbolAVL::buscar(const string& id) const
{
    return buscarPorId(id) != nullptr;
}
 
const Paciente* ArbolAVL::buscarNombre(NodoAVL* nodo, const string& nombreMinuscula) const
{
    if (nodo == nullptr) return nullptr;
 
    if (minusculas(nodo->paciente.getNombre()) == nombreMinuscula)
        return &nodo->paciente;
 
    const Paciente* encontrado = buscarNombre(nodo->izquierda, nombreMinuscula);
    if (encontrado != nullptr) return encontrado;
    return buscarNombre(nodo->derecha, nombreMinuscula);
}
 
const Paciente* ArbolAVL::buscarPorNombre(const string& nombre) const
{
    return buscarNombre(raiz, minusculas(recortar(nombre)));
}

void ArbolAVL::inorden(NodoAVL* nodo, string& salida) const
{
    if (nodo == nullptr) return;
    inorden(nodo->izquierda, salida);
    if (!salida.empty()) salida += ", ";
    salida += paciente_a_texto(nodo->paciente);
    inorden(nodo->derecha, salida);
}
 
void ArbolAVL::preorden(NodoAVL* nodo, string& salida) const
{
    if (nodo == nullptr) return;
    if (!salida.empty()) salida += ", ";
    salida += paciente_a_texto(nodo->paciente);
    preorden(nodo->izquierda, salida);
    preorden(nodo->derecha, salida);
}
 
void ArbolAVL::postorden(NodoAVL* nodo, string& salida) const
{
    if (nodo == nullptr) return;
    postorden(nodo->izquierda, salida);
    postorden(nodo->derecha, salida);
    if (!salida.empty()) salida += ", ";
    salida += paciente_a_texto(nodo->paciente);
}
 
void ArbolAVL::factores(NodoAVL* nodo, string& salida) const
{
    if (nodo == nullptr) return;
    factores(nodo->izquierda, salida);
    salida += "  " + nodo->paciente.getNombre() + " (" + nodo->paciente.getId() + "): "
              + "altura = " + to_string(nodo->altura)
              + ", factor de balance = " + to_string(obtenerBalance(nodo)) + "\n";
    factores(nodo->derecha, salida);
}
 
void ArbolAVL::mostrarInorden() const
{
    string salida;
    inorden(raiz, salida);
    cout << (salida.empty() ? "Sin pacientes" : salida) << endl;
}
 
void ArbolAVL::mostrarPreorden() const
{
    string salida;
    preorden(raiz, salida);
    cout << (salida.empty() ? "Sin pacientes" : salida) << endl;
}
 
void ArbolAVL::mostrarPostorden() const
{
    string salida;
    postorden(raiz, salida);
    cout << (salida.empty() ? "Sin pacientes" : salida) << endl;
}
 
void ArbolAVL::mostrarFactoresBalance() const
{
    string salida;
    factores(raiz, salida);
    if (salida.empty()) cout << "Sin pacientes" << endl;
    else cout << salida;
}
 

