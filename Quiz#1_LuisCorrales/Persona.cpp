#include "Persona.h"

Persona::Persona(void) {

}

Persona::Persona(string perCedula, string perNombre, string perApellido) {
	Cedula = perCedula;
	Nombre = perNombre;
	Apellido = perApellido;
}

// Getters and Setters
string Persona::getCedula() { 
	return Cedula; 
}

void Persona::setCedula(string perCedula) { 
	Cedula = perCedula; 
}

string Persona::getNombre() { 
	return Nombre; 
}

void Persona::setNombre(string perNombre) { 
	Nombre = perNombre; 
}

string Persona::getApellido() { 
	return Apellido; 
}

void Persona::setApellido(string perApellido) { 
	Apellido = perApellido; 
}

// Serialization and Deserialization
Persona::Persona(ifstream& entrada) {
	deserialize(entrada, this);
}

bool Persona::guardar(ofstream& salida) {
	return serialize(salida, (Persona*)this);
}

void Persona::deserialize(ifstream& entrada, Persona* p) {
	p->Cedula = sstring::deserialize(entrada);
	p->Nombre = sstring::deserialize(entrada);
	p->Apellido = sstring::deserialize(entrada);
	if (!entrada.good())
		throw - 1;
}

bool Persona::serialize(ofstream& salida, Persona* p) {
	sstring::serialize(salida, p->Cedula);
	sstring::serialize(salida, p->Nombre);
	sstring::serialize(salida, p->Apellido);
	return salida.good();
}

string Persona::toString() const
{
	stringstream r;
	r << "----------------------- D A T O S   P E R S O N A  -----------------------" << endl;
	r << "---  Cedula: " << Cedula << endl;
	r << "---  Nombre: " << Nombre << endl;
	r << "---  Apellido: " << Apellido << endl;
	r << "--------------------------------------------------------------------------" << endl;
	return r.str();
}

Persona::~Persona() { }
