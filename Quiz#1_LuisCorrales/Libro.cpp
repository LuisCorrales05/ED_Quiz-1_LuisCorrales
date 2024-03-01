#include "Libro.h"

Libro::Libro(void) {}

Libro::Libro(string libCodigo,string libNombreLibro) {
	Codigo = libCodigo;
	NombreLibro = libNombreLibro;
}

string Libro::getCodigo() { 
	return Codigo; 
}
void Libro::setCodigo(string libCodigo) {
	Codigo = libCodigo; 
}

string Libro::getNombreLibro() { 
	return NombreLibro; 
}
void Libro::setNombreLibro(string libNombreLibro) { 
	NombreLibro = libNombreLibro;
}

// Serialization and Deserialization
Libro::Libro(ifstream& entrada) {
	deserialize(entrada, this);
}

bool Libro::guardar(ofstream& salida) {
	return serialize(salida, (Libro*)this);
}

void Libro::deserialize(ifstream& entrada, Libro* libro) {
	libro->Codigo = sstring::deserialize(entrada);
	libro->NombreLibro = sstring::deserialize(entrada);
	if (!entrada.good())
		throw - 1;
}


bool Libro::serialize(ofstream& salida, Libro* libro) {
	sstring::serialize(salida, libro->Codigo);
	sstring::serialize(salida, libro->NombreLibro);
	return salida.good();
}

string Libro::toString() const
{
	stringstream r;
	r << "-------------------------  D A T O S   L I B R O  -------------------------" << endl;
	r << "---  Codigo: " << Codigo << endl;
	r << "---  Nombre de Libro: " << NombreLibro << endl;
	r << "---------------------------------------------------------------------------" << endl;
	return r.str();
}

Libro::~Libro() {}
