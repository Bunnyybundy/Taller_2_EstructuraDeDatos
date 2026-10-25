#include "main.h"
#include <iostream>
#include <fstream>
#include "Utilidades.h"
using namespace std;

namespace {

    int separar(const string& linea, char separador, string campos[], int maximo) {
        int cantidad = 0;
        string actual = "";
        for (size_t i = 0; i < linea.size(); i++) {
            if (linea[i] == separador) {
                if (cantidad < maximo) {
                    campos[cantidad] = recortar(actual);
                }
                cantidad++;
                actual = "";
            }else {
                actual += linea[i];
            }
        }
        if (cantidad < maximo) {
            campos[cantidad] = recortar(actual);
        }
        cantidad++;
        return cantidad;
    }

    bool esBandera(const string& texto) {
        return texto == "0" || texto == "1";
    }

    bool parsearPaciente(const string& linea, Paciente& paciente, string& error) {
        string c[11];
        int cantidad = separar(linea, ';', c, 11);

        if (cantidad != 11) {
            error = "formato incorrecto (se esperan 11 campos)";
            return false;
        }

        for (const string& campo : c) {
            if (campo.empty()) {
                error = "hay campos vacios";
                return false;
            }
        }

        if (!esEnteroValido(c[2])) { error = "edad no numerica"; return false; }
        if (!esDecimalValido(c[3])) { error = "temperatura no numerica"; return false; }
        if (!esEnteroValido(c[4])) { error = "presion arterial no numerica"; return false; }
        if (!esEnteroValido(c[5])) { error = "dolor no numerico"; return false; }
        if (!esBandera(c[7])) { error = "Trauma debe ser 0 o 1"; return false; }
        if (!esBandera(c[8])) { error = "SintomasNeurologicos debe ser 0 o 1"; return false; }
        if (!esBandera(c[9])) { error = "RequiereCirugia debe ser 0 o 1"; return false; }
        if (!esEnteroValido(c[10])) { error = "dias de hospitalizacion no numericos"; return false; }

        paciente = Paciente(c[0], c[1], stoi(c[2]), "");
        paciente.setTemperatura(aDecimal(c[3]));
        paciente.setPresionArterial(stoi(c[4]));
        paciente.setDolor(stoi(c[5]));
        paciente.setTipoDolor(minusculas(c[6]));
        paciente.setTrauma(c[7] == "1");
        paciente.setSintomasNeurologicos(c[8] == "1");
        paciente.setRequiereCirugia(c[9] == "1");
        paciente.setDiasHospitalizacion(stoi(c[10]));

        return ArbolDecision::datosValidos(paciente, error);
    }
}

bool cargarPacientes(const string& nombreArchivo, ColaPacientes& cola) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo \"" << nombreArchivo << "\"." << endl;
        return false;
    }

    string linea;
    int numeroLinea = 0;
    int cargados = 0;
    int omitidos = 0;

    while (getline(archivo, linea)) {
        numeroLinea++;
        linea = recortar(linea);
        if (linea.empty()) continue;

        Paciente temporal;
        string error;
        if (!parsearPaciente(linea, temporal, error)) {
            cout << "Linea " << numeroLinea << " invalida (" << error << "), se omite." << endl;
            omitidos++;
            continue;
        }

        if (cola.contieneId(temporal.getId())) {
            cout << "Linea " << numeroLinea << ": paciente con ID " << temporal.getId()
                 << " duplicado, se omite." << endl;
            omitidos++;
            continue;
        }

        cola.enqueue(new Paciente(temporal));
        cargados++;
    }

    archivo.close();
    cout << cargados << " pacientes cargados correctamente";
    if (omitidos > 0) cout << " (" << omitidos << " lineas omitidas)";
    cout << "." << endl;
    return true;
}

void atenderPacientes(ColaPacientes& cola, Hospital& hospital, const ArbolDecision& arbol) {
    if (cola.estaVacia()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }

    cout << "=== PACIENTES EN ESPERA ===" << endl;
    cola.mostrar();

    int cantidad;
    if (!leerEntero("Indique la cantidad de pacientes a atender: ", cantidad)) return;
    if (cantidad <= 0) {
        cout << "Cantidad invalida." << endl;
        return;
    }

    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
    int atendidos = 0;
    while (atendidos < cantidad && !cola.estaVacia()) {
        Paciente* p = cola.dequeue();

        cout << "ID: " << p->getId() << endl;
        cout << "Nombre: " << p->getNombre() << endl;
        cout << "Edad: " << p->getEdad() << endl;
        cout << "Temperatura: " << p->getTemperatura() << endl;
        cout << "Presion arterial: " << p->getPresionArterial() << endl;
        cout << "Dolor: " << p->getDolor() << endl;
        cout << "TipoDolor: " << p->getTipoDolor() << endl;
        cout << "Trauma: " << p->getTrauma() << endl;
        cout << "SintomasNeurologicos: " << p->getSintomasNeurologicos() << endl;
        cout << "RequiereCirugia: " << p->getRequiereCirugia() << endl;
        cout << "DiasHospitalizacion: " << p->getDiasHospitalizacion() << endl;

        string ruta;
        string servicio = arbol.determinarServicio(*p, ruta);
        cout << "Ruta: " << ruta << endl;

        if (servicio == "Datos invalidos") {
            cout << "Paciente descartado: datos invalidos o insuficientes." << endl;
        }else {
            cout << "Servicio asignado: " << servicio << endl;
            if (hospital.insertarPaciente(*p, servicio)) {
                cout << "Paciente insertado en el AVL de " << servicio << "." << endl;
            }else {
                cout << "No se pudo insertar: el ID " << p->getId()
                      << " ya esta registrado en el hospital." << endl;
            }
        }
        cout << endl;

        delete p;
        atendidos++;
    }

    if (atendidos < cantidad) {
        cout << "Se atendieron " << atendidos << " pacientes (no habia mas en espera)." << endl;
    }
}

int main(int argc, char* argv[]) {
    string archivo = (argc > 1) ? argv[1] : "pacientes.txt";

    Hospital hospital;
    ColaPacientes cola;
    ArbolDecision arbol;

    if (!cargarPacientes(archivo, cola)) {
        return 1;
    }

    int opcion = 0;
    do {
        cout << "\n=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamentos" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Ver arbol de decision" << endl;
        cout << "5. Salir" << endl;

        if (!leerEntero("Seleccionar opcion: ", opcion)) break;

        switch (opcion) {
            case 1:
                atenderPacientes(cola, hospital, arbol);
                break;
            case 2:
                hospital.verDepartamentos();
                break;
            case 3:
            {
                cout << "=== BUSCAR PACIENTE ===" << endl;
                string clave;
                if (!leerLinea("Indique el ID o Nombre del paciente: ", clave)) break;
                if (clave.empty()) cout << "Debe ingresar un ID o nombre." << endl;
                else hospital.buscarPaciente(clave);
                break;
            }
            case 4:
                arbol.mostrarPreorden();
                arbol.mostrarInorden();
                arbol.mostrarPostorden();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
