/*
    2.3 Escreva uma funçao chamada duplaClassificada que classifique 2 valores inteiros conforme o codigo passado como argumento (0-ordem crescente 1-ordem decrescente).
    
    Entrada: Um co digo que identifica a ordem de classificaça o (0-ordem crescente 1-ordem decrescente).Entrada: Dois valores inteiros.
    Saída: Os 2 valores de entrada na ordem desejada
    Retorno: Nenhum
    
    Escreva um programa para ler uma quantidade indeterminada de duplas de valores. Escrever cada dupla em ordem crescente se a soma dos elementos da dupla for par e em ordem decrescente se a soma for í mpar. Os valores em ordem (conforme o caso) devem ser obtidos atrave s da chamada a  funça o duplaClassificada. O programa termina quando os dois valores informadosforem iguais (nesta situaça o os valores na o devem ser impressos).

    [Entrada] [Saída]
    1 2       2 1
    4 3       4 3
    2 4       2 4
    10 2      2 10
    1 3       1 3
    5 3       3 5
    2 2
*/
# include <stdio.h>
# include <locale.h>

void duplaClassificada(int *num1, int *num2);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int num1, num2;
    // Inputs

    // Processing
    do {
        printf("Digite primeiro valor: "); scanf("%d", &num1);
        printf("Digite segundo valor: "); scanf("%d", &num2);

        if (num1 == num2) break;

        duplaClassificada(&num1, &num2);

        if ((num1 + num2) % 2 == 0)
            printf("Ordem Crescente: %d %d\n\n", num1, num2);

        else
            printf("Ordem Decrescente: %d %d\n\n", num2, num1);

    } while (num1 != num2);
    // Outputs

    return 0;
}

void duplaClassificada(int *num1, int *num2) {

    if (*num1 > *num2) {
        int aux = *num1;
        *num1 = *num2;
        *num2 = aux;
    }
}