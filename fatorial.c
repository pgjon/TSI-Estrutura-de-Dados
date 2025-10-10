/*
    
*/
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

int fatorial(int n);
int main(){
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int n;
    // Inputs
    scanf("%d", &n);

    printf("Fatorial de %d = %d", n, fatorial(n));
    // Processing

    // Outputs

    return 0;
}

int fatorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    
    return n * fatorial(n - 1);
}