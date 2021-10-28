
#include <string.h>
#include "input.h"

/**
 * @fn int getInt(int*, char*, char*, int, int)
 * @brief pide un entero y valida que se encuentre en el rango indicado
 *
 * @param num int* recibe la direcci�n de memoria en donde se guardar� el entero solicitado
 * @param message char* recibe un literal con el mensaje de petici�n de un entero para ser mostrado al usuario
 * @param errorMessage char* recibe un literal con el mensaje de error
 * @param min int recibe el n�mero minimo posible
 * @param max int recibe el n�mero m�ximo posible
 * @return 0 si funcion� correctamente, retorna -1 si hubo un error
 */
int getInt (int* num, char* message, char* errorMessage, int min, int max)
{
	int ret = -1;
	int enteredNum;

	if(num != NULL && message != NULL && errorMessage != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enteredNum);
		while(enteredNum < min || enteredNum > max)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enteredNum);
		}
		*num = enteredNum;
		ret = 0;
	}
	return ret;
}

/**
 * @fn int getFloat(float*, char*, char*, int, int)
 * @brief pide el ingrese de un n�mero flotante y lo valida en el rango indicado
 *
 * @param num float* recibe la direcci�n de memoria en donde se guardar� el flotante solicitado
 * @param message char* recibe un literal con el mensaje de petici�n de un entero para ser mostrado al usuario
 * @param errorMessage char* recibe un literal con el mensaje de error
 * @param min int recibe el n�mero minimo posible
 * @param max int recibe el n�mero m�ximo posible
 * @return 0 si funcion� correctamente, retorna -1 si hubo un error
 */
int getFloat(float* num, char* message, char* errorMessage, int min, int max)
{
	int ret = -1;
	float enteredNum;

	if (num != NULL && message && errorMessage != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%f", &enteredNum);
		while(enteredNum < min || enteredNum > max)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%f", &enteredNum);
		}
		*num = enteredNum;
		ret = 0;
	}
	return ret;
}

/**
 * @fn void getString(char*, char*, char*, int)
 * @brief pide el ingrese de una cadena de caracteres y valida que no sea mayor al m�ximo permitido
 *
 * @param string char* recibe la direcci�n de memoria en donde se guardar� la cadena de caracateres validada
 * @param message char* recibe un literal con el mensaje de petici�n de un entero para ser mostrado al usuario
 * @param errorMessage char* recibe un literal con el mensaje de error
 * @param max int recibe el mayor n�mero de caracteres aceptados
 */
void getString (char* string, char* message, char* errorMessage, int max)
{
	char unvalidatedString[200];
	int tam;

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", unvalidatedString);
	tam = strlen (unvalidatedString);
	while (tam > max)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%[^\n]", unvalidatedString);
		tam = strlen (unvalidatedString);
	}
	strcpy (string, unvalidatedString);
}

/**
 * @fn int systemPause(char*)
 * @brief pausa la ejecucion del programa momentaneamente hasta que el usuario presione alguna tecla
 *
 * @param message recibe un mensaje para ser mostrado al usuario
 * @return retonra 0 si funcion� y -1 si hubo error
 */
int systemPause(char* message)
{
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}
