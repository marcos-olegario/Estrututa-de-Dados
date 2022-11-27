#include "catalogo.h"
#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct catalogo_{
    JOGO **jogos;
    int totalJogos;
};

void adicionar_ao_catalogo(CATALOGO *catalogo, JOGO *novo_jogo, int count){
    catalogo->jogos = (JOGO**) realloc(catalogo->jogos, count * sizeof(JOGO**));

    catalogo->jogos[count-1] = novo_jogo;
    catalogo->totalJogos++;
}

CATALOGO *criar_catalogo(int tamanho_inicial){
    CATALOGO *novo_catalogo = (CATALOGO*) malloc(tamanho_inicial);

    novo_catalogo->totalJogos = 0;
    novo_catalogo->jogos = NULL;

    return novo_catalogo;
}

void busca_por_ano(CATALOGO *catalogo, int ano){
  // iterador local:
  int busca = 0;

  for(int i=0; i<catalogo->totalJogos; i++){
      if (jogo_ano(catalogo->jogos[i]) == ano){
          busca = 1;
          printf("%s \n", jogo_nome(catalogo->jogos[i]));
      }
  }
  if (busca == 0){
      printf("Nada encontrado\n");
  }
}

void busca_por_empresa(CATALOGO *catalogo, char *empresa) {
    // iterador local:
    int busca = 0;

    for (int i = 0; i < catalogo->totalJogos; i++) {

        if(strcmp(jogo_empresa(catalogo->jogos[i]),empresa) == 0){
            busca = 1;
            printf("%s \n", jogo_nome(catalogo->jogos[i]));
        }
    }
    if (busca == 0) {
        printf("Nada encontrado\n");
    }
}

void deletar_catalogo(CATALOGO *catalogo){
    for (int i = 0; i < catalogo->totalJogos; i++) {
        apagar_jogo(catalogo->jogos[i]);
    }
    free(catalogo->jogos);
    free(catalogo);
}

//Função usada apenas para testes
/*
JOGO *get_jogo(CATALOGO *catalogo, int pos){
    return catalogo->jogos[pos];
}*/
