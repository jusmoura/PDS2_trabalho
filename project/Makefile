CC=g++

# Pastas Principais
BIN_DIR=bin
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj

# Models & Controllers
MODELS_DIR=models
CONTROLLERS_DIR=controllers

# Sub-Pastas
PLAYERS_DIR=players
GAMES_DIR=games

all: main

# Modelo
# $(SRC_DIR)/$(PLAYERS_DIR)/$(MODELS_DIR)/player.cpp
# $(SRC_DIR)/$(PLAYERS_DIR)/$(CONTROLLERS_DIR)/player_controller.cpp

# Players Module
$(OBJ_DIR)/game.o: $(INCLUDE_DIR)/game.hpp $(SRC_DIR)/$(PLAYERS_DIR)/$(MODELS_DIR)/game.cpp
	$(CC) -c $(SRC_DIR)/$(PLAYERS_DIR)/$(MODELS_DIR)/game.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/game.o

$(OBJ_DIR)/game_controller.o: $(INCLUDE_DIR)/game_controller.hpp $(SRC_DIR)/$(PLAYERS_DIR)/$(CONTROLLERS_DIR)/game_controller.cpp $(INCLUDE_DIR)/game.hpp
	$(CC) -c $(SRC_DIR)/$(PLAYERS_DIR)/$(CONTROLLERS_DIR)/game_controller.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/game_controller.o
    
$(OBJ_DIR)/player.o: $(INCLUDE_DIR)/player.hpp $(SRC_DIR)/$(PLAYERS_DIR)/$(MODELS_DIR)/player.cpp $(INCLUDE_DIR)/game_controller.hpp
	$(CC) -c $(SRC_DIR)/$(PLAYERS_DIR)/$(MODELS_DIR)/player.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/player.o

$(OBJ_DIR)/database_controller.o: $(INCLUDE_DIR)/database_controller.hpp $(SRC_DIR)/$(PLAYERS_DIR)/$(CONTROLLERS_DIR)/database_controller.cpp $(INCLUDE_DIR)/player_controller.hpp
	$(CC) -c $(SRC_DIR)/$(PLAYERS_DIR)/$(CONTROLLERS_DIR)/database_controller.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/database_controller.o

$(OBJ_DIR)/player_controller.o: $(INCLUDE_DIR)/player_controller.hpp $(SRC_DIR)/$(PLAYERS_DIR)/$(CONTROLLERS_DIR)/player_controller.cpp $(INCLUDE_DIR)/player.hpp $(INCLUDE_DIR)/database_controller.hpp
	$(CC) -c $(SRC_DIR)/$(PLAYERS_DIR)/$(CONTROLLERS_DIR)/player_controller.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/player_controller.o

# Games Module
#
#
#
#

# main
$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/player_controller.hpp $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o
    
main: $(OBJ_DIR)/main.o $(OBJ_DIR)/game.o $(OBJ_DIR)/game_controller.o $(OBJ_DIR)/player.o $(OBJ_DIR)/player_controller.o $(OBJ_DIR)/database_controller.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/game_controller.o $(OBJ_DIR)/game.o $(OBJ_DIR)/player.o $(OBJ_DIR)/player_controller.o $(OBJ_DIR)/database_controller.o -o $(BIN_DIR)/main
    
clean:
	rm -f $(BIN_DIR)/main $(OBJ_DIR)/*.o