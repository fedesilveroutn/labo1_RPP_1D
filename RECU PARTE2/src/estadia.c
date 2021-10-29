
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

/**
 * @fn int estadia_buscarLugar(sEstadia[], int)
 * @brief  busca un lugar vacio, es decir, con estado cero
 *
 * @param reserva recibe un array sEstadia
 * @param tam recibe el tamaño del array
 * @return retorna retorna la posición vacía si la encontró o -1 si no encontró ningún lugar vacío
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
 * @brief busca una coincidencia de IDs entre lo pasado por paramatro y el campo id, dentro de los subindices de un array sEstadia con estado ocupado
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

/**
 * @fn int estadia_buscarCoincidenciaIdDuenio(sDuenio[], int, int)
 * @brief busca una coincidencia entre el campo id de una variable sDuenio y lo compara con el id recibido por parametro
 *
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenio recibe el tamanio de ese array sDuenio
 * @param id recibe el ID (idDuenio) con el que hara la comparacion
 * @return retorna 0 si encontro una coincidencia y -1 si hubo error
 */
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
 * @fn sEstadia estadia_pedirDatos(sEstadia, int, sPerro[], int, sDuenio, int)
 * @brief pide los datos para cargar un array sEstadia
 *
 * @param auxiliar recibe una variable de tipo sEstadia
 * @param ultimoId recibe el último ID correspondiente a la estadía
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array sPerro
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
		perro_mostrarTodos(listaPerros, tamPerro);
		getInt (&idPerro, "\nIngrese el ID del perro para el cual quiere reservar una estadía: ", "Error. Ingrese un ID válido: ", 1000 , 10000);
		while (estadia_buscarCoincidenciaId (listaPerros, tamPerro , idPerro) == -1)
		{
			printf("Error. ID de perro inexistente. Reintente.\n");
			getInt (&idPerro, "Ingrese el ID del perro: ", "Error. Ingrese un ID válido: ", 1000 , 2000);
		}
		duenio_mostrarTodos(listaDuenios, tamDuenio);
		getInt (&idDuenio, "\nIngrese el ID del DUEÑO de ese perro: ", "\nError. Ingrese un ID válido: ", 30000 , 40000);
		while (estadia_buscarCoincidenciaIdDuenio (listaDuenios , tamDuenio , idDuenio) == -1 )
		{
			printf("\nError. ID de dueño inexistente. Reintente.\n");
			getInt (&idDuenio, "\nIngrese el ID del dueño: ", "\nError. Ingrese un ID válido: ", 30000 , 40000);
			printf("\n----------------------------------------------------------------------------------------\n");
		}
		fecha = fecha_pedir("\nFecha de la reserva...\n");
		auxiliar.id = id;
		auxiliar.idPerro = idPerro;
		auxiliar.idDuenio = idDuenio;
		auxiliar.fecha = fecha;
		auxiliar.estado = 1;
	}
	return auxiliar;
}

/**
 * @fn int estadia_verificar(sEstadia, sPerro, sDuenio)
 * @brief muestra ID ESTADIA-NOMBRE_PERRO-RAZA-NOMBRE_DUEÑO-TELEFONO-FECHA y solicita al usuario que confirme los datos ingresados
 * 		  para luego retornar la respuesta
 *
 * @param reserva recibe una variable del tipo sEstadia
 * @param perro recibe una variable del tipo sPerro
 * @param duenio recibe una variable del tipo sDuenio
 * @return retorna la respuesta ingresada por el usuario siendo (0 = no / 1 = si)
 */
int estadia_verificar (sEstadia reserva, sPerro perro, sDuenio duenio)
{
	int respuesta;

	if (reserva.estado == 1)
	{
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n%-20s %-20s %-20s %-20s %-20s %-20s\n", "ID ESTADIA", "NOMBRE PERRO", "RAZA", "NOMBRE DUEÑO", "TELEFONO", "FECHA");
		printf("\n%-20d %-20s %-20s %-20s %-20d %d/%d/%d",	reserva.id , perro.nombre, perro.raza, duenio.nombre, duenio.telefono, reserva.fecha.dia , reserva.fecha.mes, reserva.fecha.anio );
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");
		getInt (&respuesta, "\nDesea CONFIRMAR los datos de la estadia (0 = no / 1 = si)? : ", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);
	}
	return respuesta;
}

/**
 * @fn int estadia_reservar(sEstadia[], int, int, sPerro[], int, sDuenio[], int)
 * @brief realiza la reserva de una estadia
 *
 * @param reserva recibe un array sEstadia
 * @param tam recibe el tamanio de ese array sEstadia
 * @param ultimoId recibe el ultimo ID correspondiente a la estadia
 * @param listaPerros recibe un array sPerro
 * @param tamPerro recibe el tamanio del array sPerro
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenio recibe el tamanio de ese array sDuenio
 * @return retorna el ultimo ID actualizado si salio bien o -1 si hubo error
 */
