#include "bignumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_{
    int algorism;
    NODE *prev;
    NODE *next;
};

struct bignumber_{
    NODE *first;
    NODE *end;
    int size;
    int signal; // Sinal do número: 1 = positivo; 0 = negativo
};

// Máximo 2 números:
int max(int a, int b){
    if (a>b){
        return a;
    } else{
        return b;
    }
}

char *reverse_number(const char *number){
    
    char *new_number = (char*) malloc(strlen(number) + 1);
    
    for(int i=0; i<strlen(number); i++){
        
        new_number[i] = number[strlen(number) -1 - i];
    }
    
    new_number[strlen(number)] = '\0';
    
    return(new_number);
}

BIGNUMBER *create_bignumber(const char *str_input){

    // Variáveis auxiliares para a iteração:
    int tam = strlen(str_input);
    int sign; // Variável auxiliar que guarda o sinal
    
    char *number_str = (char*) malloc(tam+1);
    char *str = (char*) malloc(tam);

    strcpy(str, str_input);

    // Verifica o sinal:
    if (str[tam-1] == '-'){

        number_str = (char*) realloc(number_str, tam);

        number_str = strtok(str, "-");
        number_str[tam-1] = '\0'; 

        tam--;
        sign = 0;
    
    } else{
        
        // Cria uma cópia da entrada:
        strcpy(number_str, str);

        sign = 1;
    }


    // Define e separa memória para o bignumber:
    BIGNUMBER *number = (BIGNUMBER *) malloc(sizeof(BIGNUMBER));

    if (number != NULL) {
        number->first = NULL;
        number->end = NULL;
        number->size = 0;

        // Acrescenta o sinal:
        if (sign == 0){
            number->signal = 0;
        } else{
            number->signal = 1;
        }
    }

    // Preenche ele com os seus algorismos:
    for (int i = 0; i < tam; i++){
    
    	NODE *pnew = (NODE *) malloc(sizeof(NODE));
        pnew->algorism = (int)number_str[i] - 48;
    	
    	if (number->first == NULL){
    	   
    		number->first = pnew;
            pnew->prev = NULL;
    		
    	} else{
    	
    		number->end->next = pnew;
            pnew->prev = number->end;

    	}
        pnew->next = NULL;
    	number->end = pnew;
    	number->size += 1;
    }
    

    //free(number_str);
    //free(str);

    return (number);
}

// Para soma, iremos definir primeiramente duas funções:
// soma de números com mesmo sinal e sinais diferentes.

char *sum_same_sign(BIGNUMBER *number1, BIGNUMBER *number2, int sign){

    int carry = 0;
    int result_aux;
    int count = 0;

    // Crio uma string para armazenar o valor da soma:
    char *result = (char *) malloc(max(number1->size, number2->size)+1);

    NODE *numberPart1 = number1->first;
    NODE *numberPart2 = number2->first;

    while ((numberPart1 != NULL) && (numberPart2 != NULL)){

       	result_aux = carry + numberPart1->algorism + numberPart2->algorism;

        if (result_aux < 10){

            result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;
            numberPart2 = numberPart2->next;

            carry = 0;
        
        } else{

            result_aux = result_aux - 10;
			result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;
            numberPart2 = numberPart2->next;

            carry = 1;

        }

        count++;
    }

    while (numberPart1 != NULL){

       	result_aux = carry + numberPart1->algorism;

        if (result_aux < 10){

            result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;

            carry = 0;
        
        } else{

            result_aux = result_aux - 10;
			result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;

            carry = 1;

        }

        count++;
    }

    while (numberPart2 != NULL){

       	result_aux = carry + numberPart2->algorism;

        if (result_aux < 10){

            result[count] = result_aux + '0';

            numberPart2 = numberPart2->next;

            carry = 0;
        
        } else{

            result_aux = result_aux - 10;
			result[count] = result_aux + '0';

            numberPart2 = numberPart2->next;

            carry = 1;

        }

        count++;
    }

    if (carry != 0){

    	if (sign == 0){
    		result = realloc(result, max(number1->size, number2->size)+3);

    		result[count] = '1';
    		result[count+1] = '-';
	    	result[count+2] = '\0';

    	} else{
    		result = realloc(result, max(number1->size, number2->size)+2);

    		result[count] = '1';
    		result[count+1] = '\0';
    	}

    	count++;

    } else{

    	if (sign == 0){
    		result = realloc(result, max(number1->size, number2->size)+2);

    		result[count] = '-';
	    	result[count+1] = '\0';

    	} else{

    		result[count] = '\0';
    	}
    }

    return(result);
}

