/*
 * duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Fede
 */
#include "duenio.h"



int duenio_inicializar (sDuenio lista[], int tam)
{
	int i;
	int ret = -1;
	if (lista != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			lista[i].estado = 0;
		}
		ret = 0;
	}
	return ret;
}



int duenio_hardcodear (sDuenio lista[])
{
	int ret = -1;
	int i;

	if (lista != NULL)
	{
		int ids[5] = {30000 , 30001, 30002 , 30003 , 30004};
		char nombres[5][41] = {"Federico Silvero" , "Constanza Arancio", "Valentin Silvero", "Melissa Brizuela", "JuanPaulo Scallise" }    ;
		int telefono[5] = {1132497707 , 1132924403 , 1122334455 , 1133445566 , 1144556677} ;
		int estados[5] = {1 , 1 , 1 , 1 , 1} ;

		for (i = 0; i < 3; i++)
		{
			lista[i].id = ids[i];
			strcpy (lista[i].nombre , nombres[i]);
			lista[i].telefono = telefono[i];
			lista[i].estado = estados[i];
		}

		ret = 0;
	}
	return ret;
}



int duenio_cargar (sDuenio listaDuenios[], int tamDuenios, int ultimoIdDuenio)
{
		sDuenio aux;
		int ret = -1;
		int confirmacion;
		int index;
		if (listaDuenios != NULL)
		{
			if (duenio_buscarLugar (listaDuenios , tamDuenios) != -1)
			{
				aux = duenio_pedirDatos (aux , ultimoIdDuenio);
				confirmacion = duenio_verificar (aux);

				if(confirmacion == 1)
				{
					index = duenio_buscarLugar (listaDuenios , tamDuenios);
					listaDuenios[index] = aux;
					listaDuenios[index].estado = 1;
					ultimoIdDuenio++;
					ret = ultimoIdDuenio;
					printf("\n***HA CARGADO LOS DATOS DEL DUEÑO EXITOSAMENTE!***");
				}

				else
				{
					printf("\nUsted ha cancelado la carga del DUEÑO.\n");
				}
			}

			else
			{
				printf("\nNo hay lugar disponible para la carga del DUEÑO.\n");
			}
		}
		return ret;
}



int duenio_buscarLugar(sDuenio listaDuenios[], int tamDuenios)
{
	int i;
		int posicion = -1;
		if (listaDuenios != NULL)
		{
			for (i = 0; i < tamDuenios; i++)
			{
				if ( listaDuenios[i].estado == 0)
				{
					posicion = i;
					break;
				}
			}
		}

		return posicion;
}



sDuenio duenio_pedirDatos (sDuenio duenio , int ultimoIdDuenio)
{
	int id;
	char nombre[21];
	int telefono;
	sDuenio aux;

	id = ultimoIdDuenio + 1;
	getString (nombre, "Ingrese el NOMBRE del dueño: ", "Error. Ingrese un nombre válido (hasta 20 caracteres):", 21);
	getInt (&telefono, "Ingrese el TELEFONO del dueño: ", "Error. Ingrese un telefono válida (1-20): ", 1100000000 , 1199999999);

	aux.id = id;
	strcpy (aux.nombre , nombre);
	aux.telefono = telefono;

	return aux;
}



int duenio_verificar (sDuenio duenio)
{
	int respuesta;

	printf("\n----------------------------------------------------------------\n"
		   "\nDatos del dueño A CONFIRMAR: \n"
		   "\n%-10s %-20s %-20s\n", "ID", "NOMBRE DUEÑO", "TELEFONO");

	printf("%-10d %-20s %-20d"
		   "\n----------------------------------------------------------------\n",
		   duenio.id , duenio.nombre , duenio.telefono);

	getInt (&respuesta, "\nDesea CONFIRMAR los DATOS DEL DUEÑO (0 = no / 1 = si)? : ", "ERROR. Elija una opcion válida (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}



void duenio_mostrar (sDuenio duenio)
{
	if (duenio.estado == 1 )
	{
		printf("%-20d %-20s %-20d\n", duenio.id, duenio.nombre, duenio.telefono);
	}
}



int duenio_modificar (sDuenio listaDuenios[] , int tamDuenios , int pos , int id)
{
		sDuenio aux;
		int ret = -1;
		int confirmacion;
		if(listaDuenios != NULL)
		{
			aux = duenio_pedirDatosSinId (aux);
			aux.id = id;

			confirmacion = duenio_verificarSinId (aux);
			if(confirmacion == 1)
			{
				listaDuenios[pos] = aux;
				duenio_mostrar(listaDuenios[pos]);
				ret = 0;
			}

			else
			{
				printf("\nUsted ha cancelado la modificacion del dueño.\n");
			}
		}

		return ret;
}



int duenio_pedirNuevoTelefono ()
{
	int telefono;

	getInt (&telefono, "Ingrese el nuevo TELEFONO: ", "Error. Ingrese un teléfono válido (1100000000-1199999999): ", 1100000000 , 1199999999);

	return telefono;
}



sDuenio duenio_pedirDatosSinId (sDuenio duenio)
{
	char nombre[21];
	int telefono;
	sDuenio aux;

	getString (nombre, "Ingrese el NOMBRE del dueño: ", "Error. Ingrese un nombre válido (hasta 20 caracteres):", 21);
	getInt (&telefono, "Ingrese el TELEFONO del dueño: ", "Error. Ingrese un teléfono válido (1100000000-1199999999): ",1100000000 ,1199999999);

	strcpy (aux.nombre , nombre);
	aux.telefono = telefono;

	return aux;

}



int duenio_verificarSinId (sDuenio duenio)
{
	int respuesta;

	printf("\n----------------------------------------------------------------"
		   "\nDatos del dueño A CONFIRMAR: \n"
		   "\nID DUEÑO: %d\nNOMBRE: %s\nTELEFONO: %d\n"
		   "\n----------------------------------------------------------------\n", duenio.id, duenio.nombre, duenio.telefono);

	getInt (&respuesta, "Desea CONFIRMAR los datos del dueño (0 = no / 1 = si)? : ", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}




int duenio_buscarCoincidenciaId (sDuenio lista[] , int tam, int id)
{
	int posicion = -1;
	int i;
	if (lista != NULL)
	{
		for ( i = 0 ; i < tam ; i++)
		{
			if (lista[i].id == id)
			{
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}


