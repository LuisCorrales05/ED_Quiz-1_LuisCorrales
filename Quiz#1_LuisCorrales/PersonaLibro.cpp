#include "PersonaLibro.h"

PersonaLibro::PersonaLibro(void) {

}

PersonaLibro::PersonaLibro(string plCodigoLibro,string plCedulaPersona) {
	CodigoLibro = plCodigoLibro;
	CedulaPersona = plCedulaPersona;
}

string PersonaLibro::getCodigoLibro() { 
	return CodigoLibro; 
}
void PersonaLibro::setCodigoLibro(string plCodigoLibro) { 
	CodigoLibro = plCodigoLibro;
}

string PersonaLibro::getCedulaPersona() { 
	return CedulaPersona; 
}
void PersonaLibro::setCedulaPersona(string plCedulaPersona) { 
	CedulaPersona = plCedulaPersona; 
}

// Serialization and Deserialization
PersonaLibro::PersonaLibro(ifstream& entrada) {
	deserialize(entrada, this);
}

bool PersonaLibro::guardar(ofstream& salida) {
	return serialize(salida, this);
}

void PersonaLibro::deserialize(ifstream& entrada, PersonaLibro* pl) {
	pl->CodigoLibro = sstring::deserialize(entrada);
	pl->CedulaPersona = sstring::deserialize(entrada);

	if (!entrada.good())
		throw - 1;
}

bool PersonaLibro::serialize(ofstream& salida, PersonaLibro* pl) {
	sstring::serialize(salida, pl->CodigoLibro);
	sstring::serialize(salida, pl->CedulaPersona);

	return salida.good();
}

void PersonaLibro::MostrarPersonaLibro()
{
	cout << "-----------------  D A T O S   P E R S O N A / L I B R O   ----------------" << endl;
	cout << "---- Cedula Persona: " << CedulaPersona << endl;
	cout << "---- Codigo Libro: " << CodigoLibro << endl;
	cout << "---------------------------------------------------------------------------" << endl;

}

string PersonaLibro::toString() const {
	// Devuelve una representación en cadena de PersonaLibro
	return "Cedula: " + CedulaPersona + ", Codigo del libro: " + CodigoLibro;
}