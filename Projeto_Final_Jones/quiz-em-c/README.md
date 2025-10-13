# Quiz em C - Desafio do Conhecimento

## 🎯 Objetivo do Projeto

Desenvolver um jogo de perguntas e respostas interativo em linguagem C, utilizando conceitos de Estruturas de Dados (Listas Encadeadas, Filas e Pilhas) para gerenciar perguntas, jogadores e histórico de partidas. O quiz contará com diferentes níveis de dificuldade e áreas de conhecimento, proporcionando uma experiência desafiadora e educativa.

## ✨ Funcionalidades Principais

### 1. Cadastro de Jogador

- Registro de informações básicas do usuário: Nome, Idade/Data de Nascimento, Cidade/Estado, Escolaridade.

### 2. Menu Principal

- **Novo Jogo:** Inicia uma nova partida do quiz.
- **Histórico / Ranking:** Exibe as pontuações dos jogadores e o histórico de partidas.
- **Sair:** Encerra o programa.

### 3. Seleção de Dificuldade

O jogador poderá escolher entre três níveis de dificuldade, que influenciam a quantidade de questões, tempo por questão e número de áreas:

- **Fácil:**
  - Escolha de até **2 áreas** de conhecimento.
  - **10 questões** a serem respondidas.
  - **3 minutos** por questão.
  - Questões de múltipla escolha com **3 opções**.
    - A) B) C)
- **Médio:**
  - Escolha de **até 4 áreas** de conhecimento.
  - **25 questões** a serem respondidas.
  - **2 minutos** por questão.
  - Questões de múltipla escolha com **4 opções**.
    - A) B) C) D)
- **Difícil:**
  - Escolha de **pelo menos 2 ou todas** **as áreas** de conhecimento.
  - **50 questões** a serem respondidas.
  - **1 minuto** por questão.
  - Questões de múltipla escolha com **5 opções**.
    - A) B) C) D) E)

Cada questão correta vale 1 ponto.

### 4. Áreas de Conhecimento

O quiz abrangerá as seguintes áreas:

- Português
- Matemática
- Física
- Inglês
- Tecnologia
- Conhecimentos Gerais
- Cultura Pop
- Filmes & Séries

### 5. Aleatoriedade das Questões

As questões serão selecionadas aleatoriamente de um banco de dados (arquivos `.txt`), garantindo que cada partida seja única e desafiadora.

## 🧱 Estruturas de Dados Utilizadas

O projeto fará uso das seguintes Tipos Abstratos de Dados (TADs):

- **Lista Encadeada:** Para armazenar e gerenciar o ranking de jogadores (ordenado por pontuação) e as perguntas carregadas em memória.
- **Fila:** Para controlar a sequência de perguntas a serem apresentadas durante uma partida, garantindo a ordem de exibição.
- **Pilha:** Para registrar o histórico de questões respondidas em uma partida, permitindo uma possível revisão ou análise.

## 📁 Estrutura de Arquivos do Projeto

### Raiz de arquivos

quiz-em-c/
├── README.md		# Documentação do projeto (visão geral, como compilar/rodar)
├── Makefile                  # Regras de compilação (gcc, flags, alvos: all, clean, run)
├── src/                      	# Código-fonte C
│   ├── main.c              	# Ponto de entrada: orquestra menus e fluxo do jogo
│   ├── app/                  	# Camada de aplicação (interação e regras do jogo)
│   │   ├── menu.c      	# Implementação dos menus
│   │   ├── menu.h
│   │   ├── quiz.c       	# Controle da partida (seleção, tempo, pontuação)
│   │   ├── quiz.h
│   │   ├── jogador.c    	# Cadastro/validação de dados do jogador
│   │   └── jogador.h
│   ├── core/                 	# Regras de negócio (modelos e lógica central)
│   │   ├── questao.c   	# Utilidades da Questao (validação, helpers)
│   │   ├── questao.h   	# struct Questao, enums de dificuldade/área
│   │   ├── ranking.c    	# Lista ordenada de jogadores por pontuação
│   │   └── ranking.h
│   ├── ds/                   	# Estruturas de dados genéricas (TADs)
│   │   ├── fila.c            	# Fila para sequência de perguntas
│   │   ├── fila.h
│   │   ├── pilha.c       	# Pilha para histórico de questões respondidas
│   │   ├── pilha.h
│   │   ├── lista.c       	# Lista encadeada (ranking, coleção de questões)
│   │   └── lista.h
│   └── io/                   	# Entrada/saída e persistência
│       ├── parser.c       	# Leitura dos .txt por área/dificuldade
│       ├── parser.h
│       ├── storage.c    	# Persistência de ranking/histórico em arquivos
│       └── storage.h
└── data/                     	# Dados externos (não compilados)
    ├── perguntas/        	# Banco de perguntas por área
    │   ├── portugues.txt
    │   ├── matematica.txt
    │   ├── fisica.txt
    │   ├── computacao.txt
    │   ├── conhecimentos_gerais.txt
    │   ├── cultura_pop.txt
    │   ├── filmes_series.txt
    │   └── ingles.txt
    ├── ranking.txt        	# Ranking persistido entre execuções
    └── historico.txt     	# Histórico de partidas (opcional)

