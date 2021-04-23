#include <mysql.h>
#include <iostream>
#include<string.h>
#include<string>
#include "conexion.h"
using namespace std;
class empleados : empresa {
	// constructor
public:
	empleados() {
	}
	empleados(string p, string n, string a, string dire, string tel, string d, string g, string fn, string fil, string fi) empresa(p, n, a, dire, tel, d, g, fn, fil, fi) {
	}

	// METODOS
	//set (modificar)
	void setnombre(string n) { nombre = n; }
	void setapellido(string a) { apellido = a; }
	void setdireccion(string dire) { direccion = dire; }
	void settelefono(string tel) { telefono = tel; }
	void setdpi(string d) { dpi = d; }
	void setgenero(string g) { genero = g; }
	void setfecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	void setfecha_inicio_labores(string fil) { fecha_inicio_labores = fil; }
	void setpuesto(string p) { puesto = p;}
	void setfecha_ingreso(string fi) { fecha_ingreso = fi; }
	//get (mostrar)
	string getnombre() { return nombre; }
	string getapellido() { return apellido; }
	string getdireccion() { return direccion; }
	string gettelefono() { return telefono; }
	string getdpi() { return dpi; }
	string getfecha_nacimiento() { return fecha_nacimiento; }
	string getfecha_inicio_labores() { return fecha_inicio_labores; }
	string getpuesto() { return puesto; }
	string getfecha_ingreso() { return fecha_ingreso; }
	// metodo
	void crear_empleados() {
		int q_estado;
		conexion cn = conexion();

		cn.abrir_conexion();
		string t = to_string(existencia);
		if (cn.getConectar()) {
			string fecha = "now()";
			string idpuesto;
			string nombre, apellido,  direccion, telefono, dpi, genero, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso;
			cin.ignore();
			cout << "Ingrese nombre:";
			getline(cin, nombre);
			cout << "Ingrese apellido:";
			getline(cin, apellido);
			cout << ("ingrese Id puesto:");
			cin >> idpuesto;
			cin.ignore();
			cout << "Ingrese direccion: ";
			getline(cin, direccion);
			cout << ("Ingrese telefono: ");
			cin >> telefono;
			cout << ("Ingrese DPI: ");
			cin >> dpi;
			cout << ("Ingrese Genero: ");
			cin >> genero;
			cout << ("Ingrese Fecha nacimiento: ");
			cin >> fecha_nacimiento;
			cout << ("Ingrese Fecha inicio labores: ");
			cin >> fecha_inicio_labores;
			cout << ("Ingrese Fecha ingreso: ");
			cin >> fecha_ingreso;
			string insertar = "insert into productos(nombre, apellido, idpuesto, direccion, telefono, dpi, genero, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso ) values('" + nombre + "'," + apellido + ",'" + idproducto + "'," + direccion + "," + telefono + "," + dpi + "," + genero +  "," + fecha_nacimiento + "," + fecha_inicio_labores + "," + fecha_ingreso ")";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer_empleados() {
		int q_estado;
		conexion cn = conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------------- Datos de Productos --------------------------------" << endl;
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "ID |" << "Nombre |" << "Apellido |" << "ID puesto |" << "Direccion |" << "Telefono |" << "DPI | " << "Genero    | " << "Fecha Nacimiento    |" << "Fecha Inicio Labores   |" << "Fecha Ingreso   |" << endl;
				cout << ("----------------------------------------------------------------------------------------------------------------");
				cout << ("\n");
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |" << fila[1] << "     |" << fila[2] << "   |" << fila[3] << "        |" << fila[4] << "        |" << fila[5] << "       |" << fila[7] <<" |" << fila[8] << " |" <<fila[9]<<" | " <<fila[10]<<" | " <<fila[11]<<" | " <<fila[12]<<"     |" endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificar_empleados() {
		int q_estado;
		conexion cn = conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idpuesto;
			string nombre, apellido, direccion, telefono, dpi, genero, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del empleado que desea modificar: ";
			cin >> idempleados;
			string consulta = "select * from productos where idempleados=" + idempleados + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Idempleados: " << fila[0] << endl;
					cout << ("Nombre: ") << fila[1] << endl;
					cout << ("Apellido: ") << fila[2] << endl;
					cout << ("ID puesto : ") << fila[3] << endl;
					cout << ("Direccion: ") << fila[4] << endl;
					cout << ("Telefono: ") << fila[5] << endl;
					cout << ("DPI: ") << fila[6] << endl;
					cout << ("Genero: ") << fila[7] << endl;
					cout << ("Fecha Nacimiento: ") << fila[8] << endl;
					cout << ("Fecha Inicio Labores: ") << fila[9] << endl;
					cout << ("Fecha Ingreso: ") << fila[10] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "Ingrese el id del registro que desea modificar";
						cin >> idempleados;
						cout << "Ingrese el nuevo nombre ";
						cin >> nombre;
						cout << "Ingrese el nuevo apellido ";
						cin >> apellido;
						cout << "Ingrese el nuevo id de puesto";
						cin >> idpuesto;
						cout << "Ingrese la nueva direccion";
						cin >> direccion;
						cout << "Ingrese la nueva telefono";
						cin >> telefono;
						cout << "Ingrese el nuevo DPI";
						cin >> dpi;
						cout << "Ingrese el nuevo genero";
						cin >> genero;
						cout << "Ingrese el nuevo Fecha nacimiento";
						cin >> fecha_nacimiento;
						cout << "Ingrese el nuevo Fecha inicio labores";
						cin >> fecha_inicio_labores;
						cout << "Ingrese el nuevo Fecha Ingreso";
						cin >> fecha_ingreso;
						string modificar = "update productos set nombre = '" + nombre + "',apellido = '" + apellido + "',Id puesto = '" + idpuesto + "',Direccion = '" + direccion+ "',Telefono = '" + telefono + "',Dpi = '" + dpi + "', genero = '" + genero + "', fecha nacimiento = '" + fecha_nacimiento + "', fecha inicio labores = '" + fecha_inicio_labores + "', fecha ingreso = '" + fecha_ingreso + "',  where idpuesto =" + idempleados + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}
			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}
	void eliminar_empleados() {
		int q_estado;
		conexion cn = conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idempleados;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea eliminar\n";
			cin >> idempleados;
			string eliminar = "delete from Productos where idempleados = (" + idempleados + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};