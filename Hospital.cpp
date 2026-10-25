#include "Hospital.h"
#include "Utilidades.h"
#include <iostream>
using namespace std;

Hospital::Hospital() {
    const string servicios[cantidadServicios] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    for (int i = 0; i < cantidadServicios; i++) {
        nombres[i] = servicios[i];
        arboles[i] = new ArbolAVL();
    }
}

Hospital::~Hospital() {
    for (int i = 0; i < cantidadServicios; i++) {
        delete arboles[i];
        arboles[i] = nullptr;
    }
}

int Hospital::indiceServicio(const string& nombre) const {
    for (int i = 0; i < cantidadServicios; i++) {
        if (nombres[i] == nombre) return i;
    }
    return -1;
}

bool Hospital::existeId(const string& id) const {
    for (int i = 0; i < cantidadServicios; i++) {
        if (arboles[i]->buscar(id)) return true;
    }
    return false;
}

bool Hospital::insertarPaciente(const Paciente& paciente, const string& servicio) {
    int indice = indiceServicio(servicio);
    if (indice < 0) return false;
    if (existeId(paciente.getId())) return false;

    Paciente copia = paciente;
    copia.setServicio(servicio);
    return arboles[indice]->insertar(copia);
}

void Hospital::verDepartamentos() {
    cout << "=== ESTADO DE LOS DEPARTAMENTOS ===" << endl;
    for (int i = 0; i < cantidadServicios; i++) {
        cout << nombres[i] << endl;
        if (arboles[i]->estaVacio())
        {
            cout << "  Sin pacientes" << endl;
        }else {
            cout << "  Pacientes: ";
            arboles[i]->mostrarInorden();
        }
    }

    while (true) {
        cout << "\nConsultar un departamento en detalle:" << endl;
        for (int i = 0; i < cantidadServicios; i++) {
            cout << "  " << (i + 1) << ". " << nombres[i] << endl;
        }
        cout << "  9. Volver" << endl;

        int opcion;
        if (!leerEntero("Seleccionar opcion: ", opcion)) return;
        if (opcion == 9) return;
        if (opcion < 1 || opcion > cantidadServicios) {
            cout << "Opcion invalida." << endl;
            continue;
        }
        consultarDepartamento(opcion - 1);
    }
}

void Hospital::consultarDepartamento(int indice) {
    ArbolAVL* arbol = arboles[indice];

    while (true) {
        cout << "\n=== " << nombres[indice] << " (AVL) ===" << endl;
        cout << "1. Recorrido inorden" << endl;
        cout << "2. Recorrido preorden" << endl;
        cout << "3. Recorrido postorden" << endl;
        cout << "4. Altura del arbol" << endl;
        cout << "5. Factor de balance de cada nodo" << endl;
        cout << "6. Eliminar paciente por ID" << endl;
        cout << "7. Volver" << endl;

        int opcion;
        if (!leerEntero("Seleccionar opcion: ", opcion)) return;

        switch (opcion) {
            case 1:
                cout << "Inorden: ";
                arbol->mostrarInorden();
                break;
            case 2:
                cout << "Preorden: ";
                arbol->mostrarPreorden();
                break;
            case 3:
                cout << "Postorden: ";
                arbol->mostrarPostorden();
                break;
            case 4:
                cout << "Altura del arbol: " << arbol->altura()
                     << " (pacientes: " << arbol->tamano() << ")" << endl;
                break;
            case 5:
                cout << "Factores de balance (altura izquierda - altura derecha):" << endl;
                arbol->mostrarFactoresBalance();
                break;
            case 6:
            {
                string id;
                if (!leerLinea("ID del paciente a eliminar: ", id)) return;
                if (arbol->eliminar(id))
                    cout << "Paciente " << id << " eliminado de " << nombres[indice] << "." << endl;
                else
                    cout << "No existe un paciente con ID " << id << " en este departamento." << endl;
                break;
            }
            case 7:
                return;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }
}

void Hospital::buscarPaciente(const string& clave) const
{
    cout << "Buscando en AVL..." << endl;

    for (int i = 0; i < cantidadServicios; i++) {
        string ruta;
        const Paciente* p = arboles[i]->buscarPorId(clave, ruta);
        if (p != nullptr) {
            cout << "Paciente encontrado:" << endl;
            p->mostrarFicha();
            cout << "Ruta de busqueda:" << endl;
            cout << ruta << endl;
            return;
        }
    }

    for (int i = 0; i < cantidadServicios; i++) {
        const Paciente* p = arboles[i]->buscarPorNombre(clave);
        if (p != nullptr) {
            cout << "Paciente encontrado:" << endl;
            p->mostrarFicha();
            return;
        }
    }

    cout << "No se encontro ningun paciente con ID o nombre \"" << clave << "\"." << endl;
}

