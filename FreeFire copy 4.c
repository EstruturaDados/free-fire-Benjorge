#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTES 20

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

void mostrarComponentes(Componente lista[], int n) {
    printf("\n--- Componentes da Torre ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               lista[i].nome, lista[i].tipo, lista[i].prioridade);
    }
}

int bubbleSortNome(Componente lista[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                Componente temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

int insertionSortTipo(Componente lista[], int n) {
    int comparacoes = 0;
    for (int i = 1; i < n; i++) {
        Componente chave = lista[i];
        int j = i - 1;
        while (j >= 0 && strcmp(lista[j].tipo, chave.tipo) > 0) {
            lista[j + 1] = lista[j];
            j--;
            comparacoes++;
        }
        lista[j + 1] = chave;
        comparacoes++;
    }
    return comparacoes;
}

int selectionSortPrioridade(Componente lista[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (lista[j].prioridade < lista[min].prioridade)
                min = j;
        }
        if (min != i) {
            Componente temp = lista[i];
            lista[i] = lista[min];
            lista[min] = temp;
        }
    }
    return comparacoes;
}

int buscaBinariaPorNome(Componente lista[], int n, char chave[]) {
    int inicio = 0, fim = n - 1, comparacoes = 0;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;
        int cmp = strcmp(lista[meio].nome, chave);
        if (cmp == 0) {
            printf("Componente-chave encontrado!\n");
            return comparacoes;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("Componente-chave não encontrado.\n");
    return comparacoes;
}

int main() {
    Componente torre[MAX_COMPONENTES];
    int total = 0;
    int opcao;
    char chaveBusca[30];

    do {
        printf("\n=== MENU DE MISSÃO: TORRE DE FUGA ===\n");
        printf("1. Adicionar Componente\n");
        printf("2. Descartar Componente\n");
        printf("3. Listar Componentes (Inventário)\n");
        printf("4. Organizar Mochila (Ordenar Componentes)\n");
        printf("5. Busca Binária por Componente-Chave (por nome)\n");
        printf("0. ATIVAR TORRE DE FUGA (Sair)\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        switch (opcao) {
            case 1:
                if (total >= MAX_COMPONENTES) {
                    printf("Limite de componentes atingido.\n");
                    break;
                }
                printf("Nome: "); fgets(torre[total].nome, 30, stdin);
                torre[total].nome[strcspn(torre[total].nome, "\n")] = 0;
                printf("Tipo: "); fgets(torre[total].tipo, 20, stdin);
                torre[total].tipo[strcspn(torre[total].tipo, "\n")] = 0;
                printf("Prioridade (1-10): "); scanf("%d", &torre[total].prioridade);
                getchar();
                total++;
                break;

            case 2: {
                char nome[30];
                printf("Nome do componente a descartar: ");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = 0;
                int encontrado = 0;
                for (int i = 0; i < total; i++) {
                    if (strcmp(torre[i].nome, nome) == 0) {
                        for (int j = i; j < total - 1; j++)
                            torre[j] = torre[j + 1];
                        total--;
                        encontrado = 1;
                        printf("Componente descartado!\n");
                        break;
                    }
                }
                if (!encontrado) printf("Componente não encontrado.\n");
                break;
            }

            case 3:
                mostrarComponentes(torre, total);
                break;

            case 4: {
                int escolha;
                printf("\n--- Estratégia de Ordenação ---\n");
                printf("1. Por Nome (Bubble Sort)\n");
                printf("2. Por Tipo (Insertion Sort)\n");
                printf("3. Por Prioridade (Selection Sort)\n");
                printf("Escolha: ");
                scanf("%d", &escolha);
                getchar();

                int comp = 0;
                if (escolha == 1) comp = bubbleSortNome(torre, total);
                else if (escolha == 2) comp = insertionSortTipo(torre, total);
                else if (escolha == 3) comp = selectionSortPrioridade(torre, total);
                else {
                    printf("Opção inválida.\n");
                    break;
                }

                printf("Componentes organizados. Comparações realizadas: %d\n", comp);
                mostrarComponentes(torre, total);
                break;
            }

            case 5:
            printf("Antes de realizar a busca binária, é necessário ordenar os componentes por nome.\n");
            int compOrdenacao = bubbleSortNome(torre, total);
            printf("Componentes ordenados por nome. Comparações: %d\n", compOrdenacao);
            mostrarComponentes(torre, total);

            printf("\nDigite o nome do componente-chave: ");
            fgets(chaveBusca, 30, stdin);
            chaveBusca[strcspn(chaveBusca, "\n")] = 0;

            int compBusca = buscaBinariaPorNome(torre, total, chaveBusca);
            printf("Comparações realizadas na busca: %d\n", compBusca);
            break;
        }
    } while (opcao != 0);

    return 0;
}