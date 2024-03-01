#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "std.h"
#include "PersonaLibro.h"
#include "lista.h"

class interfaz
{
public:
	interfaz();
	virtual ~interfaz();
	virtual void mostrarOpciones();
	virtual int seleccionarOpcion();
	virtual void mostrarMenu();
private:
	Persona* _persona;
	Libro* _libro;
	PersonaLibro* _personaLibro;
	lista<Persona>* _listaPersonas;
	lista<Libro>* _listaLibros;
	lista<PersonaLibro>* _listaPersonaLibros;
	static const string archivoPersona;
	static const string archivoLibro;
	static const string archivoPersonaLibro;

};

#endif


