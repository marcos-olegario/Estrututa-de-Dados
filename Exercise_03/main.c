#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#include <stdbool.h> n sei se precisa
#include "jogo.h"
#include "catalogo.h"

char *readLine() {
    char *string = NULL;
    char currentInput;
    int index = 0;
    do {
        currentInput = (char)getchar();
        string = (char *) realloc(string, sizeof(char) * (index + 1));
        string[index] = currentInput;
        index++;
        if(currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    } while((currentInput != '\n') && (currentInput != EOF));
    string[index - 1] = '\0';
    return string;
}

void consome_char(){
    char c;
    c = (char)getchar();

    if (c == '\r'){
        getchar();
    }
}

int main(){

    //Quantidade de jogos cadastrados:
    int count = 0;

    //Variável auxiliar de entrada de texto:
    char *entrada;

    // Inicialmente criamos um catálogo:

    CATALOGO *catalogo;
    catalogo = criar_catalogo(100);

    // Em seguida, realizamos as leituras para cadastrar jogos:
    char *nome_jogo;
    do {
        nome_jogo = readLine();
        if (strcmp(nome_jogo, "F") == 0) continue;
        char *empresa = readLine();
        int ano;

        scanf("%i\n", &ano);
        //consome_char();

        count++;

        JOGO *novo_jogo = criar_jogo(nome_jogo, empresa, ano);
        adicionar_ao_catalogo(catalogo, novo_jogo, count);

    } while(strcmp(nome_jogo, "F") != 0);

    // Depois, realizamos as buscas desejadas:
    entrada = readLine();
    while(strcmp(entrada, "F") != 0){

        if(strcmp(entrada, "A") == 0) {
            int ano;
            scanf("%i", &ano);
            consome_char();

            // busca por ano
            busca_por_ano(catalogo, ano);
        }
        else if(strcmp(entrada, "E") == 0){
            char *empresa = readLine();

            //busca por empresa
            busca_por_empresa(catalogo, empresa);
            free(empresa);
        }
        entrada = readLine();
    }

    //Função usada apenas para testes
    /*
    for (int i=0; i<=count;i++){
        print_jogo(get_jogo(catalogo, i));
    }*/

    free(entrada);
    deletar_catalogo(catalogo);

    return 0;
}