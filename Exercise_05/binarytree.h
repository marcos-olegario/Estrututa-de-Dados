#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "cliente.h"

typedef struct arv_bin BT;
typedef struct node_st NODE;

BT *create_tree(void);
boolean make_tree(BT *arvore, CLIENT *cliente);
NODE *create_node(CLIENT *cliente);
NODE *insert_client(NODE *raiz, CLIENT *cliente);
void new_insert(BT *arvore);
CLIENT *search_client(NODE *raiz, long int cpf);
CLIENT *tree_search(BT *arvore, long int cpf);
void new_insert(BT *arvore);
void new_search(BT *arvore);

void pre_ordem(BT *arvore);
void pre_ordem_recursao(NODE *raiz);

boolean remove_tree_node_aux(NODE **raiz, long int cpf);
boolean remove_tree_node(BT *arvore);
void troca_max_esq(NODE *troca, NODE *raiz, NODE *ant);

void remove_tree(NODE **raiz);
void desmatamento(BT **arvore);

#endif //BINARYTREE_H
