
#ifndef INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_H_

int getInt (int* num, char* message, char* errorMessage, int min, int max);
int getFloat (float* num, char* message, char* errorMessage, int min, int max);
void getString (char* string, char* message, char* errorMessage, int max);
int systemPause(char* message);

#endif /* INPUT_H_ */
