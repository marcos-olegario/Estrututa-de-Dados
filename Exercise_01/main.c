#include <stdio.h>

void calcular(int *amt, int *vetor){

    vetor[0] = (int) *amt/100;
    *amt = *amt-(vetor[0] * 100);
	
    vetor[1] = (int) *amt/50;
    *amt = *amt-(vetor[1] * 50);
  
    vetor[2] = (int) *amt/25;
    *amt = *amt-(vetor[2] * 25);
  
    vetor[3] = (int) *amt/10;
    *amt = *amt-(vetor[3] * 10);
  
    vetor[4] = (int) *amt/5;
    *amt = *amt-(vetor[4] * 5);
  
    vetor[5] = *amt;

    return;
}

int main(){
    
    int amt;
    int vetor[6] = {0, 0, 0, 0, 0, 0};
    
    scanf("%d",&amt);
    
    calcular(&amt, vetor);
    
    printf("O valor consiste em %d moedas de 1 real\n", vetor[0]);
    printf("O valor consiste em %d moedas de 50 centavos\n", vetor[1]);
    printf("O valor consiste em %d moedas de 25 centavos\n", vetor[2]);
    printf("O valor consiste em %d moedas de 10 centavos\n", vetor[3]);
    printf("O valor consiste em %d moedas de 5 centavos\n", vetor[4]);
    printf("O valor consiste em %d moedas de 1 centavo\n", vetor[5]);
    
    return 0;
}

