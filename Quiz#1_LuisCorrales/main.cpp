#include <iostream>
#include "PersonaLibro.h"
#include "lista.h"


using namespace std;

// Ruta de los archivos
const string archivoPersona = "..\\personas.txt";
const string archivoLibro = "..\\libros.txt";
const string archivoPersonaLibro = "..\\personaLibro.txt";

int main() {
    int opcion;
    lista<Persona> listaPersonas;
    lista<Libro> listaLibros;
    lista<PersonaLibro> listaPersonaLibros;

    Persona* instPersona;
    Persona* nuevaPersona;
    Libro* nuevoLibro;
    PersonaLibro* nueva_personaLibro;
    ofstream salida(archivoPersona.c_str());
    ofstream salidaLibro(archivoLibro.c_str());
    ofstream salidaLibroPersona(archivoPersonaLibro.c_str());

    ifstream entrada(archivoPersona.c_str());
    try {
        instPersona = new Persona(entrada);
        listaPersonas.agregarFinal(instPersona);
        if (entrada.good()) {
            cout << "Se cargaron los datos del archivo exitosamente" << endl;
            cin.get();
        }
    }
    catch (...) {
        cout << "Ocurrió un error, no se cargaron los datos del archivo" << endl;
        cin.get();
    }
    entrada.close();


    do {
        system("cls");
        cout << " ________________________________________________________________\n";
        cout << "| ______  Q U I Z  I  E S T R U C T U R A  D E  D A T O S  ______|\n";
        cout << "|________________________________________________________________|\n";
        cout << "| Seleccione una opcion:                                         |\n";
        cout << "| 1. Ingresar Persona a la lista                                 |\n";
        cout << "| 2. Ingresar Libro a la lista                                   |\n";
        cout << "| 3. Mostrar Personas                                            |\n";
        cout << "| 4. Mostrar Libros                                              |\n";
        cout << "| 5. Asociar un Libro a una Persona                              |\n";
        cout << "| 6. Mostrar asociados                                           |\n";
        cout << "| 7. Salir                                                       |\n";
        cout << "|________________________________________________________________|" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            // Agregar Persona
            system("cls");
            cout << "----------------------- D A T O S   P E R S O N A  -----------------------" << endl;
            cout << "Ingrese la cedula de la Persona: ";
            string cedula;
            cin >> cedula;
            cout << "Ingrese el nombre de la persona: " << endl;
            string nombre;
            getline(cin, nombre);
            while (nombre == "")
            {
                cout << "El espacio no puede estar vacio, se debe de escribir el nombre de la persona: " << endl;
                getline(cin, nombre);
            }

            string apellido;
            cout << "Ingrese el apellido de la persona: " << endl;
            getline(cin, apellido);
            while (apellido == "")
            {
                cout << "El espacio no puede estar vacio, se debe de escribir el apellido de la persona: " << endl;
                getline(cin, apellido);
            }
            nuevaPersona = new Persona(cedula, nombre, apellido);
            listaPersonas.agregarFinal(nuevaPersona);
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "¡La Persona fue registrado con exito!" << endl;
            system("pause");
            system("cls");

        }
        break;

        case 2:
        {
            // Agregar Libros
            system("cls");
            cout << "------------------------  I N G R E S A R  L I B R O S ------------------------" << endl;
            cout << "Ingrese el codigo del libro" << endl;
            string codigo;
            cin >> codigo;

            cout << "Ingrese el nombre del libro" << endl;
            string nombre;
            getline(cin, nombre);
            while (nombre == "")
            {
                cout << "¡Por favor, ingresar un nombre para el libro!." << endl;
                getline(cin, nombre);
            }

            nuevoLibro = new Libro(codigo, nombre);
            cout << "-------------------------------------------------------------------------------" << endl;
            listaLibros.agregarFinal(nuevoLibro);
            cout << "¡El libro fue registrado con exito!" << endl;
            system("pause");
            system("cls");
        }
        break;

        case 3:
        {
            //Mostrar Personas
            system("cls");
            cout << listaPersonas.toString();
            system("pause");
            system("cls");

        }
        break;

        case 4:
        {
            // Mostrar Libros
            system("cls");
            cout << listaLibros.toString();
            system("pause");
            system("cls");
        }
        break;

        case 5:
        {
            // Asociar libro y Persona
            cout << listaPersonas.toString() << endl;
            cout << listaLibros.toString() << endl;
            cout << "Ingrese la cedula de la Persona: ";
            string cedulaP;
            cin >> cedulaP;
            cout << "Ingresa el codigo del libro: ";
            string codigoLib;
            cin >> codigoLib;
            nueva_personaLibro = new PersonaLibro(cedulaP, codigoLib);
            listaPersonaLibros.agregarFinal(nueva_personaLibro);

        }
        break;

        case 6:
        {
            // Mostrar Asociados
            system("cls");
           cout << listaPersonaLibros.toString();
           system("pause");
           system("cls");

        }
        break;

        case 7: {
            
            cout << "Saliendo del programa." << endl;
            //Persona
            iteradorLista<Persona>* iteradorPersonas = listaPersonas.obtenerIterador();
            while (iteradorPersonas->masElementos()) {
                Persona* personaActual = iteradorPersonas->proximoElemento();
                personaActual->guardar(salida);
            }
            salida.close();
            
            // Libro
            iteradorLista<Libro>* iteradorLibro = listaLibros.obtenerIterador();
            while (iteradorLibro->masElementos()) {
                Libro* libroActual = iteradorLibro->proximoElemento();
                libroActual->guardar(salidaLibro);
            }
            salidaLibro.close();
            
            //PersonaLibro
            iteradorLista<PersonaLibro>* iteradorPLibro = listaPersonaLibros.obtenerIterador();
            while (iteradorPLibro->masElementos()) {
                PersonaLibro* personaLibroActual = iteradorPLibro->proximoElemento();
                personaLibroActual->guardar(salidaLibroPersona);
            }
            salidaLibroPersona.close();
        }
        break;

        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }

    } while (opcion != 7);
	return 0;
};