
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
			}
			ret = 0;
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

	if (lista != NULL)
	{
		int ids[3] = {7000 , 7001, 7002};
		char nombres[3][21] = {"Lobo" , "Sheila", "Reina" }    ;
		char razas[3][21] = {"Sharpei" , "Golden" , "Galgo" };
		int edades[3] = {2 , 12 , 13} ;
		int estados[3] = {1 , 1 , 1 } ;

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
 * @return retorna -1 si hubo error, retorna la posición si funcionó correctamente
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
 * @brief busca una coincidencia entre el ID pasado por parametro y el ID correspondiente al campo id del array sPerro
 *
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @param id recibe el id con el cual hacer la comparación
 * @return retorna la posicion donde encontró la coincidencia con el id, -1 si no hay coincidencia
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
 * @brief pide los datos para cargar una instancia de sPerro
 *
 * @param perro recibe una instancia sPerro
 * @param ultimoIdPerro recibe el último ID correspondiente al último perro ingresado
 * @return retorna un aux sPerro cargado con todos los datos solicitados
 */
sPerro perro_pedirDatos (sPerro perro , int ultimoIdPerro)
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	sPerro aux; //voy a cargar mi auxiliar con los datos que le pedi al usuario y lo retorno ya cargado

	id = ultimoIdPerro + 1;
	getString (nombre, "Ingrese el NOMBRE del perro: ", "ERROR. Reingrese un NOMBRE válido (hasta 20 caracteres):", 21);
	getString (raza, "Ingrese la RAZA del perro: ", "ERROR. Reingrese una RAZA válida (hasta 20 caracteres):", 21);
	getInt (&edad, "Ingrese la EDAD del perro: ", "ERROR. Reingrese una EDAD válida (1-20): ", 1 , 20);

	aux.id = id;
	strcpy (aux.nombre , nombre);
	strcpy (aux.raza , raza);
	aux.edad = edad;

	return aux;
}




/**
 * @fn sPerro perro_pedirDatosSinId(sPerro)
 * @brief pide los datos para cargar una instancia sPerro pero sin pedir el ID
 *
 * @param perro recibe una instancia sPerro
 * @return retorna un auxiliar cargado con los datos ingresados por el usuario
 */
sPerro perro_pedirDatosSinId (sPerro perro)
{
	char nombre[21];
	char raza[21];
	int edad;
	sPerro aux;

	getString (nombre, "Ingrese el NOMBRE del perro: ", "Error. Ingrese un nombre válido (hasta 20 caracteres):", 21);
	getString (raza, "Ingrese la RAZA del perro: ", "Error. Ingrese una raza válida (hasta 20 caracteres):", 21);
	getInt (&edad, "Ingrese la EDAD del perro: ", "Error. Ingrese una edad válida (1-20): ", 1 , 20);

	strcpy (aux.nombre , nombre);
	strcpy (aux.raza , raza);
	aux.edad = edad;

	return aux;
}



/**
 * @fn int perro_verificar(sPerro)
 * @brief muestra al usuario los datos cargados en perro y le preguntra si quiere confirmar
 *
 * @param perro recibe una instancia sPerro
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
 * @fn int perro_verificarSinId(sPerro)
 * @brief muestra al usuario los datos cargados en perro (sin el ID) y le preguntra si quiere confirmar
 *
 * @param perro perro recibe una instancia sPerro
 * @return retorna la respuesta ingresada por el usuario siendo 0 = no / 1 = si
 */
int perro_verificarSinId (sPerro perro)
{
	int respuesta;

	printf("\n----------------------------------------------------------------"
		   "\nDatos del perro A CONFIRMAR: \n"
		   "\nNOMBRE: %s\nRAZA: %s\nEDAD: %d\n"
		   "\n----------------------------------------------------------------\n", perro.nombre, perro.raza, perro.edad);

	getInt (&respuesta, "Desea CONFIRMAR los datos del perro (0 = no / 1 = si)? : ", "Error. Elija una opcion (0 = no / 1 = si): ", 0 , 1);

	return respuesta;
}



