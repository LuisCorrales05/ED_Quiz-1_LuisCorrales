#pragma once
#include "std.h"

class Persona
{
private:
	string Cedula;
	string Nombre;
	string Apellido;

public:
	Persona(void);
	Persona(string perCedula, string perNombre, string perApellido);

	// Getters
	string getCedula();
	string getNombre();
	string getApellido();

	// Setters
	void setCedula(string perCedula);
	void setNombre(string perNombre);
	void setApellido(string perApellido);

	// Serialization and Deserialization
	Persona(ifstream&);
	virtual bool guardar(ofstream&);

	void deserialize(ifstream& entrada, Persona* p);
	bool serialize(ofstream& salida, Persona* p);

	virtual string toString() const;

	// Destructor
	~Persona();
};

