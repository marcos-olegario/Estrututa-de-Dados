#include "jogo.h"
#include "catalogo.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

struct jogo_{
    char *nome_jogo;
    char *empresa;
    int ano;
};

JOGO *criar_jogo(char *nome, char *empresa, int ano){
    JOGO *novo_jogo = (JOGO*) calloc(1, sizeof(JOGO));

    novo_jogo->empresa = (char*) malloc(sizeof(char)*(*empresa));
    novo_jogo->nome_jogo = (char*) malloc(sizeof(char) * (*nome));

    strcpy(novo_jogo->nome_jogo, nome);
    strcpy(novo_jogo->empresa, empresa);
    novo_jogo->ano = ano;

    return novo_jogo;
}

int jogo_ano(JOGO *jogo){
    return jogo->ano;
}

char *jogo_nome(JOGO *jogo){
    return jogo->nome_jogo;
}

char *jogo_empresa(JOGO *jogo) {
    return jogo->empresa;
}

void apagar_jogo(JOGO *jogo){
    free(jogo->nome_jogo);
    free(jogo->empresa);
    free(jogo);
}

//Função usada apenas para testes
/*
void print_jogo(JOGO *jogo){
    printf("Nome do jogo: %s\n", jogo->nome_jogo);
    printf("Empresa produtora: %s\n", jogo->empresa);
    printf("Ano de lançamento: %i\n", jogo->ano);
}*/