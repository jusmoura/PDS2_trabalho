# Compilador
CC = g++

# Diretórios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Lista de arquivos fonte e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN_DIR)/main

# Compila os arquivos .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $< -o $@

# Limpar
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/main

.PHONY: all clean