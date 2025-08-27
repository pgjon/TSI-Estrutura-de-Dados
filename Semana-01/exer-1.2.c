/*
    1.2 Escreva as seguintes funções em C:
    
    Nome: exibeOnzeTracos
    Descrição: Exibe na tela uma linha com 11 hifens(“-”). Utilizar uma repetição.
    
    Nome: retanguloTracos
    Descrição: Exibe na tela um retângulo com 4 linhas (usar repetição) de 11 hifens. Cada linha com 11 hifens deve ser impressa com a chamada da função exibeOnzeTracos descrita anteriormente.
    
    Escreva  um  programa  em  C  para  exibir  na  tela  2  retângulos  com  umalinha  em  branco  entre  eles.Cada retângulo deve ser mostrado a partir de uma chamada a função retanguloTracos.
    
    [Saída]
    -----------
    -----------
    -----------
    -----------
    
    -----------
    -----------
    -----------
    -----------
*/
# include <stdio.h>
# include <locale.h>

void exibeOnzeTracos(void);
void retanguloTracos(void);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    
    // Inputs
    
    // Processing
    for (int i = 0; i < 2; i++) {
        retanguloTracos();
        printf("\n");
    }
    // Outputs

    return 0;
}

void exibeOnzeTracos(void) {
    int i;

    for (i = 0; i < 11; i++) {
        printf("-");
    }
}

void retanguloTracos(void) {
    int i;

    for (i = 0; i < 4; i++) {
        exibeOnzeTracos();
        printf("\n");
    }
}