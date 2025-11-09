//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ESTRUTURAS

//struct do item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

//struct do nó para a lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

//VARIÁVEIS GLOBAIS:
#define MAX_ITENS 10
Item mochilaVetor[MAX_ITENS];
int totalItensVetor = 0;

No* mochilaLista = NULL;
int totalItensLista = 0;

//FUNÇÕES PARA O VETOR 

//1ª - INSERIR
void inserirItemVetor() {
    if (totalItensVetor >= MAX_ITENS) {
        printf("Mochila (vetor) cheia!\n");
        return;
    }
    Item novo;
    printf("Nome: "); scanf("%s", novo.nome);
    printf("Tipo: "); scanf("%s", novo.tipo);
    printf("Quantidade: "); scanf("%d", &novo.quantidade);
    mochilaVetor[totalItensVetor++] = novo;
}

//2ª - REMOVER
void removerItemVetor() {
    char nome[30];
    printf("Nome do item a remover: "); scanf("%s", nome);
    for (int i = 0; i < totalItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < totalItensVetor - 1; j++)
                mochilaVetor[j] = mochilaVetor[j + 1];
            totalItensVetor--;
            printf("Item removido!\n");
            return;
        }
    }
    printf("Item não encontrado.\n");
}

//3ª - LISTAR
void listarItensVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila (vetor) vazia.\n");
        return;
    }
    for (int i = 0; i < totalItensVetor; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
    }
}

//4ª - BUSCA SEGUENCIAL
void buscarItemVetor() {
    char nome[30];
    printf("Buscar por nome: "); scanf("%s", nome);
    for (int i = 0; i < totalItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
            return;
        }
    }
    printf("Item não encontrado.\n");
}


//FUNÇÕES PARA LISTA ENCADEADA

//1ª - INSERIR
void inserirItemLista() {
    No* novo = (No*) malloc(sizeof(No));
    printf("Nome: "); scanf("%s", novo->dados.nome);
    printf("Tipo: "); scanf("%s", novo->dados.tipo);
    printf("Quantidade: "); scanf("%d", &novo->dados.quantidade);
    novo->proximo = mochilaLista;
    mochilaLista = novo;
    totalItensLista++;
}

//2ª - REMOVER
void removerItemLista() {
    char nome[30];
    printf("Nome do item a remover: "); scanf("%s", nome);
    No *atual = mochilaLista, *anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) mochilaLista = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            totalItensLista--;
            printf("Item removido!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Item não encontrado.\n");
}

//3ª - LISTAR
void listarItensLista() {
if (mochilaLista == NULL) {
        printf("Mochila (lista) vazia.\n");
        return;
    }
    No* atual = mochilaLista;
    while (atual != NULL) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
        atual = atual->proximo;
    }
}

//4ª - BUSCA SEQUENCIAL
void buscarItemLista() {
    char nome[30];
    printf("Buscar por nome: "); scanf("%s", nome);
    No* atual = mochilaLista;
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            return;
        }
        atual = atual->proximo;
    }
    printf("Item não encontrado.\n");
}
//-------------------------------------------------------------------------------------------

int main() {
    int estrutura, opcao;
    printf("Escolha a estrutura: 1 - Vetor | 2 - Lista Encadeada: ");
    scanf("%d", &estrutura);

    do {
        printf("\n--- Menu da Mochila ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens na Mochila\n");
        printf("4. Buscar Item por Nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (estrutura == 1) {
            switch (opcao) {
                case 1: inserirItemVetor(); break;
                case 2: removerItemVetor(); break;
                case 3: listarItensVetor(); break;
                case 4: buscarItemVetor(); break;
                case 0: printf("Saindo...\n"); break;
                default: printf("Opção inválida!\n");
            }
        } else {
            switch (opcao) {
                case 1: inserirItemLista(); break;
                case 2: removerItemLista(); break;
                case 3: listarItensLista(); break;
                case 4: buscarItemLista(); break;
                case 0: printf("Saindo...\n"); break;
                default: printf("Opção inválida!\n");
            }
        }
    } while (opcao != 0);

    return 0;
}