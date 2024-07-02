CC=g++
BIN_DIR=bin
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj

all: main

$(OBJ_DIR)/games.o: $(INCLUDE_DIR)/games.hpp $(SRC_DIR)/games.cpp
	$(CC) -c $(SRC_DIR)/games.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/games.o
    
$(OBJ_DIR)/player.o: $(INCLUDE_DIR)/player.hpp $(SRC_DIR)/player.cpp $(INCLUDE_DIR)/games.hpp
	$(CC) -c $(SRC_DIR)/player.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/player.o
    
$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/games.hpp $(INCLUDE_DIR)/player.hpp $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o
    
main: $(OBJ_DIR)/main.o $(OBJ_DIR)/games.o $(OBJ_DIR)/player.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/games.o $(OBJ_DIR)/player.o -o $(BIN_DIR)/main
    
clean:
	rm -f $(BIN_DIR)/main $(OBJ_DIR)/*.o