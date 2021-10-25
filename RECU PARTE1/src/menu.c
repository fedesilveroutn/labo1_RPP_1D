
#include "menu.h"
#include "perro.h"
#include "estadia.h"
#include "duenio.h"

/**
 * @fn int menu(sEstadia[], int, sPerro[], int, int, int)
 * @brief contiene la lógica del programa, muestra los menus de opciones y sus distintos posibles flujos
 *
 * @param listaEstadias recibe un array de sEstadia
 * @param tamEstadias recibe el tamaño del array listaEstadia
 * @param listaPerros recibe un array de sPerro
 * @param tamPerros recibe el tamaño del array listaPerros
 * @param uIdEstadia recibe el último id correspondiente a las estadías
 * @param uIdPerro recibe el último id correspondiente a los perros
 * @return retorna 0 si funcionó correctamente.
 */
int menu (sEstadia listaEstadias[], int tamEstadias , sPerro listaPerros[] , int tamPerros, sDuenio listaDuenios [], int tamDuenios , int uIdEstadia ,int uIdPerro,int uIdDuenio)
{
	int opcion;

	int auxUltimoIdPerro;
	int contadorPerros = 3; //inicializo en 3 porque había hardcodeado

	int auxUltimoIdDuenio;
	int contadorDuenios = 5; //inicializo en 5 porque había hardcodeado

	int auxUltimoIdEstadia;
	int contadorEstadias;

	int flagPerro;
	int flagDuenio;
	int flagEstadias;

	float edadPromedio;



	//int opcionSubMenu;
	//
	//int auxNuevoTelefono;
	//int idSearch;
	//int idModificacion;
	//int posicion;
	//int cancelacion;


	//int posPerroConMasEstadias;

	if (listaEstadias != NULL && listaPerros != NULL && listaDuenios != NULL)
	{
		//inicializo todos los arrays de estructuras
		perro_inicializar (listaPerros , tamPerros);
		estadia_inicializar (listaEstadias, tamEstadias);
		duenio_inicializar(listaDuenios, tamDuenios);

		//hardcodeo lo necesario
		perro_hardcodear(listaPerros);
		duenio_hardcodear (listaDuenios);


		//muestro menu de opciones y guardo la elegida en la variable "opcion"
		do
		{
			getInt (&opcion,
					"-------------------------------------------\n"
					"\n1. RESERVAR ESTADIA"
					"\n2. MODIFICAR ESTADIA"
					"\n3. CANCELAR ESTADÍA"
					"\n4. LISTAR ESTADÍAS"
					"\n5. LISTAR PERROS"
					"\n6. Promedio de edad de los perros"
					"\n7. Perro que tiene más estadias reservadas"
					"\n8. Listado de perros con sus estadías diarias reservadas"
					"\n9. SALIR"
					"\n-------------------------------------------\n"
					"Ingrese una opcion (1-9): ",
					"ERROR."
					"\n-------------------------------------------\n"
					"\n1. RESERVAR ESTADIA"
					"\n2. MODIFICAR ESTADIA"
					"\n3. CANCELAR ESTADÍA"
					"\n4. LISTAR ESTADÍAS"
					"\n5. LISTAR PERROS"
					"\n6. Promedio de edad de los perros"
					"\n7. Perro que tiene más estadias reservadas"
					"\n8. Listado de perros con sus estadías diarias reservadas"
					"\n9. SALIR"
					"\n-------------------------------------------\n"
					"Reingrese una opcion válida (1-9): ", 1 , 9);






			switch (opcion)
			{

			case 1:

				printf( "\n-------------------------------------------\n"
						"\nRESERVANDO UNA ESTADIA...\n"
						"\n-------------------------------------------\n");


				//PARA CARGAR UN PERRO
				getInt(&flagPerro,"Desea cargar un perro? (0 = no / 1 = si): ","Error. Reingrese una opcion válida (0 = no / 1 = si): ",0,1 );
				if (flagPerro == 1)
				{
					//llamo a la funcion cargar perro y el retorno (ult ID  de perro actualizado), lo guardo en auxUltimoIdPerro.
					//si es diferente a -1, recien ahí actualizo el ultimoID real y el contador de perros.
					auxUltimoIdPerro = perro_cargar (listaPerros, tamPerros, uIdPerro);
					if (auxUltimoIdPerro != -1)
					{
						uIdPerro = auxUltimoIdPerro;
						contadorPerros++;
						systemPause("\nPresione una tecla para continuar...\n");
					}

					else
					{
						printf("\nLa carga del perrro NO SE HA REALIZADO");
						systemPause("\nPresione una tecla para continuar...\n");
					}
				}


				//PARA CARGAR UN DUENIO
				getInt (&flagDuenio,"\n----------------------------------------------------------------\n"
									"\nDesea cargar un dueño? (0 = no / 1 = si): ",
									"\n----------------------------------------------------------------\n"
									"\nError. Reingrese una opción válida (0 = no / 1 = si): ", 0 , 1);

				if (flagDuenio == 1)
				{
					//si ya hay ingresado por lo menos un perro:
					//llamo a la funcion cargar duenio y el retorno (ult ID  de duenio actualizado), lo guardo en auxUltimoIdDuenio.
					//si es diferente a -1, recien ahí actualizo el ultimoID real y el contador de duenios.

					auxUltimoIdDuenio = duenio_cargar (listaDuenios, tamDuenios, uIdDuenio);
					if (auxUltimoIdDuenio != -1)
					{
						uIdDuenio = auxUltimoIdDuenio;
						contadorDuenios++;
						systemPause("\nPresione una tecla para continuar...\n");
					}

					else
					{
						printf("\nLa carga del dueño NO SE HA REALIZADO");
						systemPause("\nPresione una tecla para continuar...\n");
					}

				}



				//PARA CARGAR UNA ESTADIA

				//si ya hay ingresado por lo menos un perro y un duenio entonces:
				//llamo a la funcion reservar estadía y el retorno (ult ID  de estadía actualizado), lo guardo en auxUltimoIdEstadia.
				//si es diferente a -1, recien ahí actualizo el ultimoID real y el contador de estadías.
				if (contadorPerros > 0 && contadorDuenios > 0)
				{
					auxUltimoIdEstadia = estadia_reservar (listaEstadias, tamEstadias , uIdEstadia, listaPerros, tamPerros , listaDuenios, tamDuenios);
					if (auxUltimoIdEstadia != -1)
					{
						uIdEstadia = auxUltimoIdEstadia;
						contadorEstadias++;

						//flag = 1; //desbloqueo las otras funciones del menu
						flagEstadias = 1;
						printf("\n***Ha realizado la RESERVA exitosamente!***");
					}
				}

				else
				{
					printf("\nPara cargar una estadía debe haber cargado por lo meno un perro y un dueño antes.");
				}

				systemPause("\nPresione una tecla para continuar...\n");
			    break;




			//PARA LISTAR ESTADIAS
			case 4:

				if(flagEstadias == 1 )
				{
					//estadia_mostrarSoloEstadia(listaEstadias, tamEstadias , listaDuenios, tamDuenios);
					nexo_mostrarEstadiasCompletas (listaEstadias, tamEstadias, listaPerros, tamPerros, listaDuenios, tamDuenios);
					systemPause("\nPresione una tecla para continuar...\n");
				}
				else
				{
					printf("\nError. Para listar las estadías primero debe hacer por lo menos una reserva");
					systemPause("\nPresione una tecla para continuar...\n");
				}

				break;



			//PARA LISTAR PERROS
			case 5:
				if (contadorPerros > 0)
				{
					printf("\nListado de perros: ");
					perro_mostrarTodos(listaPerros, tamPerros);
					systemPause("\nPresione una tecla para continuar...\n");
				}
				else
				{
					printf("\nError. Debe cargar al menos un perro para poder mostrarlo\n");
					systemPause("\nPresione una tecla para continuar...\n");
				}

				break;




			//PARA EL PROMEDIO DE EDAD DE LOS PERROS
			case 6:
				if (contadorPerros > 1)
				{
					edadPromedio = perro_edadPromedio(listaPerros, tamPerros, contadorPerros);
					printf("\nLa edad promedio de los perros cargados es: %.2f\n", edadPromedio);
					systemPause("\nPresione una tecla para continuar...\n");
				}
				else
				{
					printf("\nError. Debe cargar al menos dos perros para poder calcular el promedio\n");
					systemPause("\nPresione una tecla para continuar...\n");
				}

				break;




			case 8:

				if (flagEstadias == 1 && contadorPerros > 0)
				{
					//Listado de perros con sus estadías diarias reservadas.
					nexo_mostrarPerrosConEstadias (listaPerros, tamPerros, listaEstadias ,  tamEstadias);
					systemPause("\nPresione una tecla para continuar...\n");
				}

				else
				{
					printf("Error. No se pueden mostrar los perros con sus estadías sin haber cargado los datos previamente");
					systemPause("\nPresione una tecla para continuar...\n");
				}

				break;
			}














			/*
			case 2:
					if (flagEstadias == 1 )
					{
					printf("\nModificando la estadía...\n");
					estadia_mostrarSoloEstadia(listaEstadias, tamEstadias, listaDuenios, tamDuenios);
					printf("\n\nIngrese el ID de la ESTADIA a modificar: ");
					fflush(stdin);
					scanf("%d", &idSearch);
					while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
					{
						printf("\nError. Reingrese el un ID existente: ");
						fflush(stdin);
						scanf("%d", &idSearch);
					}

					posicion = estadia_buscarCoincidenciaId2 (listaEstadias , tamEstadias, idSearch);

						do
						{
						getInt (&opcionSubMenu,
												"\nMENU DE MODIFICACIONES"
												"\n--------------------------\n"
												"\n1. TELEFONO DE CONTACTO"
												"\n2. PERRO"
												"\n3. SALIR"
												"\n--------------------------\n"
												"Ingrese una opción (1-3): ",
												"\n--------------------------\n"
												"\n1. TELEFONO DE CONTACTO"
												"\n2. PERRO"
												"\n3. SALIR"
												"\n--------------------------\n"
												"Error. Reingrese una opción válida (1-3): " , 1 , 3);

							switch (opcionSubMenu)
							{
							case 1:
									printf("\nModificando el teléfono de contacto...\n");
									auxNuevoTelefono = estadia_modificar (1);
									if (auxNuevoTelefono != -1)
									{
										listaDuenios[posicion].telefono = auxNuevoTelefono;
										//listaEstadias[posicion].telefonoContacto = auxNuevoTelefono;
										printf("\nHa modificado el NUEVO TELEFONO exitosamente!\n");
										system("pause");
									}

									else
									{
										printf("\nHa cancelado la modificación del nuevo telefono.\n");
										system("pause");
									}
									break;



							case 2:
									printf("\nModificando el perro...\n");
									if (posicion != -1)
									{
										idModificacion = listaPerros[posicion].id;
										perro_modificar(listaPerros, tamPerros, posicion , idModificacion);
										printf("\nHa modificado el PERRO exitosamente!\n");
										system("pause");
									}
									else
									{
										printf("\nNo fue posible encontrar el perro solicitado.\n");
									}

									break;

							case 3:
									printf("\nVolviendo al menú principal...\n");
									break;
							}


						}while (opcionSubMenu != 3);
					}
					else
					{
						printf("\nError. Para acceder a las funciones primero debe hacer una reserva!\n");
					}

					break;

			case 3:

				if( flagEstadia == 1 )
				{
					printf("\nCancelando estadía...\n");
					estadia_mostrarSoloEstadia(listaEstadias, tamEstadias, listaDuenios, tamDuenios);

					printf("\n\nIngrese el ID de la ESTADIA a cancelar: ");
					fflush(stdin);
					scanf("%d", &idSearch);
					while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
					{
						printf("\nError. Reingrese el un ID existente: ");
						fflush(stdin);
						scanf("%d", &idSearch);
					}

					cancelacion = estadia_cancelar(listaPerros, tamPerros, listaEstadias, tamEstadias, listaDuenios, tamDuenios, idSearch);
					if (cancelacion != -1)
					{
						contadorPerros--;
						contadorDuenios--;
						contadorEstadias--;
						printf("\nHa CANCELADO la estadía exitosamente!\n");
						system("pause");
					}

					else
					{
						printf("\nError. No se ha podido cancelar la estadía.\n");
						system("pause");
					}
				}
				else
				{
					printf("\nError. Para acceder a las funciones primero debe hacer una reserva\n");
				}

				break;*/





			/*








			case 7:
					if (flagEstadias == 1 && contadorPerros > 0)
					{

						//Perro que tiene más estadias reservadas
						posPerroConMasEstadias = perro_encontrarMayorCantidadEstadias (listaPerros, tamPerros);
						printf("El perro que más estadías tiene es...\n");
						perro_mostrar(listaPerros[posPerroConMasEstadias]);
						system("pause");
					}

					else
					{
						printf("\nError. No se puede calcular el perro con más estadías porque debe haber por lo menos un perro y una estadía cargada");
						system("pause");
					}


					break;






			case 9:
					printf("\nSaliendo...\n");
					break;

			}*/

		}while (opcion != 9);
	}

	return 0;
}

