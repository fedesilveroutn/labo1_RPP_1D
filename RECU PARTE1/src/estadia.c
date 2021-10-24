
#include "estadia.h"



/**
 * @fn int estadia_inicializar(sEstadia[], int)
 * @brief inicializa en 0 los estados de todos los subindices de un array de sEstadia
 *
 * @param reservas recibe un array de sEstadia
 * @param tam recibe el tamaño del array
 * @return retorna 0 si funcionó correctamente, retorna -1 si hubo un error
 */
int estadia_inicializar (sEstadia reservas[], int tam)
{
	int i;
	int ret = -1;
	if (reservas != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			reservas[i].estado = 0;
		}
		ret = 0;
	}
	return ret;
}


/*
**
 * @fn int estadia_hardcodear(sEstadia[])
 * @brief hardcodea los valores de los primeros 3 subindices de un array sEstadia
 *
 * @param reserva recibe el array sEstadia a ser hardcodeado
 * @return retorna 0 si funcionó correctamente, retorna -1 si hubo un error
 *
int estadia_hardcodear (sEstadia reserva[])
{
	int ret = -1;
	int i;
	if(reserva != NULL)
	{
		int ids[3] = {100000 , 100001 , 100002};
		//char duenioNombres[3][51] = {"Federico" , "Valentin", "Constanza" };
		//int telefonoContacto[3] = {1132497707 , 1122442411 , 1132924403};
		int idsPerros[3] = {7000 , 7001 , 7002 };
		int idDuenios[3] = {30000 , 30001, 30002 };
		int dias[3] = {13 , 20 , 27};
		int meses[3] = {10 , 11 , 12};
		int anios[3] = {2021 , 2021 , 2021};
		int estados[3] = {1 , 1 , 1};

		for (i = 0; i < 3; i++)
		{
			reserva[i].id = ids[i];
			//strcpy (reserva[i].nombreDuenio , duenioNombres[i]);
			//reserva[i].telefonoContacto = telefonoContacto[i];
			reserva[i].idDuenio = idDuenios[i];


			reserva[i].idPerro = idsPerros[i];
			reserva[i].fecha.dia = dias[i];
			reserva[i].fecha.mes = meses[i];
			reserva[i].fecha.anio = anios[i];
			reserva[i].estado = estados[i];
		}

		ret = 0;
	}
	return ret;
}
*/


/**
 * @fn int estadia_buscarLugar(sEstadia[], int)
 * @brief  busca un lugar vacio, es decir, con estado cero
 *
 * @param reserva recibe un array sEstadia
 * @param tam recibe el tamaño del array
 * @return retorna -1 si no encontró ningún lugar vacío, retorna la posición vacía si la encontró
 */
int estadia_buscarLugar (sEstadia reserva[] , int tam)
{
	int i;
	int posicion = -1;
	if(reserva != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if ( reserva[i].estado == 0)
			{
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}



/**
 * @fn int estadia_buscarExistenciaId(sEstadia[], int, int)
 * @brief busca una coincidencia de IDs dentro de los subindices de un array sEstadia con estado ocupado
 *
 * @param reserva recibe el array sEstadia
 * @param tam recibe el tamaño del array
 * @param id recibe el ID con el que hará la compación
 * @return retorna 0 si encontró una coincidencia, retorna -1 si no lo hizo
 */
int estadia_buscarExistenciaId (sEstadia reserva[] , int tam , int id)
{
	int ret = -1;
	int i;
	if (reserva != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if (reserva[i].estado == 1	&& reserva[i].id == id)
			{
				ret = 0;
			}
		}
	}

	return ret;
}



/**
 * @fn int estadia_buscarCoincidenciaId(sPerro[], int, int)
 * @brief  compara el campo ID del array sPerro con el ID pasado por parámetro
 *
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @param id recibe el ID con el que debe hacer la comparación
 * @return retorna 0 si encontró una coicidencia, retorna -1 si no lo hizo
 */
int estadia_buscarCoincidenciaId (sPerro lista[] , int tam , int id)
{
	int ret = -1;
	int i;
	if (lista != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if (lista[i].id == id)
			{
				ret = 0;
			}
		}
	}

	return ret;
}



