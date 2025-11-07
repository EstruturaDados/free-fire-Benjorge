#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

//constante global
#define MAX_ITENS 10

Item mochila[MAX_ITENS];
int totalItens = 0;

//FUNÇÕES DO SISTEMA
//Inserir itens
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("Nome do item: ");
    scanf("%s", &novo.nome);
    printf("Tipo do item: ");
    scanf("%s", &novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens++] = novo;
    printf("Item adicionado com sucesso!\n");
}

//remover itens
void removerItem() {
    char nomeRemover[30];
    printf("Informe o nome do item a ser removido: ");
    scanf("%s", &nomeRemover);

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            encontrado = 1;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado.\n");
    }
}

//listar itens
void listarItens() {
    if (totalItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\nItens na mochila:\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

//Buscar itens
void buscarItem() {
    char nomeBusca[30];
    printf("Informe o nome do item a buscar: ");
    scanf("%s", &nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item não encontrado.\n");
}

//Principal
int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    int opcao;

    do {
        printf("\n--- Menu da Mochila ---\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}



