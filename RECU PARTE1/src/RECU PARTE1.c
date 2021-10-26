/*
 ============================================================================
Recuperatorio parte 1.
Alumno: Federico Elías Silvero.
Divisón: 1°D
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "menu.h"
#define TAM 20
#define IDESTADIA 99999
#define IDPERRO 7002
#define IDDUENIO 30002

int main(void) {
	setbuf(stdout, NULL);


	sPerro perros [TAM];
	sDuenio duenios [TAM];
	sEstadia reservas [TAM];

	menu (reservas , TAM , perros, TAM , duenios, TAM , IDESTADIA , IDPERRO , IDDUENIO );
	printf("\nFin del programa.");

	return 0;
}