char *sum_dif_sign(BIGNUMBER *number1, BIGNUMBER *number2){

    int carry = 0;
    int result_aux;
    int count = 0;

    int sign; // Sinal do maior número


    // Crio uma string para armazenar o valor da soma:
    char *result = (char *) malloc(max(number1->size, number2->size)+1);

    NODE *numberPart1 = number1->first;
    NODE *numberPart2 = number2->first;

    while ((numberPart1 != NULL) && (numberPart2 != NULL)){

        if (more_than(bignumber_abs(number1), bignumber_abs(number2)) == 1){
            result_aux = numberPart1->algorism - numberPart2->algorism - carry;
            sign = number1->signal;

        } else{
            result_aux = numberPart2->algorism - numberPart1->algorism - carry;
            sign = number2->signal;
        }
        
        if (result_aux < 0){

            result_aux = result_aux + 10;
            result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;
            numberPart2 = numberPart2->next;

            carry = 1;
        
        } else{

            result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;
            numberPart2 = numberPart2->next;

            carry = 0;

        }

        count++;
    }

    while (numberPart1 != NULL){

        result_aux = numberPart1->algorism - carry;

        if (result_aux < 0){

            result_aux = result_aux + 10;
            result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;

            carry = 1;
        
        } else{

            result[count] = result_aux + '0';

            numberPart1 = numberPart1->next;

            carry = 0;

        }

        count++;
    }

    while (numberPart2 != NULL){

        result_aux = numberPart2->algorism - carry;

        if (result_aux < 0){

            result_aux = result_aux + 10;
            result[count] = result_aux + '0';

            numberPart2 = numberPart2->next;

            carry = 1;
        
        } else{

            result[count] = result_aux + '0';

            numberPart2 = numberPart2->next;

            carry = 0;

        }

        count++;
    }

    if (carry != 0){

        if (sign == 0){
            result = realloc(result, max(number1->size, number2->size)+3);

            result[count] = '1';
            result[count+1] = '-';
            result[count+2] = '\0';

        } else{
            result = realloc(result, max(number1->size, number2->size)+2);

            result[count] = '1';
            result[count+1] = '\0';
        }

        count++;

    } else{

        if (sign == 0){
            result = realloc(result, max(number1->size, number2->size)+2);

            result[count] = '-';
            result[count+1] = '\0';

        } else{

            result[count] = '\0';
        }
    }

    return(result);
}


BIGNUMBER *sum_bignumbers(BIGNUMBER *number1, BIGNUMBER *number2){

    BIGNUMBER *result_sum = (BIGNUMBER *) malloc(sizeof(BIGNUMBER));

    if (number1->signal == number2->signal){

        if (number1->signal == 1){
            
            result_sum = create_bignumber(sum_same_sign(number1, number2, 1));
            return result_sum;
        
        } else{
            
            result_sum = create_bignumber(sum_same_sign(number1, number2, 0));
            return result_sum;

        }

    } else{

        result_sum = create_bignumber(sum_dif_sign(number1, number2));
        return result_sum;

    }

}


boolean equal_to(BIGNUMBER *number1, BIGNUMBER *number2){

    if (number1->size != number2->size) return FALSE;

    // Crio nós para percorrer os bignumbers:
    NODE *numberPart1 = number1->first;
    NODE *numberPart2 = number2->first;

    while (numberPart1 != NULL && numberPart2 != NULL){

        if (numberPart1->algorism != numberPart2->algorism) return FALSE;

        numberPart1 = numberPart1->next;
        numberPart2 = numberPart2->next;

    }

    return TRUE;

}

boolean more_than(BIGNUMBER *number1, BIGNUMBER *number2){

	if (number1->signal > number2->signal) return TRUE;
	if (number1->signal < number2->signal) return FALSE;

	if (number1->signal == 1){

		if (number1->size > number2->size) return TRUE;
		if (number1->size < number2->size) return FALSE;
	
	} else{

		if (number1->size < number2->size) return TRUE;
		if (number1->size > number2->size) return FALSE;

	}

    // Crio nós para percorrer os bignumbers:
    NODE *numberPart1 = number1->end;
    NODE *numberPart2 = number2->end;

	for (int i=0; i<number1->size; i++){

        if (numberPart1->algorism < numberPart2->algorism) return FALSE;
        if (numberPart1->algorism > numberPart2->algorism) return TRUE;

        numberPart1 = numberPart1->prev;
        numberPart2 = numberPart2->prev;

	}

    return FALSE;

}

boolean less_than(BIGNUMBER *number1, BIGNUMBER *number2){

    if (number1->signal > number2->signal) return FALSE;
    if (number1->signal < number2->signal) return TRUE;

    if (number1->signal == 1){

        if (number1->size > number2->size) return FALSE;
        if (number1->size < number2->size) return TRUE;
    
    } else{

        if (number1->size < number2->size) return FALSE;
        if (number1->size > number2->size) return TRUE;

    }

    // Crio nós para percorrer os bignumbers:
    NODE *numberPart1 = number1->end;
    NODE *numberPart2 = number2->end;

    for (int i=0; i<number1->size; i++){

        if (numberPart1->algorism < numberPart2->algorism) return TRUE;
        if (numberPart1->algorism > numberPart2->algorism) return FALSE;

        numberPart1 = numberPart1->prev;
        numberPart2 = numberPart2->prev;

    }

    return FALSE;

}

void del_bignumber(BIGNUMBER *number){
    NODE* numberPart = number->first;
    NODE* pnew = number->first->next;

    while (pnew != NULL)
    {
        pnew = numberPart->next;
        free(numberPart);
        numberPart = pnew;
        
    }
    
    free(number);
} 

BIGNUMBER *bignumber_abs(BIGNUMBER *number){
    char *number_abs = (char *) malloc(number->size);
    int count = 0;

    NODE *numberPart = number->end;

    while (numberPart != NULL){
        number_abs[count] = (numberPart->algorism) + '0';
        
        numberPart = numberPart->next;
        count++;
    }

    return(create_bignumber(number_abs));

}

void print_bignumber(BIGNUMBER *number){

    NODE *numberPart = number->first;
    char *numberPrint = (char*) malloc(number->size);
    int count = 0;

    printf("Resultado :: ");

    if (number->signal == 0){
        printf("%s", "-");
    }

    while (numberPart != NULL){
        numberPrint[count] = (numberPart->algorism) + '0';
        
        numberPart = numberPart->next;
        count++;
    }

    printf("%s\n", reverse_number(numberPrint));
}

int big_size(BIGNUMBER *number){

	return(number->size);
}

void print_bool(boolean inp){

    if (inp == 1){
        printf("Resultado :: True\n");
    } else if (inp == 0){
        printf("Resultado :: False\n");
    } else{
        printf("ERRO\n");
    }

}
