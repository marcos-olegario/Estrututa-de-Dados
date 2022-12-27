//#include "util.h"
//#include "cliente.h"
#include "binarytree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

	int n; // Número de operações

    char *opr; // Operação escolhida
    
    BT *arvore = create_tree(); // Definir árvore
    CLIENT *cliente = NULL; // Definir cliente

    scanf("%d\n", &n);

    // Código criar arvore

    for(int i=0; i<n; i++){

        cliente = create_client();
        make_tree(arvore, cliente);

    }

    opr = readLine();

    switch (get_id(opr)){

        case 1: { // Inserção
            new_insert(arvore);
            pre_ordem(arvore);
            break;
        } 
        case 2: { // Remoção
            remove_tree_node(arvore);
            pre_ordem(arvore);
            break;
        } 
        case 3: { // Busca
            new_search(arvore);
            break;
        }
    }

    desmatamento(&arvore);
    remove_client(&cliente);

    free(cliente);
    cliente = NULL;

	return(0);
}