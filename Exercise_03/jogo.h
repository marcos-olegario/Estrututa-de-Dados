#ifndef JOGO_H
#define JOGO_H

typedef struct jogo_ JOGO;

JOGO *criar_jogo(char *nome, char *empresa, int ano);
int jogo_ano(JOGO *jogo);
char *jogo_nome(JOGO *jogo);
char *jogo_empresa(JOGO *jogo);
void apagar_jogo(JOGO *jogo);

// void print_jogo(JOGO *jogo); //Função usada apenas para testes

#endif //JOGO_H
