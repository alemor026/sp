#pragma once
#include <mysql.h>
#include <iostream>
using namespace  std;
class conexion
{
private:  MYSQL* conectar;
public:
	void abrir_conexion() {

		conectar = mysql_init(0);
		onectar = mysql_real_connect(conectar, "localhost", "segundoparcial", "@Ale0227@Ale1126.0204", "segundo_parcial", 3306, NULL, 0);

	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}

}; 
