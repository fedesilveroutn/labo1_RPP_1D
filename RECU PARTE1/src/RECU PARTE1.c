/*
 ============================================================================
Recuperatorio parte 1.
Alumno: Federico Elías Silvero.
Divisón: 1°D

validaciones: 1 si sale mal y 0 si sale bien
accion: -1 si da error y 0 si sale bien
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "menu.h"
#define TAM 5
#define IDESTADIA 100002 //inicializo los IDs porque los había hardcodeado
#define IDPERRO 7002
#define IDDUENIO 30002

int main(void) {
	setbuf(stdout, NULL);


	sPerro perros [TAM];
	sDuenio duenios [TAM];
	sEstadia reservas [TAM];

	menu (reservas , TAM , perros, TAM , duenios, TAM , IDESTADIA , IDPERRO , IDDUENIO );

	return 0;
}
