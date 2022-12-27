#ifndef UTIL_H
#define UTIL_H

#define TRUE 1
#define FALSE 0
typedef int boolean;

//#include "binarytree.h"
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readLine();
char* read_info();

int get_id(const char *opr);
long int cpf_to_int(const char *cpf);

#endif //UTIL_H
