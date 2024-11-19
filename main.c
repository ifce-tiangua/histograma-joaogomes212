#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o histograma
void imprime_histograma(int* vendas[], int num_categorias) {
    for (int i = 0; i < num_categorias; i++) {
        printf("%d ", *vendas[i]); // Imprime o valor de vendas da categoria
        for (int j = 0; j < *vendas[i]; j++) {
            printf("*"); // Imprime os asteriscos correspondentes
        }
        printf("\n"); // Quebra de linha após cada categoria
    }
}

int main() {
    int num_categorias;

    // Solicita ao usuário o número de categorias
 //   printf("Digite o número de categorias: ");
    scanf("%d", &num_categorias);

    // Aloca memória para o vetor de ponteiros
    int** vendas = (int**)malloc(num_categorias * sizeof(int*));
    if (vendas == NULL) {
    //    printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Lê os valores de vendas para cada categoria
    for (int i = 0; i < num_categorias; i++) {
        vendas[i] = (int*)malloc(sizeof(int)); // Aloca memória para cada ponteiro
        if (vendas[i] == NULL) {
         //   printf("Erro ao alocar memória.\n");
            return 1;
        }
       // printf("Digite a quantidade vendida para a categoria %d: ", i + 1);
        scanf("%d", vendas[i]); // Lê o valor diretamente no ponteiro
    }

    // Imprime o histograma
  //  printf("\nHistograma:\n");
    imprime_histograma(vendas, num_categorias);

    // Libera a memória alocada
    for (int i = 0; i < num_categorias; i++) {
        free(vendas[i]); // Libera cada ponteiro individualmente
    }
    free(vendas); // Libera o vetor de ponteiros

    return 0;
}
