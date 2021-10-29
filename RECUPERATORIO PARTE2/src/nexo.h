
#ifndef NEXO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "perro.h"
#include "estadia.h"
#include "duenio.h"
#define NEXO_H_

void nexo_mostrarEstadiasCompletas (sEstadia reservas[], int tamEstadias, sPerro listaPerros[], int tamPerros, sDuenio listaDuenios[], int tamDuenios);
void nexo_mostrarPerrosConDuenios (sPerro listaPerros[] , int tamPerros, sDuenio listaDuenios[], int tamDuenios);
void nexo_mostrarPerrosConEstadias (sPerro listaPerros[], int tamPerros, sEstadia listaEstadias[], int tamEstadias);
int nexo_existenciaEstadia ( sPerro listaPerros[] , int tam   );
int nexo_contarAlanConEstadias (sDuenio listaDuenios[], int tamDuenios, sEstadia listaEstadias[], int tamEstadias );
int nexo_listarEstadiasLuciasEnSegundaQuincena (sEstadia listaEstadias[], int tamEstadias, sDuenio listaDuenios[], int tamDuenios, sPerro listaPerros[], int tamPerros, int tamAux );

#endif /* NEXO_H_ */
