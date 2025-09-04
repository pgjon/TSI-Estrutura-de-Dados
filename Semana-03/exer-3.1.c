/*
    3.1 Definir um tipo chamado Horario para armazenar um horario composto de: hora, minuto, segundo.
        
    Escreva um programa em C para ler dois horários. Escreva o menor horário no formato HH:MM:SS. No caso de igualdade escrever a mensagem "Horários iguais".
*/
# include <stdio.h>
# include <locale.h>

typedef struct {
    int hora, minuto, segundo;
} Horario;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    Horario h1, h2;
    // Inputs
    printf("Digite o primeiro horário (HH MM SS): ");
    scanf("%d %d %d", &h1.hora, &h1.minuto, &h1.segundo);
    printf("Digite o segundo horário (HH MM SS): ");
    scanf("%d %d %d", &h2.hora, &h2.minuto, &h2.segundo);

    // Processing
    if ((h1.hora < h2.hora) || 
       (h1.hora == h2.hora && h1.minuto < h2.minuto) || 
       (h1.hora == h2.hora && h1.minuto == h2.minuto && h1.segundo < h2.segundo)) 
    {
        printf("Primeiro horário é menor: %.2d:%.2d:%.2d", h1.hora, h1.minuto, h1.segundo);
    } else if ((h1.hora == h2.hora) && (h1.minuto == h2.minuto) && (h1.segundo == h2.segundo)) {
        printf("Horários iguais!");
    } else {
        printf("Segundo Horário é menor: %.2d:%.2d:%.2d", h2.hora, h2.minuto, h2.segundo);
    }
    // Outputs
    
    return 0;
}