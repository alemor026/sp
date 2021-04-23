
#include <mysql.h>
#include <iostream>
#include <string>
#include "conexion.h"
using namespace std;
class puesto : empresa {
	// METODOS
	//set (modificar)
	void setpuesto(string p) { puesto= p; }
	//get (mostrar)
	string getpuesto() { return p; }
	// metodo
	void crear_puesto() {
		int q_estado;
		conexion cn = conexion();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string puesto;
			cout << "Ingrese puesto:";
			cin >> puesto;
			string insertar = "insert into puesto(puesto) values('" + puesto + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer_puesto() {
		int q_estado;
		conexion cn = conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "------------ Datos de puestos ------------" << endl;
			string consulta = "select * from puesto";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;
				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar_puesto() {
		int q_estado;
		conexion cn = conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idpuestp puesto;
			char s;
			cout << ("------------------------- Modificar Datos ---------------------------") << endl;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idpuesto;
			string consulta = "select * from puesto where idmarca=" + idpuesto + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "Id puesto: " << fila[0] << endl;
					cout << ("puesto: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\ningrese el nuevo nombre de la puesto: ";
						cin >> puesto;
						string modificar = "update marcas set puesto = '" + puesto + "' where idpuesto =" + idpuesto + "";
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

	void eliminar_puesto() {
		int q_estado;
		conexion cn = conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idpuesto;
			cout << "Ingrese puesto:";
			cin >> idpuesto;
			string eliminar = "delete from marcas where idpuesto=(" + idpuesto + ")";
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