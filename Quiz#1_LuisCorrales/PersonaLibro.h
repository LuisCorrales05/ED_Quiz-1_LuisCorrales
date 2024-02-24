#pragma once
#include "Libro.h"

class PersonaLibro
{
private:
	string CodigoLibro;
	string CedulaPersona;

public:
	PersonaLibro(void);
	PersonaLibro(string plCodigoLibro, string plCedulaPersona);

	string getCodigoLibro();
	void setCodigoLibro(string plCodigoLibro);
	string getCedulaPersona();
	void setCedulaPersona(string plCedulaPersona);

	// Serialization and Deserialization
	PersonaLibro(ifstream&);
	virtual bool guardar(ofstream&);

	void deserialize(ifstream& entrada, PersonaLibro* pl);
	bool serialize(ofstream& salida, PersonaLibro* pl);

	void MostrarPersonaLibro();
	string toString() const;
};
