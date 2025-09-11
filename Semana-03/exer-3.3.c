/*
    3.3 Defina o tipo Conta para armazenar o número de uma conta e seu respectivo saldo.
    
    Implemente as seguintes operações:
    
    criaConta                                           depositaNaConta
    Saída: Uma conta                                    Entrada/Saída: Uma conta
    Entrada: Número da conta                            Entrada: valor do depósito.
    Descrição: Atribui os valores iniciais.             Descrição: Atualiza o atributo saldo com o valor do
    O saldo deve ser zerado.                            depósito

    retiraDaConta                                       obtemSaldo
    Entrada/Saída: Uma conta                            Entrada: uma conta
    Entrada: valor da retirada.                         Retorno: O saldo da conta
    Descrição: Atualiza o atributo saldo com o valor 
    da retirada.
    
    Escreva um programa para controlar a conta corrente e a conta poupança do sr. Silva. As contas são integradas de forma que quando não houver saldo suficiente na conta corrente uma transferência automá- tica da conta poupança cobrira um eventual saldo (o valor da transferência deve ser igual ao valor necessário para cobrir o saldo negativo). O programa deve ler o número e o saldo inicial da conta corrente e da poupança criando duas variáveis do tipo Conta(cada uma representa uma conta). A seguir ler uma quantidade indeterminada de duplas de dados representando respectivamente o código da operação (1.Depósito conta corrente 2.Depósito poupança 3.Retirada conta corrente 4.Retirada poupança 5.Fim) e o valor do movimento. O programa termina ao ser informado um código igual a 5 (nesta situação o valor do movimento não deve ser lido).
    
    -Cada conta deve ser armazenada em uma variável do tipo Conta.
    -A cada operação executada o programa deve exibir o saldo atualizado das duas contas.
    -A operação de retirada da conta poupança só deverá ocorrer se houver saldo disponível, caso contrário a mensagem "Saldo insuficiente" deverá ser exibida.
    -As operações de depósito e retirada devem ser realizadas com chamadas as funções depositaNaConta e retiraDaConta.
    -A operação de retirada da conta corrente deverá ser executada da seguinte forma:
    
    se saldo na conta corrente for insuficiente então
        se saldo na poupança for suficiente para cobrir o valor que falta então
            transferir o valor que falta para a conta corrente e executar a retirada
        senão
            exibir a mensagem "Saldo insuficiente"
        fim_se
    senão
        executar a retirada
    fim_se

*/
# include <stdio.h>
# include <locale.h>

// Criando uma estrutura do tipo Conta
typedef struct {
    int numero;
    float saldo;
} Conta;

// Definindo funções
void criaConta (int numero, Conta *c); // função do tipo Conta com retorno do número da conta

void depositaNaConta (Conta *c, float valor); // função sem retorno entra com valor de deposito e 
                                              // armazena no poneitor *c

int retiraDaConta (Conta *c, float valor);    // função que retorna o valor de saque que é extraido 
                                              // do ponteiro c*

float obtemSaldo (Conta c);  // função que restorna o saldo da conta



int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int num_CC, num_CP; // conta corrente e conta poupança
    float saldo_CC, saldo_CP; // saldo das contas
    
    // Inputs
    // Criar contas
    printf("Digite número da Conta Corrente: "); // numero da conta corrente a ser criada
    scanf("%d", &num_CC);
    printf("Digite saldo da Conta Corrente: "); // saldo inicial da conta, será atribuido com a função
    scanf("%f", &saldo_CC);                     // depositaNaConta
    
    printf("Digite número da Conta Poupança: "); 
    scanf("%d", &num_CP);
    printf("Digite saldo da Conta Poupança: "); 
    scanf("%f", &saldo_CP);

    // Processing
    Conta corrente, poupanca;
    criaConta(num_CC, &corrente); // cria a CC com saldo 0
    criaConta(num_CP, &poupanca); // cria a CP com saldo 0

    // deposita o "saldo inicial" lido, que na prática é o primeiro depósito
    depositaNaConta(&corrente, saldo_CC);
    depositaNaConta(&poupanca, saldo_CP);

    int op; 
    float valor;

    while (1) {
        printf("Digite uma das operações abaixo:\n");
        printf(" 1.Depósito conta corrente\n 2.Depósito poupança\n 3.Retirada conta corrente\n 4.Retirada poupança\n 5.Fim\nOperação: ");
        scanf("%d", &op);
        
        if (op == 5) {
            printf("Saldo Conta Corrente: %.2f\nSaldo Conta Poupança: %.2f\n",
            obtemSaldo(corrente), obtemSaldo(poupanca));
            break;
        }

        if (op == 1) { // depósito corrente
            printf("Digite o valor de para deposito na conta corrente: ");
            scanf("%f", &valor);
            depositaNaConta(&corrente, valor);
        }
        
        else if (op == 2) { // depósito poupança
            printf("Digite o valor de para deposito na conta poupança: ");
            scanf("%f", &valor);
            depositaNaConta(&poupanca, valor);
        }

        else if (op == 3) { // retirada corrente com transferência automática
            printf("Digite o valor de para retirar: ");
            scanf("%f", &valor);

            if (!retiraDaConta(&corrente, valor)) { // ao chamar a função retiraDaConta e retornar 0, 
                                                    // entra na condição e retira da poupança ou informa 
                                                    // que osaldo é insuficiente para efetuar o saque
                float falta = valor - obtemSaldo(corrente); // variável para saber quanto falta para o saque
                if (obtemSaldo(poupanca) >= falta) { // se o saldo da poupança for maior do que falta na cc
                                                     // entra na condição e retira da poupança quanto falta
                    retiraDaConta(&poupanca, falta);
                    depositaNaConta(&corrente, falta); // o valor que foi retirado da poupança é colocado na
                                                       // conta corrente
                    retiraDaConta(&corrente, valor); // finalmente o valor desejado de saque é retirado da
                                                     // conta corrente
                } else {
                    printf("Saldo insuficiente\n"); // caso não tenha saldo na conta poupança, informa saldo
                                                    // insuficiênte
                }
            }
        }
        
        else if (op == 4) { // retirada poupança
            printf("Digite o valor de para retirar da poupança: ");
            scanf("%f", &valor);
            if (!retiraDaConta(&poupanca, valor)) {
                printf("Saldo insuficiente\n");
            }
        }

        printf("Saldo Conta Corrente: %.2f\nSaldo Conta Poupança: %.2f\n",
        obtemSaldo(corrente), obtemSaldo(poupanca));
    }

    // Outputs

    return 0;
}

/*  função que cria uma conta nova. recebe como parâmetro o numero da conta
    ao qual, é atribuido a c.numero. Variável local c do tipo Conta que será 
    retornada. O saldo da conta é iniciado em 0.0*/
void criaConta(int numeroConta, Conta *c) {
    c -> numero = numeroConta;
    c -> saldo = 0.0;
}

/*  função para realizar um deposito na conta. recebe um valor e atualiza no ponteiro c**/
void depositaNaConta (Conta *c, float valor) {
    c->saldo += valor;
}

/* função que recebe um ponteiro c* do tipo Conta e um float como valor de retirada de saque*/
int retiraDaConta(Conta *c, float valor) {
    if (c->saldo >= valor) {
        c->saldo -= valor;
        return 1; /* se o saldo da conta for maior que o valor de retirada, a operação é concluida
                     o saldo é atulizado com a subtração do valor desejado*/
    } else {
        return 0; // caso o valor de retirada seja maior que o saldo, retorna 0
    }
}

// função que recebe uma conta e retorna o seu saldo 
float obtemSaldo(Conta c) {
    return c.saldo;
}