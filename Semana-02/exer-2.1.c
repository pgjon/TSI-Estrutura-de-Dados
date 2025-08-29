/*
    2.1 Escreva uma funçao em C chamada duplaCrescente que classifique 2 valores inteiros passados como argumento em ordem crescente.
    
    Entrada: Dois numeros inteiros
    Saída: Os dois inteiros em ordem crescente.
    Retorno: Nenhum
    
    Escreva um programa em C para ler uma quantidade indeterminada de duplas de inteiros. Escrever cada dupla em ordem crescente. Os valores em ordem crescente devem ser obtidos atraves da chamada a  funçao duplaCrescente. O programa termina quando os dois valores informados forem iguais (nesta situaçao os valores na o devem ser impressos).
    
    [Entrada] [Saída]
    1 2        1 2
    4 3        3 4
    2 2 
*/
# include <stdio.h>
# include <locale.h>

void duplaCrescente(int num1, int num2);

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

        duplaCrescente(num1, num2);

    } while (num1 != num2);
    // Outputs

    return 0;
}

void duplaCrescente(int num1, int num2) {

    if (num1 > num2) {
        int aux = num1;
        num1 = num2;
        num2 = aux;
    }

    printf("Ordem Crescente: %d %d\n\n", num1, num2);
}