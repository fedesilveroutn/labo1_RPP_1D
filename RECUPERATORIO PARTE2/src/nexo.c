
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

/**
 * @fn int nexo_contarAlanConEstadias(sDuenio, int, sEstadia, int)
 * @brief recorre el array sDuenio y si el campo nombre es == "Alan" entonces se fija si tiene por lo menos una estadia,
 * 		  si es que sí, aumenta el contador y luego lo retorna.
 * @param listaDuenios
 * @param tamDuenios
 * @param listaEstadias
 * @param tamEstadias
 * @return Retorna el contador con la cantidad de estadias que tienen los duenios Alan o -1 si hay error.
 */
int nexo_contarAlanConEstadias (sDuenio listaDuenios[], int tamDuenios, sEstadia listaEstadias[], int tamEstadias )
{
	int i;
	int contador = -1;

	if ( listaDuenios != NULL && listaEstadias != NULL)
	{
		contador = 0;

		for (i = 0; i < tamDuenios; i++)
		{
			if ( strcmp (listaDuenios[i].nombre , "Alan" ) == 0 || strcmp (listaDuenios[i].nombre , "alan" ) == 0)
			{
				if (listaDuenios[i].contadorEstadia > 0 )
				{
					contador++;
				}
			}
		}
	}
	return contador;
}

/**
 * @fn int nexo_listarEstadiasLuciasEnSegundaQuincena(sEstadia[], int, sDuenio[], int, sPerro[], int, int)
 * @brief muestra aquellas estadías que cumplan con el requisito que el nombre sea == "Lucia/lucia" y que esten reservadas del 16-30 de noviembre
 *
 * @param listaEstadias
 * @param tamEstadias
 * @param listaDuenios
 * @param tamDuenios
 * @param listaPerros
 * @param tamPerros
 * @param tamAux
 * @return retorna 0 si funciono o -1 si hubo error
 */
int nexo_listarEstadiasLuciasEnSegundaQuincena (sEstadia listaEstadias[], int tamEstadias, sDuenio listaDuenios[], int tamDuenios, sPerro listaPerros[], int tamPerros, int tamAux )
{
	int ret = -1;
	int i;
	sEstadia auxEstadiasLucia[tamAux] ;
	int posicionDueniosLucia;
	int contadorEstadiasLucia = 0;

	if (listaEstadias != NULL && listaDuenios != NULL)
	{
		estadia_inicializar(auxEstadiasLucia, 20);

		for ( i = 0; i < tamEstadias; i++ )
		{
			posicionDueniosLucia = duenio_buscarCoincidenciaId(listaDuenios, tamDuenios, listaEstadias[i].idDuenio );
			if (posicionDueniosLucia != -1 )
			{
				if ( strcmp (listaDuenios[posicionDueniosLucia].nombre , "Lucia") == 0 || strcmp (listaDuenios[posicionDueniosLucia].nombre , "lucia") == 0)
				{
					if (listaEstadias[i].fecha.anio == 2021 && listaEstadias[i].fecha.mes == 11 && listaEstadias[i].fecha.dia > 15 )
					{
						auxEstadiasLucia[i] = listaEstadias[i];
						auxEstadiasLucia[i].estado = 1;
						contadorEstadiasLucia++;
					}
				}
			}
		}

		if (contadorEstadiasLucia > 0 )
		{
			nexo_mostrarEstadiasCompletas(auxEstadiasLucia, 20 , listaPerros, tamPerros, listaDuenios, tamDuenios);
			ret = 0;
		}

		else
		{
			printf("\nERROR. No se ha encontrado ninguna estadía reservada por un dueño Lucia");
		}
	}

	return ret;
}












