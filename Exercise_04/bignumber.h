#ifndef BIGNUMBERS_H
#define BIGNUMBERS_H

#define TRUE 1 /*define valor booleano – não existe na linguagem C*/
#define FALSE 0
#define boolean int //define um tipo booleano
#define ERRO -32000

typedef struct bignumber_ BIGNUMBER;
typedef struct node_ NODE;

BIGNUMBER *create_bignumber(const char *str_input);

char *sum_same_sign(BIGNUMBER *number1, BIGNUMBER *number2, int sign);
char *sum_dif_sign(BIGNUMBER *number1, BIGNUMBER *number2);
BIGNUMBER *sum_bignumbers(BIGNUMBER *number1, BIGNUMBER *number2);

boolean equal_to(BIGNUMBER *number1, BIGNUMBER *number2);

boolean more_than(BIGNUMBER *number1, BIGNUMBER *number2);
boolean less_than(BIGNUMBER *number1, BIGNUMBER *number2);

void del_bignumber(BIGNUMBER *number);

// Funções auxiliares
void print_bignumber(BIGNUMBER *number);
void print_bool(boolean inp);
int big_size(BIGNUMBER *number);
char *reverse_number(const char *number);
int max(int a, int b);
BIGNUMBER *bignumber_abs(BIGNUMBER *number);

#endif //BIGNUMBERS_H
