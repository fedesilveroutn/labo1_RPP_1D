
#include "perro.h"
#include <stdio.h>



/**
 * @fn int perro_inicializar(sPerro[], int)
 * @brief inicializa todos los estados de los subindeces del array sPerro en 0
 *
 * @param perros recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @return retorna -1 si hubo error, retorna 0 si funcionó correctamente
 */
int perro_inicializar (sPerro perros[], int tam)
{
	int i;
	int ret = -1;
	if (perros != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			perros[i].estado = 0;
			perro_inicializarContadorEstadia(perros, tam);
		}
		ret = 0;
	}
	return ret;
}

/**
 * @fn int perro_inicializarContadorEstadia(sPerro[], int)
 * @brief inicializa el campo "contadorEstadia" del todos los elementos del array sPerro en 0
 *
 * @param listaPerros recibe un array de sPerro
 * @param tamPerros recibe el tamanio del array
 * @return retorna 0 si funcionó y -1 si salió mal
 */
int perro_inicializarContadorEstadia (sPerro listaPerros[], int tamPerros)
{
	int ret = -1;
	int i;

	if (listaPerros != NULL)
	{
		for (i = 0; i < tamPerros; i++)
		{
			listaPerros[i].contadorEstadia = 0;
		}
	}

	return ret;
}

/**
 * @fn int perro_hardcodear(sPerro[])
 * @brief hardcodea los valores de los primeros 3 subindices de un array sPerro
 *
 * @param lista recibe un array sPerro
 * @return retorna -1 si hubo error, retorna 0 si funcionó correctamente
 */
int perro_hardcodear (sPerro lista[])
{
	int ret = -1;
	int i;
	int ids[3] = {7000 , 7001, 7002};
	char nombres[3][21] = {"Lobo" , "Sheila", "Reina" }    ;
	char razas[3][21] = {"Sharpei" , "Golden" , "Galgo" };
	int edades[3] = {2 , 12 , 13} ;
	int estados[3] = {1 , 1 , 1 } ;

	if (lista != NULL)
	{
		for (i = 0; i < 3; i++)
		{
			lista[i].id = ids[i];
			strcpy (lista[i].nombre , nombres[i]);
			strcpy (lista[i].raza , razas[i]);
			lista[i].edad = edades[i];
			lista[i].estado = estados[i];
		}

		ret = 0;
	}
	return ret;
}

/**
 * @fn int perro_buscarLugar(sPerro[], int)
 * @brief
 *
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @return retorna la primera posición vacía que encuentra o retorna -1 si no encontró ninguna libre
 */
