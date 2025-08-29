/*
    2.2 Escreva uma funçao em C chamada classificaCrescente que classifique 2 valores inteiros passados como argumento em ordem crescente.
    
    Entrada/Saída: Dois numeros inteiros
    Saída: Nenhuma
    Retorno: Nenhum
    
    Reescreva o programa principal do exercício 2.1 utilizando a funçao classificaCrescente para obter os valores classificados.
*/
# include <stdio.h>
# include <locale.h>

void classificaCrescente(int *num1, int *num2);

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

        classificaCrescente(&num1, &num2);

        printf("Ordem Crescente: %d %d\n\n", num1, num2);

    } while (num1 != num2);
    // Outputs

    return 0;
}

void classificaCrescente(int *num1, int *num2) {

    if (*num1 > *num2) {
        int aux = *num1;
        *num1 = *num2;
        *num2 = aux;
    }
}