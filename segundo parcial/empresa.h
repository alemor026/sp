#include <iostream>
using namespace std;

class empresa {
	// atributos
protected: string nombre, apellido, direccion, telefono, dpi, genero, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso, puesto;
		 int existencia = 0;
		 // costructor
protected:
	empresa() {
	}
	empresa(string p, string n, string a, string dire, string tel, string d, string g, string fn, string fil, string fi) {
		nombre = n;
		apellido = a;
		direccion = dire;
		telefono = tel;
		dpi = d;
		genero = g;
		fecha_nacimiento = fn;
		fecha_inicio_labores = fil;
		puesto = p;
		fecha_ingreso = fi;
	}
};