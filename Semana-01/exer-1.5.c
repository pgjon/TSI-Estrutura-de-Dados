/*
    1.5 Escreva um programa em C para ler um inteiro Q (máximo 10). A seguir ler um vetor Z de Q elementos e um valor Y. Copiar todos os elementos maiores que Y que estão no vetor Z para um vetor W (sem deixar elementos vazios entre os valores copiados). Escrever o vetor Wapós o término cópia.
    
    [Entrada]                   [Saída]
    10
    2 15 14 18 9 13 0 45 12 21
    14
                                15 18 45 21
*/
# include <stdio.h>
# include <locale.h>

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int Q, Y, i, acc = 0;
    // Inputs
    printf("Digite um valor Q: "); scanf("%d", &Q);

    // Processing
    int Z[Q], W[Q];

    for (i = 0; i < Q; i++) {
        printf("%dº valor do vetor Z: ", i+1); scanf("%d", &Z[i]);
    }

    printf("\nAgora, digite um valor Y: "); scanf("%d", &Y);

    for (i = 0; i < Q; i++) {
        if (Z[i] > Y) {
            W[acc] = Z[i];
            acc++;
        }
    }
    // Outputs

    for (i = 0; i < acc; i++) {
        printf("%d ", W[i]);
    }
    return 0;
}