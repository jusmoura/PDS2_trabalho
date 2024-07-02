CC=g++
BIN_DIR=bin
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj

all: main

$(OBJ_DIR)/game.o: $(INCLUDE_DIR)/game.hpp $(SRC_DIR)/game.cpp
	$(CC) -c $(SRC_DIR)/game.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/game.o

$(OBJ_DIR)/game_controller.o: $(INCLUDE_DIR)/game_controller.hpp $(SRC_DIR)/game_controller.cpp $(INCLUDE_DIR)/game.hpp
	$(CC) -c $(SRC_DIR)/game_controller.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/game_controller.o
    
$(OBJ_DIR)/player.o: $(INCLUDE_DIR)/player.hpp $(SRC_DIR)/player.cpp $(INCLUDE_DIR)/game_controller.hpp
	$(CC) -c $(SRC_DIR)/player.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/player.o
    
$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/player.hpp $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o
    
main: $(OBJ_DIR)/main.o $(OBJ_DIR)/game.o $(OBJ_DIR)/game_controller.o $(OBJ_DIR)/player.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/game_controller.o $(OBJ_DIR)/game.o $(OBJ_DIR)/player.o -o $(BIN_DIR)/main
    
clean:
	rm -f $(BIN_DIR)/main $(OBJ_DIR)/*.o