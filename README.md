
# Taller 2 - Estructura de Datos

## Integrantes
- **Constanza Araya** – **21.609.057-8** – **Bunnyybundy** – **ICCI** – **Paralelo: C1**
- **Kevin Zamora** – **21.578.521-1** – **kivairou** – **ICCI** – **Paralelo: C1**

---

## Descripción

Este taller implementa un sistema de gestión hospitalaria utilizando **estructuras de datos en C++17**.

El programa tiene como objetivo organizar y clasificar pacientes según sus antecedentes, asignándolos al servicio hospitalario correspondiente.

Las principales funcionalidades contempladas son:
- Cargar pacientes desde un archivo de texto.
- Organizar los pacientes en una **cola dinámica**.
- Clasificar pacientes mediante un **árbol binario de decisión**.
- Asignar cada paciente al servicio hospitalario correspondiente.
- Organizar los pacientes de cada servicio mediante **árboles AVL**.
- Buscar pacientes por su identificador.
- Realizar recorridos de árboles.
- Mantener balanceados los árboles AVL mediante rotaciones.

Las estructuras principales del proyecto son:
- **Persona / Paciente**: clases que representan a las personas y almacenan los antecedentes de cada paciente.
- **ColaPacientes**: cola dinámica para administrar a los pacientes pendientes de clasificación.
- **ArbolDecision**: árbol binario que determina el servicio hospitalario de cada paciente.
- **NodoAVL**: nodo que almacena un paciente y mantiene los enlaces a sus hijos y su altura.
- **ArbolAVL**: árbol de búsqueda balanceado para organizar los pacientes por identificador.
- **Hospital**: clase encargada de administrar e integrar los componentes del sistema.

---

## Servicios Hospitalarios

El sistema contempla los siguientes servicios:
- Urgencias.
- Medicina General.
- Cardiología.
- Neurología.
- Traumatología.
- Cirugía.
- Pediatría.
- Hospitalización.

---

## Criterios del Árbol de Decisión

La clasificación de los pacientes considera las siguientes reglas:

1. Si el paciente tiene menos de 14 años, se asigna a **Pediatría**.
2. Si presenta trauma:
   - Si requiere cirugía, se asigna a **Cirugía**.
   - Si no requiere cirugía, se asigna a **Traumatología**.
3. Si no presenta trauma y tiene síntomas neurológicos, se asigna a **Neurología**.
4. Si el tipo de dolor es `pecho`, se asigna a **Cardiología**, siempre que no se haya cumplido una condición anterior.
5. Si la temperatura es igual o superior a 38,5 °C, o el nivel de dolor es igual o superior a 8, se asigna a **Urgencias**.
6. Si tiene dos o más días de hospitalización, se asigna a **Hospitalización**.
7. Si no cumple ninguna de las condiciones anteriores, se asigna a **Medicina General**.

Las condiciones se evalúan en el orden indicado.

---

## Formato del Archivo de Pacientes

Los datos de los pacientes se almacenan en un archivo de texto llamado `pacientes.txt`.

Cada línea representa un paciente y los campos están separados por punto y coma (`;`).

El formato esperado es:

```text
ID;Nombre;Edad;Temperatura;PresionArterial;Dolor;TipoDolor;Trauma;SintomasNeurologicos;RequiereCirugia;DiasHospitalizacion
```

Los registros deben respetar el formato esperado por el programa para poder procesarse correctamente.

---

## Instrucciones de Compilación y Ejecución

> **Nota de desarrollo:** El proyecto se desarrolla en C++17 y utiliza CMake para su configuración en CLion. También debe comprobarse su compilación en GitHub Codespaces.

### 1. Entorno Principal: CLion

#### Compilación:
1. Abrir el proyecto en CLion.
2. Verificar que `CMakeLists.txt` incluya todos los archivos `.cpp` necesarios.
3. Esperar a que CMake configure el proyecto.
4. Seleccionar **Build → Build Project** o presionar `Ctrl+F9`.

#### Ejecución:
1. Verificar que el archivo `pacientes.txt` se encuentre en el directorio de trabajo utilizado por el programa, si la ejecución requiere dicho archivo.
2. Seleccionar la configuración de ejecución del proyecto.
3. Presionar **Run** o `Shift+F10`.

---

### 2. Entorno Alternativo: Terminal Linux o GitHub Codespaces

Para compilar el proyecto mediante CMake:

1. Abrir una terminal en la carpeta raíz del proyecto.
2. Ejecutar los siguientes comandos:

```bash
cmake -S . -B build
cmake --build build
```

3. Ejecutar el programa utilizando el nombre y la ruta del ejecutable generado.

Por ejemplo, si el ejecutable se llama `Taller_2_EstructuraDeDatos`:

```bash
./build/Taller_2_EstructuraDeDatos
```

El nombre del ejecutable puede variar según la configuración de `CMakeLists.txt`.

**Importante:** La compilación debe comprobarse en GitHub Codespaces antes de la entrega.

---


## Observaciones

- Proyecto desarrollado en **C++17**.
- Configuración del proyecto mediante **CMake**.
- Las estructuras de datos requeridas deben implementarse manualmente.
- La cola permite organizar los pacientes pendientes de procesamiento.
- El árbol de decisión determina el servicio hospitalario según los antecedentes del paciente.
- Los árboles AVL permiten organizar y buscar pacientes mediante su identificador.
- Se debe gestionar correctamente la memoria dinámica.
- Se deben contemplar los registros inválidos y los identificadores duplicados.
- La compilación y ejecución deben verificarse en GitHub Codespaces.

---

