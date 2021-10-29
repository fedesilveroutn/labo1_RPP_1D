
#ifndef ESTADIA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "fecha.h"
#include "perro.h"
#include "duenio.h"
#define ESTADIA_H_

typedef struct
{
	int id;
	int idPerro;
	int idDuenio;
	sFecha fecha;
	int estado;

} sEstadia;

int estadia_inicializar (sEstadia reservas[], int tam);
int estadia_reservar (sEstadia reserva[] , int tam , int ultimoId , sPerro listaPerros[] , int tamPerro, sDuenio listaDuenios[] , int tamDuenio);
int estadia_buscarLugar (sEstadia reserva[] , int tam);
sEstadia estadia_pedirDatos (sEstadia auxiliar , int ultimoId , sPerro listaPerros[] , int tamPerro, sDuenio listaDuenios[], int tamDuenio);
int estadia_verificar (sEstadia reserva, sPerro perro, sDuenio duenio);
int estadia_buscarExistenciaId (sEstadia reserva[] , int tam , int id);
int estadia_buscarCoincidenciaId (sPerro lista[] , int tam , int id);
int estadia_buscarCoincidenciaId2 (sEstadia reserva[] , int tam , int id);
int estadia_buscarCoincidenciaIdDuenio (sDuenio listaDuenios[] , int tamDuenio , int id);
int estadia_modificar (int elemento);
int estadia_cancelar (sPerro perros[], int tamPerros, sEstadia reserva[], int tamEstadias , sDuenio listaDuenios[], int tamDuenios, int id);
int estadia_ordenarPorFecha (sEstadia reservas[], int tamReservas , sDuenio listaDuenios[], int tamDuenios);
void estadia_mostrarSoloEstadia (sEstadia reservas[] , int tamReservas, sDuenio listaDuenios[], int tamDuenios);

#endif /* ESTADIA_H_ */
