#include "cliente.h"
#include "binarytree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct client_{

	char *name;
	char *cpf;
	char *balance;
	char *age;

	long int cpf_num;

};

CLIENT *create_client(){

	CLIENT *client = (CLIENT *) malloc(sizeof(CLIENT));
	char *nome;
	char *idade;
	char *saldo;
	char *cpf_str;

	if (client != NULL){

	    cpf_str = read_info();
		nome = read_info();
	    idade = read_info();
	    saldo = read_info();

		client->name = nome;
		client->age = idade;
		client->balance = saldo;

		client->cpf = cpf_str;
		client->cpf_num = cpf_to_int(cpf_str);
	
		return client;
	}
	return NULL;
}

void remove_client(CLIENT **cliente){
    free((*cliente)->cpf);
    (*cliente)->cpf = NULL;

    free((*cliente)->name);
    (*cliente)->name = NULL;
    
    free((*cliente)->age);
    (*cliente)->age = NULL;
    
    free((*cliente)->balance);
    (*cliente)->balance = NULL;

    (*cliente)->cpf_num = 0;

    return;
}

void print_client(CLIENT *cliente){
	printf("Conta :: %s\n", cliente->name);
	printf("CPF :: %s\n", cliente->cpf);	
	printf("Idade :: %s\n", cliente->age);
	printf("Saldo atual :: R$ %s\n", cliente->balance);
}

long int give_cpf(CLIENT *cliente){
	return cliente->cpf_num;
}
