#include "cliente.h"
#include "binarytree.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node_st {
	CLIENT *cliente;
	NODE *esq;
	NODE *dir;
};

struct arv_bin {
	NODE *raiz;
};

BT *create_tree(void) {
	BT *r = (BT *) malloc(sizeof(BT));

	if (r != NULL){
		r->raiz = NULL;
		return(r);
	}
	return NULL;
}

boolean make_tree(BT *arvore, CLIENT *cliente){
	return((arvore->raiz = insert_client(arvore->raiz, cliente)) != NULL);
}

NODE *create_node(CLIENT *cliente){
	NODE *no = (NODE *) malloc(sizeof(NODE));

	if (no != NULL){
		no->cliente = cliente;
		no->dir = NULL;
		no->esq = NULL;

		return no;
	}
	return NULL;
} 

NODE *insert_client(NODE *raiz, CLIENT *cliente){

	if(raiz == NULL) {
        raiz = create_node(cliente);
    }
    else if (give_cpf(raiz->cliente) < give_cpf(cliente)) {
        raiz->dir = insert_client(raiz->dir, cliente);
    }
    else {
        raiz->esq = insert_client(raiz->esq, cliente);
    }
    return raiz;	
}

void pre_ordem(BT *arvore){

    printf("Preorder\n");
    pre_ordem_recursao(arvore->raiz);
    printf("\n");
    return;
}

void pre_ordem_recursao(NODE *raiz){

    if (raiz != NULL) {
    	if (give_cpf(raiz->cliente) < 10000000000)
        	printf("0");
        printf("%ld\n", give_cpf(raiz->cliente));
        pre_ordem_recursao(raiz->esq);
        pre_ordem_recursao(raiz->dir);
    }
    return;
}

CLIENT *search_client(NODE *raiz, long int cpf){

	if(raiz == NULL){
		return NULL;
	}
	if(cpf == give_cpf(raiz->cliente)){
		return (raiz->cliente);
	}
	if(cpf < give_cpf(raiz->cliente)){
		return (search_client(raiz->esq, cpf));
	}
	else{
		return (search_client(raiz->dir, cpf)); 
	}
}

CLIENT *tree_search(BT *arvore, long int cpf){
	return(search_client(arvore->raiz, cpf));
}

void new_insert(BT *arvore){

	CLIENT *cliente;
	cliente = create_client();
	make_tree(arvore, cliente);

	//print_client(cliente);

}

void new_search(BT *arvore){
	CLIENT *cliente;
	char *line;
	long int cpf;

	line = readLine();
	cpf = cpf_to_int(line);

	cliente = tree_search(arvore, cpf);

	if (cliente == NULL){
		printf("Pessoa nao encontrada.\n");
	}
	else{
		print_client(cliente);
	}

	remove_client(&cliente);
}

boolean remove_tree_node_aux(NODE **raiz, long int cpf){

	NODE *p;
	if((*raiz) == NULL){
		return(FALSE);
	}

	if(cpf == give_cpf((*raiz)->cliente)){

		print_client((*raiz)->cliente);
		
		if ((*raiz)->esq == NULL || (*raiz)->dir == NULL){
			p = *raiz;
			if((*raiz)->esq == NULL){
				*raiz = (*raiz)->dir;
			} else{
				*raiz = (*raiz)->esq;
			}
			free(p);
			p = NULL;
		} else{
			troca_max_esq((*raiz)->dir, (*raiz), (*raiz));
		}
		return(TRUE);
	
	}else{
		if(cpf > give_cpf((*raiz)->cliente)){ 
			return remove_tree_node_aux(&(*raiz)->esq, cpf);
		}else{
			return remove_tree_node_aux(&(*raiz)->dir, cpf);
		}
	}
}

boolean remove_tree_node(BT *arvore){

	long int cpf = cpf_to_int(readLine());

	if (arvore != NULL){
		return (remove_tree_node_aux(&arvore->raiz, cpf));
	}
	return(FALSE);
}

void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant){

	if(troca->dir != NULL){
		troca_max_esq(troca->esq, raiz, troca);
		return;
	}
	if(raiz == ant){
		ant->dir = troca->dir;
	}
	else{
		ant->esq = troca->dir;
	}
	raiz->cliente = troca->cliente;
	free(troca);
	troca = NULL;
}

void remove_tree(NODE **raiz){
	if (*raiz != NULL){
		remove_tree(&(*raiz)->esq);
		remove_tree(&(*raiz)->dir);
		remove_client(&((*raiz)->cliente));
		free(*raiz);
		*raiz = NULL;
	}
	return;
}

void desmatamento(BT **arvore){
	remove_tree(&(*arvore)->raiz);
	free(*arvore);
	*arvore = NULL;

	return;
}