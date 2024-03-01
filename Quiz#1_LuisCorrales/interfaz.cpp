#include "interfaz.h"

// Rutas de los archivos

const string interfaz::archivoPersona = "..\\personas.txt";
const string interfaz::archivoLibro = "..\\libros.txt";
const string interfaz::archivoPersonaLibro = "..\\personaLibro.txt";

// Constructor de la clase interfaz
interfaz::interfaz() : _listaPersonas(new lista<Persona>()), _listaLibros(new lista<Libro>()), _listaPersonaLibros(new lista<PersonaLibro>())
{
    ifstream entrada(archivoPersona.c_str());
    ifstream entradalibro(archivoLibro.c_str());
    ifstream entradaPL(archivoPersonaLibro.c_str());

    try {
        // Entrada de las Personas
        while (entrada.good()) {
            _persona = new Persona(entrada);
            if (!entrada.eof()) {  // Verifica si no se ha alcanzado el final del archivo
                _listaPersonas->agregarFinal(_persona);
            }
        }

        cout << "Se cargaron todos los datos de los archivo exitosamente" << endl;
    }
    catch (...) {
        cout << "Ocurrió un error, no se cargaron los datos del archivo" << endl;
        cin.get();
    }
    entrada.close();

    try
    {
        // Entrada de los libros
        while (entradalibro.good()) {
            _libro = new Libro(entradalibro);
            if (!entradalibro.eof()) {
                _listaLibros->agregarFinal(_libro);
            }
        }
    }
    catch (...)
    {
        cout << "Ocurrió un error en libros, no se cargaron los datos del archivo" << endl;
        cin.get();
    }
    entradalibro.close();
    try
    {
        // Entrada de las PersonasLibros
        while (entradaPL.good()) {
            _personaLibro = new PersonaLibro(entradaPL);
            if (!entradaPL.eof()) {
                _listaPersonaLibros->agregarFinal(_personaLibro);
            }
        }
    }
    catch (...)
    {
        cout << "Ocurrió un error en PL, no se cargaron los datos del archivo" << endl;
        cin.get();
    }
    entradaPL.close();
}

interfaz::~interfaz()
{
    delete _persona;
    delete _listaPersonas;
    delete _libro;
    delete _listaLibros;
    delete _personaLibro;
    delete _listaPersonaLibros;
}

int interfaz::seleccionarOpcion() {
    int opcion = 0;
    cout << "Ingrese su opcion: ";
    cin >> opcion;
    return opcion;
}

void interfaz::mostrarOpciones() {
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
}

void interfaz::mostrarMenu() {
    int opcion;

    Persona* nuevaPersona;
    Libro* nuevoLibro;
    PersonaLibro* nueva_personaLibro;
    ofstream salida(archivoPersona.c_str());
    ofstream salidaLibro(archivoLibro.c_str());
    ofstream salidaLibroPersona(archivoPersonaLibro.c_str());

    do
    {
        system("cls");
        mostrarOpciones();
        opcion = seleccionarOpcion();
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
            _listaPersonas->agregarFinal(nuevaPersona);
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
            _listaLibros->agregarFinal(nuevoLibro);
            cout << "¡El libro fue registrado con exito!" << endl;
            system("pause");
            system("cls");
        }
        break;

        case 3:
        {
            //Mostrar Personas
            system("cls");
            cout << _listaPersonas->toString();
            system("pause");
            system("cls");

        }
        break;

        case 4:
        {
            // Mostrar Libros
            system("cls");
            cout << _listaLibros->toString();
            system("pause");
            system("cls");
        }
        break;

        case 5:
        {
            // Asociar libro y Persona
            cout << _listaPersonas->toString() << endl;
            cout << "Ingrese la cedula de la Persona: ";
            string cedulaP;
            cin >> cedulaP;
            system("cls");
            cout << _listaLibros->toString() << endl;
            cout << "Ingresa el codigo del libro: ";
            string codigoLib;
            cin >> codigoLib;

            bool verficador_cedula = false;
            bool verificar_codigo = false;

            iteradorLista<Persona>* iteradorPersonas = _listaPersonas->obtenerIterador();
            while (iteradorPersonas->masElementos()) {
                Persona* personaActual = iteradorPersonas->proximoElemento();
                if (personaActual->getCedula() == cedulaP) {
                    verficador_cedula = true;
                    break;
                }
            }

            iteradorLista<Libro>* iteradorLibro = _listaLibros->obtenerIterador();
            while (iteradorLibro->masElementos()) {
                Libro* libroActual = iteradorLibro->proximoElemento();
                if (libroActual->getCodigo() == codigoLib) {
                    verificar_codigo = true;
                    break;
                }
            }

            if (verficador_cedula && verificar_codigo) {
                nueva_personaLibro = new PersonaLibro(codigoLib, cedulaP);
                _listaPersonaLibros->agregarFinal(nueva_personaLibro);
                cout << "Asociación exitosa." << endl;
            }
            else {
                cout << "Error, la cedula o el codigo no están registrados." << endl;
            }
            system("pause");
        }
        break;

        case 6:
        {
            // Mostrar Asociados
            system("cls");
            cout << _listaPersonaLibros->toString();
            system("pause");
            system("cls");

        }
        break;

        case 7: {

            cout << "Saliendo del programa." << endl;
            //Persona
            iteradorLista<Persona>* iteradorPersonas = _listaPersonas->obtenerIterador();
            while (iteradorPersonas->masElementos()) {
                Persona* personaActual = iteradorPersonas->proximoElemento();
                personaActual->guardar(salida);
            }
            salida.close();

            // Libro
            iteradorLista<Libro>* iteradorLibro = _listaLibros->obtenerIterador();
            while (iteradorLibro->masElementos()) {
                Libro* libroActual = iteradorLibro->proximoElemento();
                libroActual->guardar(salidaLibro);
            }
            salidaLibro.close();

            //PersonaLibro
            iteradorLista<PersonaLibro>* iteradorPLibro = _listaPersonaLibros->obtenerIterador();
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
}