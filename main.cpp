#include "main.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "ColaPacientes.h"
#include "Hospital.h"
using namespace std;

namespace {

    bool esServicioValido(const string& servicio) {
        const string valido[8] = {
            "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
            "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
        };
        for (int i = 0; i < 8; i++) {
            if (valido[i] == servicio) return true;
        }
        return false;
    }

    bool esNumero(const string& texto) {
        if (texto.empty()) return false;
        for (char c : texto) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    }
}

void cargarPacientes(const string& nombreArchivo, ColaPacientes& cola) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    int numeroLinea = 0;
    int cargados = 0;

    while (getline(archivo, linea)) {
        numeroLinea++;
        if (linea.empty()) continue;

        char buffer[512];
        strncpy(buffer, linea.c_str(), sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';

        char* campos[4] = { nullptr, nullptr, nullptr, nullptr };
        int indice = 0;
        char* cursor = buffer;
        campos[indice] = cursor;
        indice++;

        while (*cursor != '\0' && indice < 4) {
            if (*cursor == ';') {
                *cursor = '\0';
                campos[indice] = cursor + 1;
                indice++;
            }
            cursor++;
        }

        if (indice != 4) {
            cout << "Linea " << numeroLinea << " invalida (formato incorrecto), se omite." << endl;
            continue;
        }

        string id(campos[0]);
        string nombre(campos[1]);
        string edadTexto(campos[2]);
        string servicio(campos[3]);

        if (id.empty() || nombre.empty() || edadTexto.empty() || servicio.empty()) {
            cout << "Linea " << numeroLinea << " invalida (campos vacios), se omite." << endl;
            continue;
        }

        if (!esNumero(edadTexto)) {
            cout << "Linea " << numeroLinea << " invalida (edad no numerica), se omite." << endl;
            continue;
        }

        if (!esServicioValido(servicio)) {
            cout << "Linea " << numeroLinea << " invalida (servicio '" << servicio << "' no reconocido), se omite." << endl;
            continue;
        }

        if (cola.contieneId(id)) {
            cout << "Paciente con ID " << id << " duplicado, se omite." << endl;
            continue;
        }

        int edad = stoi(edadTexto);
        Paciente* nuevo = new Paciente(id, nombre, edad, servicio);
        cola.enqueue(nuevo);
        cargados++;
    }

    archivo.close();
    cout << cargados << " pacientes cargados correctamente." << endl;
}


void atenderPacientes(ColaPacientes& cola, Hospital& hospital, PilaHistorial& historial)
{
    if (cola.estaVacia()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }

    cout << "=== PACIENTES EN ESPERA ===" << endl;
    cola.mostrar();

    cout << "Indique la cantidad de pacientes a atender: ";
    int cantidad;
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Cantidad invalida." << endl;
        return;
    }

    cout << "=== ATENDIENDO PACIENTES ===" << endl;
    int atendidos = 0;
    while (atendidos < cantidad && !cola.estaVacia()) {
        Paciente* p = cola.dequeue();
        p->mostrarInfo();

        if (hospital.agregarPacienteAServicio(p)) {
            p->setAtendido(true);
            cout << "Paciente enviado a " << p->getServicio() << "." << endl;
            historial.push(p);
        } else {
            cout << "Servicio invalido para el paciente, se descarta." << endl;
            delete p;
        }
        cout << endl;
        atendidos++;
    }

    if (atendidos < cantidad) {
        cout << "Se atendieron " << atendidos << " pacientes (no habia mas en espera)." << endl;
    }
}

int main()
{
    Hospital h;
    ColaPacientes cola;
    PilaHistorial historial;

    cargarPacientes("pacientes.txt",cola);

    int opcion;
    do
    {
        cout << "=== HOSPITAL MARMAJA ===\n";
        cout << "1. Atender pacientes\n ";
        cout << "2. Ver departamento\n";
        cout << "3. Revisar historial\n";
        cout << "4. Salir\n";
        cin >> opcion;

        switch (opcion)
        {
            case 1: atenderPacientes(cola, h, historial);
                 break;
            case 2: h.mostrarServicios();
                 break;
            case 3: historial.mostrar();
                break;
            case 4: cout <<"Saliendo..."<<endl;
            break;
            default: cout <<"Opcion no valida"<<endl;
            break;
        }
    }while(opcion != 4);
    return 0;
}