/**
 * @fn int perro_cargar(sPerro[], int, int)
 * @brief realiza la carga de una instancia sPerro
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
		//si la funcion buscar devuelve algo != -1 significa que existe un lugar disponible para cargar un perro
		if (perro_buscarLugar (lista , tam) != -1)
		{
			//pido los datos y los guardo en un auxiliar para verificar si el usuario esta de acuerdo con lo que ingresó
			aux = perro_pedirDatos (aux , ultimoIdPerro);
			confirmacion = perro_verificar (aux);


			//si la respuesta a la confirmacion fue que si entonces:
			if(confirmacion == 1)
			{
				//vuelvo a buscar un lugar disponible pero esta vez guardo la posición del subíndice libre en index
				index = perro_buscarLugar (lista , tam);

				//asigno en la posicion index de mi lista de perros, lo que tenía guardado en auxiliar y cambio el estado a ocupado
				lista[index] = aux;
				lista[index].estado = 1;

				//como ya se cargó el perro, aumento el ultimo ID de perro
				ultimoIdPerro++;

				//muestro el perro que cargué
				printf("\n***PERRO CARGADO EXITOSAMENTE!***");


				//retorno el último ID de perro actualizado
				ret = ultimoIdPerro;
			}

			else
			{
				//mensaje a mostrar si no confirma la carga
				printf("\nUsted ha cancelado la carga del perro.\n");
			}

		}

		else
		{
			//mensaje a mostrar si no pudo encontrar la existencia de un lugar disponible para la carga
			printf("\nNo hay lugar disponible para la carga del perro.");
		}
	}
	return ret;
}



/**
 * @fn int perro_modificar(sPerro[], int, int, int)
 * @brief modifica los datos de una instancia de sPerro ingresando el ID correspondiente
 *
 * @param lista recibe un array sPerro
 * @param tam recibe el tamaño del array
 * @param pos recibe una posicion
 * @param id recibe el ID correspondiente al perro
 * @return retorna 0 si funcionó o -1 si hubo un error
 */
int perro_modificar (sPerro lista[] , int tam , int pos , int id)
{
	sPerro aux;
	int ret = -1;
	int confirmacion;
	if(lista != NULL)
	{
		aux = perro_pedirDatosSinId (aux);
		aux.id = id;

		confirmacion = perro_verificarSinId (aux);
		if(confirmacion == 1)
		{
			lista[pos] = aux;
			perro_mostrar(lista[pos]);
			ret = 0;
		}

		else
		{
			printf("\nUsted ha cancelado la modificacion del perro.\n");
		}
	}

	return ret;
}



/**
 * @fn int perro_ordenarPorId(sPerro[], int)
 * @brief ordena el array sPerro por el ID
 *
 * @param lista recibe un array sPerro
 * @param tamPerros recibe el tamaño del array
 * @return retorna 0 si funcionó correctamente o retorna -1 si hubo un error
 */
int perro_ordenarPorId (sPerro lista[], int tamPerros)
{
	int i;
	int swap;
	int nuevoLimite;
	sPerro aux;
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
 * @brief muestra los datos cargados en la instancia de sPerro pasada por parámetro
 *
 * @param perro recibe una instancia sPerro
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
 * @brief muestra todos los elementos del array sPerro
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
	}
}



/**
 * @fn float perro_edadPromedio(sPerro[], int, int)
 * @brief calcula el promedio de las edades
 *
 * @param lista recibe un array sPerro
 * @param tamPerros recibe el tamaño del array
 * @param contador recibe un contador
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



int perro_encontrarMayorCantidadEstadias (sPerro listaPerros[], int tamPerros)
{
	int max;
	int pos;
	int i;
	int flag = 0;

	for (i = 0; i < tamPerros; i++)
	{
		if (flag == 0 || listaPerros[i].contadorEstadias > max)
		{
			max = listaPerros[i].contadorEstadias;
			pos = i;
			flag = 1;
		}
	}

	return pos;
}

