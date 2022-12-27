#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine() {
    char *string = NULL;
    char ch = '\0';
    int i = 0;

    while((ch = getchar()) == '\n');
    if(ch != EOF)
        ungetc(ch, stdin);

    do{
        ch = (char)getchar();
        string = (char *) realloc(string, ++i * sizeof (char));
        string[i - 1] = ch;
    } while ((ch != '\n') && (ch != ';'));

    string[i- 1] = '\0';

    return (string);
}

char* read_info(){
    char* aux;
    aux = readLine();

    return(aux);
}

long int cpf_to_int(const char *str){

	long int cpf_int = 0;
	    
	for(int i=0; i<strlen(str); i++){
	        
	    if(str[i] == '.' || str[i] == '-'){
	        continue;
	    }
	    cpf_int = (cpf_int * 10) + ((int)str[i] - 48);
	    }
    
    return cpf_int;
}

int get_id(const char *opr){

    if (strcmp(opr, "I") == 0) return 1; 
    if (strcmp(opr, "R") == 0) return 2;
    if (strcmp(opr, "B") == 0) return 3;
    return -32000;

}



