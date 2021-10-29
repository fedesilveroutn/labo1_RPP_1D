
#include "duenio.h"



/**
 * @fn int duenio_inicializar(sDuenio[], int)
 * @brief inicializa en 0 el campo estado del array sDuenio
 *
 * @param lista recibe un array sDuenio
 * @param tam recibe el tamanio de ese array
 * @return retorna 0 si funcionó y -1 si hubo error
 */
int duenio_inicializar (sDuenio lista[], int tam)
{
	int i;
	int ret = -1;
	if (lista != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			lista[i].estado = 0;
			duenio_inicializarContadorEstadia(lista, tam);
		}
		ret = 0;
	}
	return ret;
}

/**
 * @fn int duenio_inicializarContadorEstadia(sDuenio[], int)
 * @brief inicializa el campo contadorEstadia de un array sDuenio en 0
 *
 * @param listaDuenios
 * @param tamDuenios
 * @return
 */
int duenio_inicializarContadorEstadia (sDuenio listaDuenios[], int tamDuenios)
{
	int ret = -1;
	int i;

	if (listaDuenios != NULL)
	{
		for (i = 0; i < tamDuenios; i++)
		{
			listaDuenios[i].contadorEstadia = 0;
		}
	}

	return ret;
}

/**
 * @fn int duenio_hardcodear(sDuenio[])
 * @brief hardcodea los primeros cinco elementos de un array sDuenio
 *
 * @param lista recibe un array sDuenio
 * @return retorna 0 si funcionó y -1 si hubo error
 */
int duenio_hardcodear (sDuenio lista[])
{
	int ids[5] = {30000 , 30001, 30002 , 30003 , 30004};
	char nombres[5][41] = {"Federico Silvero" , "Constanza Arancio", "Valentin Silvero", "Melissa Brizuela", "JuanPaulo Scallise" }    ;
	int telefono[5] = {1132497707 , 1132924403 , 1122334455 , 1133445566 , 1144556677} ;
	int estados[5] = {1 , 1 , 1 , 1 , 1} ;
	int ret = -1;
	int i;

	if (lista != NULL)
	{
		for (i = 0; i < 5; i++)
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

/**
 * @fn int duenio_cargar(sDuenio[], int, int)
 * @brief realiza la carga una estructura sDuenio
 *
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array
 * @param ultimoIdDuenio recibe el ultimo ID correspondiente a los duenios
 * @return retonra el ultimo ID correspondiente a los duenios actualizado o retorna -1 si hubo error
 */
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
				listaDuenios[index].contadorEstadia = 0;
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

/**
 * @fn int duenio_buscarLugar(sDuenio[], int)
 * @brief busca un espacio disponible y si lo hay, retorna la posicion en donde lo encontro
 *
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array
 * @return ret retorna la primera posicion libre que encuentra o -1 si no encontro ninguna
 */
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

/**
 * @fn sDuenio duenio_pedirDatos(sDuenio, int)
 * @brief pide al usuario el ingreso de los datos necesarios para cargar una variable sDuenio
 *
 * @param duenio recibe una variable tipo sDuenio
 * @param ultimoIdDuenio recibe el ultimo ID cargado correspondiente a los duenios
 * @return retorna un auxiliar sDuenio cargado con todos los datos ingresados por el usuario
 */
sDuenio duenio_pedirDatos (sDuenio duenio , int ultimoIdDuenio)
{
	sDuenio aux;
	int id;
	char nombre[21];
	int telefono;

	id = ultimoIdDuenio + 1;
	getString (nombre, "Ingrese el NOMBRE del dueño: ", "Error. Ingrese un nombre válido (hasta 20 caracteres):", 21);
	getInt (&telefono, "Ingrese el TELEFONO del dueño: ", "Error. Ingrese un telefono válida (1-20): ", 1100000000 , 1199999999);
	aux.id = id;
	strcpy (aux.nombre , nombre);
	aux.telefono = telefono;
	return aux;
}

/**
 * @fn int duenio_verificar(sDuenio)
 * @brief muestra los datos del duenio ingresados por el usuairo, verifica si los quiere confirmar y retorna la respuesta
 *
 * @param duenio recibe una variable tipo sDuenio
 * @return retorna la respuesta ingresada por el usuario siendo (0 = no / 1 = si)
 */
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

/**
 * @fn void duenio_mostrarTodos(sDuenio[], int)
 * @brief muestra ID-NOMBRE-TELEFONO de todos los elementos de array sDuenio
 *
 * @param listaDuenios recibe un array sDuenio
 * @param tamDuenios recibe el tamanio de ese array
 */
void duenio_mostrarTodos (sDuenio listaDuenios[], int tamDuenios)
{
	int i;
	printf("\n----------------------------------------------------------------------------------------\n");
	printf("%-20s %-20s %-20s\n\n","ID DUEÑO", "NOMBRE DUEÑO", "TELEFONO");

	for (i = 0; i < tamDuenios; i++)
	{
		if (listaDuenios[i].estado == 1 )
		{
			printf("%-20d %-20s %-20d\n", listaDuenios[i].id, listaDuenios[i].nombre, listaDuenios[i].telefono);
		}
	}
	printf("----------------------------------------------------------------------------------------\n");
}

/**
 * @fn void duenio_mostrar(sDuenio)
 * @brief muestra ID-NOMBRE-TELEFONO de una variable sDuenio
 *
 * @param duenio recibe una variable tipo sDuenio
 */
void duenio_mostrar (sDuenio duenio)
{
	if (duenio.estado == 1 )
	{
		printf("%-20d %-20s %-20d\n", duenio.id, duenio.nombre, duenio.telefono);
	}
}

/**
 * @fn int duenio_buscarCoincidenciaId(sDuenio[], int, int)
 * @brief busca una coincidencia entre el ID pasado por parametro (idDuenio) y el campo id de los elementos del array sDuenio
 *
 * @param lista recibe un array sDuenio
 * @param tam recibe el tamanio de ese array
 * @param id recibe el ID con el que hara la comparacion
 * @return retorna la posicion si encontro una coincidencia entre IDs y retorna -1 si no lo hizo
 */
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

/**
 * @fn int duenio_pedirNuevoTelefono()
 * @brief solicita al usuario el ingreso de un nuevo telefono
 *
 * @return retorna el nuevo telefono
 */
int duenio_pedirNuevoTelefono ()
{
	int telefono;

	getInt (&telefono, "Ingrese el nuevo TELEFONO: ", "Error. Ingrese un teléfono válido (1100000000-1199999999): ", 1100000000 , 1199999999);
	return telefono;
}




