#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"



void nexo_mostrarPerrosConEstadias (sPerro listaPerros[] , int tamPerros, sEstadia reservas[] ,  int tamReservas)
{
	int i;

	if (listaPerros != NULL && reservas != NULL)
	{
		perro_ordenarPorId (listaPerros , tamPerros);

		printf("\n----------------------------------------------------------------------------------------");
		printf("\n%-20s %-20s %-20s %-20s %-20s %-20s\n", "ID PERRO", "NOMBRE", "RAZA", "EDAD", "ID ESTADIA", "FECHA");
		for (i = 0; i < tamPerros; i++)
		{
			if (listaPerros[i].estado == 1 && reservas[i].estado == 1)
			{
				perro_mostrar(listaPerros[i]);
				printf(" %-15d %-2d/%-2d/%-2d\n",
												reservas[i].id,
												reservas[i].fecha.dia,
												reservas[i].fecha.mes,
												reservas[i].fecha.anio);
			}
		}
	}
}





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




void nexo_mostrarEstadiasCompletas (sEstadia reservas[], int tamEstadias, sPerro listaPerros[], int tamPerros, sDuenio listaDuenios[], int tamDuenios)
{
	int i;
	int posicionPerro;
	int posicionDuenio;

	if (reservas != NULL && listaPerros != NULL && listaDuenios != NULL)
	{
		printf( "\n%-15s %-15s %-15s %-15s %-15s %-20s %-20s %-20s %-20s\n",
				"ID PERRO", "NOMBRE PERRO", "RAZA", "EDAD", "ID DUEÑO", "NOMBRE DUEÑO", "TELEFONO", "ID ESTADIA", "FECHA");


		for (i = 0; i < tamEstadias; i++)
		{
			if(reservas[i].estado == 1 )
			{
				posicionPerro = perro_buscarCoincidenciaId(listaPerros, tamPerros, reservas[i].idPerro);
				posicionDuenio = duenio_buscarCoincidenciaId(listaDuenios, tamDuenios, reservas[i].idDuenio);

				printf( "%-15d %-15s %-15s %-15d %-15d %-20s %-20d %-20d %-2d/%-2d/%-2d" ,
						listaPerros[posicionPerro].id, listaPerros[posicionPerro].nombre, listaPerros[posicionPerro].raza, listaPerros[posicionPerro].edad,
						listaDuenios[posicionDuenio].id, listaDuenios[posicionDuenio].nombre, listaDuenios[posicionDuenio].telefono,
						reservas[i].id, reservas[i].fecha.dia, reservas[i].fecha.mes, reservas[i].fecha.anio);
			}
		}
	}
}




