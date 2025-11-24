#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// -----------------------------
// STRUCT E ENUMS
// -----------------------------
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade; // 1 a 5
} Item;

typedef enum {
    ORDENAR_NOME = 1,
    ORDENAR_TIPO,
    ORDENAR_PRIORIDADE
} CriterioOrdenacao;

// -----------------------------
// VARIÁVEIS GLOBAIS
// -----------------------------
Item mochila[MAX_ITENS];
int numItens = 0;
int comparacoes = 0;
bool ordenadaPorNome = false;

// -----------------------------
// FUNÇÕES
// -----------------------------
void limparTela() {
    for (int i = 0; i < 40; i++) printf("\n");
}

void exibirMenu() {
    printf("\n========= CÓDIGO DA ILHA – FREE FIRE =========\n");
    printf("Itens na mochila: %d/%d\n", numItens, MAX_ITENS);
    printf("Status da ordenação por nome: %s\n", ordenadaPorNome ? "ORDENADA" : "NÃO ORDENADA");

    printf("\n1. Adicionar um item");
    printf("\n2. Remover um item");
    printf("\n3. Listar itens");
    printf("\n4. Ordenar itens");
    printf("\n5. Busca binária por nome");
    printf("\n0. Sair");
    printf("\nEscolha uma opção: ");
}

void inserirItem() {
    if (numItens >= MAX_ITENS) {
        printf("❌ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("Nome do item: ");
    getchar();
    fgets(novo.nome, 50, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(novo.tipo, 30, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    printf("Prioridade (1 a 5): ");
    scanf("%d", &novo.prioridade);

    mochila[numItens++] = novo;
    ordenadaPorNome = false;

    printf("✔ Item adicionado com sucesso!\n");
}

void removerItem() {
    if (numItens == 0) {
        printf("❌ Mochila vazia!\n");
        return;
    }

    char busca[50];
    printf("Nome do item a remover: ");
    getchar();
    fgets(busca, 50, stdin);
