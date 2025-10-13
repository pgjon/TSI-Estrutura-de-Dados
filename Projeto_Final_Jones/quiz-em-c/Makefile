# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./src

# Diretórios
SRC_DIR = src
OBJ_DIR = build

# Subpastas do src
APP_DIR = $(SRC_DIR)/app
CORE_DIR = $(SRC_DIR)/core
DS_DIR = $(SRC_DIR)/ds
IO_DIR = $(SRC_DIR)/io

# Nome do executável
TARGET = quiz_em_c

# Lista de fontes (.c)
SOURCES = \
  $(SRC_DIR)/main.c \
  $(APP_DIR)/menu.c $(APP_DIR)/quiz.c $(APP_DIR)/jogador.c \
  $(CORE_DIR)/questao.c $(CORE_DIR)/ranking.c \
  $(DS_DIR)/fila.c $(DS_DIR)/pilha.c $(DS_DIR)/lista.c \
  $(IO_DIR)/parser.c $(IO_DIR)/storage.c

# Converte cada .c em um .o dentro de build/ mantendo a estrutura de pastas
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão: compilar tudo
all: $(TARGET)

# Como linkar (juntar) os objetos para formar o executável
$(TARGET): $(OBJECTS)
	@echo "Linkando $(TARGET)..."
	$(CC) $(CFLAGS) -o $@ $^

# Como compilar cada .c em .o (regra genérica com criação de diretórios)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Compilar e rodar
run: all
	./$(TARGET)

# Marca targets que não são arquivos
.PHONY: all clean run