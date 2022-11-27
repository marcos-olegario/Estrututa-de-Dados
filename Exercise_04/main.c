#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"

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

int get_id(const char *opr){

    if (strcmp(opr, "soma") == 0) return 1; 
    if (strcmp(opr, "igual") == 0) return 2;
    if (strcmp(opr, "maior") == 0) return 3;
    if (strcmp(opr, "menor") == 0) return 4;
    return -32000;
}

int main(){

    int n; // Número de operações
    int id_opr; // Id de cada operação

    char *opr; // Operação escolhida
    char *number1; // String com o número 1
    char *number2; // String com o número 2
    char *line; // Conteúdo da leitura da linha
    
    BIGNUMBER *bignumber1;
    BIGNUMBER *bignumber2;

    scanf("%d\n", &n);

    for(int i=0; i<n; i++){

        line = readLine();

        opr = strtok(line, " ");
        number1 = strtok(NULL, " ");
        number2 = strtok(NULL, " ");
        id_opr = get_id(opr);

        bignumber1 = create_bignumber(reverse_number(number1));
        bignumber2 = create_bignumber(reverse_number(number2));

        switch (id_opr){

            case 1: {
                BIGNUMBER *resutado_soma = sum_bignumbers(bignumber1, bignumber2);
                print_bignumber(resutado_soma);
                break;
            } 
            case 2: {
                print_bool(equal_to(bignumber1, bignumber2));
                break;
            } 
            case 3: {
                print_bool(more_than(bignumber1, bignumber2));
                break;
            }
            case 4: {
                print_bool(less_than(bignumber1, bignumber2));
            }
        }

    }

    del_bignumber(bignumber1);
    del_bignumber(bignumber2);

    return(0);
}
