/*
    1.1 Escreva um programa em C para ler um valor Q que representa a quantidade de alunos de uma turma. A seguir  ler  Q  pares  de  dados  contendo,  cada  um,  a  altura  e  um  código  para  masculino  (1)  e  outro  para feminino (2) de cada aluno. Calcular e escrever:

        -A altura do aluno mais alto da turma.
        -A média de altura das alunas.
*/
# include <stdio.h>
# include <locale.h>

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int qAlunos;
    // Inputs
    printf("Digite a quantidade de alunos: "); scanf("%d", &qAlunos);

    int altura[qAlunos], codigoAluno[qAlunos];
    // Processing
    for (int i = 0; i < qAlunos; i++) {
        printf("Digite a ");
    }
    // Outputs

    return 0;
}