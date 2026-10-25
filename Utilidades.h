#ifndef TALLER_2_ESTRUCTURADEDATOS_UTILIDADES_H
#define TALLER_2_ESTRUCTURADEDATOS_UTILIDADES_H

#include <string>
using namespace std;

string recortar(const string& texto);
string minusculas(string texto);

bool esEnteroValido(const string& texto);
bool esDecimalValido(const string& texto);
double aDecimal(string texto);

bool leerLinea(const string& mensaje, string& salida);
bool leerEntero(const string& mensaje, int& salida);

#endif //TALLER_2_ESTRUCTURADEDATOS_UTILIDADES_H
