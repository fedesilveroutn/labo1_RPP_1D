
#include "fecha.h"

/**
 * @fn sFecha fecha_pedir(char*)
 * @brief pide el ingreso de una fecha y carga todos sus campos
 *
 * @param mensaje recibe un mensaje para ser mostrado al usuario antes de solicitar las fechas
 * @return retorna una fecha cargada con valores
 */
sFecha fecha_pedir (char* mensaje)
{
	sFecha fecha;

	printf("%s", mensaje);
	getInt(&fecha.dia , "\nIngrese el día(1-30): ", "\nError. Ingrese día válido (1-30): ", 1 , 30);
	getInt(&fecha.mes , "Ingrese el mes(1-12): ", "\nError. Ingrese mes válido (1-12): ", 1 , 12);
	getInt(&fecha.anio , "Ingrese el año(2021-2030): ", "\nError. Ingrese año válido (2021-2030): ", 2021 , 2030);
	return fecha;
}
