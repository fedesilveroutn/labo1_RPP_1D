
#include "menu.h"
#include "perro.h"
#include "estadia.h"
#include "duenio.h"

/**
 * @fn int menu(sEstadia[], int, sPerro[], int, int, int)
 * @brief contiene la l�gica del programa, muestra los menus de opciones y sus distintos posibles flujos
 *
 * @param listaEstadias recibe un array de sEstadia
 * @param tamEstadias recibe el tama�o del array listaEstadia
 * @param listaPerros recibe un array de sPerro
 * @param tamPerros recibe el tama�o del array listaPerros
 * @param uIdEstadia recibe el �ltimo id correspondiente a las estad�as
 * @param uIdPerro recibe el �ltimo id correspondiente a los perros
 * @return retorna 0 si funcion� correctamente.
 */
int menu (sEstadia listaEstadias[], int tamEstadias , sPerro listaPerros[] , int tamPerros, sDuenio listaDuenios [], int tamDuenios , int uIdEstadia ,int uIdPerro,int uIdDuenio)
{
	int opcion;

	int auxUltimoIdPerro;
	int contadorPerros = 3; //inicializo en 3 porque hab�a hardcodeado

	int auxUltimoIdDuenio;
	int contadorDuenios = 5; //inicializo en 5 porque hab�a hardcodeado

	int auxUltimoIdEstadia;
	int contadorEstadias = 0;

	int flagPerro;
	int flagDuenio;
	int flagEstadias;

	float edadPromedio;

	int idSearch;
	int cancelacion;

	int posicion;
	int opcionSubMenu;
	int auxNuevoTelefono;
	int nuevoIdPerro;
	int posNuevoIdPerro;
	int respuestaNuevoPerro;
	sPerro auxNuevoPerro;


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
					"\n3. CANCELAR ESTAD�A"
					"\n4. LISTAR ESTAD�AS"
					"\n5. LISTAR PERROS"
					"\n6. Promedio de edad de los perros"
					"\n7. Perro que tiene m�s estadias reservadas"
					"\n8. Listado de perros con sus estad�as diarias reservadas"
					"\n9. SALIR"
					"\n-------------------------------------------\n"
					"Ingrese una opcion (1-9): ",
					"ERROR."
					"\n-------------------------------------------\n"
					"\n1. RESERVAR ESTADIA"
					"\n2. MODIFICAR ESTADIA"
					"\n3. CANCELAR ESTAD�A"
					"\n4. LISTAR ESTAD�AS"
					"\n5. LISTAR PERROS"
					"\n6. Promedio de edad de los perros"
					"\n7. Perro que tiene m�s estadias reservadas"
					"\n8. Listado de perros con sus estad�as diarias reservadas"
					"\n9. SALIR"
					"\n-------------------------------------------\n"
					"Reingrese una opcion v�lida (1-9): ", 1 , 9);



			switch (opcion)
			{

			case 1:

				printf( "\n-------------------------------------------\n"
						"\nRESERVANDO UNA ESTADIA...\n"
						"\n-------------------------------------------\n");


				//PARA CARGAR UN PERRO
				getInt(&flagPerro,"Desea cargar un perro? (0 = no / 1 = si): ","Error. Reingrese una opcion v�lida (0 = no / 1 = si): ",0,1 );
				if (flagPerro == 1)
				{
					//llamo a la funcion cargar perro y el retorno (ult ID  de perro actualizado), lo guardo en auxUltimoIdPerro.
					//si es diferente a -1, recien ah� actualizo el ultimoID real y el contador de perros.
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
									"\nDesea cargar un due�o? (0 = no / 1 = si): ",
									"\n----------------------------------------------------------------\n"
									"\nError. Reingrese una opci�n v�lida (0 = no / 1 = si): ", 0 , 1);

				if (flagDuenio == 1)
				{
					//si ya hay ingresado por lo menos un perro:
					//llamo a la funcion cargar duenio y el retorno (ult ID  de duenio actualizado), lo guardo en auxUltimoIdDuenio.
					//si es diferente a -1, recien ah� actualizo el ultimoID real y el contador de duenios.

					auxUltimoIdDuenio = duenio_cargar (listaDuenios, tamDuenios, uIdDuenio);
					if (auxUltimoIdDuenio != -1)
					{
						uIdDuenio = auxUltimoIdDuenio;
						contadorDuenios++;
						systemPause("\nPresione una tecla para continuar...\n");
					}

					else
					{
						printf("\nLa carga del due�o NO SE HA REALIZADO");
						systemPause("\nPresione una tecla para continuar...\n");
					}

				}



				//PARA CARGAR UNA ESTADIA

				//si ya hay ingresado por lo menos un perro y un duenio entonces:
				//llamo a la funcion reservar estad�a y el retorno (ult ID  de estad�a actualizado), lo guardo en auxUltimoIdEstadia.
				//si es diferente a -1, recien ah� actualizo el ultimoID real y el contador de estad�as.
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
					printf("\nPara cargar una estad�a debe haber cargado por lo meno un perro y un due�o antes.");
				}

				systemPause("\nPresione una tecla para continuar...\n");
			    break;




			//PARA MODIFICAR UNA ESTADIA
			case 2:

				if (flagEstadias == 1 && contadorEstadias > 0)
				{
					printf("\nModificando la estad�a...\n");
					nexo_mostrarEstadiasCompletas(listaEstadias, tamEstadias, listaPerros, tamPerros, listaDuenios, tamDuenios);
					getInt(&idSearch, "\nIngrese el ID de la ESTADIA a modificar: ", "Error. Reingrese un ID ESTADIA v�lido: ", 100000, 199999);
					while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
					{
						getInt(&idSearch, "\nIngrese el ID de la ESTADIA a modificar: ", "Error. Reingrese un ID ESTADIA v�lido: ", 100000, 199999);
					}

					posicion = estadia_buscarCoincidenciaId2 (listaEstadias , tamEstadias, idSearch);
					if (posicion != -1)
					{
						do
						{
							getInt (&opcionSubMenu,
												"\nMENU DE MODIFICACIONES"
												"\n--------------------------\n"
												"\n1. TELEFONO DE CONTACTO"
												"\n2. PERRO"
												"\n3. SALIR"
												"\n--------------------------\n"
												"Ingrese una opci�n (1-3): ",
												"\n--------------------------\n"
												"\n1. TELEFONO DE CONTACTO"
												"\n2. PERRO"
												"\n3. SALIR"
												"\n--------------------------\n"
												"Error. Reingrese una opci�n v�lida (1-3): " , 1 , 3);

									switch (opcionSubMenu)
									{
									case 1:

										printf("\nModificando el tel�fono de contacto...\n");

										auxNuevoTelefono = estadia_modificar (1);
										if (auxNuevoTelefono != -1)
										{
											listaDuenios[posicion].telefono = auxNuevoTelefono;
											printf("\nHa modificado el NUEVO TELEFONO exitosamente!\n");
											systemPause("\nPresione una tecla para continuar...\n");
										}

										else
										{
											printf("\nHa cancelado la modificaci�n del nuevo telefono.\n");
											systemPause("\nPresione una tecla para continuar...\n");
										}
										break;


									case 2:

										printf("\nModificando el perro...\n");
										if (posicion != -1)
										{
											perro_mostrarTodos(listaPerros, tamPerros);
											getInt(&nuevoIdPerro, "\nIngrese el ID DEL PERRO que quiere asociar a la estad�a: ",
																  "\nError. Reingrese un ID PERRO v�lido: ", 7000 , 10000);
											posNuevoIdPerro = perro_buscarCoincidenciaId(listaPerros, tamPerros, nuevoIdPerro);
											auxNuevoPerro = listaPerros[posNuevoIdPerro];
											respuestaNuevoPerro =  perro_verificar(auxNuevoPerro);

											if (respuestaNuevoPerro == 1)
											{
												listaEstadias[posicion].idPerro = nuevoIdPerro;
												printf("\nHa modificado el PERRO exitosamente!\n");
												systemPause("\nPresione una tecla para continuar...\n");
											}
											else
											{
												printf("\nHa cancelado la modificaci�n del perro.");
												systemPause("\nPresione una tecla para continuar...\n");
											}

										}
										else
										{
											printf("\nNo fue posible encontrar el perro solicitado.\n");
										}
										break;


									case 3:

										printf("\nVolviendo al men� principal...\n");
										break;
									}

							}while (opcionSubMenu != 3);

						}

						else
						{
							printf("Error. El ID ingresado no coincide con ninguno.");
						}


					}
					else
					{
						printf("\nError. Para acceder a las funciones primero debe hacer una reserva!\n");
					}

					break;


			case 3:

				if( flagEstadias == 1 && contadorEstadias > 0)
				{
					printf("\nCancelando estad�a...\n");

					nexo_mostrarEstadiasCompletas(listaEstadias, tamEstadias, listaPerros, tamPerros, listaDuenios, tamDuenios);
					getInt(&idSearch, "\nIngrese el ID de la ESTADIA a cancelar: ", "\nError. Reingrese el un ID existente: ", 100000,199999);
					while ( estadia_buscarExistenciaId (listaEstadias , tamEstadias , idSearch) == -1)
					{
						printf("\nError. El ID ingresado no coincide con ninguno.");
						getInt(&idSearch, "\nIngrese el ID de la ESTADIA a cancelar: ", "\nError. Reingrese el un ID existente: ", 100000,199999);

					}

					cancelacion = estadia_cancelar(listaPerros, tamPerros, listaEstadias, tamEstadias, listaDuenios, tamDuenios, idSearch);
					if (cancelacion == 0)
					{
						contadorEstadias--;
						printf("\nHa CANCELADO la estad�a exitosamente!\n");
						systemPause("\nPresione una tecla para continuar...\n");
					}

					else
					{
						printf("\nError. No se ha podido cancelar la estad�a.\n");
						systemPause("\nPresione una tecla para continuar...\n");
					}
				}
				else
				{
					printf("\nError. Para acceder a las funciones primero debe hacer una reserva\n");
				}

				break;


			//PARA LISTAR ESTADIAS
			case 4:

				if(flagEstadias == 1 && contadorEstadias > 0)
				{
					//estadia_mostrarSoloEstadia(listaEstadias, tamEstadias , listaDuenios, tamDuenios);
					nexo_mostrarEstadiasCompletas (listaEstadias, tamEstadias, listaPerros, tamPerros, listaDuenios, tamDuenios);
					systemPause("\nPresione una tecla para continuar...\n");
				}
				else
				{
					printf("\nError. Para listar las estad�as primero debe hacer por lo menos una reserva");
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



			//PARA LISTAR PERROS CON SUS ESTADIAS DIARIAS RESERVADAS
			case 8:

				if (flagEstadias == 1 && contadorPerros > 0)
				{
					//Listado de perros con sus estad�as diarias reservadas.
					nexo_mostrarPerrosConEstadias (listaPerros, tamPerros, listaEstadias ,  tamEstadias);
					systemPause("\nPresione una tecla para continuar...\n");
				}

				else
				{
					printf("Error. No se pueden mostrar los perros con sus estad�as sin haber cargado los datos previamente");
					systemPause("\nPresione una tecla para continuar...\n");
				}

				break;
			}



















			/*








			case 7:
					if (flagEstadias == 1 && contadorPerros > 0)
					{

						//Perro que tiene m�s estadias reservadas
						posPerroConMasEstadias = perro_encontrarMayorCantidadEstadias (listaPerros, tamPerros);
						printf("El perro que m�s estad�as tiene es...\n");
						perro_mostrar(listaPerros[posPerroConMasEstadias]);
						system("pause");
					}

					else
					{
						printf("\nError. No se puede calcular el perro con m�s estad�as porque debe haber por lo menos un perro y una estad�a cargada");
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

