//
// Created by marcos on 22/09/22.
//

#ifndef CATALOGO_H
#define CATALOGO_H
#include "jogo.h"

#define TRUE 1
#define FALSE 0
#define boolean char

typedef struct catalogo_ CATALOGO;

CATALOGO *criar_catalogo(int tamanho_inicial);
void adicionar_ao_catalogo(CATALOGO *catalogo, JOGO *novo_jogo, int count);
void busca_por_ano(CATALOGO *catalogo, int ano);
void busca_por_empresa(CATALOGO *catalogo, char *empresa);
void deletar_catalogo(CATALOGO *catalogo);

//JOGO *get_jogo(CATALOGO *catalogo, int pos); //Função usada apenas para testes

#endif //CATALOGO_H
