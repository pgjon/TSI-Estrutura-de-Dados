/*
    2.4 Escreva uma funçao em C chamada calcDivisao que receba como entrada dois inteiros e retorne o valor da divisao do primeiro pelo segundo. Retornar tambem um codigo de erro indicando se foi ou na o possível calcular a divisao.
    
    Entrada: Dois inteiros.
    Saída: O resultado da divisao (float)
    Retorno: 0 se foi possível executar a divisao e 1 caso o segundo para metro de entrada for igual a zero.
    
    Escreva um programa em C para ler um valor N. A seguir ler N duplas de valores. Para cada dupla calcular e escrever o resultado da divisao do primeiro valor pelo segundo. Utilizar a funçao calcDivisao para obter o resultado. Caso a funçao retorne o codigo de erro igual a 1 deve ser impressa a mensagem “Divisa o por zero”.
    
    [Entrada] [Saída]
    3
    8 2        4
    9 2        4.5
    10 0       Divisão por zero
*/
#include <stdio.h>
#include <locale.h>

int calcDivisao(int num1, int num2, float *resultado);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int N, i, num1, num2, codigo;
    float resultado;
    
    // Inputs
    printf("Digite um valor N: "); 
    scanf("%d", &N);

    // Processing
    for (i = 0; i < N; i++) {
        printf("Digite primeiro valor: "); scanf("%d", &num1);
        printf("Digite segundo valor: "); scanf("%d", &num2);

        codigo = calcDivisao(num1, num2, &resultado);

        if (codigo == 1) {
            printf("Divisão por zero\n");
        } else {
            printf("%.1f\n", resultado);
        }
    }

    return 0;
}

int calcDivisao(int num1, int num2, float *resultado) {
    if (num2 == 0) {
        return 1;  // Código de erro
    } else {
        *resultado = (float) num1 / num2;
        return 0;  // Código de sucesso
    }
}