#pragma once
#include "Persona.h"
#include "std.h"

class Libro
{
private:
	string Codigo;
	string NombreLibro;

public:
	Libro(void);
	Libro(string libCodigo, string libNombreLibro);

	// Getters and Setters
	string getCodigo();
	void setCodigo(string libCodigo);

	string getNombreLibro();
	void setNombreLibro(string libNombreLibro);

	// Serialization and Deserialization
	Libro(ifstream&);
	virtual bool guardar(ofstream&);

	void deserialize(ifstream& entrada, Libro* libro);
	bool serialize(ofstream& salida, Libro* libro);

	virtual string toString() const;

	// Destructor
	~Libro();
};