int perro_buscarLugar (sPerro lista[] , int tam)
{
	int i;
	int posicion = -1;
	if (lista != NULL)
	{
		for (i = 0; i < tam; i++)
		{
			if ( lista[i].estado == 0)
			{
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}

/**
 * @fn int perro_buscarCoincidenciaId(sPerro[], int, int)
 * @brief busca en que posicion del array sPerro hay una coincidencia entre el ID pasado por parametro y
 * 		  el ID correspondiente al campo id de la estructura sPerro y si la encuentra retorna esa posicion
 *
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @param id recibe un ID con el cual hacer la comparación
 * @return retorna la posicion donde encontró la coincidencia entre el id parametro y el ID del campo sPerro o -1 si no hay coincidencia
 */
int perro_buscarCoincidenciaId (sPerro lista[] , int tam, int id)
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
 * @fn sPerro perro_pedirDatos(sPerro, int)
 * @brief pide los datos para cargar una instancia de sPerro y los carga en un auxiliar sPerro el cual retorna
 *
 * @param perro recibe una variable de tipo sPerro
 * @param ultimoIdPerro recibe el último ID correspondiente al último perro ingresado
 * @return retorna un auxiliar tipo sPerro cargado con todos los datos solicitados
 */
sPerro perro_pedirDatos (sPerro perro , int ultimoIdPerro)
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	sPerro aux;

	id = ultimoIdPerro + 1;
	getString (nombre, "Ingrese el NOMBRE DEL PERRO: ", "ERROR. Reingrese un NOMBRE válido (hasta 20 caracteres):", 21);
	getString (raza, "Ingrese la RAZA DEL PERRO: ", "ERROR. Reingrese una RAZA válida (hasta 20 caracteres):", 21);
	getInt (&edad, "Ingrese la EDAD DEL PERRO: ", "ERROR. Reingrese una EDAD válida (1-20): ", 1 , 20);

	aux.id = id;
	strcpy (aux.nombre , nombre);
	strcpy (aux.raza , raza);
	aux.edad = edad;

	return aux;
}

/**
 * @fn int perro_verificar(sPerro)
 * @brief muestra al usuario los datos que ha ingresado y verifica si realmente los quiere confirmar
 *
 * @param perro recibe una variable tipo sPerro
 * @return retorna la respuesta ingresada por el usuario siendo 0 = no / 1 = si
 */
int perro_verificar (sPerro perro)
{
	int respuesta;

	printf("\n----------------------------------------------------------------"
		   "\nDatos del perro A CONFIRMAR: \n");
	printf("\n%-15s %-15s %-15s %-15s", "ID" , "NOMBRE", "RAZA", "EDAD");
	printf("\n%-15d %-15s %-15s %-15d\n", perro.id , perro.nombre, perro.raza, perro.edad);
	printf("\n----------------------------------------------------------------\n");
	getInt (&respuesta, "\nDesea CONFIRMAR los datos del perro (0 = no / 1 = si)? : ", "ERROR. Elija una opcion (0 = no / 1 = si): ", 0 , 1);
	return respuesta;
}

/**
 * @fn int perro_cargar(sPerro[], int, int)
 * @brief realiza la carga de una variable sPerro
 *
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @param ultimoIdPerro recibe el último ID correspondiente a sPerro
 * @return retorna el último ID actualizado o -1 si hubo un error
 */
int perro_cargar (sPerro lista[] , int tam , int ultimoIdPerro)
{
	sPerro aux;
	int ret = -1;
	int confirmacion;
	int index;

	if (lista != NULL)
	{
		if (perro_buscarLugar (lista , tam) != -1)
		{
			aux = perro_pedirDatos (aux , ultimoIdPerro);
			confirmacion = perro_verificar (aux);
			if(confirmacion == 1)
			{
				index = perro_buscarLugar (lista , tam);
				lista[index] = aux;
				lista[index].estado = 1;
				lista[index].contadorEstadia = 0;
				ultimoIdPerro++;
				printf("\n***PERRO CARGADO EXITOSAMENTE!***");
				ret = ultimoIdPerro;
			}

			else
			{
				printf("\nUsted ha cancelado la carga del perro.\n");
			}
		}

		else
		{
			printf("\nNo hay lugar disponible para la carga del perro.");
		}
	}
	return ret;
}

/**
 * @fn int perro_ordenarPorId(sPerro[], int)
 * @brief ordena eficazmente el array sPerro según el ID y si estos son iguales, lo hace según el nombre
 *
 * @param lista recibe un array sPerro
 * @param tamPerros recibe el tamaño del array
 * @return retorna 0 si funcionó correctamente o retorna -1 si hubo un error
 */
int perro_ordenarPorId (sPerro lista[], int tamPerros)
{
	sPerro aux;
	int i;
	int swap;
	int nuevoLimite;
	int ret = -1;

	if (lista != NULL)
	{
		nuevoLimite = tamPerros - 1;
		do
		{
			swap = 0;
			for ( i = 0; i < nuevoLimite; i++)
			{
				if (lista[i].id > lista[i+1].id)
				{
					aux = lista[i];
					lista[i] = lista[i+1];
					lista[i+1] = aux;
					swap = 1;
				}
				else if (lista[i].id == lista[i+1].id)
				{
					if ( strcmp (lista[i].nombre , lista[i+1].nombre) == 1 )
					{
						aux = lista[i];
						lista[i] = lista[i+1];
						lista[i+1] = aux;
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
 * @fn void perro_mostrar(sPerro)
 * @brief muestra los datos ID-NOMBRE-RAZA-EDAD cargados en la variable tipo sPerro pasada por parámetro
 *
 * @param perro recibe una variable tipo sPerro
 */
void perro_mostrar (sPerro perro)
{
	if (perro.estado == 1 )
	{
		printf("\n%-20d %-20s %-20s %-20d", perro.id, perro.nombre, perro.raza, perro.edad);
	}
}

/**
 * @fn void perro_mostrarTodos(sPerro[], int)
 * @brief muestra ID-NOMBRE-RAZA-EDAD de todos  los elementos del array sPerro ordenados según su ID (o nombre si estos son iguales)
 *
 * @param lista recibe un array sPerro
 * @param tamPerros recibe el tamaño del array
 */
void perro_mostrarTodos (sPerro lista[] , int tamPerros)
{
	int i;

	if (lista != NULL)
	{
		perro_ordenarPorId (lista , tamPerros);
		printf("\n----------------------------------------------------------------------------------------");
		printf("\n%-20s %-20s %-20s %-20s\n", "ID PERRO", "NOMBRE", "RAZA", "EDAD");
		for (i = 0; i < tamPerros; i++)
		{
			if (lista[i].estado == 1)
			{
				perro_mostrar(lista[i]);
			}
		}
		printf("\n----------------------------------------------------------------------------------------\n");
	}
}

/**
 * @fn float perro_edadPromedio(sPerro[], int, int)
 * @brief calcula el promedio de las edades de los perros cargados y lo retorna
 *
 * @param lista recibe un array sPerro
 * @param tamPerros recibe el tamaño del array
 * @param contador recibe el contador encargado de contar la cantidad total de perros ingresados
 * @return retorna la edad promedio
 */
float perro_edadPromedio (sPerro lista[], int tamPerros, int contador)
{
	int i;
	int acumulador = 0;
	float promedio;

	if (lista != NULL)
	{
		for (i = 0 ; i < tamPerros; i++)
		{
			if (lista[i].estado == 1)
			{
				acumulador += lista[i].edad;
			}
		}
		promedio = (float) acumulador / contador;
	}

	return promedio;
}

/**
 * @fn int perro_encontrarMayorCantidadEstadias(sPerro[], int)
 * @brief recorre la lista de perros y busca el perro con mayor cantidad de estadias, cuando lo encuentra retorna la posicion de ese perro
 *
 * @param listaPerros recibe un array sPerro
 * @param tamPerros recibe el tamanio de ese array
 * @return retorna la posicion del perro que tiene mas estadias reservadas
 */
int perro_encontrarMayorCantidadEstadias (sPerro listaPerros[], int tamPerros)
{
	int max;
	int pos;
	int i;
	int flag = 0;

	for (i = 0; i < tamPerros; i++)
	{
		if (flag == 0 || listaPerros[i].contadorEstadia > max)
		{
			max = listaPerros[i].contadorEstadia;
			pos = i;
			flag = 1;
		}
	}
	return pos;
}

