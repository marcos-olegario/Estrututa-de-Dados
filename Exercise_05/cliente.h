#ifndef CLIENTE_H
#define CLIENTE_H

#include "util.h"

typedef struct client_ CLIENT;

CLIENT *create_client();
void remove_client(CLIENT **cliente);
void print_client(CLIENT *cliente);
long int give_cpf(CLIENT *cliente);

#endif //CLIENTE_H
