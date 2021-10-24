
#ifndef FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
} sFecha;


sFecha fecha_pedir (char* mensaje);

#endif /* FECHA_H_ */
