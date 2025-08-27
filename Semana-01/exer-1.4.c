/*
    1.4 Escreva uma função chamada maiorNumero que receba como entrada dois inteiros positivos e retorne o maior deles ou o valor -1 se eles forem iguais. Considere que os valores de entrada são sempre positivos (não é necessário validar).
    
    Escreva  um  programa  em  C  para  ler  um  valor  N.  A  seguir  ler  N  duplas  de  inteiros  (considere  que  serão informado apenas valores positivos). Para cada dupla informada exibir o maior elemento ou a frase “Eles são iguais”. Para obter o maior elemento deve ser utilizada a função maiorNumero.
    
    [Entrada] [Saída]
    3
    20  15     20
    7   12     12
    5   5      Eles são iguais
*/
# include <stdio.h>
# include <locale.h>

int maiorNumero (int num1, int num2);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int numA, numB, i, N, numeroReturn;
    // Inputs
    printf("Digite um valor N inteiro positivo: "); scanf("%d", &N);

    // Processing
    for (i = 0; i < N; i++) {
        printf("Digite número A: "); scanf("%d", &numA);
        printf("Digite número B: "); scanf("%d", &numB);

        numeroReturn = maiorNumero(numA, numB);

        if (numeroReturn == -1) {
            printf("Eles são iguais\n");
        } else {
            printf("%d\n", numeroReturn);
        }
    }
    // Outputs

    return 0;
}

int maiorNumero (int num1, int num2) {

    if (num1 > num2) 
        return num1;
    else if (num1 < num2)
        return num2;
    else
        return -1;
}