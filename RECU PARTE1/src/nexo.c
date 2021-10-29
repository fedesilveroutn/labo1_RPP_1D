
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"


/**
 * @fn void nexo_mostrarEstadiasCompletas(sEstadia[], int, sPerro[], int, sDuenio[], int)
 * @brief muestra ID_ESTADIA-NOMBRE_PERRO-RAZA-EDAD-NOMBRE_DUEÑO-TELEFONO-FECHA
 *
 * @param reservas recibe un array sEstadia
 * @param tamEstadias recibe el tamanio de ese array sEstadia
 * @param listaPerros recibe un array sPerro
 * @param tamPerros recibe el tamanio de ese array sPerro
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array sDuenio
 */
void nexo_mostrarEstadiasCompletas (sEstadia reservas[], int tamEstadias, sPerro listaPerros[], int tamPerros, sDuenio listaDuenios[], int tamDuenios)
{
	int i;
	int posicionPerro;
	int posicionDuenio;

	if (reservas != NULL && listaPerros != NULL && listaDuenios != NULL)
	{
		printf( "\n------------------------------------------------------------------------------------------------------------------------------\n"
				"\n%-15s %-15s %-15s %-15s %-20s %-20s %-20s\n\n",
				"ID ESTADIA", "NOMBRE PERRO", "RAZA", "EDAD", "NOMBRE DUEÑO", "TELEFONO", "FECHA");
		for (i = 0; i < tamEstadias; i++)
		{
			if(reservas[i].estado == 1 )
			{
				posicionPerro = perro_buscarCoincidenciaId(listaPerros, tamPerros, reservas[i].idPerro);
				posicionDuenio = duenio_buscarCoincidenciaId(listaDuenios, tamDuenios, reservas[i].idDuenio);
				printf( "%-15d %-15s %-15s %-15d %-20s %-20d %-2d/%-2d/%-2d\n" ,
						reservas[i].id, listaPerros[posicionPerro].nombre, listaPerros[posicionPerro].raza, listaPerros[posicionPerro].edad,
						listaDuenios[posicionDuenio].nombre, listaDuenios[posicionDuenio].telefono,
						reservas[i].fecha.dia, reservas[i].fecha.mes, reservas[i].fecha.anio);
			}
		}
		printf( "------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

/**
 * @fn void nexo_mostrarPerrosConDuenios(sPerro[], int, sDuenio[], int)
 * @brief muestra NOMBRE_PERRO-RAZA-ID_PERRO-NOMBRE_DUEÑO-TELEFONO-ID_DUENIO
 *
 * @param listaPerros recibe un array sPerro
 * @param tamPerros recibe el tamanio de ese array sPerro
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array sDuenio
 */
void nexo_mostrarPerrosConDuenios (sPerro listaPerros[] , int tamPerros, sDuenio listaDuenios[], int tamDuenios)
{
	int i;

	if (listaPerros != NULL && listaDuenios != NULL)
	{
		printf("\n----------------------------------------------------------------\nPERROS Y DUEÑOS CARGADOS EN EL SISTEMA:\n");
		printf("\n%-20s %-20s %-20s %-20s %-20s %-20s \n",
			   "NOMBRE PERRO", "RAZA", "ID PERRO", "NOMBRE DUEÑO", "TELEFONO", "ID DUENIO" );
		for (i = 0; i < tamPerros; i++)
		{
			if (listaPerros[i].estado != 0 && listaDuenios[i].estado != 0)
			{
				printf("\n%-20s %-20s %-20d %-20s %-20d %-20d", listaPerros[i].nombre, listaPerros[i].raza, listaPerros[i].id, listaDuenios[i].nombre, listaDuenios[i].telefono,  listaDuenios[i].id);
			}
		}

	}
}

/**
 * @fn void nexo_mostrarPerrosConEstadias(sPerro[], int, sEstadia[], int)
 * @brief muestra todas las estadias que tiene cada perro
 *
 * @param listaPerros recibe un array sPerro
 * @param tamPerros recibe el tamanio de ese array sPerro
 * @param listaEstadias recibe un array sEstadia
 * @param tamEstadias recibe el tamanio de ese array sEstadia
 */
void nexo_mostrarPerrosConEstadias (sPerro listaPerros[], int tamPerros, sEstadia listaEstadias[], int tamEstadias)
{
	int i;
	int j;

	if (listaPerros != NULL && listaEstadias != NULL)
	{
		for (i = 0; i < tamPerros; i++)
		{
			if (listaPerros[i].estado == 1 && listaPerros[i].contadorEstadia > 0 )
			{
				printf( "\n***************************************\n"
						"%s cuenta con las siguientes reservas:\n", listaPerros[i].nombre);
				for (j = 0; j < tamEstadias; j++)
				{
					if (listaEstadias[j].idPerro == listaPerros[i].id)
					{
						printf("\n%d/%d/%d", listaEstadias[j].fecha.dia, listaEstadias[j].fecha.mes, listaEstadias[j].fecha.anio );
					}
				}

			}
		}
	}
}

/**
 * @fn int nexo_existenciaEstadia(sPerro[], int)
 * @brief busca si existe por lo menos una estadia cargada
 *
 * @param listaPerros recibe un array sPerro
 * @param tam recibe el tamanio de ese array sPerro
 * @return retorna 0 si el campo contadorEstadia es mayor a 0 y por lo tanto en todo el array sPerro hay por lo menos una estadia reservada o -1 si no
 */
int nexo_existenciaEstadia ( sPerro listaPerros[] , int tam   )
{
	int ret = -1;
	int i;

	for (i = 0; i < tam; i++)
	{
		if (listaPerros[i].contadorEstadia > 0 )
		{
			ret = 0;
			break;
		}
	}
	return ret;
}





