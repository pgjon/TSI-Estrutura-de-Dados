/*

*/
#include <stdio.h>
struct Data {
  int dia, mes, ano;
};

int main() {
    struct Data dt;
    
    printf("Informe o dia: ");
    scanf("%d", &dt.dia);
    
    printf("Informe o mês: ");
    scanf("%d", &dt.mes);
    
    printf("Informe o ano: ");
    scanf("%d", &dt.ano);

    if (dt.dia == 7 && dt.mes == 9) {
        printf("Dia da independência\n");
    } else {
        printf("Sem comemoração\n");
    }

    printf("Data digitada : %d / %d / %d\n", dt.dia, dt.mes, dt.ano);

    return 0;
}