/**
 * @fn int estadia_buscarCoincidenciaId2(sEstadia[], int, int)
 * @brief compara el campo ID de los subindices del array sEstadia con el ID pasado por parámetro
 *
 * @param reserva recibe el array sEstadia
 * @param tam recibe el tamaño del array
 * @param id recibe el ID con el cual hacer la comparación
 * @return si encontró una coincidencia retorna la posición en donde lo hizo, caso contrario retorna -1
 */
int estadia_buscarCoincidenciaId2 (sEstadia reserva[] , int tam , int id)
{
	int i;
	int posicion = -1;
	if(reserva != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if ( reserva[i].id == id)
			{
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}




int estadia_buscarCoincidenciaIdDuenio (sDuenio listaDuenios[] , int tamDuenio , int id)
{
	int ret = -1;
	int i;
	if (listaDuenios != NULL)
	{
		for (i = 0; i < tamDuenio; i++)
		{
			if (listaDuenios[i].id == id)
			{
				ret = 0;
				break;
			}
		}
	}

	return ret;
}

/**
 * @fn sEstadia estadia_pedirDatos(sEstadia, int, sPerro[], int)
 * @brief pide los datos para cargar un array sEstadia
 *
 * @param auxiliar recibe una instancia de sEstadia
 * @param ultimoId recibe el último ID correspondiente a la estadía
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @return retorna el auxiliar cargado con los datos ingresados
 */
sEstadia estadia_pedirDatos (sEstadia auxiliar , int ultimoId , sPerro listaPerros[] , int tamPerro, sDuenio listaDuenios[], int tamDuenio)
{
	int id;
	int idPerro;
	int idDuenio;
	sFecha fecha;

	if (listaPerros != NULL && listaDuenios != NULL)
	{
		id = ultimoId + 1;

		//pido el ingreso de un ID de perro y busco si existe
		getInt (&idPerro, "\n\nIngrese el ID del perro: ", "Error. Ingrese un ID válido: ", 1000 , 10000);
		while (estadia_buscarCoincidenciaId (listaPerros, tamPerro , idPerro) == -1)
		{
			printf("Error. ID de perro inexistente. Reintente.\n");
			getInt (&idPerro, "Ingrese el ID del perro: ", "Error. Ingrese un ID válido: ", 1000 , 2000);
		}


		//pido el ingreso de un ID de dueño y busco si existe
		getInt (&idDuenio, "Ingrese el ID del dueño: ", "Error. Ingrese un ID válido: ", 30000 , 40000);
		while (estadia_buscarCoincidenciaIdDuenio (listaDuenios , tamDuenio , idDuenio) == -1 )
		{
			printf("Error. ID de dueño inexistente. Reintente.\n");
			getInt (&idDuenio, "Ingrese el ID del dueño: ", "Error. Ingrese un ID válido: ", 30000 , 40000);
		}


		fecha = fecha_pedir("\nDatos de la reserva");

		//asigno a mi auxiliar todos los datos que pedí que sean ingresados y lo retorno cargado
		auxiliar.id = id;
		auxiliar.idPerro = idPerro;
		auxiliar.idDuenio = idDuenio;
		auxiliar.fecha = fecha;
	}
	return auxiliar;
}



/**
 * @fn int estadia_verificar(sEstadia)
 * @brief  imprime los datos cargados por el usuario y le pide que los confirme
 *
 * @param reserva recibe una instancia de sEstadia
 * @return retorna la respuesta del usuario siendo 0 = no y 1 = si
 */
int estadia_verificar (sEstadia reserva, sPerro perro, sDuenio duenio)
{
	int respuesta;

	printf("\n----------------------------------------------------------------\nDatos de la estadia A CONFIRMAR:\n");
	printf("\n%-20s %-20s %-20s %-20s %-20s %-20s\n",
		   "ID ESTADIA", "NOMBRE PERRO", "RAZA", "NOMBRE DUEÑO", "TELEFONO", "FECHA");


	printf("\n%-20d %-20s %-20s %-20s %-20d %d/%d/%d", reserva.id , perro.nombre, perro.raza, duenio.nombre, duenio.telefono, reserva.fecha.dia , reserva.fecha.mes, reserva.fecha.anio );



	getInt (&respuesta, "\n\nDesea CONFIRMAR los datos de la estadia (0 = no / 1 = si)? : ", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}



/**
 * @fn int estadia_reservar(sEstadia[], int, int, sPerro[], int)
 * @brief se encarga de realizar la reserva de la estadia para un perro
 *
 * @param reserva recibe un array sEstadia
 * @param tam recibe el tamaño del array
 * @param ultimoId recibe el último ID correspondiente a la estadia
 * @param lista recibe un array sPerro
 * @param tamPerro recibe el tamaño del array
 * @return retorna el último ID actualizado
 */
int estadia_reservar (sEstadia reserva[] , int tam , int ultimoId , sPerro listaPerros[] , int tamPerro, sDuenio listaDuenios[] , int tamDuenio)
{
	sEstadia aux;
	int ret = -1;
	int confirmacion;
	int index;
	int posicionIdPerro;
	int posicionIdDuenio;

	if (reserva != NULL && listaPerros != NULL && listaDuenios != NULL)
	{
		if (estadia_buscarLugar (reserva , tam) != -1)
		{
			nexo_mostrarPerrosConDuenios(listaPerros, tamPerro, listaDuenios, tamDuenio);
			aux = estadia_pedirDatos (aux , ultimoId , listaPerros , tamPerro , listaDuenios, tamDuenio);
			posicionIdPerro = perro_buscarCoincidenciaId(listaPerros, tamPerro, aux.idPerro);
			posicionIdDuenio = duenio_buscarCoincidenciaId(listaDuenios, tamDuenio, aux.idDuenio);


			confirmacion = estadia_verificar (aux, listaPerros[posicionIdPerro], listaDuenios[posicionIdDuenio]);

			if(confirmacion == 1)
			{
				index = estadia_buscarLugar (reserva , tam);
				reserva[index] = aux;
				reserva[index].estado = 1;
				listaPerros[index].contadorEstadias++;

				ultimoId++;
				ret = ultimoId;
			}

			else
			{
				printf("\nUsted ha cancelado la reserva.\n");
			}
		}

		else
		{
			printf("\nNo hay lugar disponible para reservar.\n");
		}
	}

	return ret;
}



/**
 * @fn int estadia_modificar(int)
 * @brief modifica el elemento que le sea solicitado
 *
 * @param elemento recibe el elemento a modificar (pensando en un posible switch de opcion a futuro)
 * @return retorna -1 si no funcionó, retorna 0 si funcionó correctamente
 */
int estadia_modificar (int elemento)
{
	int ret = -1;
	int nuevoTelefono;
	int respuesta;

	if (elemento == 1 )
	{
		//getInt (&nuevoTelefono ,"\nIngrese su nuevo NUMERO DE TELEFONO: ","\nError. Reingrese un número válido (1100000000-1199999999): ", 1100000000,1199999999);
		nuevoTelefono = duenio_pedirNuevoTelefono ();


		printf("\nSu nuevo número de teléfono es: %d\n", nuevoTelefono);
		getInt (&respuesta, "\nDesea confirmar la modificacion del TELEFONO (0 = no / 1 = si) ?: ", "\nError. Ingrese una opción válida (0 = no / 1 = si): ", 0 , 1);

		if ( respuesta == 1)
		{
			ret = nuevoTelefono;
		}

		else
		{
			printf("\nUsted ha cancelado la modificacion del tel dentro de la funcion estadia_modificar");
		}
	}
	else
	{
		printf("\nNo se puede modificar una opcion que no existe.");
	}

	return ret;
}



/**
 * @fn int estadia_cancelar(sPerro[], int, sEstadia[], int, int)
 * @brief realiza una baja lógica
 *
 * @param perros recibe un array sPerro
 * @param tamPerros recibe el tamaño del array
 * @param reserva recibe un array sEstadia
 * @param tamEstadias recibe el tamaño del array sEstadia
 * @param id recibe el ID correspondiente a la estadia a ser dada de baja
 * @return retorna -1 si hubo error, retorna 0 si funcionó correctamente
 */
int estadia_cancelar (sPerro perros[], int tamPerros, sEstadia reserva[], int tamEstadias , sDuenio listaDuenios[], int tamDuenios, int id)
{
	int ret = -1;
	int pos;

	if (reserva != NULL && perros!= NULL && listaDuenios != NULL)
	{
		pos = estadia_buscarCoincidenciaId2(reserva, tamEstadias, id);
		reserva[pos].estado = 0;
		perros[pos].estado = 0;
		listaDuenios[pos].estado = 0;
		ret = 0;
	}

	return ret;
}



/**
 * @fn int estadia_ordenarPorFecha(sEstadia[], int)
 * @brief ordena las reservas por fechas y si estas son iguales, lo hace por el nombre del dueño
 *
 * @param reservas recibe un array sEstadia
 * @param tamReservas recibe el tamaño del array
 * @return retorna -1 si hubo error, retorna 0 si funcionó correctamente
 */
int estadia_ordenarPorFecha (sEstadia reservas[], int tamReservas , sDuenio listaDuenios[], int tamDuenios)
{
	int i;
	int swap;
	int nuevoLimite;
	sEstadia aux;
	int ret = -1;

	if (reservas != NULL)
	{
		nuevoLimite = tamReservas - 1;

		do
		{
			swap = 0;
			for ( i = 0; i < nuevoLimite; i++)
			{
				if (reservas[i].fecha.anio < reservas[i+1].fecha.anio || reservas[i].fecha.mes < reservas[i+1].fecha.mes || reservas[i].fecha.dia < reservas[i+1].fecha.dia )
				{
					aux = reservas[i];
					reservas[i] = reservas[i+1];
					reservas[i+1] = aux;
					swap = 1;
				}
				else if (reservas[i].fecha.anio == reservas[i+1].fecha.anio)
				{
					if ( strcmp (listaDuenios[i].nombre , listaDuenios[i+1].nombre) == 1 )
					{
						aux = reservas[i];
						reservas[i] = reservas[i+1];
						reservas[i+1] = aux;
						swap = 1;
					}
				}
			}
			nuevoLimite--;

		}while (swap == 1);

		ret = 0;
	}
	return ret;
}



/**
 * @fn void estadia_mostrarSoloEstadia(sEstadia[], int)
 * @brief imprime todas las reservas realizadas
 *
 * @param reservas recibe un array sEstadia
 * @param tamReservas recibe el tamaño del array
 */
void estadia_mostrarSoloEstadia (sEstadia reservas[] , int tamReservas, sDuenio listaDuenios[], int tamDuenios)
{
	int i;

	if (reservas != NULL && listaDuenios != NULL)
	{
		estadia_ordenarPorFecha (reservas, tamReservas, listaDuenios, tamDuenios);

		printf("\n%-15s %-15s\n", "ID ESTADIA", "FECHA");

		for(i = 0; i < tamReservas; i++)
		{
			if (reservas[i].estado == 1)
			{
				printf("%-15d %-2d/%-2d/%-2d\n",
															reservas[i].id,
															reservas[i].fecha.dia,
															reservas[i].fecha.mes,
															reservas[i].fecha.anio);
			}
		}
	}
}
