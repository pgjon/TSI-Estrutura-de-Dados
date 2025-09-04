/*
    3.2 Definir um tipo chamado Aluno para armazenar os seguintes dados de um aluno: numero de matrícula e data de nascimento (tipo Data).
    
    Escrever um programa em C para ler a data de hoje armazenando-a em uma variavel do tipo Data. A seguir ler uma quantidade indeterminada de dados de alunos (Aluno). Para cada aluno lido escrever se ele ja  completou 18 anos ate a data informada. O programa termina ao ser informado um valor negativo para a matrícula. Nesta situaçao a data de nascimento nao deve ser lida.
*/
# include <stdio.h>
# include <locale.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int matricula;
    Data dataNascimento;
} Aluno;


int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    Data dataHoje;
    Aluno aluno;
    // Inputs
    printf("Digite a data de hoje DD/MM/AAAA: ");
    scanf("%d %d %d", &dataHoje.dia, &dataHoje.mes, &dataHoje.ano);

    // Processing
    do {
        int idade = 0;
        printf("\nDigite sua matrícula: ");
        scanf("%d", &aluno.matricula);
        if (aluno.matricula < 0) {
            printf("Matrícula informada negativa.\nPrograma encerrado!");
            break;
        }

        printf("Digite sua data de nascimento: ");
        scanf("%d %d %d", &aluno.dataNascimento.dia, &aluno.dataNascimento.mes, &aluno.dataNascimento.ano);

        idade = (dataHoje.ano - aluno.dataNascimento.ano);

        // lógica para dar exatidão entre a data de hoje e a data de nascimento. 
        if ((dataHoje.mes < aluno.dataNascimento.mes) || (dataHoje.mes == aluno.dataNascimento.mes && dataHoje.dia < aluno.dataNascimento.dia)) {
            idade -= 1;
        }

        if (idade >= 18) {
            printf("\nJá completou 18 anos!\n");
            printf("Matrícula: %d", aluno.matricula);
            printf("\nIdade: %d", idade);
        } else {
            printf("\nAinda não completou 18 anos!\n");
            printf("Matrícula: %d", aluno.matricula);
            printf("\nIdade: %d", idade);
        }
    } while (aluno.matricula > -1);
    // Outputs

    return 0;
}