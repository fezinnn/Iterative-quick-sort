#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "pilha.h"

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivo) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quicksort_iterativo(int arr[], int n) {
    t_pilha *pilha = criar_pilha(n);

    empurrar(pilha, 0);
    empurrar(pilha, n - 1);

    while (!esta_vazio(pilha)) {
        int alto = remover(pilha);
        int baixo = remover(pilha);

        int pivo = particao(arr, baixo, alto);

        if (pivo - 1 > baixo) {
            empurrar(pilha, baixo);
            empurrar(pilha, pivo - 1);
        }
        if (pivo + 1 < alto) {
            empurrar(pilha, pivo + 1);
            empurrar(pilha, alto);
        }
    }

    free(pilha->itens);
    free(pilha);
}

void mensagem_menu() {
    printf("**************************************************\n");
    printf("*                                                *\n");
    printf("*                 Bem-vindo!                      *\n");
    printf("*                                                *\n");
    printf("*   Programa de Ordenacao com QuickSort Nao      *\n");
    printf("*   Recursivo                                    *\n");
    printf("*                                                *\n");
    printf("*   Este programa ordena uma lista de numeros    *\n");
    printf("*   inteiros utilizando o algoritmo QuickSort    *\n");
    printf("*   nao recursivo.                               *\n");
    printf("*                                                *\n");
    printf("**************************************************\n\n");
}

int main() {
    setlocale(LC_ALL, "");

    mensagem_menu();

    int quantidade_elementos;
    char input[256];

    printf("Digite a quantidade de elementos: ");
    if (!fgets(input, sizeof(input), stdin) || sscanf(input, "%d", &quantidade_elementos) != 1 || quantidade_elementos <= 0) {
        printf("Numero de elementos invalido.\n");
        return 1;
    }

    int *arr = (int *)malloc(quantidade_elementos * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite os elementos do vetor na mesma linha: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Erro na leitura dos elementos.\n");
        free(arr);
        return 1;
    }

    char *token = strtok(input, " ");
    int count = 0;

    while (token != NULL) {
        if (count >= quantidade_elementos) {
            printf("Erro: Numero de elementos digitados e maior que o tamanho do vetor.\n");
            free(arr);
            return 1;
        }
        if (sscanf(token, "%d", &arr[count]) != 1) {
            printf("Erro: Numero de elementos digitados e invalido.\n");
            free(arr);
            return 1;
        }
        count++;
        token = strtok(NULL, " ");
    }

    if (count != quantidade_elementos) {
        printf("Erro: Numero de elementos digitados e diferente do tamanho do vetor especificado.\n");
        free(arr);
        return 1;
    }

    quicksort_iterativo(arr, quantidade_elementos);

    printf("Vetor ordenado: ");
    for (int i = 0; i < quantidade_elementos; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}