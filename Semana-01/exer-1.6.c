/*
    1.6 Escreva um programa em C para ler a quantidade L de linhas (máximo 10) e a quantidade C de colunas (máximo 10) de uma matriz. A seguir ler uma matriz L x C (considere que serão informados apenas valores positivos). A seguir ler uma quantidade indeterminada de valores. Para cada valor escrever uma mensagem indicando  se  ele  está  ou  não  armazenado  na  matriz.  Para  cada  valor  informado,  a  mensagem  deve  ser impressa apenas uma vez. O programa termina ao ser informado um valor negativo.
    
    [Entrada] [Saída]          
    3     4
    2 3 2 4
    1 2 3 5
    6 4 3 1
    1                 Está na matriz
    10                Não está na matriz
    5                 Está na matriz
    8                 Não está na matriz
    -1
*/
# include <stdio.h>
# include <locale.h>

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int L, C, i, j;
    // Inputs
    printf("Digite a quantidade de L da matriz: "); scanf("%d", &L);
    printf("Digite a quantidade de C da matriz: "); scanf("%d", &C);

    int matriz[L][C];
    // Processing
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("%dº Linha e %dº Coluna: ", i+1, j+1); scanf("%d", &matriz[i][j]);
        }
    }

    int num;

    do {
        int count = 0;
        
        printf("\nDigite um valor para saber se está na matriz: "); scanf("%d", &num);
        if (num < 0) break;

        for (i = 0; i < L; i++) {
            for (j = 0; j < C; j++) {
                if (num == matriz[i][j]) {
                    count++;
                    break;
                }
            }
        }

        if (count > 0) {
            printf("Está na matriz!");
        } else {
            printf("Não está na matriz!");
        }

    } while (num >= 0);
    // Outputs

    return 0;
}