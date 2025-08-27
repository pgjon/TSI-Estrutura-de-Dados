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
    int qAlunos, sexoAluno, qtdAlunas = 0;
    // Inputs
    printf("Digite a quantidade de alunos: "); scanf("%d", &qAlunos);

    float alturaAluno[qAlunos], alunoMaisAlto = 0.0, mediaAlturaAlunas = 0.0, somaAlturaAlunas = 0.0;

    printf("Informação: para sexo, digite (1) para masculino e (2) para feminino.\n");

    // Processing
    for (int i = 0; i < qAlunos; i++) {
        printf("Digite sua altura: "); scanf("%f", &alturaAluno[i]);

        printf("Digite seu sexo: "); scanf("%d", &sexoAluno);

        if (sexoAluno == 1) {
            if (alunoMaisAlto < alturaAluno[i]) {
                alunoMaisAlto = alturaAluno[i];
            }
        } else {
            somaAlturaAlunas += alturaAluno[i];
            qtdAlunas++;
        }
    }
    // Outputs
    mediaAlturaAlunas = somaAlturaAlunas / qtdAlunas;

    if (alunoMaisAlto == 0.0) {
        printf("\nNão tem alunos do sexo masculino na turma!\n");
    } else {
        printf("\nAluno mais alto da turma: %.2f m\n", alunoMaisAlto);
    }

    printf("Média da altura das alunas: %.2f m\n", mediaAlturaAlunas);


    return 0;
}