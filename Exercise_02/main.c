#include <stdio.h>

typedef struct{
    char nomePokemon[50];
    char tipoPrimario[20];
    char tipoSecundario[20];

    struct atributos_{
        int hp;
        int ataque;
        int defesa;
        int ataqueEspecial;
        int defesaEspecial;
        int velocidade;
    } atributos;

    struct ataques_{
        char nomeAtaque[20];
        int poderBase;
        float acuracia;
        char classe;
    } ataques[4];

} POKEDEX;

void cadastrar(POKEDEX *pokedex){
    scanf("%s", pokedex->nomePokemon);
    scanf("%s", pokedex->tipoPrimario);
    scanf("%s", pokedex->tipoSecundario);
    scanf("%d", &pokedex->atributos.hp);
    scanf("%d", &pokedex->atributos.ataque);
    scanf("%d", &pokedex->atributos.defesa);
    scanf("%d", &pokedex->atributos.ataqueEspecial);
    scanf("%d", &pokedex->atributos.defesaEspecial);
    scanf("%d", &pokedex->atributos.velocidade);
}

void addAtaque(POKEDEX *pokedex, int idAtq){
    scanf("%s", pokedex->ataques[idAtq].nomeAtaque);
    scanf("%d", &pokedex->ataques[idAtq].poderBase);
    scanf("%f", &pokedex->ataques[idAtq].acuracia);
    scanf(" %c", &pokedex->ataques[idAtq].classe);
}

void imprimirPokemon(POKEDEX pokedex){
    printf("Nome do Pokemon: %s\n", pokedex.nomePokemon);
    printf("Tipo primario: %s\n", pokedex.tipoPrimario);
    printf("Tipo secundario: %s\n", pokedex.tipoSecundario);
    printf("Status:\n");
    printf("\tHP: %d\n", pokedex.atributos.hp);
    printf("\tAtaque: %d\n", pokedex.atributos.ataque);
    printf("\tDefesa: %d\n", pokedex.atributos.defesa);
    printf("\tAtaque Especial: %d\n", pokedex.atributos.ataqueEspecial);
    printf("\tDefesa Especial: %d\n", pokedex.atributos.defesaEspecial);
    printf("\tVelocidade: %d\n\n", pokedex.atributos.velocidade);
}

void imprimirAtaque(POKEDEX pokedex, int idAtq){
    printf("Nome do Ataque: %s\n", pokedex.ataques[idAtq].nomeAtaque);
    printf("Poder base: %d\n", pokedex.ataques[idAtq].poderBase);
    printf("Acuracia: %f\n", pokedex.ataques[idAtq].acuracia);
    printf("Classe: %c\n\n", pokedex.ataques[idAtq].classe);
}

int main(){

    POKEDEX pokedexTotal[1000];
    int pokedexTotalCount = -1;
    int pare;

    do{
        scanf("%d", &pare);

        POKEDEX pokemon;
        int indicePokemon;
        int indiceAtaque;

        if (pare == 1){

            cadastrar(&pokemon);
            pokedexTotalCount++;

            pokedexTotal[pokedexTotalCount] = pokemon;

        } else if (pare == 2){

            scanf("%d", &indicePokemon);
            scanf("%d", &indiceAtaque);

            addAtaque(&pokedexTotal[indicePokemon], indiceAtaque);

        } else if (pare == 3){

            scanf("%d", &indicePokemon);
            imprimirPokemon(pokedexTotal[indicePokemon]);

        } else if (pare == 4){

            scanf("%d", &indicePokemon);
            scanf("%d", &indiceAtaque);
            imprimirAtaque(pokedexTotal[indicePokemon], indiceAtaque);

        } else{
            break;
        }

    } while (pare != 0);

    return (0);
}