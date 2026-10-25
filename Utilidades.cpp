#include "Utilidades.h"
#include <iostream>
using namespace std;

string recortar(const string& texto) {
    size_t inicio = texto.find_first_not_of(" \t\r\n");
    if (inicio == string::npos) return "";
    size_t fin = texto.find_last_not_of(" \t\r\n");
    return texto.substr(inicio, fin - inicio + 1);
}

string minusculas(string texto) {
    for (char& c : texto) {
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }
    return texto;
}

bool esEnteroValido(const string& texto) {
    if (texto.empty() || texto.size() > 9) return false;
    for (char c : texto) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

bool esDecimalValido(const string& texto) {
    if (texto.empty() || texto.size() > 10) return false;
    int separadores = 0;
    int digitos = 0;
    for (char c : texto) {
        if (c >= '0' && c <= '9') digitos++;
        else if ((c == '.' || c == ',') && separadores == 0) separadores++;
        else return false;
    }
    return digitos > 0;
}

double aDecimal(string texto) {
    for (char& c : texto) {
        if (c == ',') c = '.';
    }
    return stod(texto);
}

bool leerLinea(const string& mensaje, string& salida) {
    cout << mensaje;
    if (!getline(cin, salida)) return false;
    salida = recortar(salida);
    return true;
}

bool leerEntero(const string& mensaje, int& salida) {
    string texto;
    while (true) {
        if (!leerLinea(mensaje, texto)) return false;
        if (esEnteroValido(texto)) {
            salida = stoi(texto);
            return true;
        }
        cout << "Entrada invalida... ingrese un numero entero." << endl;
    }
}
