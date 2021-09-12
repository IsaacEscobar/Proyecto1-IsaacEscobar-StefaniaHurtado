#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>


//librerias que incluimos 
using std::cout;
using std::cin;
using std::cout;
using std::string;


class Persona
{

protected:
	string nombre;
	int documento;

public:
    Persona();
    Persona(string nombre);
    Persona(int documento);
    void mostrarInformacion(string nombre, int documento);

    // Gets and sets

	string getNombre();
	void setNombre(string nombre);
	int getDocumento();
	void setDocumento(int documento);
};

#endif // PERSONA_H