### 📄Formato dos Arquivos

#### perguntas.txt

```
## 📄 Formato dos Arquivos de Perguntas (`.txt`)  
Cada arquivo de área (`portugues.txt`, `matematica.txt`, etc.) conterá as questões separadas por dificuldade.  
  
```

**#Dificuldade: 1**

Qual é o plural de "pão"?

A) Pães

B) Pãos

C) Pãeses

*Resposta: A*

**#Dificuldade: 2**

Em qual alternativa há crase obrigatória?

A) Vou à escola

B) Cheguei à tarde

C) Dei o livro à ele

D) Devo fazer à tarefa cedo

*Resposta: A*

**#Dificuldade: 3**

Qual figura de linguagem ocorre em "choveu canivetes"?

A) Metonímia

B) Hipérbole

C) Metáfora

D) Pleonasmo

E) Eufemismo

*Resposta: C*

#### ranking.txt

```
## 🏆 Formato do Arquivo de Ranking (`ranking.txt`)  
O arquivo `ranking.txt` armazenará os resultados dos jogadores no formato:  
```

Nome do Jogador;Pontuação;Dificuldade

Gabriel Ferreira;8;Fácil

Mariana Lopes;12;Médio

Rafael Pinto;35;Difícil

### 🛠️ Como Compilar e Executar (Exemplo Básico)

#### Requisitos

* GCC (ou Clang) instalado
* Make instalado
* Terminal posicionado na raiz do projeto (quiz-em-c/)

#### Compilação (recomendado)

**bash**

make

* O Makefile compila todos os arquivos em src/ e gera o executável: quiz_em_c

Alvos úteis:

* make run → compila (se necessário) e executa
* make clean → remove arquivos compilados (build/) e o executável

#### Execução

**bash**

./quiz_em_c

* No Windows (MinGW): .\quiz_em_c.exe

#### Compilação manual (alternativa, sem Makefile)

Se preferir compilar manualmente, execute a partir da raiz do projeto:

**bash**

gcc -Wall -Wextra -std=c11 -I./src
  src/main.c
  src/app/menu.c src/app/quiz.c src/app/jogador.c
  src/core/questao.c src/core/ranking.c
  src/ds/fila.c src/ds/pilha.c src/ds/lista.c
  src/io/parser.c src/io/storage.c
  -o quiz_em_c

*Observações:

* A flag -I./src permite includes como "app/quiz.h", "core/questao.h", "ds/fila.h", "io/parser.h".
* Se você adicionar novos arquivos .c, atualize a lista SOURCES no Makefile (ou inclua no comando manual).
* 

## 🚀 Próximos Passos

Para dar vida ao "Quiz em C", as próximas etapas de desenvolvimento incluem:

1. [ ] **Definição e Implementação dos TADs:**
    * [ ] Criar as estruturas (`struct`) e funções básicas para os Tipos Abstratos de Dados (TADs) `Fila`, `Pilha` e `Lista` no diretório `src/ds/`.
    * [ ] Implementar as operações essenciais para cada TAD (inicialização, inserção, remoção, verificação de vazio, etc.).
2. [ ] **Modelagem das Entidades Principais:**
    * [ ] Definir as estruturas `Jogador` (em `src/app/jogador.h`) e `Questao` (em `src/core/questao.h`) com todos os atributos necessários.
3. [ ] **Desenvolvimento do Módulo de Leitura (`src/io/parser.c`):**
    * [ ] Implementar a lógica para ler e parsear os arquivos de perguntas (`data/perguntas/*.txt`), filtrando por área e dificuldade conforme o formato definido.
    * [ ] Garantir que as questões sejam carregadas corretamente em uma estrutura de dados em memória (ex: uma lista encadeada de `Questao`).
4. [ ] **Implementação da Lógica do Jogo (`src/app/quiz.c`):**
    * [ ] Desenvolver a seleção aleatória e o embaralhamento das questões.
    * [ ] Criar a interface para apresentação das perguntas e coleta das respostas do jogador.
    * [ ] Implementar o temporizador para cada questão.
    * [ ] Contabilizar a pontuação e gerenciar o fluxo da partida.
5. [ ] **Gerenciamento de Ranking e Histórico (`src/core/ranking.c` e `src/io/storage.c`):**
    * [ ] Implementar a inserção de jogadores no ranking (lista ordenada).
    * [ ] Desenvolver as funções para salvar e carregar o ranking e o histórico de partidas nos arquivos `data/ranking.txt` e `data/historico.txt`.
6. [ ] **Criação dos Menus Interativos (`src/app/menu.c`):**
    * [ ] Implementar o menu principal e o menu de seleção de dificuldade, integrando as funcionalidades de "Novo Jogo", "Histórico/Ranking" e "Sair".

* [ ] **Alimentar diretório perguntas**
  * [X] portugues.txt
  * [ ] matematica.txt
  * [ ] fisica.txt
  * [ ] ingles.txt
  * [ ] tecnologia.txt
  * [ ] conhecimentos_gerais.txt
  * [ ] cultura_pop
  * [ ] filmes_series

# Fim
