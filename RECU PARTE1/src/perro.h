
#ifndef PERRO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

#define PERRO_H_

typedef struct
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estado;
	int contadorEstadias;

} sPerro;

int perro_inicializar (sPerro perros[], int tam);
int perro_hardcodear (sPerro lista[]);
int perro_buscarLugar (sPerro lista[] , int tam);
int perro_buscarCoincidenciaId (sPerro lista[] , int tam, int id);
sPerro perro_pedirDatos (sPerro perro , int ultimoIdPerro);
sPerro perro_pedirDatosSinId (sPerro perro);
int perro_verificar (sPerro perro);
int perro_verificarSinId (sPerro perro);
int perro_cargar (sPerro lista[] , int tam , int ultimoIdPerro);
int perro_modificar (sPerro lista[] , int tam , int index , int id);
int perro_ordenarPorId (sPerro lista[], int tamPerros);
void perro_mostrar (sPerro perro);
void perro_mostrarTodos (sPerro lista[] , int tamPerros);
float perro_edadPromedio (sPerro lista[], int tamPerros, int contador);
int perro_encontrarMayorCantidadEstadias (sPerro listaPerros[], int tamPerros);


#endif /* PERRO_H_ */