int estadia_reservar (sEstadia reserva[] , int tam , int ultimoId , sPerro listaPerros[] , int tamPerro, sDuenio listaDuenios[] , int tamDuenio)
{
	sEstadia aux;
	int ret = -1;
	int confirmacion;
	int index;
	int posicionIdPerro;
	int posicionIdDuenio;
	int posPerro;

	if (reserva != NULL && listaPerros != NULL && listaDuenios != NULL)
	{
		if (estadia_buscarLugar (reserva , tam) != -1)
		{
			aux = estadia_pedirDatos (aux , ultimoId , listaPerros , tamPerro , listaDuenios, tamDuenio);
			posicionIdPerro = perro_buscarCoincidenciaId(listaPerros, tamPerro, aux.idPerro);
			posicionIdDuenio = duenio_buscarCoincidenciaId(listaDuenios, tamDuenio, aux.idDuenio);
			printf("\nDatos de la estadia A CONFIRMAR:");
			confirmacion = estadia_verificar (aux, listaPerros[posicionIdPerro], listaDuenios[posicionIdDuenio]);
			if(confirmacion == 1)
			{
				index = estadia_buscarLugar (reserva , tam);
				reserva[index] = aux;
				reserva[index].estado = 1;
				posPerro = perro_buscarCoincidenciaId(listaPerros, tamPerro, reserva[index].idPerro);
				listaPerros[posPerro].contadorEstadia++;
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
		nuevoTelefono = duenio_pedirNuevoTelefono ();
		printf("\nSu nuevo número de teléfono será: %d\n", nuevoTelefono);
		getInt (&respuesta, "\nDesea confirmar la modificacion del TELEFONO (0 = no / 1 = si) ?: ", "\nError. Ingrese una opción válida (0 = no / 1 = si): ", 0 , 1);
		if ( respuesta == 1)
		{
			ret = nuevoTelefono;
		}

		else
		{
			printf("\nUsted ha cancelado la modificacion del teléfono");
		}
	}
	else
	{
		printf("\nNo se puede modificar una opcion que no existe.");
	}
	return ret;
}

/**
 * @fn int estadia_cancelar(sPerro[], int, sEstadia[], int, sDuenio[], int, int)
 * @brief realiza la cancelacion de una estadia
 *
 * @param perros recibe un array sPerro
 * @param tamPerros recibe el tamanio de ese array sPerro
 * @param reserva recibe un array sEstadia
 * @param tamEstadias recibe el tamanio de ese array sEstadia
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array sDuenio
 * @param id recibe el ID correspondiente a la estadia que se quiere cancelar
 * @return retorna 0 si funciono o -1 si hubo error
 */
int estadia_cancelar (sPerro perros[], int tamPerros, sEstadia reserva[], int tamEstadias , sDuenio listaDuenios[], int tamDuenios, int id)
{
	int ret = -1;
	int pos;
	int posPerro;
	int posDuenio;
	int confirmacion;

	if (reserva != NULL && perros!= NULL && listaDuenios != NULL)
	{
		pos = estadia_buscarCoincidenciaId2(reserva, tamEstadias, id);
		posPerro = perro_buscarCoincidenciaId(perros, tamPerros, reserva[pos].idPerro);
		posDuenio = duenio_buscarCoincidenciaId(listaDuenios, tamDuenios, reserva[pos].idDuenio);
		if(pos != -1)
		{
			printf("\nDatos de la estadía a ser cancelada: ");
			confirmacion = estadia_verificar (reserva[pos], perros[posPerro], listaDuenios[posDuenio]);
			if (confirmacion == 1)
			{

				reserva[pos].estado = 0;
				perros[posPerro].contadorEstadia--;
				ret = 0;
			}
			else
			{
				printf("\nUsted ha rechazado realizar la cancelacion de la estadía");
			}
		}
		else
		{
			printf("\nError. El ID entregado no coincide con ninguna estadía.");
		}
	}
	return ret;
}

/**
 * @fn int estadia_ordenarPorFecha(sEstadia[], int, sDuenio[], int)
 * @brief ordena las estadias de forma creciente segun la fecha o si estas son iguales, lo hace segun el nombre del duenio
 *
 * @param reservas recibe un array sEstadia
 * @param tamReservas recibe el tamanio de ese array sEstadia
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array sDuenio
 * @return retorna 0 si funciono o -1 si hubo error
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
 * @fn void estadia_mostrarSoloEstadia(sEstadia[], int, sDuenio[], int)
 * @brief muestra ID_ESTADIA-FECHA de las estadias con estado = 1
 *
 * @param reservas recibe un array sEstadia
 * @param tamReservas recibe el tamanio de ese array sEstadia
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array sDuenio
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
